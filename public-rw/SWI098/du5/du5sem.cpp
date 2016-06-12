/*

DU5SEM.CPP

*/

#include "du5sem.h"
#include "du5tok.h"
#include "duerr.h"

using namespace ai;

namespace mlc
{
	namespace lukas
	{
    /*  
    ****************************************************************************
    *                                                                          *
    * Add* and Find* functions                                                 *
    *                                                                          *
    ****************************************************************************
    */
	 
		void AddLabel(MlaskalCtx * const ctx, const unsigned int lineNumber, const ls_int_index labelIdentifier)
		{
			ic_label icLabel = new_label(ctx);
			ctx->tab->add_label_entry(lineNumber, labelIdentifier, icLabel);	
		}

    void AddConstant(MlaskalCtx * const ctx, const unsigned int lineNumber, const ls_id_index constantIdentifier, const Constant & constant)
		{
      type_category constantTypeCategory = constant.typePointer->cat();
			switch(constantTypeCategory)
			{
				case TCAT_BOOL :
				{
				  // Add boolean constant.
				  ctx->tab->add_const_bool(lineNumber, constantIdentifier, constant.booleanValue);
        }
				break;
				case TCAT_INT :
				{
				  // Add integer constant.
				  ctx->tab->add_const_int(lineNumber, constantIdentifier, constant.integerValue);
        }
				break;
				case TCAT_REAL :
				{
				  // Add real constant.
				  ctx->tab->add_const_real(lineNumber, constantIdentifier, constant.realValue);
        }
				break;
				case TCAT_STR :
				{
				  // Add string constant.
				  ctx->tab->add_const_str(lineNumber, constantIdentifier, constant.stringValue);
        }
				break;
				default :
				  // Error (unsupported constant type)
				break;
			}
		}
		
		Constant FindConstant(const MlaskalCtx * const ctx, const unsigned int lineNumber, const ls_id_index constantIdentifier)
		{
		  // Find the symbol in the semantic tables.
		  symbol_pointer symbolPointer = ctx->tab->find_symbol(constantIdentifier);
		  
      // Ensure the symbol is a constant.
      if (!symbolPointer || symbolPointer->kind() != SKIND_CONST)
		  {
        // Error (Symbol is not a constant.)
        error(DUERR_NOTCONST, lineNumber, constantIdentifier->c_str());
        return Constant(ctx->tab->logical_undef());
      }
		
		  // The symbol is a constant.
      // (symbolPointer != NULL && symbolPointer->kind() == SKIND_CONSTANT)
      const_symbol_reference constSymbolReference = symbolPointer->access_const();
      
      // Using the type of the constant, assign it a value.
      type_pointer constantTypePointer = constSymbolReference->access_typed()->type();
      type_category constantTypeCategory = constantTypePointer->cat();
      switch(constantTypeCategory)
      {
        case TCAT_BOOL :
        {
          // The symbol is a boolean constant.
          bool constantBooleanValue = constSymbolReference->access_bool_const()->bool_value();
          return Constant(constantTypePointer, constantBooleanValue);
        }
        break;
        case TCAT_INT :
        {
          // The symbol is an integer constant.
          ls_int_index constantIntegerValue = constSymbolReference->access_const()->access_int_const()->int_value();
          return Constant(constantTypePointer, constantIntegerValue);
        }
        break;
        case TCAT_REAL :
        {
          // The symbol is a real constant.
          ls_real_index constantRealValue = constSymbolReference->access_const()->access_real_const()->real_value();
          return Constant(constantTypePointer, constantRealValue);
        }
        break;
        case TCAT_STR :
        {
          // The symbol is a string constant.
          ls_str_index constantStringValue = constSymbolReference->access_const()->access_str_const()->str_value();
          return Constant(constantTypePointer, constantStringValue);
        }
        break;
        default :
        {
          // Error (The symbol is a constant of unsupported type.)
          return Constant(ctx->tab->logical_undef());
        }
        break;
      }
    }

    void AddType(MlaskalCtx * const ctx, const unsigned int lineNumber, const ls_id_index typeIdentifier, const type_pointer typePointer)
		{
		  // Add the type to the semantic tables.
			ctx->tab->add_type(lineNumber, typeIdentifier, typePointer);
		}
			 
		type_pointer FindType(const MlaskalCtx * const ctx, const unsigned int lineNumber, const ls_id_index typeIdentifier)
		{
		  // Fins the symbol in the semantic tables.
			symbol_pointer sp = ctx->tab->find_symbol(typeIdentifier);
			
			// Ensure the symbol is a type.
			if (!sp || sp->kind() != SKIND_TYPE)
			{
			  // Error (Symbol is not a type.)
        error(DUERR_NOTTYPE, lineNumber, typeIdentifier->c_str());
				return ctx->tab->logical_undef();
      }
			
      // Symbol is a type.
      // (sp != NULL && sp->kind() == SKIND_TYPE)
      
			return sp->access_typed()->type();
		}
		
    void AppendFieldGroup(field_list * const fieldList, const identifier_list & identifierList, const type_pointer typePointer)
    {
      // For each field identifier in the list of identifiers ...
		  for (identifier_list::const_iterator cit = identifierList.begin(); cit != identifierList.end(); ++cit)
		  {
        // ... append the field to the list of fields.
		    ls_id_index fieldIdentifier = cit->second;
			  fieldList->append_field(fieldIdentifier, typePointer);
		  }
    }
  
    Variable FindField(const MlaskalCtx * const ctx, const Variable & variable, const unsigned int lineNumber, const ls_id_index fieldIdentifier) 
		{
      // Ensure the variable is a record.
      if (variable.typePointer->cat() != TCAT_RECORD)
      {
        // TODO
        // Error (The variable is not a record.)
        error(DUERR_NOTRECORD, lineNumber, "TODO");
        return Variable(SKIND_UNDEF, ctx->tab->logical_undef(), 0);
      }

      // The variable is a record.
      // (variable.typePointer->cat() == TCAT_RECORD)

      // Find the symbol in the record as a field.
      field_pointer fp = variable.typePointer->access_record()->find(fieldIdentifier);

      // Ensure the symbol does exist in the record as a field.
      if (!fp)
      {
        // Error (The symbol is not a field.)
        error(DUERR_NOTFIELD, lineNumber, fieldIdentifier->c_str());
        return Variable(SKIND_UNDEF, ctx->tab->logical_undef(), 0);
      }

      // The symbol is a field.
      // (fp)

      return Variable(variable.symbolKind, fp->type(), variable.stackAddress + fp->offset());  
    }

		void AddVariableGroup(MlaskalCtx * const ctx, const identifier_list & identifierList, const type_pointer typePointer)
		{
      // For each variable identifier in the list of identifiers ...
			for(identifier_list::const_iterator cit = identifierList.begin(); cit != identifierList.end(); ++cit)
      {
        // ... add the variable to the semantic tables.
        unsigned int lineNumber = cit->first;
        ls_id_index variableIdentifier = cit->second;
				ctx->tab->add_var(lineNumber, variableIdentifier, typePointer);
			}
		}
 
    Variable FindVariable(const MlaskalCtx * const ctx, const unsigned int lineNumber, const ls_id_index variableIdentifier)
    {
      // Find the symbol in the semantic tables.
      symbol_pointer sp = ctx->tab->find_symbol(variableIdentifier);
      if (!sp || (sp->kind() != SKIND_GLOBAL_VARIABLE) && (sp->kind() != SKIND_LOCAL_VARIABLE))
      {
        // Error (The symbol is not a variable.)
        error(DUERR_NOTVAR, lineNumber, variableIdentifier->c_str());
        return Variable(SKIND_UNDEF, ctx->tab->logical_undef(), 0);  
      }

      // The symbol is a variable.
      // (sp && (sp->kind == SKIND_GLOBAL_VARIABLE || sp->kind() == SKIND_LOCAL_VARIABLE))

      return Variable(sp->kind(), sp->access_typed()->type(), sp->access_variable()->address());
    }
    
    void AppendFormalParameterGroup(const MlaskalCtx * const ctx, parameter_list * const formalParameterList, const bool byValue, const identifier_list & identifierList, const unsigned int lineNumber, const ls_id_index typeIdentifier)
    {
      // Find the type in the semantic tables.
      type_pointer typePointer = FindType(ctx, lineNumber, typeIdentifier);

      // For each formal parameter identifier in the list of identifiers ...
      for (identifier_list::const_iterator cit = identifierList.begin(); cit != identifierList.end(); ++cit)
  		{
  		  ls_id_index formalParameterIdentifier = cit->second;
  		  if (byValue)
  		  {
  		    // ... append the formal parameter to the list of formal parameters by value.
  		    formalParameterList->append_parameter_by_value(formalParameterIdentifier, typePointer);
        }
        else
        {
          // ... append the formal parameter to the list of formal parameters by value.
          formalParameterList->append_parameter_by_reference(formalParameterIdentifier, typePointer);
        }
  		}
    }  
		
    /*  
    ****************************************************************************
    *                                                                          *
    * Append*Instruction functions                                             *
    *                                                                          *
    ****************************************************************************
    */

    void AppendINITInstruction(icblock_pointer & icblockPointer, const type_category typeCategory)
    {
      // Depending on the type category ...
      switch (typeCategory)
      {
        case TCAT_BOOL :
        {
          // ... append a INITB (initialize boolean) instruction.
          icblockPointer->append_instruction(new INITB());
        }
        break;
        case TCAT_INT :
        {
          // ... append a INITI (initialize integer) instruction.
          icblockPointer->append_instruction(new INITI());
        }
        break;
        case TCAT_REAL :
        {
          // ... append a INITR (initialize real) instruction.
          icblockPointer->append_instruction(new INITR());
        }
        break;
        case TCAT_STR :
        {
          // ... append a INITS (initialize string) instruction.
          icblockPointer->append_instruction(new INITS());
        }
        break;
        default :
          // Error (Unsupported type category.)
        break;
      }
    }
  
    void AppendLDLITInstruction(icblock_pointer & icblockPointer, const Constant & constant)
    {
      // Determine the constant type category.
      type_category constantTypeCategory = constant.typePointer->cat();
      
      // Depending on the category of the constant type ...
      switch (constantTypeCategory)
      {
        case TCAT_BOOL :
        {
          // ... append a LDLITB (load boolean literal) instruction.
          icblockPointer->append_instruction(new LDLITB(constant.booleanValue));
        }
        break;
        case TCAT_INT :
        {
          // ... append a LDLITI (load integer literal) instruction.
          icblockPointer->append_instruction(new LDLITI(constant.integerValue));
        }
        break;
        case TCAT_REAL :
        {
          // .... append a LDLITR (load real literal) instruction.
          icblockPointer->append_instruction(new LDLITR(constant.realValue));
        }
        break;
        case TCAT_STR :
        {
          // ... append a LDLITS (load string literal) instruction.
          icblockPointer->append_instruction(new LDLITS(constant.stringValue));
        }
        break;
        default :
          // Error (Unsupported type category.)
        break;
      }
    }

    void AppendMINUSInstruction(icblock_pointer & icblockPointer, const type_category typeCategory)
    {
      // Depending on the type category ...
      switch (typeCategory)
      {
        case TCAT_INT :
        {
          // ... append a MINUSI (unary minus integer) instruction.
          icblockPointer->append_instruction(new MINUSI());
        }
        break;
        case TCAT_REAL :
        {
          // ... append a MINUSR (unary minus real) instruction.
          icblockPointer->append_instruction(new MINUSR());
        }
        break;
        default :
        {
          // Error (Unsupported type category.)
        }
        break;
      }
    }

    void AppendADDInstruction(icblock_pointer & icblockPointer, const type_category typeCategory)
    {
      // Depending on the type category ...
      switch (typeCategory)
      {
        case TCAT_INT :
        {
          // ... append a ADDI (add integer) instruction.
          icblockPointer->append_instruction(new ADDI());
        }
        break;
        case TCAT_REAL :
        {
          // ... append a ADDR (add real) instruction.
          icblockPointer->append_instruction(new ADDR());
        }
        break;
        case TCAT_STR :
        {
          // ... append a ADDS (add string) instruction.
          icblockPointer->append_instruction(new ADDS());
        }
        break;
        default :
        {
          // Error (Unsupported type category.)
        }
        break;
      }
    }

    void AppendSUBInstruction(icblock_pointer & icblockPointer, const type_category typeCategory)
    {
      // Depending on the type category ...
      switch (typeCategory)
      {
        case TCAT_INT :
        {
          // ... append a SUBI (subtract integer) instruction.
          icblockPointer->append_instruction(new SUBI());
        }
        break;
        case TCAT_REAL :
        {
          // ... append a SUBR (subtract real) instruction.
          icblockPointer->append_instruction(new SUBR());
        }
        break;
        default :
        {
          // Error (Unsupported type category.)
        }
        break;
      }
    }

    void AppendMULInstruction(icblock_pointer & icblockPointer, const type_category typeCategory)
    {
      // Depending on the type category ...
      switch (typeCategory)
      {
        case TCAT_INT :
        {
          // ... append a MULI (multiply integer) instruction.
          icblockPointer->append_instruction(new MULI());
        }
        break;
        case TCAT_REAL :
        {
          // ... append a MULR (multiply real) instruction.
          icblockPointer->append_instruction(new MULR());
        }
        break;
        default :
        {
          // Error (Unsupported type category.)
        }
        break;
      }
    }

    void AppendDIVInstruction(icblock_pointer & icblockPointer, const type_category typeCategory)
    {
      // Depending on the type category ...
      switch (typeCategory)
      {
        case TCAT_INT :
        {
          // ... append a DIVI (divide integer) instruction.
          icblockPointer->append_instruction(new DIVI());
        }
        break;
        case TCAT_REAL :
        {
          // ... append a DIVR (udivide real) instruction.
          icblockPointer->append_instruction(new DIVR());
        }
        break;
        default :
        {
          // Error (Unsupported type category.)
        }
        break;
      }
    }

    void AppendMODInstruction(icblock_pointer & icblockPointer, const type_category typeCategory)
    {
      // Depending on the type category ...
      switch (typeCategory)
      {
        case TCAT_INT :
        {
          // ... append a MODI (modulo integer) instruction.
          icblockPointer->append_instruction(new MODI());
        }
        break;
        default :
        {
          // Error (Unsupported type category.)
        }
        break;
      }
    }

    void AppendDTORInstruction(icblock_pointer & icblockPointer, const type_category typeCategory)
    {
      // Depending on the type category ...
      switch (typeCategory)
      {
        case TCAT_BOOL :
        {
          // ... append a DTORB (destruct boolean) instruction.
          icblockPointer->append_instruction(new DTORB());
        }
        break;
        case TCAT_INT :
        {
          // ... append a DTORI (destruct integer) instruction.
          icblockPointer->append_instruction(new DTORI());
        }
        break;
        case TCAT_REAL :
        {
          // ... append a DTORR (destruct real) instruction.
          icblockPointer->append_instruction(new DTORR());
        }
        break;
        case TCAT_STR :
        {
          // ... append a DTORS (destruct string) instruction.
          icblockPointer->append_instruction(new DTORS());
        }
        break;
        default :
          // Error (Unsupported type category.)
        break;
      }
    }
  
    void AppendLDInstruction(icblock_pointer & icblockPointer, const symbol_kind symbolKind, const type_category typeCategory, const stack_address stackAddress)
    {
      switch (symbolKind)
      {
        case SKIND_GLOBAL_VARIABLE :
        {
          switch (typeCategory)
          {
            case TCAT_BOOL :
            {
              // global boolean variable
              icblockPointer->append_instruction(new GLDB(stackAddress));
            }
            break;
            case TCAT_INT :
            {
              // global integer variable
              icblockPointer->append_instruction(new GLDI(stackAddress));
            }
            break;
            case TCAT_REAL :
            {
              // global real variable
              icblockPointer->append_instruction(new GLDR(stackAddress));
            }
            break;
            case TCAT_STR :
            {
              // global string variable
              icblockPointer->append_instruction(new GLDS(stackAddress));
            }
            break;
            default :
              // Error (Variable of unsupported type.)
            break;
          }
        }
        break;
        case SKIND_LOCAL_VARIABLE :
        {
          switch (typeCategory)
          {
            case TCAT_BOOL :
            {
              // local boolean variable
              icblockPointer->append_instruction(new LLDB(stackAddress));
            }
            break;
            case TCAT_INT :
            {
              // local integer variable
              icblockPointer->append_instruction(new LLDI(stackAddress));
            }
            break;
            case TCAT_REAL :
            {
              // local real variable
              icblockPointer->append_instruction(new LLDR(stackAddress));
            }
            break;
            case TCAT_STR :
            {
              // local string variable
              icblockPointer->append_instruction(new LLDS(stackAddress));
            }
            break;
            default :
              // Error (Variable of unsupported type.)
            break;
          }
        }
        break;
        default :
          // Error (Symbol is not a variable.)
        break;
      }
    }
         
    void AppendSTInstruction(icblock_pointer & icblockPointer, const symbol_kind symbolKind, const type_category typeCategory, const stack_address stackAddress)
    {
      switch (symbolKind)
      {
        case SKIND_GLOBAL_VARIABLE :
        {
          switch (typeCategory)
          {
            case TCAT_BOOL :
            {
              // global boolean variable
              icblockPointer->append_instruction(new GSTB(stackAddress));
            }
            break;
            case TCAT_INT :
            {
              // global integer variable
              icblockPointer->append_instruction(new GSTI(stackAddress));
            }
            break;
            case TCAT_REAL :
            {
              // global real variable
              icblockPointer->append_instruction(new GSTR(stackAddress));
            }
            break;
            case TCAT_STR :
            {
              // global string variable
              icblockPointer->append_instruction(new GSTS(stackAddress));
            }
            break;
            default:
              // Error (Variable is of unsupported type.)
            break;
          }
        }
        break;
        case SKIND_LOCAL_VARIABLE :
        {
          switch (typeCategory)
          {
            case TCAT_BOOL :
            {
              // local boolean variable
              icblockPointer->append_instruction(new LSTB(stackAddress));
            }
            break;
            case TCAT_INT :
            {
              // local integer variable
              icblockPointer->append_instruction(new LSTI(stackAddress));
            }
            break;
            case TCAT_REAL :
            {
              // local real variable
              icblockPointer->append_instruction(new LSTR(stackAddress));
            }
            break;
            case TCAT_STR :
            {
              // local string variable
              icblockPointer->append_instruction(new LSTS(stackAddress));
            }
            break;
            default:
              // Error (Variable is of unsupported type.)
            break;
          }
        }
        break;
        default :
          // Error (Symbol is not a variable.)
        break;
      }
    }
  

    /*  
    ****************************************************************************
    *                                                                          *
    * Append*StatementICBlock functions                                        *
    *                                                                          *
    ****************************************************************************
    */

    /***** Assignment statements *****/

    void AppendAssignmentStatementICBlock(const MlaskalCtx * const ctx, const unsigned int lineNumber, icblock_pointer & result, const ls_id_index identifier, const TypedICBlock & expression)
    {
      // Find the symbol in the semantic tables.
      symbol_pointer symbolPointer = ctx->tab->find_symbol(identifier);

      // Ensure the symbol is either a variable or a function.
      if (!symbolPointer || (symbolPointer->kind() != SKIND_GLOBAL_VARIABLE && symbolPointer->kind() != SKIND_LOCAL_VARIABLE && symbolPointer->kind() != SKIND_FUNCTION))
      {
        // Error (The symbol is neither a (global or local) variable nor a function.
        error(DUERR_NOTLVALUE, lineNumber, identifier->c_str());
      }

      // The symbol is either a (global or local) variable or a function.
      // (symbolPointer && (symbolPointer->kind() == SKIND_GLOBAL_VARIABLE || symbolPointer->kind() == SKIND_LOCAL_VARIABLE || symbolPointer->kind() == SKIND_FUNCTION))

      // Depending on the symbol kind ...
      switch (symbolPointer->kind())
      {
        case SKIND_GLOBAL_VARIABLE :
        case SKIND_LOCAL_VARIABLE :
        {
          // The symbol is a (global or local) variable.
          Variable variable = FindVariable(ctx, lineNumber, identifier);
          
          // Append the IC block representing the variable assignment statement.
          AppendVariableAssignmentStatementICBlock(lineNumber, result, variable, expression);
        }
        break;
        case SKIND_FUNCTION :
        {
          // The symbol is a function.
          function_symbol_pointer functionSymbolPointer = symbolPointer->access_function();

          // Ensure we are nested and the function being assigned is my function.
          if (!ctx->tab->nested() || identifier != ctx->tab->my_function_name())
          {
            // Error (The function being assigned is not my function.)
            error(DUERR_NOTMINE, lineNumber);
            return;
          }

          // We are nested and the function being assigned is my function.
          // (ctx->tab->nested() && functionIdentifier == ctx->tab->my_function_name()) 

          // Append the IC block representing the function assignment statement.
          AppendFunctionAssignmentStatementICBlock(lineNumber, result, functionSymbolPointer, expression);   
        }
        break;
        default :
        {
          // Error (Unsupported symbol kind.)
          error(DUERR_NOTLVALUE, lineNumber, identifier->c_str());
        }
        break;
      }
    }

    void AppendVariableAssignmentStatementICBlock(const unsigned int lineNumber, icblock_pointer & result, const Variable & variable, const TypedICBlock & expression)
    {
      //
      // 1. Append the IC block representing the expression.
      //
      
      icblock_append_delete(result, expression.icblockPointer);

      //
      // 2. Append the ST instruction.
      //

      // Ensure the variable can be assigned the expression.
      bool assignmentPossible = CheckAssignmentPossibility(result, lineNumber, variable.typePointer, expression.typePointer);
      if (!assignmentPossible)
      {
        // Error (The variable can not be assigned the expression.)
        error(DUERR_CANNOTCONVERT, lineNumber);
      }

      // The variable can be assigned the expression.
      // (assignmentPossible)

      type_category variableTypeCategory = variable.typePointer->cat();
      if (variableTypeCategory == TCAT_RECORD)
      {
        // The variable being assigned is a record and the assigniment is possible. Hence the expression is a record as well.
        record_type_pointer recordTypePointer = variable.typePointer->access_record();

        // The stack address of the left-hand side record.
        stack_address lhsRecordStackAddress = variable.stackAddress;

        // The stack address of the right-hand side record.
        stack_address rhsRecordStackAddress = expression.stackAddress; // TODO

        AppendRecordToRecordAssignmentStatementICBlock(result, variable.symbolKind, recordTypePointer, lhsRecordStackAddress, rhsRecordStackAddress);
      }
      else
      {
        // The variable being assigned is not a record.
        AppendSTInstruction(result, variable.symbolKind, variableTypeCategory, variable.stackAddress);
      }
    }

    void AppendLDInstructions(icblock_pointer & result, const symbol_kind symbolKind, const record_type_pointer recordTypePointer, const stack_address rhsStackAddress)
    {
      for (record_type::const_iterator cit = recordTypePointer->begin(); cit != recordTypePointer->end(); ++cit)
      {
        field_entry fieldEntry = *cit;
        if (fieldEntry.type()->cat() == TCAT_RECORD)
        {
          // nested record (recursively)
          AppendLDInstructions(result, symbolKind, fieldEntry.type()->access_record(), rhsStackAddress + fieldEntry.offset());
        }
        else // (fieldEntry.type()->cat() != TCAT_RECORD)
        {
          // load
          AppendLDInstruction(result, symbolKind, fieldEntry.type()->cat(), rhsStackAddress + fieldEntry.offset());
        }
      }
    }

    void AppendSTInstructions(icblock_pointer & result, const symbol_kind symbolKind, const record_type_pointer recordTypePointer, const stack_address lhsStackAddress)
    {
      icblock_pointer stInstructions = icblock_create();
      for (record_type::const_iterator cit = recordTypePointer->begin(); cit != recordTypePointer->end(); ++cit)
      {
        field_entry fieldEntry = *cit;
        if (fieldEntry.type()->cat() == TCAT_RECORD)
        {
          // nested record (recursively)
          AppendSTInstructions(stInstructions, symbolKind, fieldEntry.type()->access_record(), lhsStackAddress + fieldEntry.offset());
        }
        else // (fieldEntry.type()->cat() != TCAT_RECORD)
        {
          // load
          icblock_pointer stInstruction = icblock_create();
          AppendSTInstruction(stInstruction, symbolKind, fieldEntry.type()->cat(), lhsStackAddress + fieldEntry.offset());

          // Prepend
          icblock_append_delete(stInstruction, stInstructions);
          stInstructions = stInstruction;
        }
      }

      icblock_append_delete(result, stInstructions);
    }

    void AppendRecordToRecordAssignmentStatementICBlock(icblock_pointer & result, const symbol_kind symbolKind, const record_type_pointer recordTypePointer, const stack_address lhsStackAddress, const stack_address rhsStackAddress)
    {
      AppendLDInstructions(result, symbolKind, recordTypePointer, rhsStackAddress);
      AppendSTInstructions(result, symbolKind, recordTypePointer, lhsStackAddress);
    }

    void AppendFunctionAssignmentStatementICBlock(const unsigned int lineNumber, icblock_pointer & result, const function_symbol_pointer functionSymbolPointer, const TypedICBlock & expression)
    {
      //
      // 1. Append the IC block representing the expression.
      //
      
      icblock_append_delete(result, expression.icblockPointer);

      //
      // 2. Append the ST instruction.
      //

      // Ensure the function can be assigned the expression.
      type_pointer functionReturnTypePointer = functionSymbolPointer->access_typed()->type();
      bool assignmentPossible = CheckAssignmentPossibility(result, lineNumber, functionReturnTypePointer, expression.typePointer);
      if (!assignmentPossible)
      {
        // Error (The function can not be assigned the expression.)
        error(DUERR_CANNOTCONVERT, lineNumber);
      }

      // The function can be assigned the expression.
      // (assignmentPossible)

      //AppendSTInstruction(result, SKIND_LOCAL_VARIABLE, functionReturnTypePointer->cat(), ctx->tab->my_return_address());
    }


    /***** Subprogram calls *****/

    void AppendProcedureCallStatementICBlock(const MlaskalCtx * const ctx, const unsigned int lineNumber, icblock_pointer & result, const ls_id_index procedureIdentifier, const actual_parameter_list & actualParameterList)
    {
      // Find the symbol in the semantic tables.
      symbol_pointer symbolPointer = ctx->tab->find_symbol(procedureIdentifier);
      
      // Ensure the symbol is a procedure.
      if (!symbolPointer || symbolPointer->kind() != SKIND_PROCEDURE)
      {
        // Error (Symbol is not a procedure.)
        error(DUERR_NOTPROC, lineNumber, procedureIdentifier->c_str());
        return;
      }

      // The symbol is a procedure.
      // (symbolPointer && symbolPointer->kind() == SKIND_PROCEDURE)
      procedure_symbol_pointer procedureSymbolPointer = symbolPointer->access_procedure();

      AppendSubprogramCallICBlock(ctx, result, lineNumber, procedureIdentifier, actualParameterList);
    }

    void AppendFunctionCallExpressionTypedICBlock(const MlaskalCtx * const ctx, const unsigned int lineNumber, TypedICBlock & result, const ls_id_index functionIdentifier, const actual_parameter_list & actualParameterList)
    {
      // Find the symbol in the semantic tables.
      symbol_pointer symbolPointer = ctx->tab->find_symbol(functionIdentifier);
      
      // Ensure the symbol is a function.
      if (!symbolPointer || symbolPointer->kind() != SKIND_FUNCTION)
      {
        // Error (Symbol is not a function.)
        error(DUERR_NOTFNC, lineNumber, functionIdentifier->c_str());
        return;
      }

      // The symbol is a function.
      // (symbolPointer && symbolPointer->kind() == SKIND_FUNCTION)
      function_symbol_pointer functionSymbolPointer = symbolPointer->access_function();

      // The return type of the function is the type of the IC block.
      type_pointer functionReturnTypePointer = functionSymbolPointer->access_typed()->type();
      result.typePointer = functionReturnTypePointer; 

      // Push the return value on the stack.
      type_category functionReturnTypeCategory = functionReturnTypePointer->cat();
      AppendINITInstruction(result.icblockPointer, functionReturnTypeCategory);

      AppendSubprogramCallICBlock(ctx, result.icblockPointer, lineNumber, functionIdentifier, actualParameterList);
    }

    void AppendSubprogramCallICBlock(const MlaskalCtx * const ctx, icblock_pointer & result, const unsigned int lineNumber, const ls_id_index subprogramIdentifier, const actual_parameter_list & actualParameterList)
    {
      // Find the symbol in the semantic tables.
		  symbol_pointer symbolPointer = ctx->tab->find_symbol(subprogramIdentifier);
		  
      // Ensure the symbol is a subprogram (a procedure or a function).
      if (!symbolPointer || (symbolPointer->kind() != SKIND_PROCEDURE && symbolPointer->kind() != SKIND_FUNCTION))
		  {
		    // Error (The symbol is neither a procedure nor a function.)
        return;
      }

      // The symbol is a subprogram (a procedure or a function).
      // (symbolPointer && (symbolPointer->kind() == SKIND_PROCEDURE || symbolPointer->kind() == SKIND_FUNCTION))
      subprogram_symbol_pointer subprogramSymbolPointer = symbolPointer->access_subprogram();
      
      //
      // 1. Push the actual parameters on the stack.
      //

      // The list of formal parameters.
      const parameter_list * formalParameterList = subprogramSymbolPointer->parameters();
      
      // The number of formal parameters.
      unsigned int formalParameterCount = (unsigned int)formalParameterList->size();

      // The number of actual parameters.
      unsigned int actualParameterCount = (unsigned int)actualParameterList.size();
      
      // Make sure the number of actual parameters corrpesponds to the number of formal parameters.
      if (actualParameterCount != formalParameterCount)
      {
        // Error (the number of actual parameters does not correspond to the number of formal parameters)
        error(DUERR_PARNUM, lineNumber, subprogramIdentifier->c_str());
        return;
      }
      
      unsigned int i = 0;
      for (parameter_list::const_iterator cit = formalParameterList->begin(); cit != formalParameterList->end(); ++cit)
      {
        // The formal parameter.
        parameter_entry formalParameter = *cit;

        // The actual parameter.
        TypedICBlock actualParameter = actualParameterList[i++];
        
        icblock_append_delete(result, actualParameter.icblockPointer);
        CheckAssignmentPossibility(result, lineNumber, formalParameter.ltype, actualParameter.typePointer); 
      }

      //
      // 2. Append CALL instruction.
      //
      
      result->append_instruction(new CALL(subprogramSymbolPointer->access_subprogram()->code()));
      
      //
      // 4. Append DTOR instructions.
      // 
      
      icblock_pointer dtorInstructions = icblock_create();
      for (parameter_list::const_iterator cit = formalParameterList->begin(); cit != formalParameterList->end(); ++cit)
      {
        icblock_pointer dtorInstruction = icblock_create();
        type_category formalParameterTypeCategory = cit->ltype->cat();
        
        AppendDTORInstruction(dtorInstruction, formalParameterTypeCategory);

        // Prepend the DTOR instruction at the beginning of the DTOR IC block.
        icblock_append_delete(dtorInstruction, dtorInstructions);
        dtorInstructions = dtorInstruction;  
      }
      icblock_append_delete(result, dtorInstructions); 
    }


    /*  
    ****************************************************************************
    *                                                                          *
    * Append*OperationTypedICBlock functions                                   *
    *                                                                          *
    ****************************************************************************
    */
    
    /***** Unary operations *****/

    void AppendMinusOperationTypedICBlock(const MlaskalCtx * const ctx, const unsigned int lineNumber, TypedICBlock & result, const TypedICBlock & operand)
    {
      // The operand type category.
      type_category operandTypeCategory = operand.typePointer->cat();

      // The result type category.
      type_category resultTypeCategory;

      // Ensure the operation is legal and determine the result type and its category.
      if (operandTypeCategory == TCAT_INT)
      {
        // - integer
        result.typePointer = ctx->tab->logical_integer();
        resultTypeCategory = TCAT_INT;
      }
      else if (operandTypeCategory == TCAT_REAL)
      {
        // - real
        result.typePointer = ctx->tab->logical_real();
        resultTypeCategory = TCAT_REAL;
      }
      else
      {
        // Error (The operation is not legal.)
        error(DUERR_CANNOTCONVERT, lineNumber);
        result.typePointer = ctx->tab->logical_undef();
        return;
      }

      // The operation is legal.

      // 1. Place the operand on the stack.
      icblock_append_delete(result.icblockPointer, operand.icblockPointer);

      // 2. Append a MINUS instruction.
      AppendMINUSInstruction(result.icblockPointer, resultTypeCategory);
    }


    /***** Binary operations *****/

    void AppendAdditionOperationTypedICBlock(const MlaskalCtx * const ctx, const unsigned int lineNumber, TypedICBlock & result, const TypedICBlock & lhsOperand, const TypedICBlock & rhsOperand)
    {
      // The left-hand side operand type category.
      type_category lhsOperandTypeCategory = lhsOperand.typePointer->cat();

      // The right-hand side operand type category.
      type_category rhsOperandTypeCategory = rhsOperand.typePointer->cat();

      //
      // 1. Ensure the operation is legal and determine the result type.
      //
      if (lhsOperandTypeCategory == TCAT_INT && rhsOperandTypeCategory == TCAT_INT)
      {
        // integer + integer = integer
        result.typePointer = ctx->tab->logical_integer();
      }
      else if (lhsOperandTypeCategory == TCAT_INT && rhsOperandTypeCategory == TCAT_REAL)
      {
        // integer + real = real
        result.typePointer = ctx->tab->logical_real();
      }
      else if (lhsOperandTypeCategory == TCAT_REAL && rhsOperandTypeCategory == TCAT_INT)
      {
        // real + integer = real
        result.typePointer = ctx->tab->logical_real();
      }
      else if (lhsOperandTypeCategory == TCAT_REAL && rhsOperandTypeCategory == TCAT_REAL)
      {
        // real + real = real
        result.typePointer = ctx->tab->logical_real();
      }
      else if (lhsOperandTypeCategory == TCAT_STR && rhsOperandTypeCategory == TCAT_STR)
      {
        // string + string = string
        result.typePointer = ctx->tab->logical_string();
      }
      else
      {
        // Error (The operation is not legal.)
        error(DUERR_CANNOTCONVERT, lineNumber);
        result.typePointer = ctx->tab->logical_undef();
        return;
      }

      // The operation is legal.

      type_category resultTypeCategory = result.typePointer->cat();

      //
      // 2. Place the left-hand side operand on the stack.
      //
      icblock_append_delete(result.icblockPointer, lhsOperand.icblockPointer);
      
      // Append an integer-to-real conversion if necessary.
      if (lhsOperandTypeCategory != resultTypeCategory)
      {
        result.icblockPointer->append_instruction(new CVRTIR());
      }

      //
      // 3. Place the right-hand-side operand on the stack.
      //
      icblock_append_delete(result.icblockPointer, rhsOperand.icblockPointer);

      // Append an integer-to-real conversion if necessary.
      if (rhsOperandTypeCategory != resultTypeCategory)
      {
        result.icblockPointer->append_instruction(new CVRTIR());
      }

      //
      // 4. Append an ADD instruction.
      //
      AppendADDInstruction(result.icblockPointer, resultTypeCategory);
    }
    
    void AppendSubtractionOperationTypedICBlock(const MlaskalCtx * const ctx, const unsigned int lineNumber, TypedICBlock & result, const TypedICBlock & lhsOperand, const TypedICBlock & rhsOperand)
    {
      // The left-hand side operand type category.
      type_category lhsOperandTypeCategory = lhsOperand.typePointer->cat();

      // The right-hand side operand type category.
      type_category rhsOperandTypeCategory = rhsOperand.typePointer->cat();

      //
      // 1. Ensure the operation is legal and determine the result type.
      //
      if (lhsOperandTypeCategory == TCAT_INT && rhsOperandTypeCategory == TCAT_INT)
      {
        // integer - integer = integer
        result.typePointer = ctx->tab->logical_integer();
      }
      else if (lhsOperandTypeCategory == TCAT_INT && rhsOperandTypeCategory == TCAT_REAL)
      {
        // integer - real = real
        result.typePointer = ctx->tab->logical_real();
      }
      else if (lhsOperandTypeCategory == TCAT_REAL && rhsOperandTypeCategory == TCAT_INT)
      {
        // real - integer = real
        result.typePointer = ctx->tab->logical_real();
      }
      else if (lhsOperandTypeCategory == TCAT_REAL && rhsOperandTypeCategory == TCAT_REAL)
      {
        // real - real = real
        result.typePointer = ctx->tab->logical_real();
      }
      else
      {
        // Error (The operation is not legal.)
        error(DUERR_CANNOTCONVERT, lineNumber);
        result.typePointer = ctx->tab->logical_undef();
        return;
      }

      // The operation is legal.

      type_category resultTypeCategory = result.typePointer->cat();

      //
      // 2. Place the left-hand side operand on the stack.
      //
      icblock_append_delete(result.icblockPointer, lhsOperand.icblockPointer);
      
      // Append an integer-to-real conversion if necessary.
      if (lhsOperandTypeCategory != resultTypeCategory)
      {
        result.icblockPointer->append_instruction(new CVRTIR());
      }

      //
      // 3. Place the right-hand-side operand on the stack.
      //
      icblock_append_delete(result.icblockPointer, rhsOperand.icblockPointer);

      // Append an integer-to-real conversion if necessary.
      if (rhsOperandTypeCategory != resultTypeCategory)
      {
        result.icblockPointer->append_instruction(new CVRTIR());
      }

      //
      // 4. Append a SUB instruction.
      //
      AppendSUBInstruction(result.icblockPointer, resultTypeCategory);
    }

    void AppendDisjunctionOperationTypedICBlock(const MlaskalCtx * const ctx, const unsigned int lineNumber, TypedICBlock & result, const TypedICBlock & lhsOperand, const TypedICBlock & rhsOperand)
    {
      // The left-hand side operand type category.
      type_category lhsOperandTypeCategory = lhsOperand.typePointer->cat();

      // The right-hand side operand type category.
      type_category rhsOperandTypeCategory = rhsOperand.typePointer->cat();

      //
      // 1. Ensure the operation is legal and determine the result type.
      //
      if (lhsOperandTypeCategory == TCAT_BOOL && rhsOperandTypeCategory == TCAT_BOOL)
      {
        // boolan OR boolan = boolean
        result.typePointer = ctx->tab->logical_bool();
      }
      else
      {
        // Error (The operation is not legal.)
        error(DUERR_CANNOTCONVERT, lineNumber);
        result.typePointer = ctx->tab->logical_undef();
        return;
      }

      // The operation is legal.

      //
      // 2. Place the left-hand side operand on the stack.
      //
      icblock_append_delete(result.icblockPointer, lhsOperand.icblockPointer);

      //
      // 3. Place the right-hand-side operand on the stack.
      //
      icblock_append_delete(result.icblockPointer, rhsOperand.icblockPointer);

      //
      // 4. Append an OR instruction.
      //
      result.icblockPointer->append_instruction(new OR());
    }
    
    void AppendMultiplicationOperationTypedICBlock(const MlaskalCtx * const ctx, const unsigned int lineNumber, TypedICBlock & result, const TypedICBlock & lhsOperand, const TypedICBlock & rhsOperand)
    {
      // The left-hand side operand type category.
      type_category lhsOperandTypeCategory = lhsOperand.typePointer->cat();

      // The right-hand side operand type category.
      type_category rhsOperandTypeCategory = rhsOperand.typePointer->cat();

      //
      // 1. Ensure the operation is legal and determine the result type.
      //
      if (lhsOperandTypeCategory == TCAT_INT && rhsOperandTypeCategory == TCAT_INT)
      {
        // integer * integer = integer
        result.typePointer = ctx->tab->logical_integer();
      }
      else if (lhsOperandTypeCategory == TCAT_INT && rhsOperandTypeCategory == TCAT_REAL)
      {
        // integer * real = real
        result.typePointer = ctx->tab->logical_real();
      }
      else if (lhsOperandTypeCategory == TCAT_REAL && rhsOperandTypeCategory == TCAT_INT)
      {
        // real * integer = real
        result.typePointer = ctx->tab->logical_real();
      }
      else if (lhsOperandTypeCategory == TCAT_REAL && rhsOperandTypeCategory == TCAT_REAL)
      {
        // real * real = real
        result.typePointer = ctx->tab->logical_real();
      }
      else
      {
        // Error (The operation is not legal.)
        error(DUERR_CANNOTCONVERT, lineNumber);
        result.typePointer = ctx->tab->logical_undef();
        return;
      }

      // The operation is legal.

      type_category resultTypeCategory = result.typePointer->cat();

      //
      // 2. Place the left-hand side operand on the stack.
      //
      icblock_append_delete(result.icblockPointer, lhsOperand.icblockPointer);
      
      // Append an integer-to-real conversion if necessary.
      if (lhsOperandTypeCategory != resultTypeCategory)
      {
        result.icblockPointer->append_instruction(new CVRTIR());
      }

      //
      // 3. Place the right-hand-side operand on the stack.
      //
      icblock_append_delete(result.icblockPointer, rhsOperand.icblockPointer);

      // Append an integer-to-real conversion if necessary.
      if (rhsOperandTypeCategory != resultTypeCategory)
      {
        result.icblockPointer->append_instruction(new CVRTIR());
      }

      //
      // 4. Append an MUL instruction.
      //
      AppendMULInstruction(result.icblockPointer, resultTypeCategory);
    }

    void AppendRealDivisionOperationTypedICBlock(const MlaskalCtx * const ctx, const unsigned int lineNumber, TypedICBlock & result, const TypedICBlock & lhsOperand, const TypedICBlock & rhsOperand)
    {
      // The left-hand side operand type category.
      type_category lhsOperandTypeCategory = lhsOperand.typePointer->cat();

      // The right-hand side operand type category.
      type_category rhsOperandTypeCategory = rhsOperand.typePointer->cat();

      //
      // 1. Ensure the operation is legal.
      //
      if (lhsOperandTypeCategory == TCAT_INT && rhsOperandTypeCategory == TCAT_INT)
      {
        // integer / integer = real
        result.typePointer = ctx->tab->logical_real();
      }
      else if (lhsOperandTypeCategory == TCAT_INT && rhsOperandTypeCategory == TCAT_REAL)
      {
        // integer / real = real
        result.typePointer = ctx->tab->logical_real();
      }
      else if (lhsOperandTypeCategory == TCAT_REAL && rhsOperandTypeCategory == TCAT_INT)
      {
        // real / integer = real
        result.typePointer = ctx->tab->logical_real();
      }
      else if (lhsOperandTypeCategory == TCAT_REAL && rhsOperandTypeCategory == TCAT_REAL)
      {
        // real / real = real
        result.typePointer = ctx->tab->logical_real();
      }
      else
      {
        // Error (The operation is not legal.)
        error(DUERR_CANNOTCONVERT, lineNumber);
        result.typePointer = ctx->tab->logical_undef();
        return;
      }

      // The operation is legal.

      type_category resultTypeCategory = result.typePointer->cat();

      //
      // 1. Place the left-hand side operand on the stack.
      //
      icblock_append_delete(result.icblockPointer, lhsOperand.icblockPointer);
      
      // Append an integer-to-real conversion if necessary.
      if (lhsOperandTypeCategory != resultTypeCategory)
      {
        result.icblockPointer->append_instruction(new CVRTIR());
      }

      //
      // 2. Place the right-hand-side operand on the stack.
      //
      icblock_append_delete(result.icblockPointer, rhsOperand.icblockPointer);

      // Append an integer-to-real conversion if necessary.
      if (rhsOperandTypeCategory != resultTypeCategory)
      {
        result.icblockPointer->append_instruction(new CVRTIR());
      }

      // 3. Append a DIV instruction.
      AppendDIVInstruction(result.icblockPointer, resultTypeCategory);
    }

    void AppendIntegerDivisionOperationTypedICBlock(const MlaskalCtx * const ctx, const unsigned int lineNumber, TypedICBlock & result, const TypedICBlock & lhsOperand, const TypedICBlock & rhsOperand)
    {
      // The left-hand side operand type category.
      type_category lhsOperandTypeCategory = lhsOperand.typePointer->cat();

      // The right-hand side operand type category.
      type_category rhsOperandTypeCategory = rhsOperand.typePointer->cat();

      //
      // 1. Ensure the operation is legal.
      //
      if (lhsOperandTypeCategory == TCAT_INT && rhsOperandTypeCategory == TCAT_INT)
      {
        // integer DIV integer = integer
        result.typePointer = ctx->tab->logical_integer();
      }
      else if (lhsOperandTypeCategory == TCAT_INT && rhsOperandTypeCategory == TCAT_REAL)
      {
        // integer DIV real = integer
        result.typePointer = ctx->tab->logical_integer();
      }
      else if (lhsOperandTypeCategory == TCAT_REAL && rhsOperandTypeCategory == TCAT_INT)
      {
        // real DIV integer = integer
        result.typePointer = ctx->tab->logical_integer();
      }
      else if (lhsOperandTypeCategory == TCAT_REAL && rhsOperandTypeCategory == TCAT_REAL)
      {
        // real DIV real = integer
        result.typePointer = ctx->tab->logical_integer();
      }
      else
      {
        // Error (The operation is not legal.)
        error(DUERR_CANNOTCONVERT, lineNumber);
        result.typePointer = ctx->tab->logical_undef();
        return;
      }

      // The operation is legal.

      type_category resultTypeCategory = result.typePointer->cat();

      //
      // 2. Place the left-hand side operand on the stack.
      //
      icblock_append_delete(result.icblockPointer, lhsOperand.icblockPointer);
      
      // Append an integer-to-real conversion if necessary.
      if (lhsOperandTypeCategory != resultTypeCategory)
      {
        // Error (Real-to-integer conversion, a possible loss of precision.)
        error(DUERR_CONVERSION, lineNumber);
        result.icblockPointer->append_instruction(new CVRTRI());
      }

      //
      // 3. Place the right-hand-side operand on the stack.
      //
      icblock_append_delete(result.icblockPointer, rhsOperand.icblockPointer);

      // Append an integer-to-real conversion if necessary.
      if (rhsOperandTypeCategory != resultTypeCategory)
      {
        // Error (Real-to_integer conversion, a possible loss of precision.)
        error(DUERR_CONVERSION, lineNumber);
        result.icblockPointer->append_instruction(new CVRTRI());
      }

      //
      // 4. Append a DIV instruction.
      //
      AppendDIVInstruction(result.icblockPointer, resultTypeCategory);
    }

    void AppendModuloOperationTypedICBlock(const MlaskalCtx * const ctx, const unsigned int lineNumber, TypedICBlock & result, const TypedICBlock & lhsOperand, const TypedICBlock & rhsOperand)
    {
      // The left-hand side operand type category.
      type_category lhsOperandTypeCategory = lhsOperand.typePointer->cat();

      // The right-hand side operand type category.
      type_category rhsOperandTypeCategory = rhsOperand.typePointer->cat();

      //
      // 1. Ensure the operation is legal.
      //
      if (lhsOperandTypeCategory == TCAT_INT && rhsOperandTypeCategory == TCAT_INT)
      {
        // integer MOD integer = integer
        result.typePointer = ctx->tab->logical_integer();
      }
      else if (lhsOperandTypeCategory == TCAT_INT && rhsOperandTypeCategory == TCAT_REAL)
      {
        // integer MOD real = integer
        result.typePointer = ctx->tab->logical_integer();
      }
      else if (lhsOperandTypeCategory == TCAT_REAL && rhsOperandTypeCategory == TCAT_INT)
      {
        // real MOD integer = integer
        result.typePointer = ctx->tab->logical_integer();
      }
      else if (lhsOperandTypeCategory == TCAT_REAL && rhsOperandTypeCategory == TCAT_REAL)
      {
        // real MOD real = integer
        result.typePointer = ctx->tab->logical_integer();
      }
      else
      {
        // Error (The operation is not legal.)
        error(DUERR_CANNOTCONVERT, lineNumber);
        result.typePointer = ctx->tab->logical_undef();
        return;
      }

      // The operation is legal.

      type_category resultTypeCategory = result.typePointer->cat();

      //
      // 2. Place the left-hand side operand on the stack.
      //
      icblock_append_delete(result.icblockPointer, lhsOperand.icblockPointer);
      
      // Append an integer-to-real conversion if necessary.
      if (lhsOperandTypeCategory != resultTypeCategory)
      {
        // Error (Real-to-integer conversion, a possible loss of precision.)
        error(DUERR_CONVERSION, lineNumber);
        result.icblockPointer->append_instruction(new CVRTRI());
      }

      //
      // 3. Place the right-hand-side operand on the stack.
      //
      icblock_append_delete(result.icblockPointer, rhsOperand.icblockPointer);

      // Append an integer-to-real conversion if necessary.
      if (rhsOperandTypeCategory != resultTypeCategory)
      {
        // Error (Real-to_integer conversion, a possible loss of precision.)
        error(DUERR_CONVERSION, lineNumber);
        result.icblockPointer->append_instruction(new CVRTRI());
      }

      //
      // 4. Append a MOD instruction.
      //
      AppendMODInstruction(result.icblockPointer, resultTypeCategory);
    }

    void AppendConjunctionOperationTypedICBlock(const MlaskalCtx * const ctx, const unsigned int lineNumber, TypedICBlock & result, const TypedICBlock & lhsOperand, const TypedICBlock & rhsOperand)
    {
      // The left-hand side operand type category.
      type_category lhsOperandTypeCategory = lhsOperand.typePointer->cat();

      // The right-hand side operand type category.
      type_category rhsOperandTypeCategory = rhsOperand.typePointer->cat();

      //
      // 1. Ensure the operation is legal and determine the result type.
      //
      if (lhsOperandTypeCategory == TCAT_BOOL && rhsOperandTypeCategory == TCAT_BOOL)
      {
        // boolan AND boolan = boolean
        result.typePointer = ctx->tab->logical_bool();
      }
      else
      {
        // Error (The operation is not legal.)
        error(DUERR_CANNOTCONVERT, lineNumber);
        result.typePointer = ctx->tab->logical_undef();
        return;
      }

      // The operation is legal.

      //
      // 2. Place the left-hand side operand on the stack.
      //
      icblock_append_delete(result.icblockPointer, lhsOperand.icblockPointer);

      //
      // 3. Place the right-hand-side operand on the stack.
      //
      icblock_append_delete(result.icblockPointer, rhsOperand.icblockPointer);

      //
      // 4. Append an AND instruction.
      //
      result.icblockPointer->append_instruction(new AND());
    }


    /*  
    ****************************************************************************
    *                                                                          *
    * Miscellaneous functions                                                  *
    *                                                                          *
    ****************************************************************************
    */
     
		bool IsScalarType(const type_category typeCategory)
		{
		  return (typeCategory == TCAT_BOOL) || (typeCategory == TCAT_INT) || (typeCategory == TCAT_REAL) || (typeCategory == TCAT_STR);
		}

    bool CheckAssignmentPossibility(icblock_pointer & icblockPointer, const unsigned int lineNumber, const type_pointer variableTypePointer, const type_pointer expressionTypePointer)
    {
      if (!identical_type(variableTypePointer, expressionTypePointer))
      {
        // Type of the variable does not match the type of the expression. A conversion is necessary.
        if (variableTypePointer->cat() == TCAT_REAL && expressionTypePointer->cat() == TCAT_INT)
        {
          // real := integer
          // Integer-to-real conversion necessary. No loss of data.
          icblockPointer->append_instruction(new CVRTIR());
          return true;
        }
        else if (variableTypePointer->cat() == TCAT_INT && expressionTypePointer->cat() == TCAT_REAL)
        {
          // integer := real
          // Real-to-integer conversion necessary. Possible loss of data.
          icblockPointer->append_instruction(new CVRTRI());
          return true;
        }
        else
        {
          // Error (No conversion possible.)
          error(DUERR_CANNOTCONVERT, lineNumber);
          return false;
        }
      }
      else
      {
        // Type of the variable matches the type of the expression. No conversion is necessary.
        return true;
      }
    }
	} // namespace lukas
} // namespace mlc
