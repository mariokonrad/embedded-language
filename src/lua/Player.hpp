#ifndef __PLAYER__HPP__
#define __PLAYER__HPP__

class Player
{
	public:
		virtual const char * race() const = 0;
		virtual void action() = 0;
};

#endif
