// game.cpp

#include <lua.hpp>

extern "C" {
extern int luaopen_game(lua_State * L);
}

int main(int argc, char ** argv)
{
	if (argc != 2) {
		printf("\nusage: %s script-filename\n\n", argv[0]);
		return -1;
	}

	// open state
	lua_State * lua = lua_open();

	// open all libs (math, io, system, table, ...)
	luaL_openlibs(lua);

    // initialize generated module
    luaopen_game(lua);

	// execute script
	if (luaL_dofile(lua, argv[1])) {
		fprintf(stderr, "ERROR: %s\n", lua_tostring(lua, -1));
	}

	// clean up
	lua_close(lua);
    return 0;
}

