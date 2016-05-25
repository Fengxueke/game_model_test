#include "stdafx.h"
#include "level.h"

void level::Level(character c, Role r)
{
	if (c.R.getEXP() > 50 && c.R.getEXP()<100) {

		c.R.setLevel(2);
	}

	else if (c.R.getEXP() > 100 && c.R.getEXP()<200) {

		c.R.setLevel(3);
	}
	else if (c.R.getEXP() > 200 && c.R.getEXP()<400) {

		c.R.setLevel(4);
	}
	else if (c.R.getEXP() > 400 && c.R.getEXP()<800) {

		c.R.setLevel(5);
	}
	else if (c.R.getEXP() > 800 && c.R.getEXP()<1600) {

		c.R.setLevel(6);
	}
}
