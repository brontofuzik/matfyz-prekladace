/*

    DU5SEM.H

*/

#ifndef DU5SEM_H_
#define DU5SEM_H_

#include "du5.h"
#include "du5lval.hpp"

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
	  
		/**
		 *    Adds a label.     		 
		 */
		void AddLabel(MlaskalCtx * const ctx, const unsigned int lineNumber, const ls_int_index labelIdentifier);
		
    /**
		 *    Adds a constant.
		 */		 
		void AddConstant(MlaskalCtx * const ctx, const unsigned int lineNumber, const ls_id_index constantIdentifier, const Constant & constant);
		
		/**
		 *    Finds a constant.
		 */		 
		Constant FindConstant(const MlaskalCtx * const ctx, const unsigned int lineNumber, const ls_id_index constantIdentifier);
		
		/**
		 *    Adds a type.
		 */		 
		void AddType(MlaskalCtx * const ctx, const unsigned int lineNumber, const ls_id_index typeIdentifier, const type_pointer typePointer);
		
		/**
		 *    Finds a type.
		 */		 
		type_pointer FindType(const MlaskalCtx * const ctx, const unsigned int lineNumber, const ls_id_index typeIdentifier);
		
		/**
		 *    Appends a group of fields.
		 */
    void AppendFieldGroup(field_list * const fieldList, const identifier_list & identifierList, const type_pointer typePointer);

    /**
     *    Finds a field.
     */
    Variable FindField(const MlaskalCtx * const ctx, const Variable & variable, const unsigned int lineNumber, const ls_id_index fieldIdentifier);
		
		/**
		 *    Adds a group of variables.
		 */
		void AddVariableGroup(MlaskalCtx * const ctx, const identifier_list & identifierList, const type_pointer typePointer);
		
		/**
		 *    Finds a variable.
		 */		 
    Variable FindVariable(const MlaskalCtx * const ctx, const unsigned int lineNumber, const ls_id_index variableIdentifier);        
    
    /**
     *    Appends a group of formal parameters.
     */
    void AppendFormalParameterGroup(const MlaskalCtx * const ctx, parameter_list  * const formalParameterList, const bool byValue, const identifier_list & IdentifierList, const unsigned int lineNumber, const ls_id_index typeIdentifier);             
		

    /*  
    ****************************************************************************
    *                                                                          *
    * Append*Instruction functions                                             *
    *                                                                          *
    ****************************************************************************
    */

    /**
     *    Appends a INIT (initialize) instruction to the IC block.
     */
    void AppendINITInstruction(icblock_pointer & icblockPointer, const type_category typeCategory);

    /**
     *    Appends a LDLIT (load literal) instruction to the IC block.
     */     
    void AppendLDLITInstruction(icblock_pointer & icblockPointer, const Constant & constant);

    /**
     *    Appends a CVRT (convert) instruction to the IC block.
     */
    void AppendCVRTInstruction(icblock_pointer & icblockPointer);

    /**
     *    Appends a MINUS (unary minus) instruction to the IC block.
     */
    void AppendMINUSInstruction(icblock_pointer & icblockPointer, const type_category typeCategory);

    /**
     *    Appends an ADD (addition) instruction to the IC block.
     */
    void AppendADDInstruction(icblock_pointer & icblockPointer, const type_category typeCategory);

    /**
     *    Appends an SUB (subtraction) instruction to the IC block.
     */
    void AppendSUBInstruction(icblock_pointer & icblockPointer, const type_category typeCategory);

    /**
     *    Appends a MUL (multiplication) instruction to the IC block.
     */
    void AppendMULInstruction(icblock_pointer & icblockPointer, const type_category typeCategory);

    /**
     *    Appends a DIV (division) instruction to the IC block.
     */
    void AppendDIVInstruction(icblock_pointer & icblockPointer, const type_category typeCategory);

    /**
     *    Appends a MOD (modulo) instruction to the IC block.
     */
    void AppendMODInstruction(icblock_pointer & icblockPointer, const type_category typeCategory);

    /**
     *    Appends a DTOR (destruct) instruction to the IC block.
     */
    void AppendDTORInstruction(icblock_pointer & icblockPointer, const type_category typeCategory);

    /**
	   *    Appends a LD (load) instruction.
	   */	   
    void AppendLDInstruction(icblock_pointer & icblockPointer, const symbol_kind symbolKind, const type_category typeCategory, const stack_address stactAddress);
    
    /**
     *    Appends a ST (store) instruction.
     */     
    void AppendSTInstruction(icblock_pointer & icblockPointer, const symbol_kind symbolKind, const type_category typeCategory, const stack_address stactAddress);

    
    /*  
    ****************************************************************************
    *                                                                          *
    * Append*StatementICBlock functions                                        *
    *                                                                          *
    ****************************************************************************
    */

    /***** Assignments statements *****/

    /**
     *    Appends an IC block representing an exrepssion to a variable or a function assignment statement.
     */
    void AppendAssignmentStatementICBlock(const MlaskalCtx * const ctx, const unsigned int lineNumber, icblock_pointer & result, const ls_id_index identifier, const TypedICBlock & expression);

    /**
     *    Appends an IC block representing an expression to a field assignment statement.
     */
    void AppendVariableAssignmentStatementICBlock(const unsigned int lineNumber, icblock_pointer & result, const Variable & variable, const TypedICBlock & expression);

    /**
     *    Appends an IC block representing a record to record assignment.
     */
    void AppendRecordToRecordAssignmentStatementICBlock(icblock_pointer & result, const symbol_kind symbolKind, const record_type_pointer recordTypePointer, const stack_address lhsStackAddress, const stack_address rhsStackAddress);

    /**
     *     Appends an IC block representing a function assignment.
     */
    void AppendFunctionAssignmentStatementICBlock(const unsigned int lineNumber, icblock_pointer & result, const function_symbol_pointer functionSymbolPointer, const TypedICBlock & expression);


    /***** Subprorgam calls *****/

    /**
     *    Appends an IC block representing a procedure call statement.
     */
    void AppendProcedureCallStatementICBlock(const MlaskalCtx * const ctx, const unsigned int lineNumber, icblock_pointer & result, const ls_id_index procedureIdentifier, const actual_parameter_list & actualParameterList);

    /**
     *    Appends an IC block representing a function call expression.
     */
    void AppendFunctionCallExpressionTypedICBlock(const MlaskalCtx * const ctx, const unsigned int lineNumber, TypedICBlock & result, const ls_id_index functionIdentifier, const actual_parameter_list & actualParameterList);

    /**
     *    Appends an IC block representing a subprogram (a procedure or a function) call.
     */
    void AppendSubprogramCallICBlock(const MlaskalCtx * const ctx, icblock_pointer & result, const unsigned int lineNumber, const ls_id_index subprogramIdentifier, const actual_parameter_list & actualParameterList);

    /*  
    ****************************************************************************
    *                                                                          *
    * Append*OperationTypedICBlock functions                                   *
    *                                                                          *
    ****************************************************************************
    */

    /***** Unary operations *****/

    /**
     *    Appends a typed IC block representing a (unary) minus operation.
     */
    void AppendMinusOperationTypedICBlock(const MlaskalCtx * const ctx, const unsigned int lineNumber, TypedICBlock & result, const TypedICBlock & operand);


    /***** Binary operations *****/

    /**
     *    Appends a typed IC block representing an addition operation.
     */
    void AppendAdditionOperationTypedICBlock(const MlaskalCtx * const ctx, const unsigned int lineNumber, TypedICBlock & result, const TypedICBlock & lhsOperand, const TypedICBlock & rhsOperand);
    
    /**
     *    Appends a typed IC block representing a subtraction operation.
     */
    void AppendSubtractionOperationTypedICBlock(const MlaskalCtx * const ctx, const unsigned int lineNumber, TypedICBlock & result, const TypedICBlock & lhsOperand, const TypedICBlock & rhsOperand);

    /**
     *    Appends a typed IC block representing a logical disjunction (OR) operation.
     */
    void AppendDisjunctionOperationTypedICBlock(const MlaskalCtx * const ctx, const unsigned int lineNumber, TypedICBlock & result, const TypedICBlock & lhsOperand, const TypedICBlock & rhsOperand);
    
    /**
     *    Appends a typed IC block representing a multiplication operation.
     */
    void AppendMultiplicationOperationTypedICBlock(const MlaskalCtx * const ctx, const unsigned int lineNumber, TypedICBlock & result, const TypedICBlock & lhsOperand, const TypedICBlock & rhsOperand);

    /**
     *    Appends a typed IC block representing a (real) division operation.
     */
    void AppendRealDivisionOperationTypedICBlock(const MlaskalCtx * const ctx, const unsigned int lineNumber, TypedICBlock & result, const TypedICBlock & lhsOperand, const TypedICBlock & rhsOperand);

    /**
     *    Appends a typed IC block representing a (integer) division operation.
     */
    void AppendIntegerDivisionOperationTypedICBlock(const MlaskalCtx * const ctx, const unsigned int lineNumber, TypedICBlock & result, const TypedICBlock & lhsOperand, const TypedICBlock & rhsOperand);

    /**
     *    Appends a typed IC block representing modulo operation.
     */
    void AppendModuloOperationTypedICBlock(const MlaskalCtx * const ctx, const unsigned int lineNumber, TypedICBlock & result, const TypedICBlock & lhsOperand, const TypedICBlock & rhsOperand);

    /**
     *    Appends a typed IC block representing a logical conjunction (AND) operator.
     */
    void AppendConjunctionOperationTypedICBlock(const MlaskalCtx * const ctx, const unsigned int lineNumber, TypedICBlock & result, const TypedICBlock & lhsOperand, const TypedICBlock & rhsOperand);
  

    /*  
    ****************************************************************************
    *                                                                          *
    * Miscellaneous functions                                                  *
    *                                                                          *
    ****************************************************************************
    */

		/**
		 *    Determines whether a type is scalar.
		 */		 
		bool IsScalarType(const type_category typeCategory);

    /**
     *
     */
    bool CheckAssignmentPossibility(icblock_pointer & icblockPointer, const unsigned int lineNumber, const type_pointer variableTypePointer, const type_pointer expressionTypePointer);
  } // namespace lukas
} // namespace mlc

#endif
