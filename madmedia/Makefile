CC=gcc
CXX=g++
CFLAGES= -g3 -Wno-deprecated -fPIC
INCDIR= -I../include/\
	-I../include/common
LIBS= 
SRC=$(shell ls *.cpp)
OBJ=$(SRC:.cpp=.o)
LIBMADMELIA=libmadmelia.so
all:clean $(LIBMADMELIA)
$(LIBMADMELIA):$(OBJ)
	$(CXX) $(CFLAGES) $(INCDIR) -shared -o $(LIBMADMELIA) $^ $(LIBS)
	@cp -f *.so ../lib
%.o:%.cpp
	$(CXX) $(CFLAGES) $(INCDIR) -c $< -o $@ $(LIBS) 
%.o:%.cc
	$(CXX) $(CFLAGES) -c $< -o $@ $(LIBS) 
%.o:%.c
	$(CC) $(CFLAGES) -c $< -o $@ $(LIBS)
clean:
	@ rm -rf *.o	
	@ rm -rf *.so
	@ rm -f ../lib/$(LIBMADMELIA)
	@ rm -f $(LIBMADMELIA)
