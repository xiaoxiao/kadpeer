CC=gcc
CXX=g++
CFLAGES=-g3 -Wno-deprecated
INCDIR=-I../include\
 	-I../include/common
LIBS=-L../lib -lcommon
SRC=$(shell ls *.cpp)
OBJ=$(SRC:.cpp=.o)
Target=kadpeer
all:clean $(Target)
$(Target):$(OBJ)
	$(CXX) $(CFLAGES) $(INCDIR) -o $(Target) $^ $(LIBS)
	@cp -f $(Target) ../lib/
%.o:%.cpp
	$(CXX) $(CFLAGES) $(INCDIR) -c $< -o $@ $(LIBS) 
%.o:%.cc
	$(CXX) $(CFLAGES) -c $< -o $@ $(LIBS) 
%.o:%.c
	$(CC) $(CFLAGES) -c $< -o $@ $(LIBS)
clean:
	@ rm -rf *.o	
	@ rm -f $(Target)
	@ rm -f ../lib/$(Target)
