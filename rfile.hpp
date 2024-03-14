// rfile.hpp - описание класса RFile

#include "iodevice.hpp"

#ifndef R_FILE_HPP
#define R_FILE_HPP

#define reset_error "RFile::reset: File is not close state!"
#define create_error_state "RFile::createIO: File is not undef state!"
#define create_error_name "RFile::createIO: File name is incorrect!"
#define create_error_perm "RFile::createIO: File permissions is not correct!"
#define open_error_state "Rfile::openIO: File was opened"
#define open_error_name  "Rfile::openIO: File name is incorrect!"
#define open_error_mode  "Rfile::openIO: File mode is incorrect!"

	class RFile : public IODevice
	{
		/* Класс управляет процессом открытия и создания файлов */
		
		public:
		
			enum 
			{
				/* Некоторые используемые классом константы */
				
				undef   = 0,  // Неопределённое состояние
				permlen = 10, // Размер массива с разрешениями на файл
				namemax = 255 // Максимальная длина имени файла
			};
			
			enum
			{
				/* Целочисленные идентификаторы состояния файла */
				
				closed  = 1, // Файл закрыт
				opened  = 2  // Файл открыт
			};
			
			enum
			{
				/* Целочисленные идентификаторы режимов
					открытия файла --------------------- */
				
				ReadMode  = 1, 
				WriteMode = 2,
				ReadWrite = 3
			};
		
		private:
		
			int state;	 					  // Состояние файла
			long size; 						  // Размер файла
			int m_mode; 					  // Режим открытия файла
			char m_name[namemax];        // Имя файла
			char m_permissions[permlen]; // Разрешения на файл
		
		public:
		
			/* Конcтрукторы и деструкторы класса */
		
				RFile();
				virtual ~RFile() {}
				
			/* Селекторы класса */
			
				int getState() const { return state;  }
				long getSize() const { return size;   }
				int getMode()  const { return m_mode; }
				
				const char *getName() const { return m_name; }
				const char *getPermissions() const { return m_permissions; }

			/* Модификаторы класса */
			
				bool setMode(int mode);
				bool setName(const char *name);
				bool setPermissions(const char *permission);
				
			/* Методы для создания файлов */
			
				bool createIO();
				bool createIO(const char *name, const char *permissions);
				
			/* Методы для открытия и закрытия файлов */
			
				bool openIO();
				bool openIO(const char *name, int mode);
				
				bool closeIO();
				
			/* Методы чтения и записи в файл */
			
				int rddata(char *buf, int size);				
				int wrdata(const char *buf, int size);
				
			/* Методы для управления позиционированием в файле */
			
				int getPosition();
				bool setPosition(int position);
				
				bool setPositionAtEnd();
				bool setPositionAtBegin();
			
			/* Методы для работы с константами режима открытия файлы */
			
				int modeValue(int mode) const;
				bool modeCheck(int mode) const;
				
			/* Методы для работы со строкой разрешений */
			
				int permValue(const char *permission) const;
				bool permCheck(const char *permission) const;
								
			/* Другие методы класса */
			
				void reset();
		
	}; // class RFile

#endif // R_FILE_HPP