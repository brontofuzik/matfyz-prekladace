%{  
  #include "du5.h"
  #include "du5lval.hpp"
  #include "duerr.h"
  #include "du5sem.h"
  #include "du5tok.h"

	/* Semantic value */
	#define YYSTYPE mlc::MlaskalLval

	/* Locations */
	#define YYLTYPE unsigned
	#define YYLLOC_DEFAULT(cur, rhs, n)	do { if(n) (cur)=(rhs)[1]; else (cur)=(rhs)[0]; } while(0)

	/* Local stuff */
	using namespace std;
	using namespace mlc;
	using namespace ai;
    
	/* Error stuff */
	#define YYERROR_VERBOSE 1
	static void yyerror(YYLTYPE *line, mlc::MlaskalCtx *ctx, const char *m);    
%}

/* Keywords */
%token DUTOK_PROGRAM             /* program */
%token DUTOK_LABEL               /* label */
%token DUTOK_CONST               /* const */
%token DUTOK_TYPE                /* type */
%token DUTOK_VAR                 /* var */
%token DUTOK_BEGIN               /* begin */
%token DUTOK_END                 /* end */
%token DUTOK_PROCEDURE           /* procedure */
%token DUTOK_FUNCTION	           /* function */
%token DUTOK_ARRAY               /* array */
%token DUTOK_OF                  /* of */
%token DUTOK_GOTO                /* goto */
%token DUTOK_IF                  /* if */
%token DUTOK_THEN                /* then */
%token DUTOK_ELSE                /* else */
%token DUTOK_WHILE               /* while */
%token DUTOK_DO                  /* do */
%token DUTOK_REPEAT              /* repeat */
%token DUTOK_UNTIL               /* until */
%token DUTOK_FOR                 /* for */
%token<dtge_> DUTOK_OR           /* or */
%token DUTOK_NOT                 /* not */
%token DUTOK_RECORD              /* record */

/* Literals */
%token<id_ci_> DUTOK_IDENTIFIER  /* identifier */
%token<int_ci_> DUTOK_UINT       /* unsigned integer */
%token<real_ci_> DUTOK_REAL      /* real number */
%token<str_ci_> DUTOK_STRING     /* string */

/* Delimiters */
%token DUTOK_SEMICOLON            /* ; */
%token DUTOK_DOT                  /* . */
%token DUTOK_COMMA                /* , */
%token<dtge_> DUTOK_EQ            /* = */
%token DUTOK_COLON                /* : */
%token DUTOK_LPAR                 /* ( */
%token DUTOK_RPAR                 /* ) */
%token DUTOK_DOTDOT               /* .. */
%token DUTOK_LSBRA                /* [ */
%token DUTOK_RSBRA                /* ] */
%token DUTOK_ASSIGN               /* := */

/* Grouped operators and keywords */
%token<dtge_> DUTOK_OPER_REL      /* <, <=, <>, >=, > */
%token<dtge_> DUTOK_OPER_SIGNADD  /* +, - */
%token<dtge_> DUTOK_OPER_MUL      /* *, /, div, mod, and */
%token<dtge_> DUTOK_FOR_DIRECTION /* to, downto */

/* Types */
%type<dtge_>
  relational_operator
  optional_sign
  additive_operator
  multiplicative_operator

%type<id_ci_>
  program_header
  procedure_header
  existing_constant
  existing_type

%type<typePointer>
  type_denoter
  new_type
  new_structured_type
  new_record_type

%type<functionHeader>
  function_header

%type<fieldList>
  optional_field_specification
  field_specification
  field_group_definition_list
  field_group_definition

%type<formalParameterList>
  optional_formal_parameter_specification
  formal_parameter_group_list
  formal_parameter_group
  formal_parameter_group_passed_by_value
  formal_parameter_group_passed_by_reference

%type<icblockPointer>
  program_block
  subprogram_block
  statement_section  
  compound_statement
  statement_sequence
  statement
  matched_statement
  unlabeled_matched_statement
  assignment_statement
  procedure_call_statement
  goto_statement
  matched_if_statement
  matched_while_statement
  repeat_statement
  matched_for_statement
  unmatched_statement
  unlabeled_unmatched_statement
  unmatched_if_statement
  unmatched_while_statement
  unmatched_for_statement
  
%type<constant>
  constant_denoter
  new_constant
  new_signless_constant
  new_signful_constant

%type<variable>
  array_variable
  record_variable

%type<typedICBlock>
  actual_parameter
  expression
  simple_expression
  signless_simple_expression
  term
  factor
  function_call

%type<identifierList>
  identifier_list

%type<actualParameterList>
  optional_actual_parameter_specification
  actual_parameter_specification
  actual_parameter_list

/* Options */
%start mlaskal
%error-verbose
%pure-parser
%parse-param {mlc::MlaskalCtx *ctx}
%lex-param {mlc::MlaskalCtx *ctx}
%locations

%%

mlaskal :
	program
	;
	
/***** Program *****/

program : /* Program */
	program_header DUTOK_SEMICOLON program_block DUTOK_DOT
	{
	  // SA, ICG
	  ctx->tab->set_main_code($1, $3);
  }
	;
	
program_header :
	DUTOK_PROGRAM DUTOK_IDENTIFIER
	{
	  // SA
	  $$ = $2;
  }
	;

program_block : /* Blok P */
	optional_label_declaration_section
	optional_constant_definition_section
	optional_type_definition_section
	optional_variable_definition_section
	optional_subprogram_definition_section
	statement_section
	{
	  // SA
	  $$ = $6;
  }
	;
	
/***** Optional label declaration section *****/
	
optional_label_declaration_section :
	label_declaration_section
| /* empty */
  ;

label_declaration_section :
  DUTOK_LABEL label_list DUTOK_SEMICOLON
  ;
	
label_list :
	label_list DUTOK_COMMA label_denoter
| label_denoter
	;
	
label_denoter :
	DUTOK_UINT
	{
		// SA
		lukas::AddLabel(ctx, @1, $1);
	}
	;
	
/***** Optional constant definition section *****/

optional_constant_definition_section :
  constant_definition_section
| /* empty */
  ;

constant_definition_section :
	DUTOK_CONST constant_definition_list DUTOK_SEMICOLON
  ;
	
constant_definition_list :
	constant_definition_list DUTOK_SEMICOLON constant_definition
| constant_definition
  ;
	
constant_definition :
	DUTOK_IDENTIFIER DUTOK_EQ constant_denoter
	{
		// SA 
		lukas::AddConstant(ctx, @1, $1 , $3);
	}
	;
	
/***** Constant denoter *****/

constant_denoter : /* Konstanta */
	existing_constant
	{
		// SA
		$$ = lukas::FindConstant(ctx, @1, $1);
		
	}
| new_constant
	{
		// SA (default)
		$$ = $1;
	}
  ;
    
existing_constant :
	DUTOK_IDENTIFIER
	{
		// SA (default)
		$$ = $1; 
	}
	;
	
new_constant :
	new_signless_constant
	{
		// SA (default)
		$$ = $1;
	}
| new_signful_constant
	{
		// SA (default)
		$$ = $1;
	}
	;	
	
new_signless_constant : /* Konstanta bez znamienka */
	DUTOK_UINT
	{
		// SA
		$$.typePointer = ctx->tab->logical_integer();
		$$.integerValue = $1;
	}
| DUTOK_REAL
  {
		// SA
		$$.typePointer = ctx->tab->logical_real();
		$$.realValue = $1;
	}
| DUTOK_STRING
  {
		// SA
		$$.typePointer = ctx->tab->logical_string();
		$$.stringValue = $1;
	}
  ;
	
new_signful_constant :
	DUTOK_OPER_SIGNADD DUTOK_UINT
	{
		// SA
		$$.typePointer = ctx->tab->logical_integer();
		$$.integerValue = ($1 == DUTOKGE_MINUS) ? ctx->tab->ls_int().add((-1) * (*$2)) : $2; 
	}
| DUTOK_OPER_SIGNADD DUTOK_REAL
	{
		// SA
		$$.typePointer = ctx->tab->logical_real();
		$$.realValue = ($1 == DUTOKGE_MINUS) ? ctx->tab->ls_real().add((-1) * (*$2)) : $2;
	}
  ;

/***** Optional type definition section *****/

optional_type_definition_section :
  type_definition_section
| /* empty */
  ;

type_definition_section :
	DUTOK_TYPE type_definition_list DUTOK_SEMICOLON
	;
	
type_definition_list :
	type_definition_list DUTOK_SEMICOLON type_definition
| type_definition
	;
	
type_definition :
	DUTOK_IDENTIFIER DUTOK_EQ type_denoter
	{
		// SA
		lukas::AddType(ctx, @1, $1, $3);
	}
	;
	
/***** Type denoter *****/
	
type_denoter : /* Typ */
	existing_type
	{
		// SA
		$$ = lukas::FindType(ctx, @1, $1);
	}
| new_type
  {
		// SA (default)
		$$ = $1;
	}
	;
	
existing_type :
	DUTOK_IDENTIFIER
	{
		// SA (default)
		$$ = $1;
	}
	;
	
new_type :
	new_ordinal_type
	{
    // SA (empty)
	}
| new_structured_type
  {
		// SA (default)
		$$ = $1;
	}
	;
	
/***** New ordinal type *****/

new_ordinal_type :
	new_enumerated_type
| new_subrange_type
	;

new_enumerated_type :
	DUTOK_LPAR identifier_list DUTOK_RPAR
	;

new_subrange_type :
	constant_denoter DUTOK_DOTDOT constant_denoter
	;

/***** New structured type *****/

new_structured_type :
	new_array_type
	{
    // SA (empty)
	}
| new_record_type
  {
		// SA (default)
		$$ = $1;
	}
	;
	
/***** New array type *****/

new_array_type :
	DUTOK_ARRAY DUTOK_LSBRA index_list DUTOK_RSBRA DUTOK_OF type_denoter
	;

index_list :
	index_list DUTOK_COMMA ordinal_type_denoter
| ordinal_type_denoter
  ;
	
ordinal_type_denoter :
	DUTOK_IDENTIFIER
| new_ordinal_type
  ;
	
/***** New record type *****/
	
new_record_type :
	DUTOK_RECORD optional_field_specification DUTOK_END
	{
		// SA
		$$ = ctx->tab->create_record_type($2, @1);
	}
  ;
	
optional_field_specification :
	field_specification
	{
	 	// SA (default)
	  $$ = $1;
	}
| /* empty */
  {
		// SA
		$$ = create_field_list();
	}
	;

field_specification :
  field_group_definition_list optional_semicolon
  {
    // SA
    $$ = $1;
  }
  ;
	
field_group_definition_list : /* Zoznam poloziek */
	field_group_definition_list DUTOK_SEMICOLON field_group_definition
	{
		// SA
		$$ = $1;
		$$->append_and_kill($3);
	}
| field_group_definition
  {
		// SA (default)
		$$ = $1;
	}
	;
	
field_group_definition :
	identifier_list DUTOK_COLON type_denoter
	{
		// SA
		$$ = create_field_list();
		lukas::AppendFieldGroup($$, $1, $3);
	}
	;

identifier_list :
	identifier_list DUTOK_COMMA DUTOK_IDENTIFIER
	{
		// SA
		$$ = $1;
		
		lukas::linenumber_identifier_pair linenumberIdentifierPair(@3, $3); 
		$$.push_back(linenumberIdentifierPair);
	}
| DUTOK_IDENTIFIER
	{
		// SA
		$$ = lukas::identifier_list();
		
		lukas::linenumber_identifier_pair linenumberIdentifierPair(@1, $1);
		$$.push_back(linenumberIdentifierPair); 
	}
	;

optional_semicolon :
	DUTOK_SEMICOLON
| /* empty */
	;
	
/**** Optional variable definition section ****/

optional_variable_definition_section :
  variable_definition_section
| /* empty */
  ;

variable_definition_section :
	DUTOK_VAR variable_group_definition_list DUTOK_SEMICOLON
	;
	
variable_group_definition_list :
	variable_group_definition_list DUTOK_SEMICOLON variable_group_definition
| variable_group_definition
	;
	
variable_group_definition :
	identifier_list DUTOK_COLON type_denoter
	{
		// SA
		lukas::AddVariableGroup(ctx, $1, $3);
	}
	;
	
/***** Variable access *****/

variable_access :
	DUTOK_IDENTIFIER
	{
	  // SA (empty)
  }
| array_variable
  {
    // SA (empty)
  }
| record_variable
  {
    // SA (empty)
  }
	;
	
array_variable :
	variable_access DUTOK_LSBRA expression_list DUTOK_RSBRA
  {
    // TODO
    $$ = lukas::Variable(SKIND_LOCAL_VARIABLE, ctx->tab->logical_undef(), 0);
  }
	;

expression_list :
	expression_list DUTOK_COMMA expression
| expression
	;


record_variable :
  record_variable DUTOK_DOT DUTOK_IDENTIFIER
  {
    // SA
    $$ = lukas::FindField(ctx, $1, @3, $3);
  }
| DUTOK_IDENTIFIER DUTOK_DOT DUTOK_IDENTIFIER
  {
    // SA
    lukas::Variable recordVariable = lukas::FindVariable(ctx, @1, $1);
    $$ = lukas::FindField(ctx, recordVariable, @3, $3);
  }
  ;	
	
/***** Optional subprogram definition section *****/

optional_subprogram_definition_section :
  subprogram_definition_section
| /* empty */
	;

subprogram_definition_section :
	subprogram_definition_list DUTOK_SEMICOLON
	;
	
subprogram_definition_list :
	subprogram_definition_list DUTOK_SEMICOLON subprogram_definition
| subprogram_definition
	;
	
subprogram_definition :
	procedure_definition
| function_definition
	;
	
/***** Procedure definition *****/
	
procedure_definition :
	procedure_header DUTOK_SEMICOLON subprogram_block
	{
		// SA, ICG
		ctx->tab->set_subprogram_code($1, $3);
		ctx->tab->leave(@3);
	}
	;
	
procedure_header : /* Zahlavie procedury */
	DUTOK_PROCEDURE DUTOK_IDENTIFIER optional_formal_parameter_specification
	{
		// SA
    // Pass the procedure identifier to the procedure definition.
		$$ = $2;
		
		ctx->tab->add_proc(@2, $2, $3);
		ctx->tab->enter(@2, $2);
	}
	;
	
optional_formal_parameter_specification :
	DUTOK_LPAR formal_parameter_group_list DUTOK_RPAR
	{
		// SA
		$$ = $2
	}
| /* empty */
	{
		// SA
		$$ = create_parameter_list();
	}
	;
	
formal_parameter_group_list : /* Formalne parametre */
	formal_parameter_group_list DUTOK_SEMICOLON formal_parameter_group
	{
		// SA
		$$ = $1; 
		$$->append_and_kill($3);
	}
| formal_parameter_group
	{
		// SA (default)
		$$ = $1;
	}
	;
	
formal_parameter_group :
	formal_parameter_group_passed_by_value
	{
		// SA (default)
		$$ = $1;
	}
| formal_parameter_group_passed_by_reference
	{
		// SA (default)
		$$ = $1;
	}
	;
	
formal_parameter_group_passed_by_value :
	identifier_list DUTOK_COLON existing_type
	{
		// SA
		$$ = create_parameter_list();
		
		// `true' as the second actual parameter specifies appending by value.
		lukas::AppendFormalParameterGroup(ctx, $$, true, $1, @3, $3);
	}
	;
	
formal_parameter_group_passed_by_reference :
	DUTOK_VAR identifier_list DUTOK_COLON existing_type
	{
		// SA
		$$ = create_parameter_list();
		
		// `false' as the second actual parameter specifies appending by reference.
		lukas::AppendFormalParameterGroup(ctx, $$, false, $2, @4, $4);
	}
	;
	
subprogram_block : /* Blok */
	optional_label_declaration_section
	optional_constant_definition_section
	optional_type_definition_section
	optional_variable_definition_section
	statement_section
	{
	  // SA
	  $$ = $5;
  }
	;
	
/***** Function definition *****/

function_definition :
	function_header DUTOK_SEMICOLON subprogram_block
	{
		// SA, ICG
		lukas::AppendSTInstruction($3, SKIND_LOCAL_VARIABLE, $1.functionReturnTypePointer->cat(), ctx->tab->my_return_address());
		ctx->tab->set_subprogram_code($1.functionIdentifier, $3);
		ctx->tab->leave(@3);
	}
	;
	
function_header : /* Zahlavie funkcie */
	DUTOK_FUNCTION DUTOK_IDENTIFIER optional_formal_parameter_specification DUTOK_COLON existing_type
	{
    // Ensure the function return type is scalar.
    type_pointer functionReturnTypePointer = lukas::FindType(ctx, @5, $5);
    if (!lukas::IsScalarType(functionReturnTypePointer->cat()))
    {
      // Error (The function return type is not scalar.)
      error(DUERR_NOTSCALAR, @5, $5->c_str());
    }

    // Pass the function header to the function definition.
    $$ = lukas::FunctionHeader($2, functionReturnTypePointer);

		ctx->tab->add_fnc(@2, $2, functionReturnTypePointer, $3);
		ctx->tab->enter(@2, $2);	
	}
	;
	
/***** Statement section *****/

statement_section :                          
	compound_statement
	{
	  // SA (default)
	  $$ = $1;
  }
	;
	
compound_statement :
	DUTOK_BEGIN statement_sequence DUTOK_END
  {
    // SA (default)
    $$ = $2;
  }
	;
	
statement_sequence :
	statement_sequence DUTOK_SEMICOLON statement
	{
	  // SA
	  $$ = $1;
	  icblock_append_delete($$, $3);
  }
| statement
  {
    // SA (default)
    $$ = $1;
  }
	;
	
/***** Statement *****/

statement : /* Prikaz */
	matched_statement
	{
	  // SA (default)
	  $$ = $1;
  }
| unmatched_statement
  {
    // SA (default)
    $$ = $1;
  }
	;
	
/***** Matched statement *****/	
	
matched_statement :
	optional_label unlabeled_matched_statement
	{
	  // SA
	  $$ = $2;
  }
  ;
	
optional_label :
  label_denoter DUTOK_COLON
| /* empty */
  ;

unlabeled_matched_statement : 
	assignment_statement
	{
	  // SA (default)
	  $$ = $1;
  }
| procedure_call_statement
  {
    // SA (default)
    $$ = $1;
  }
| goto_statement
  {
    // SA (empty)
  }
| compound_statement
  {
    // SA (default)
    $$ = $1;
  }
| matched_if_statement
  {
    // SA (default)
    $$ = $1;
  }
| matched_while_statement
  {
    // SA (default)
    $$ = $1;
  }
| repeat_statement
  {
    // SA (default)
    $$ = $1;
  }
| matched_for_statement
  {
    // SA (default)
    $$ = $1;
  }
| /* empty */
  {
    $$ = icblock_create();
  }
	;
	
/***** Assignment statement *****/	
	
assignment_statement :
  DUTOK_IDENTIFIER DUTOK_ASSIGN expression
  {
    // SA
    $$ = icblock_create();
    lukas::AppendAssignmentStatementICBlock(ctx, @$, $$, $1, $3);
  }
| array_variable DUTOK_ASSIGN expression
  {
    // SA
    $$ = icblock_create();
    lukas::AppendVariableAssignmentStatementICBlock(@$, $$, $1, $3);
  }
| record_variable DUTOK_ASSIGN expression
  {
    // SA
    $$ = icblock_create();
    lukas::AppendVariableAssignmentStatementICBlock(@$, $$, $1, $3);
  }
  ;
	
/***** Procedure call statement *****/
	
procedure_call_statement :
	DUTOK_IDENTIFIER optional_actual_parameter_specification
	{
    // SA, ICG
    $$ = icblock_create();
    lukas::AppendProcedureCallStatementICBlock(ctx, @1, $$, $1, $2);
  }
	;
	
optional_actual_parameter_specification :
	actual_parameter_specification
	{
    // SA (default)
	  $$ = $1;
  }
| /* empty */
  {
    $$ = lukas::actual_parameter_list();
  } 
	;

actual_parameter_specification :
  DUTOK_LPAR actual_parameter_list DUTOK_RPAR
  {
    // SA
    $$ = $2;
  }
  ;
	
actual_parameter_list : /* Skutocne parametre */
	actual_parameter_list DUTOK_COMMA actual_parameter
	{
	  // SA
	  $$ = $1;
	  
	  $$.push_back($3);
  }
| actual_parameter
  {
    // SA
    $$ = lukas::actual_parameter_list();
    
    $$.push_back($1);
  }
	;
	
actual_parameter :
	expression
	{
	  // SA (default)
    $$ = $1;  
  }
	;
	
/***** Goto statement *****/

goto_statement :
	DUTOK_GOTO label_denoter
  {
    // SA (empty)
  }
	;

/***** Matched if statement *****/

matched_if_statement :
	DUTOK_IF expression DUTOK_THEN matched_statement DUTOK_ELSE matched_statement
  {
    // SA (empty)
  }
	;
	
/***** Matched while statement *****/

matched_while_statement :
	while_header matched_statement
  {
    // SA (empty)
  }
	;
	
while_header :
	DUTOK_WHILE expression DUTOK_DO
	;
	
/***** Repeat statement *****/
	
repeat_statement :
  DUTOK_REPEAT statement_sequence DUTOK_UNTIL expression
  {
    // SA (empty)
  }
	;
	
/***** Matched for statement *****/

matched_for_statement :
	for_header matched_statement
  {
    // SA (empty)
  }
	;
	
for_header :
	DUTOK_FOR DUTOK_IDENTIFIER DUTOK_ASSIGN expression DUTOK_FOR_DIRECTION expression DUTOK_DO
	;
	
/***** Unmatched statement *****/	
	
unmatched_statement :
	optional_label unlabeled_unmatched_statement
	{
	  // SA
	  $$ = $2;
  }
	;
	
unlabeled_unmatched_statement :
	unmatched_if_statement
	{
    // SA (default)
    $$ = $1;
  }
| unmatched_while_statement
  {
    // SA (default)
    $$ = $1;
  }
| unmatched_for_statement
  {
    // SA (default)
    $$ = $1;
  }
	;

/***** Unmatched if statement *****/
	
unmatched_if_statement :
  DUTOK_IF expression DUTOK_THEN matched_statement DUTOK_ELSE unmatched_statement
  {
    // SA (empty)
  }
| DUTOK_IF expression DUTOK_THEN statement
  {
    // SA (empty)
  }
	;
	
/***** Unmatched while statement *****/

unmatched_while_statement :
	while_header unmatched_statement
  {
    // SA (empty)
  }
	;
	
/***** Unmatched for statement *****/

unmatched_for_statement :
	for_header unmatched_statement
  {
    // SA (empty)
  }
	;
	
/***** Expression *****/	
	
expression : /* Vyraz */ /* Can be boolean, integer or real. */
	simple_expression relational_operator simple_expression
| simple_expression
  {
    // SA (default)
    $$ = $1;
  }
	;
	
relational_operator : /* <, <=, =, <>, >=, > */
	DUTOK_OPER_REL
  {
    // SA (default)
    $$ = $1;
  }
| DUTOK_EQ
  {
    // SA (default)
    $$ = $1;
  }
	;
	
/***** Simple expression *****/

simple_expression : /* Jednoduchy vyraz */ /* Can be integer or real. */
	optional_sign signless_simple_expression
	{
	  // SA, ICG
    $$.icblockPointer = icblock_create();

    // Depending on the operator ...
    switch ($1)
    {
      case DUTOKGE_MINUS :
      {
        // ... append a (unary) minus operation.
        lukas::AppendMinusOperationTypedICBlock(ctx, @$, $$, $2);
      }
      break;
      default :
      {
        $$ = $2;
      }
      break;
    }
  }
	;
	
optional_sign : /* +, -, */
	DUTOK_OPER_SIGNADD
  {
    // SA (default)
    $$ = $1;
  }
| /* empty */
  {
    // SA
    $$ = -1;
  }
	;

signless_simple_expression : /* Can be integer or real. */
	signless_simple_expression additive_operator term
	{
	  // SA, ICG
    $$.icblockPointer = icblock_create();

    // Depending on the opeartor ...
    switch ($2)
    {
      case DUTOKGE_PLUS :
      {
        // ... append an addition operation.
        lukas::AppendAdditionOperationTypedICBlock(ctx, @$, $$, $1, $3);
      }
      break;
      case DUTOKGE_MINUS :
      {
        // ... append a subtraction operation.
        lukas::AppendSubtractionOperationTypedICBlock(ctx, @$, $$, $1, $3);
      }
      break;
      case DUTOK_OR :
      {
        // ... append a disjunction operation.
        lukas::AppendDisjunctionOperationTypedICBlock(ctx, @$, $$, $1, $3);
      }
      break;
      default:
      {
        // Error (Unsupported operator.)
      }
      break;
    }
  }
| term
  {                                        
    // SA (default)
    $$ = $1;
  }
	;
	
additive_operator : /* +, -, or */
	DUTOK_OPER_SIGNADD
   {
    // SA (default)
    $$ = $1;
  }
| DUTOK_OR
  {
    // SA (default)
    $$ = $1;
  }
	;

/***** Term *****/

term : /* Term */ /* Can be integer or real. */
	term multiplicative_operator factor
	{
	  // SA, ICG
    $$.icblockPointer = icblock_create();

    // Depending on the operator ...
    switch ($2)
    {
      case DUTOKGE_ASTERISK :
      {
        // ... append a multiplication operation.
        lukas::AppendMultiplicationOperationTypedICBlock(ctx, @$, $$, $1, $3);
      }
      break;
      case DUTOKGE_SOLIDUS :
      {
        // ... append a (real) division operation.
        lukas::AppendRealDivisionOperationTypedICBlock(ctx, @$, $$, $1, $3);
      }
      break;
      case DUTOKGE_DIV :
      {
        // ... append a (integral) division operation.
        lukas::AppendIntegerDivisionOperationTypedICBlock(ctx, @$, $$, $1, $3);
      }
      break;
      case DUTOKGE_MOD :
      {
        // ... append a modulo operation.
        lukas::AppendModuloOperationTypedICBlock(ctx, @$, $$, $1, $3);
      }
      break;
      case DUTOKGE_AND :
      {
        // ... append a conjunction operation.
        lukas::AppendConjunctionOperationTypedICBlock(ctx, @$, $$, $1, $3);
      }
      break;
      default :
      {
        // Error (Unsupported operand.)
      }
      break;
    }
  }
| factor
	{
	  // SA (default)
	  $$ = $1;
  }
	;

multiplicative_operator : /* *, /, div, mod, and */
	DUTOK_OPER_MUL
  {
    // SA (default)
    $$ = $1;
  }
	;
	
/***** Factor *****/

factor : /* Faktor */ /* Can be integer or real. */
  new_signless_constant /* Does not match DUTOK_IDENTIFIER. */
  {
    // SA, ICG
    
    // type
    $$.typePointer = $1.typePointer;
    
    // IC block
    $$.icblockPointer = icblock_create();
    lukas::AppendLDLITInstruction($$.icblockPointer, $1);
  }
| DUTOK_IDENTIFIER /* Matches constants, variables and parameterless function calls. */
  {
    // SA, ICG
    
    // Find the symbol in the semantic tables.
    symbol_pointer sp = ctx->tab->find_symbol($1);
    if (!sp)
    {
      // Error (The symbol does not exist.)
      error(DUERR_NOTVAR, @1, $1->c_str());
    }
  
    // Depending on the kind of symbol ...
    $$.icblockPointer = icblock_create();
    switch (sp->kind())
    {
      case SKIND_CONST :
      {
        // The symbol is a constant.
        
        // Find the constant in the semantic tables.
        lukas::Constant constant = lukas::FindConstant(ctx, @1, $1);
        
        // type
        $$.typePointer = constant.typePointer;
        
        // IC block
        lukas::AppendLDLITInstruction($$.icblockPointer, constant);
      }
      break;
      case SKIND_GLOBAL_VARIABLE :
      case SKIND_LOCAL_VARIABLE :
      {
        // The symbol is a (global or local) variable.
        
        // Find the variable in the semantic tables.
        lukas::Variable variable = lukas::FindVariable(ctx, @1, $1);
        
        // type
        $$.typePointer = variable.typePointer;
        
        // IC block
        if (variable.typePointer->cat() == TCAT_RECORD)
        {
          // The variable is a record.
          $$.stackAddress = sp->access_variable()->address();
        }
        else
        {
          // The variables is not a record.
          lukas::AppendLDInstruction($$.icblockPointer, variable.symbolKind, variable.typePointer->cat(), variable.stackAddress);
        }
      }
      break;
      case SKIND_FUNCTION :
      {
        // The symbol is a function.

        $$ = lukas::TypedICBlock();
        lukas::actual_parameter_list emptyActualParameterList = lukas::actual_parameter_list();
        lukas::AppendFunctionCallExpressionTypedICBlock(ctx, @1, $$, $1, emptyActualParameterList); 
      }
      break;
      default :
      {
        // The symbol is not a constant nor a variable nor a function.
      
        // type
        $$.typePointer = ctx->tab->logical_undef();
        
        // Error
        error(DUERR_NOTVAR, @1, $1->c_str());
      }
      break;
    }
  }
| array_variable
  {
    // SA, ICG

    // type
    $$.typePointer = $1.typePointer;
    
    // IC block
    $$.icblockPointer = icblock_create();
    if ($1.typePointer->cat() == TCAT_RECORD)
    {
      // The field is a record.
      $$.stackAddress = $1.stackAddress;
    }
    else
    {
      // The field is not a record.
      lukas::AppendLDInstruction($$.icblockPointer, $1.symbolKind, $1.typePointer->cat(), $1.stackAddress);
    }
  }
| record_variable  /* Does not match DUTOK_IDENTIFIER. */
  {
    // SA, ICG
    
    // type
    $$.typePointer = $1.typePointer;
    
    // IC block
    $$.icblockPointer = icblock_create();
    if ($1.typePointer->cat() == TCAT_RECORD)
    {
      // The field is a record.
      $$.stackAddress = $1.stackAddress;
    }
    else
    {
      // The field is not a record.
      lukas::AppendLDInstruction($$.icblockPointer, $1.symbolKind, $1.typePointer->cat(), $1.stackAddress);
    }
  }
| function_call 
  {
    // SA (default)
    $$ = $1;
  }
| DUTOK_LPAR expression DUTOK_RPAR
  {
    // SA (default)
    $$ = $2;
  }
| DUTOK_NOT factor
  {
    // SA (empty)
  }
	;
	
function_call :
  DUTOK_IDENTIFIER actual_parameter_specification /* Matches parametrized function calls. */
  {
    // SA, ICG 
    $$ = lukas::TypedICBlock();
    lukas::AppendFunctionCallExpressionTypedICBlock(ctx, @1, $$, $1, $2);
  }
  ;  
	
%%

static void yyerror(unsigned *line, MlaskalCtx *, const char *m)
{
    error(DUERR_SYNTAX, *line, m);
}
