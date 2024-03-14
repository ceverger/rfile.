// set.cpp - реализация модификаторов класса RFile

#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "rfile.hpp"

	bool RFile::setMode(int mode)
	{
		if(!modeCheck(mode)) return false;		
		m_mode = mode;		
		return true;
	}
	
	bool RFile::setName(const char *name)
	{
		if(name == nullptr) return false;
		if(strlen(name) >= namemax - 1) return false;
		
		for(int i = 0; i < namemax; ++i) m_name[i] = '\0';
		for(int i = 0; i < namemax; ++i) m_name[i] = name[i];

		return true;
	}
	
	bool RFile::setPermissions(const char *permissions)
	{
		if(!permCheck(permissions)) return false;
		
		for(int i = 0; i < permlen; ++i)
			m_permissions[i] = '\0';
		
		for(int i = 0; i < permlen; ++i)
			m_permissions[i] = permissions[i];
		
		return true;
	}