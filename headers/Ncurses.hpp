
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
	void	general(std::string name, std::string ver, std::string buld);
	void	general_help(std::string user, std::string host);
	void	ram(void);
	void	cpu(void);
	Ncurses();
	~Ncurses();
};


#endif