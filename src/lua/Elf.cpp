#include "Elf.hpp"
#include <cstdio>

const char * Elf::race() const
{
	return "Elf";
}

void Elf::action()
{
	printf("shoots arrow\n");
}

