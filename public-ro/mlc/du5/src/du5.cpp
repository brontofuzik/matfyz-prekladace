/*

    DU5.CPP

    DB

    Main for DU5

*/

#include <cstdio>
#include <fstream>

#include "du5.h"
#include "du5tok.h"
#include "duerr.h"
#include "dutables.h"
#include "flat_icblock.hpp"
#include "labeled_icblock.hpp"
#include "ai_factory.hpp"

#if defined( DEBUG_MEMORY_LEAKS) && defined( _MSC_VER) && defined( _DEBUG)
#define _AFXDLL
#include "afx.h"
#endif

using namespace std;
using namespace mlc;
using namespace mlaskal;

extern FILE *yyin;

namespace mlc {

    // literal and identifier tables
    ls_int_type ls_int;
    ls_real_type ls_real;
    ls_str_type ls_str;
    ls_id_type ls_id;

    int symtab_preprocess(struct MlaskalCtx *ctx, bool debug)
    {
	ctx->aic = new abstract_ic();
	ctx->tab = new symbol_tables( debug, ctx->aic);

	ctx->tab->init_builtins();

	return 0;
    }

    int symtab_postprocess(struct MlaskalCtx *ctx, const std::string & dump_fname)
    {
	if ( ! dump_fname.empty() )
	{
	    std::ofstream out( dump_fname.c_str());
	    if ( out.fail() )
	    {
		error( DUERR_NOOUTFILE, 0, dump_fname);
	    }
	    else
	    {
		ctx->tab->dump( out);
	    }
	}

	delete ctx->tab;
	ctx->tab = 0;
	delete ctx->aic;
	ctx->aic = 0;

	return 0;
    }
}

int main(int argc, char **argv)
{
string asm_file;
bool debug_symtab=false;
string dump_fname;

    if(argc<3)
    {
	cout << "Usage: du5 <input_file> <output_file> [options]\n";
	cout << "Options:\n";
	cout << "\t-S<asm_file>\tassembler listing\n";
	cout << "\t-B\t\tdebug symbol tables\n";
	cout << "\t-D<xml_file>\t\tdump symbol tables canonically\n";
	return 16;
    }

    for(int i=3;i<argc;++i)
	if(argv[i][0]=='/' || argv[i][0]=='-')
	    switch(argv[i][1])
	    {
	    case 'D':
		dump_fname = argv[i]+2;
		break;
	    case 'S':
		asm_file = argv[i]+2;
		break;
	    case 'B':
		debug_symtab = true;
		break;
	    }
	else
	    cout << "Unknown parameter \"" << argv[i] << "\"\n";

    if((yyin=fopen(argv[1], "r"))==0)
    {
	error(DUERR_NOINFILE, 0, argv[1]);
	return 16;
    }

#if defined( DEBUG_MEMORY_LEAKS) && defined( _MSC_VER) && defined( _DEBUG)
    CMemoryState msOld;
    msOld.Checkpoint();
#endif

    {
	MlaskalCtx ctx;

	symtab_preprocess( & ctx, debug_symtab);

	yyparse(&ctx);

    //    append_library(*ctx.aic);

	flat_icblock ficb(*ctx.aic);

	ficb.save(argv[2]);
	if(!asm_file.empty())
	    ficb.save_asm(asm_file);

	symtab_postprocess( & ctx, dump_fname);
    }

#if defined( DEBUG_MEMORY_LEAKS) && defined( _MSC_VER) && defined( _DEBUG)
    msOld.DumpAllObjectsSince();
#endif

    fclose(yyin);

    if(n_errors)
	error(DUERR_ERRS, 0, n_errors, n_warnings);
    else if(n_warnings)
	error(DUERR_NOK, 0, n_warnings);
    else
	error(DUERR_OK, 0);

    return 0;
}
