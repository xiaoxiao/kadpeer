CC=gcc
CXX=g++
MAKE=gmake
all:
	@[ -d lib ] || mkdir lib
	@[ -d bin ] || mkdir bin
	$(MAKE) -C common
	$(MAKE) -C src
clean:
	$(MAKE) -C common clean
	$(MAKE) -C src clean
	@[ ! -d lib ] || rm -rf lib
	@[ ! -d bin ] || rm -rf bin