.PHONY: all clean

CXXFLAGS+=-DXP_UNIX

all : simple

simple : simple.o
	$(CXX) -o $@ $^ -L$(LIB_DIR) -ljs

clean :
	$(RM) *.o
	$(RM) simple

%.o : %.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS) -I$(INC_DIR_JS)

