/* modevalue.cpp -  */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
		 
#include "rfile.hpp"

	int RFile::modeValue(int mode) const
	{
		int md = -1;
		
		if(mode == ReadMode) md = O_RDONLY;
		else if(mode == WriteMode) md = O_WRONLY;
		else if(mode == ReadWrite) md = O_RDWR;
		
		return md;
	}
	
	bool RFile::modeCheck(int mode) const
	{
		if(mode == ReadMode) return true;
		if(mode == WriteMode) return true;
		if(mode == ReadWrite) return true;
		
		return false;
	}