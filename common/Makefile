CC=gcc
CXX=g++
CFLAGES=  -Wno-deprecated -fPIC
INCDIR= -I../include/\
	-I../include/common
LIBS=-lpthread 
SRC=$(shell ls *.cpp)
OBJ=$(SRC:.cpp=.o)
LIBOUTPUT=libcommon.so
all:clean $(LIBOUTPUT)
$(LIBOUTPUT):$(OBJ)
	$(CXX) $(CFLAGES) $(INCDIR) -shared -o $(LIBOUTPUT) $^ $(LIBS)
	@cp -f *.so ../lib/
%.o:%.cpp
	$(CXX) $(CFLAGES) $(INCDIR) -c $< -o $@ $(LIBS) 
%.o:%.cc
	$(CXX) $(CFLAGES) -c $< -o $@ $(LIBS) 
%.o:%.c
	$(CC) $(CFLAGES) -c $< -o $@ $(LIBS)
clean:
	@ rm -rf *.o	
	@ rm -rf *.so
	@ rm -f ../lib/$(LIBOUTPUT)
	@ rm -f $(LIBOUTPUT)
