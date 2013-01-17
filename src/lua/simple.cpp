// simple.cpp

#include <lua.hpp>

static int lua__hello_world(lua_State * lua)
{
	int i = luaL_checkinteger(lua, -1);
	printf("Hello World: %d\n", i);
	return 0;
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

	// register custom function
	lua_register(lua, "hello_world", lua__hello_world);

	// execute script
	if (luaL_dofile(lua, argv[1])) {
		fprintf(stderr, "ERROR: %s\n", lua_tostring(lua, -1));
	}

	// clean up
	lua_close(lua);
	return 0;
}

