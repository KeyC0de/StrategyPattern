#pragma once

#ifdef _DEBUG
#	define _CRTDBG_MAP_ALLOC
#	define _CRTDBG_MAP_ALLOC_NEW
#	include <crtdbg.h>
#	include <assert.h>
#	include "winner.h"

#ifndef TRUE
#define TRUE 1
#endif // !TRUE


namespace debugLeak
{

bool anyMemoryLeaks()
{
	// confirms integrity of memory blocks allocated by debug heap
	assert( _CrtCheckMemory() == TRUE,
		"_CrtCheckMemory() assertion failed\n" );
	if ( _CrtDumpMemoryLeaks() )
	{
		return true;
	}
	else
	{
		return false;
	}
}

};// namespace debugLeak

#endif