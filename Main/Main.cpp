#include "stdafx.h"
#include <crtdbg.h>
#include <cassert>
#include <stdlib.h>
#include "Sorts.h"

#define _CRTDBG_MAP_ALLOC

int main(int argc, char *argv[])
{
	{
		Sorts<int> sorts;
		int numSort = 0;

		if (argc == 2) {
			numSort = stoi(argv[1]);
		}
		else { //manual
			numSort = 50000;
		}

		cout << "SORTING : " << numSort << " items" << endl << endl;
		sorts.RunSorts(numSort);
	}
		
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtDumpMemoryLeaks();

	//Not Running from console.
	if (argc == 1)	{
		system("pause");
	}
}