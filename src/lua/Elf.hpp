#ifndef __ELF__HPP__
#define __ELF__HPP__

#include "Player.hpp"

class Elf : public Player
{
	public:
		virtual const char * race() const;
		virtual void action();
};

#endif
