all:
	g++ -g -fpic -c rfile.cpp     -o ../build/rfile.o     -I .
	g++ -g -fpic -c createio.cpp  -o ../build/createio.o  -I .
	g++ -g -fpic -c openio.cpp    -o ../build/openio.o    -I .
	g++ -g -fpic -c set.cpp       -o ../build/set.o       -I .
	g++ -g -fpic -c modevalue.cpp -o ../build/modevalue.o -I .
	g++ -g -fpic -c permvalue.cpp -o ../build/permvalue.o -I .
	g++ -g -fpic -c setpos.cpp    -o ../build/setpos.cpp  -I .
	g++ -g -fpic -c rddata.cpp    -o ../build/rddata.o    -I .
	g++ -g -fpic -c wrdata.cpp    -o ../build/wrdata.o    -I . 
	g++ -shared ../build/*.o   -o ../build/librfile.so.0
