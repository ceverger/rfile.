// rfile.cpp - реализация конструкторов и других методов класса RFile

#include "rfile.hpp"

	RFile::RFile() : IODevice()
	{
		/* Конструктор класса по умолчанию */
		
		typeID = FileType;
		state = undef;
		reset();
	}
	
	void RFile::reset()
	{
		/* Сброс информации о файле */
		
		if(state != closed) 
		{
			errstr = reset_error;
			return;
		}
		
		fd = -1;
		errstr = nullptr;
		
		size = 0;
		m_mode = undef;
		
		for(int i = 0; i < namemax; ++i)
			m_name[i] = '\0';
		
		for(int i = 0; i < permlen; ++i)
			m_permissions[i] = '\0';
	}