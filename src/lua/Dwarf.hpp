#ifndef __DWARF__HPP__
#define __DWARF__HPP__

#include "Player.hpp"

class Dwarf : public Player
{
	public:
		virtual const char * race() const;
		virtual void action();
};

#endif
