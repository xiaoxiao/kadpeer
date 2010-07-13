CC=gcc
CXX=g++
MAKE=gmake
all : clean
	@[ -d lib ] || mkdir lib
	@[ -d bin ] || mkdir bin
	$(MAKE) -C common
	$(MAKE) -C src
	@cp -f lib/* bin/
	@cp -f lib/* ./
clean :
	$(MAKE) -C common clean
	$(MAKE) -C src clean
	@[ ! -d lib ] || rm -rf lib
	@[ ! -d bin ] || rm -rf bin
	@[ ! -f *.so ] || rm -f *.so
	@[ ! -f kadpeer ] || rm -f kadpeer
