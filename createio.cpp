// createio.cpp - реализация методов для создания файлов класса Filer */

#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "rfile.hpp"
		
	bool RFile::createIO()
	{
		/* Создание ещё несуществующего файла */
			
		if(state != undef) 
		{
			errstr = create_error_state;
			return false;
		}
		
		if(*m_name == '\0')
		{
			errstr = create_error_name;
			return false;
		}
		
		if(*m_permissions == '\0')
		{
			errstr = create_error_perm;
			return false;			
		}

		mode_t um = umask(0); // Временно сбрасываем значение umask
		
		fd = open(m_name, O_CREAT | O_EXCL, permValue(m_permissions));
		
		if(fd < 0)
		{
			errstr = strerror(errno);
			return false;
		}

		umask(um);
		
		if(close(fd))
		{
			errstr = strerror(errno);
			return false;			
		}
		
		fd = -1;
		state = closed;
		
		return true;
	}
		
	bool RFile::createIO(const char *name, const char *permissions)
	{
		/* Создание ещё несуществующего файла и получение
		   дескриптора для ввода-вывода (version 1) ----- */
			
		if(state != undef) 
		{
			errstr = create_error_state;
			return false;
		}
		
		if(!setName(name))
		{
			errstr = create_error_name;
			return false;
		}
		
		if(!setPermissions(permissions))
		{
			errstr = create_error_perm;
			return false;			
		}
		
		mode_t um = umask(0); // Временно сбрасываем значение umask
		
		fd = open(m_name, O_CREAT | O_EXCL, permValue(m_permissions));
		
		if(fd < 0)
		{
			errstr = strerror(errno);
			return false;
		}

		umask(um);
		
		if(close(fd))
		{
			errstr = strerror(errno);
			return false;			
		}
		
		fd = -1;		
		state = closed;
		
		return true;
	}