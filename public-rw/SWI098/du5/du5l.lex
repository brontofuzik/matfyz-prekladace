%{
	#include <cerrno>  // ERANGE, errno
	#include <climits> // UINT_MAX
	#include <cmath>   // HUGE_VAL
	#include <cstdlib> // strtod(), NULL
	#include <cstring> // strlen() 
	#include <cctype>  // toupper()
	#include <string>  // string
	
	#include "duerr.h"
	#include "du5.h"
	#include "du5lval.hpp"
	#include "du5tok.h"
	#include "du5g.hpp"
	
	/* Portability stuff */
	#if defined _MSC_VER  /* M$ VS2003 does not recognize long long, VS2005 has long long but no strtoull */
		typedef unsigned __int64	UINT64;
		#define C64(n)				n##i64
		#define STRTOULL			_strtoui64
	#else						      /* the rest of the world */
		typedef unsigned long long	UINT64;
		#define C64(n)				n##LL
		#define STRTOULL			strtoull
	#endif
	
	/* Macros */
	#define return_with_line_number(DUTOK) *l = line_number; return DUTOK;
	
	/* Namespace usings */
	using namespace std;
	using namespace mlc;
	
	/* Function declarations */
	string to_uppercase(const char *);
	unsigned int parse_for_unsigned_integer(const char *);
	double parse_for_real(const char *);
	
	/* Global variable definitions */
	unsigned int line_number = 1;
%}

/* Options */
%option noyywrap
%option nostdinit
%option never-interactive
%option 8bit
%option nounput

/* Start conditions */
%x COMMENT
%x STRING

/* Name definitions */
A									              [Aa]
B									              [Bb]
C									              [Cc]
D									              [Dd]
E									              [Ee]
F									              [Ff]
G									              [Gg]
H									              [Hh]
I									              [Ii]
J									              [Jj]
K									              [Kk]
L									              [Ll]
M									              [Mm]
N									              [Nn]
O									              [Oo]
P									              [Pp]
Q									              [Qq]
R									              [Rr]
S									              [Ss]
T									              [Tt]
U									              [Uu]
V									              [Vv]
W									              [Ww]
X									              [Xx]
Y									              [Yy]
Z									              [Zz]
LETTER						              {A}|{B}|{C}|{D}|{E}|{F}|{G}|{H}|{I}|{J}|{K}|{L}|{M}|{N}|{O}|{P}|{Q}|{R}|{S}|{T}|{U}|{V}|{W}|{X}|{Y}|{Z}
DIGIT							              0|1|2|3|4|5|6|7|8|9
UNSIGNED-INTEGER                {DIGIT}+
REAL							              {DIGIT}+\.{DIGIT}+({E}[+\-]?{DIGIT}+)?|{DIGIT}+{E}[+\-]?{DIGIT}+
LETTER-OR-DIGIT		              {LETTER}|{DIGIT}
IDENTIFIER				              {LETTER}{LETTER-OR-DIGIT}*
WHITESPACE				              [ \t\f]

%%

 /***** YYLEX() LOCAL VARIABLES ****/

%{
	int open_comment_count = 0;
	string str;
%}

 /***** WHITESPACE *****/

{WHITESPACE}+ 							    /* go out with whitespaces */

 /***** KEYWORDS *****/

{P}{R}{O}{G}{R}{A}{M} 		      return_with_line_number(DUTOK_PROGRAM);

{L}{A}{B}{E}{L} 						    return_with_line_number(DUTOK_LABEL);
{C}{O}{N}{S}{T} 					    	return_with_line_number(DUTOK_CONST);
{T}{Y}{P}{E}								    return_with_line_number(DUTOK_TYPE);
{V}{A}{R}									      return_with_line_number(DUTOK_VAR);

{B}{E}{G}{I}{N}							    return_with_line_number(DUTOK_BEGIN);
{E}{N}{D}									      return_with_line_number(DUTOK_END);

{P}{R}{O}{C}{E}{D}{U}{R}{E}     return_with_line_number(DUTOK_PROCEDURE);
{F}{U}{N}{C}{T}{I}{O}{N}	      return_with_line_number(DUTOK_FUNCTION);

{A}{R}{R}{A}{Y}							    return_with_line_number(DUTOK_ARRAY);
{O}{F}										      return_with_line_number(DUTOK_OF);

{G}{O}{T}{O}								    return_with_line_number(DUTOK_GOTO);

{I}{F}										      return_with_line_number(DUTOK_IF);
{T}{H}{E}{N}								    return_with_line_number(DUTOK_THEN);
{E}{L}{S}{E}								    return_with_line_number(DUTOK_ELSE);

{W}{H}{I}{L}{E}						    	return_with_line_number(DUTOK_WHILE);
{D}{O}										      return_with_line_number(DUTOK_DO);

{R}{E}{P}{E}{A}{T}					    return_with_line_number(DUTOK_REPEAT);
{U}{N}{T}{I}{L}							    return_with_line_number(DUTOK_UNTIL);

{F}{O}{R}									      return_with_line_number(DUTOK_FOR);

{O}{R}										      return_with_line_number(DUTOK_OR);
{N}{O}{T}									      return_with_line_number(DUTOK_NOT);

{R}{E}{C}{O}{R}{D}					    return_with_line_number(DUTOK_RECORD);

 /***** DELIMITERS *****/

";"											        return_with_line_number(DUTOK_SEMICOLON);
"."											        return_with_line_number(DUTOK_DOT);
","											        return_with_line_number(DUTOK_COMMA);
"="											        return_with_line_number(DUTOK_EQ);
":"											        return_with_line_number(DUTOK_COLON);
"("											        return_with_line_number(DUTOK_LPAR);
")"											        return_with_line_number(DUTOK_RPAR);
".."										        return_with_line_number(DUTOK_DOTDOT);
"["											        return_with_line_number(DUTOK_LSBRA);
"]"											        return_with_line_number(DUTOK_RSBRA);
":="										        return_with_line_number(DUTOK_ASSIGN);

\n											        line_number++;

 /***** GROUP TOKENS *****/

"<"											        { lv->dtge_ = DUTOKGE_LT; return_with_line_number(DUTOK_OPER_REL); }
"<="										        { lv->dtge_ = DUTOKGE_LE; return_with_line_number(DUTOK_OPER_REL); }
"<>"										        { lv->dtge_ = DUTOKGE_NE; return_with_line_number(DUTOK_OPER_REL); }
">="										        { lv->dtge_ = DUTOKGE_GE; return_with_line_number(DUTOK_OPER_REL); }
">"											        { lv->dtge_ = DUTOKGE_GT; return_with_line_number(DUTOK_OPER_REL); }

"+"											        { lv->dtge_ = DUTOKGE_PLUS; return_with_line_number(DUTOK_OPER_SIGNADD); }
"-"											        { lv->dtge_ = DUTOKGE_MINUS; return_with_line_number(DUTOK_OPER_SIGNADD); }

"*"											        { lv->dtge_ = DUTOKGE_ASTERISK; return_with_line_number(DUTOK_OPER_MUL); }
"/"											        { lv->dtge_ = DUTOKGE_SOLIDUS; return_with_line_number(DUTOK_OPER_MUL); }
{D}{I}{V}								  	    { lv->dtge_ = DUTOKGE_DIV; return_with_line_number(DUTOK_OPER_MUL); }
{M}{O}{D}								  	    { lv->dtge_ = DUTOKGE_MOD; return_with_line_number(DUTOK_OPER_MUL); }
{A}{N}{D}								  	    { lv->dtge_ = DUTOKGE_AND; return_with_line_number(DUTOK_OPER_MUL); }

{T}{O} 									  	    { lv->dtge_ = DUTOKGE_TO; return_with_line_number(DUTOK_FOR_DIRECTION); }
{D}{O}{W}{N}{T}{O} 					    { lv->dtge_ = DUTOKGE_DOWNTO; return_with_line_number(DUTOK_FOR_DIRECTION); }

 /***** COMMENTS *****/

"{" 										        { /* opening brace => enter comment */ open_comment_count = 1; BEGIN( COMMENT ); }
"}"											        error( DUERR_UNEXPENDCMT, line_number );
<COMMENT>{ 
	<<EOF>>									      { error( DUERR_EOFINCMT, line_number ); BEGIN( INITIAL ); }
	"{"										        open_comment_count++;
	"}" 									       { /* closing brace => exit comment */ open_comment_count--; if (open_comment_count == 0) { BEGIN( INITIAL ); } }
	\n										        line_number++;
	[^{}\n]+
}

 /***** STRINGS *****/

' 											        { /* opening single quote => enter string */ str = ""; BEGIN( STRING ); }
<STRING>{
	<<EOF>>									      { lv->str_ci_ = ctx->tab->ls_str().add( str ); BEGIN( INITIAL ); error( DUERR_EOFINSTRCHR, line_number ); return_with_line_number(DUTOK_STRING); }
	' 										        { /* closing single quote => exit string */ lv->str_ci_ = ctx->tab->ls_str().add( str ); BEGIN( INITIAL ); return_with_line_number(DUTOK_STRING); }
	''										        str.append( "'" );
	\n 										        { lv->str_ci_ = ctx->tab->ls_str().add( str ); BEGIN( INITIAL ); error( DUERR_EOLINSTRCHR, line_number ); *l = line_number; line_number++; return DUTOK_STRING; }
	[^'\n]*									      str.append( yytext );		
}
									
 /***** LITERALS *****/

 /* IDENTIFIERS */
{IDENTIFIER}								    { lv->id_ci_ = ctx->tab->ls_id().add( to_uppercase( yytext ) ); return_with_line_number(DUTOK_IDENTIFIER); }
 
 /* (WELL-FORMED) UNSIGNED INTEGERS */
{UNSIGNED-INTEGER}					    { unsigned int x = parse_for_unsigned_integer( yytext ); lv->int_ci_ = ctx->tab->ls_int().add( x ); return_with_line_number(DUTOK_UINT); }

 /* (WELL-FORMED) REALS */
{REAL}										      { double x = parse_for_real( yytext ); lv->real_ci_ = ctx->tab->ls_real().add( x ); return_with_line_number(DUTOK_REAL); }

 /* MALFORMED UNSIGNED INTEGERS (unsigned integers followed by an identifier) */
{UNSIGNED-INTEGER}{IDENTIFIER}  { error( DUERR_BADINT, line_number, yytext ); unsigned int x = parse_for_unsigned_integer( yytext ); lv->int_ci_ = ctx->tab->ls_int().add( x ); return_with_line_number(DUTOK_UINT); }			

 /* MALFORMED REALS (reals followed by an identifier) */
{REAL}{IDENTIFIER} 							{ error( DUERR_BADREAL, line_number, yytext ); double x = parse_for_real( yytext ); lv->real_ci_ = ctx->tab->ls_real().add( x ); return_with_line_number(DUTOK_REAL); }

 /***** EVERYTHING ELSE *****/

.											          error( DUERR_UNKCHAR, line_number, *yytext, *yytext );

%%

/**
 * Converts a string to uppercase.
 */
string to_uppercase( const char * str )
{
	string result( str );
	
	for	(unsigned int i = 0; i < result.length(); i++)
	{
		result[ i ] = (char)toupper( (int)result[ i ] );
	}
	
	return result;
}

/**
 * Parses the string for an unisgned integer.
 */
unsigned int parse_for_unsigned_integer( const char * str )
{	
	unsigned int result = 0;
	int overflow = 0;
	unsigned int max_unsigned_int_div_10 = UINT_MAX / 10; 
	
	// Perform the conversion.
	for (unsigned int i = 0; i < strlen( str ); i++)
	{
		// Check for possible non-digit.
		if (! isdigit( str[ i ] ))
		{
			break;
		}
		
		// Check for possible overflow after multiplication.
		if (result > max_unsigned_int_div_10)
		{
			overflow = 1;
		}
		result *= 10;
		
		unsigned int d = str[ i ] - '0';
		
		// Check for possible overflow after addition.
		if (result > UINT_MAX - d)
		{
			overflow = 1;
		}
		result += d;
	}
	
	// Check for overflow.
	if (overflow == 1)
	{
		error( DUERR_INTOUTRANGE, line_number, str );
	}
	
	// Truncate the result.
	result = (result << 1) >> 1;
	
	return result;
}

/**
 * Parses the string for a real.
 */
double parse_for_real( const char * str )
{	
	// Perform the conversion.
	errno = 0;
	double result = strtod( str, NULL );
	
	// Check for overflow.
	if (errno == ERANGE || result == HUGE_VAL)
	{
		error( DUERR_REALOUTRANGE, line_number, str );
	}
	
	return result;
}
