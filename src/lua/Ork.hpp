#ifndef __ORK__HPP__
#define __ORK__HPP__

#include "Player.hpp"

class Ork : public Player
{
	public:
		virtual const char * race() const;
		virtual void action();
};

#endif
