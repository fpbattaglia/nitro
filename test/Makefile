

CPPFLAGS:=-g -I../build/usr/include/ $(CPPFLAGS)
CPPUNITLIB?=`pkg-config --libs cppunit`
LDFLAGS=$(CPPUNITLIB) -L../build/usr/lib64/ -lnitro
PYTHONBUILD=../python/build/lib.linux-x86_64-2.7/

TESTS=tests/node.o \
	tests/error.o \
	tests/types.o \
	tests/xml.o \
	tests/device.o \
	tests/userdevice.o \
	tests/scripts.o

run: test userdevice.so
	LD_LIBRARY_PATH=../build/usr/lib64 PYTHONPATH=$(PYTHONBUILD) ./test

mem: test userdevice.so
	LD_LIBRARY_PATH=../build/usr/lib64 valgrind --leak-check=full --show-reachable=yes $(SUPP) ./test

gdb: test userdevice.so
	LD_LIBRARY_PATH=../build/usr/lib64 gdb ./test

test: $(TESTS) test.o
	g++ -o test test.o $(TESTS) $(LDFLAGS)

userdevice.so: userdevice.cpp
	g++ $(CPPFLAGS) -fPIC -o userdevice.so -shared userdevice.cpp

clean:
	rm *.o tests/*.o test *.so
