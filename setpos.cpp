// setpos.cpp - реализация методов для создания файлов класса RFile */

#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "rfile.hpp"

	int RFile::getPosition()
	{
		if(state != opened) return -1;
		
		int pos = lseek(fd, 0, SEEK_CUR);
		
		if(pos < 0)
			{
				errstr = strerror(errno);
				return -1;
			}
			
		return pos;
	}
	
	bool RFile::setPosition(int position)
	{
		if(state != opened) return false;
		
		int pos = lseek(fd, position, SEEK_SET);
		
		if(pos < 0)
			{
				errstr = strerror(errno);
				return false;
			}
			
		return true;		
	}
	
	bool RFile::setPositionAtEnd()
	{
		if(state != opened) return false;
		
		int pos = lseek(fd, 0, SEEK_END);
		
		if(pos < 0)
			{
				errstr = strerror(errno);
				return false;
			}
			
		return true;		
	}
	
	bool RFile::setPositionAtBegin()
	{
		if(state != opened) return false;
		
		int pos = lseek(fd, 0, SEEK_SET);
		
		if(pos < 0)
			{
				errstr = strerror(errno);
				return false;
			}
			
		return true;		
	}