/*

DU5LVAL.H

*/

#ifndef DU5LVAL_H_
#define DU5LVAL_H_

#include "abstract_instr.hpp"
#include "dutables.h"
#include "flat_icblock.hpp"
#include "gen_ainstr.hpp"
#include "literal_storage.hpp"

namespace mlc
{
  namespace lukas
  {
    /**
		 *    Constant.		
		 */		
		struct Constant
		{
		/* region Public instance constructors */
		  
      /** Creates a new boolean constant. */
      Constant(type_pointer typePointer, bool booleanValue)
      {
        this->typePointer = typePointer;
        this->booleanValue = booleanValue; 
      }

      /** Creates a new integer constant. */
      Constant(type_pointer typePointer, ls_int_index integerValue)
      {
        this->typePointer = typePointer;
        this->integerValue = integerValue; 
      }

      /** Creates a new real constant. */
      Constant(type_pointer typePointer, ls_real_index realValue)
      {
        this->typePointer = typePointer;
        this->realValue = realValue; 
      }

      /** Creates a new string constant. */
      Constant(type_pointer typePointer, ls_str_index stringValue)
      {
        this->typePointer = typePointer;
        this->stringValue = stringValue; 
      }

		  /** Creates a new typed constant. */
		  Constant(type_pointer typePointer)
		  {
		    this->typePointer = typePointer;
      }

      /** Creates a new constant (default constructor). */
      Constant()
      {
      }
		  
		/* endregion // Public instance constructors */
		  
		/* region Public instance fields */
		  
		  /** Type pointer. */
			type_pointer typePointer;
				
			/** BOOL value. */
			bool booleanValue;

			/** Constant iterator into INT literal table. */
			ls_int_index integerValue;
			
			/** Constant iterator into REAL literal table. */
			ls_real_index realValue;

			/** Constant iterator into STRING literal table. */
			ls_str_index stringValue;	
		  
		/* endregion // Public insatnce fields */
		}; // struct Constant

    /**
     *    Variable.    
     */    
    struct Variable
    {
    /* region Public instance constructors */
    
      /** Creates a new variable. */
      Variable(symbol_kind symbolKind, type_pointer typePointer, stack_address stackAddress)
      {
        this->symbolKind = symbolKind;
        this->typePointer = typePointer;  
        this->stackAddress = stackAddress;
      }

      /** Creates a new variable (default constructor). */
      Variable()
      {
      }
      
    /* endregion // Public instance constructors */
      
    /* region Public instance fields */

      /** Symbol kind. */
      symbol_kind symbolKind;
        
      /** Type pointer. */
      type_pointer typePointer;
      
      /** Stack address. */
      stack_address stackAddress;
      
    /* endregion // Public instance fields */  
    }; // struct Variable

    /**
     *    Function header.
     */
    struct FunctionHeader
    {
    /* region Public instance constructors *

      /** Creates a new function header. */
      FunctionHeader(ls_id_index functionIdentifier, type_pointer functionReturnTypePointer)
      {
        this->functionIdentifier = functionIdentifier;
        this->functionReturnTypePointer = functionReturnTypePointer;
      }

      /** Creates a new function header (default constructor). */
      FunctionHeader()
      {
      }

    /* endregion // Public instance constructors */
    /* region Public instance fields */

      /** Function identifier. */
      ls_id_index functionIdentifier;

      /** Function return type. */
      type_pointer functionReturnTypePointer;

    /* ednregion // Public instance fields */
    }; // struct FunctionHeader
    
    /**
     *    Typed IC block.  
     */    
    struct TypedICBlock
		{
    /* region Public instance constructors */
    		  
		  /** Creates a new typed icblock. */
		  TypedICBlock(type_pointer typePointer, icblock_pointer icblockPointer)
      {
      	this->typePointer = typePointer;
		    this->icblockPointer = icblockPointer;
      }

      /** Creates a new typed icblock (default constructor). */
      TypedICBlock()
      {
        icblockPointer = icblock_create();
      }
      
    /* endregion // Public instance constructors */
      
    /* region Public instance fields */
      
      /** Type pointer. */
      type_pointer typePointer;
      
      /** IC block pointer. */
		  icblock_pointer icblockPointer;

      /** TODO: Remove this travesty!!! */
      stack_address stackAddress;
		  
		/* endregion // Public instance fields */
    }; // struct typedICBlock

    // identifier_list
    typedef std::pair<unsigned int, ls_id_index> linenumber_identifier_pair;
		typedef std::vector<linenumber_identifier_pair> identifier_list;
    
    // actual_parameter_list
    typedef std::vector<TypedICBlock> actual_parameter_list;
	} // namespace lukas

  /**
   *    Compiler's semantic value.
	 */ 
  struct MlaskalLval
	{
  /* region Public insatnce fields */

		/** Group element. */
		int dtge_;

		/** Constant iterator into INT literal table. */
		ls_int_type::const_iterator int_ci_;

		/** Constant iterator into REAL literal table. */
		ls_real_type::const_iterator real_ci_;

		/** Constant iterator into STRING literal table. */
		ls_str_type::const_iterator str_ci_;

		/** Constant iterator into identifier table. */
		ls_id_type::const_iterator id_ci_;

		/** Type pointer. */
		type_pointer typePointer;

    /** Function header. */
    lukas::FunctionHeader functionHeader;

		/** Field list. */
		field_list * fieldList;
		
		/** Parameter list. */
		parameter_list * formalParameterList;
		
		/** Icblock pointer. */
		icblock_pointer icblockPointer;
		
		/** Typed constant. */
		lukas::Constant constant;
		
		/** Typed variable. */
    lukas::Variable variable;
    
    /** Typed icblock. */
		lukas::TypedICBlock typedICBlock;	

		/** Identifier list. */
		lukas::identifier_list identifierList;
		
		/** Actual parameter list. */
		lukas::actual_parameter_list actualParameterList;

  /* endregion // Pubic instance fields */			
	}; // struct MlaskalLval
} // namespace mlc

// lex interface
#define YY_DECL	    int yylex(mlc::MlaskalLval *lv, unsigned *l, mlc::MlaskalCtx *ctx)
YY_DECL;

#endif
