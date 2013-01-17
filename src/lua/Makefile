.PHONY: all clean

export SWIG=swig

all : simple game

simple : simple.o
	$(CXX) -o $@ $^ -L$(LIB_DIR) -llua

simple.o : simple.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $< -I$(INC_DIR_LUA)

game : game.o game_wrap.o Elf.o Dwarf.o Ork.o
	$(CXX) -o $@ $^ -L$(LIB_DIR) -llua

game_wrap.o : game_wrap.cxx
	$(CXX) $(CXXFLAGS) -o $@ -c $< -I$(INC_DIR_LUA)

game_wrap.cxx : game.i
	$(SWIG) -c++ -lua -o $@ $^

clean :
	$(RM) simple
	$(RM) game
	$(RM) *.o
	$(RM) *_wrap.cxx

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $< -I$(INC_DIR_LUA)

