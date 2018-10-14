
#ifndef NCURSES_HPP
# define NCURSES_HPP

#include <ncurses.h>
#include <iostream>
#include "IMonitorDisplay.hpp"

class Ncurses : public IMonitorDisplay
{
public:
	WINDOW	*win;
	void	create_frame(void);
	void	start_ncurses(void);
	int		use_color(void);
	void	end_win(void);
	// void	score(int score, int level, int life, int enem, int hp);
	// void	help(void);
	void	data(void);
	void	general(void);
	void	ram(void);
	void	cpu(void);
	Ncurses();
	~Ncurses();
};


#endif