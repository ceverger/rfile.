/* permvalue.cpp - реализация метода для преобразования строки
                   с разрешениями файла в целочисленный формат */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
		 
#include "rfile.hpp"

	int RFile::permValue(const char *permissions) const
	{
		int perm = 0;
		
		if(m_permissions[0] == 'r') perm |= S_IRUSR;
		if(m_permissions[1] == 'w') perm |= S_IWUSR;
		if(m_permissions[2] == 'x') perm |= S_IXUSR;
		if(m_permissions[3] == 'r') perm |= S_IRGRP;
		if(m_permissions[4] == 'w') perm |= S_IWGRP;
		if(m_permissions[5] == 'x') perm |= S_IXGRP;
		if(m_permissions[6] == 'r') perm |= S_IROTH;
		if(m_permissions[7] == 'w') perm |= S_IWOTH;
		if(m_permissions[8] == 'x') perm |= S_IXOTH;
		
		return perm;		
	}
	
	bool RFile::permCheck(const char *permissions) const
	{
		if(permissions == nullptr) return false;
		if(strlen(permissions) < permlen - 1) return false;
		
		for(int i = 0; i < permlen  - 1; ++i)
		{
			if(permissions[i] != 'r')
				if(permissions[i] != 'w')
					if(permissions[i] != 'x')
						if(permissions[i] != '-')
							return false;
		}
		
		return true;
	}