/* createfile.cpp - реализация методов для открытия и закрытия
                    файлов класса RFile ---------------------- */
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "rfile.hpp"

	bool RFile::openIO()
	{
		if(state == opened)  
		{
			errstr = open_error_state;
			return false;
		}
		
		if(*m_name == '\0')
		{
			errstr = open_error_name;
			return false;
		}
				
		if(m_mode == undef)
		{
			errstr = open_error_mode;
			return false;
		}
		
		fd = open(m_name, modeValue(m_mode));
		
		if(fd < 0)
		{
			errstr = strerror(errno);
			return false;
		}
		
		state = opened;
		
		return true;		
	}
	
	bool RFile::openIO(const char *name, int mode)
	{
		if(state == opened)  
		{
			errstr = open_error_state;
			return false;
		}
		
		if(!setName(name))
		{
			errstr = open_error_name;
			return false;
		}
		
		if(!setMode(mode))
		{
			errstr = open_error_mode;
			return false;
		}
		
		fd = open(m_name, modeValue(m_mode));
		
		if(fd < 0)
		{
			errstr = strerror(errno);
			return false;
		}
		
		state = opened;
		
		return true;		
	}
	
	bool RFile::closeIO()
	{
		if(close(fd))
		{
			errstr = strerror(errno);
			return false;			
		}
		
		state = closed;
		
		reset();
		
		return true;
	}