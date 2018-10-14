
#include "Ncurses.hpp"

Ncurses::Ncurses(void){}
Ncurses::~Ncurses(void){}

void	Ncurses::create_frame(void)
{
	refresh();
	box(this->win, 0, 0);

	move(4, 2);
	hline('-', 73);

	move(10, 2);
	hline('-', 73);
	wrefresh(win);

	move(17, 2);
	hline('-', 73);

	move(22, 2);
	hline('-', 73);
	wrefresh(win);
}

void	Ncurses::data(void)
{
	move(0, 31);
	printw("SYSTEM INFO");
	move(4, 33);
	printw("GENERAL");
	move(2, 4);
	attron(COLOR_PAIR(4));
	printw("Data : 14.09.18");
	//printw("LEVEL: %d", level);
	attroff(COLOR_PAIR(4));
	move(2, 60);
	attron(COLOR_PAIR(4));
	printw("Time : 13:02");
	attroff(COLOR_PAIR(4));
}

void Ncurses::general(void)
{
	move(6, 6);
	attron(COLOR_PAIR(4));
	printw("host ");
	attroff(COLOR_PAIR(4));
	move(6, 36);
	attron(COLOR_PAIR(4));
	printw("->");
	attroff(COLOR_PAIR(4));
	move(6, 59);
	attron(COLOR_PAIR(4));
	printw("192.168.1.1");
	attroff(COLOR_PAIR(4));

	move(7, 6);
	attron(COLOR_PAIR(4));
	printw("user ");
	attroff(COLOR_PAIR(4));
	move(7, 36);
	attron(COLOR_PAIR(4));
	printw("->");
	attroff(COLOR_PAIR(4));
	move(7, 59);
	attron(COLOR_PAIR(4));
	printw("192.168.1.1");
	attroff(COLOR_PAIR(4));

	move(8, 6);
	attron(COLOR_PAIR(4));
	printw("version ");
	attroff(COLOR_PAIR(4));
	move(8, 36);
	attron(COLOR_PAIR(4));
	printw("->");
	attroff(COLOR_PAIR(4));
	move(8, 59);
	attron(COLOR_PAIR(4));
	printw("1.23v");
	attroff(COLOR_PAIR(4));

	move(10, 35);
	printw("CPU");
}

void Ncurses::cpu(void)
{
	move(12, 6);
	attron(COLOR_PAIR(4));
	printw("CPU ");
	attroff(COLOR_PAIR(4));
	move(12, 36);
	attron(COLOR_PAIR(4));
	printw("->");
	attroff(COLOR_PAIR(4));
	move(12, 59);
	attron(COLOR_PAIR(4));
	printw("I5 7200");
	attroff(COLOR_PAIR(4));

	move(13, 6);
	attron(COLOR_PAIR(4));
	printw("CPU cors ");
	attroff(COLOR_PAIR(4));
	move(13, 36);
	attron(COLOR_PAIR(4));
	printw("->");
	attroff(COLOR_PAIR(4));
	move(13, 59);
	attron(COLOR_PAIR(4));
	printw("4");
	attroff(COLOR_PAIR(4));

	move(14, 6);
	attron(COLOR_PAIR(4));
	printw("CPU threads ");
	attroff(COLOR_PAIR(4));
	move(14, 36);
	attron(COLOR_PAIR(4));
	printw("->");
	attroff(COLOR_PAIR(4));
	move(14, 59);
	attron(COLOR_PAIR(4));
	printw("4");
	attroff(COLOR_PAIR(4));

	move(15, 6);
	attron(COLOR_PAIR(4));
	printw("CPU used ");
	attroff(COLOR_PAIR(4));
	move(15, 36);
	attron(COLOR_PAIR(4));
	printw("->");
	attroff(COLOR_PAIR(4));
	move(15, 59);
	attron(COLOR_PAIR(4));
	printw("13");
	attroff(COLOR_PAIR(4));

	move(17, 35);
	printw("RAM");
}

void Ncurses::ram(void)
{
	move(19, 6);
	attron(COLOR_PAIR(4));
	printw("RAM used ");
	attroff(COLOR_PAIR(4));
	move(19, 36);
	attron(COLOR_PAIR(4));
	printw("->");
	attroff(COLOR_PAIR(4));
	move(19, 59);
	attron(COLOR_PAIR(4));
	printw("30");
	attroff(COLOR_PAIR(4));

	move(20, 6);
	attron(COLOR_PAIR(4));
	printw("RAM free ");
	attroff(COLOR_PAIR(4));
	move(20, 36);
	attron(COLOR_PAIR(4));
	printw("->");
	attroff(COLOR_PAIR(4));
	move(20, 59);
	attron(COLOR_PAIR(4));
	printw("70");
	attroff(COLOR_PAIR(4));

	move(22, 33);
	printw("CPU USED");
}
// void	Ncurses::score(int score, int level, int life, int enem, int hp)
// {
// 	move(2, 3);
// 	printw("SCORE: %d", score * 10);

// 	move(2, 18);
// 	printw("AMMO: %d", hp);

// 	move(2, 30);
// 	printw("LEVEL: %d", level);

// 	move(2, 45);
// 	printw("ENEMY: %d", enem);

// 	move(2, 59);
// 	attron(COLOR_PAIR(4));
// 	printw("LIFE: %d", life);
// 	attroff(COLOR_PAIR(4));
// }

void	Ncurses::start_ncurses(void)
{
	int start_y = 1;
	int start_x = 1;

	initscr(); // Переход в curses-режим
	this->win = newwin(40, 75, start_y, start_x);
	curs_set(0);
}

int		Ncurses::use_color(void)
{
	if (!has_colors())
	{
		printf("sc_1");
		printw("Terminal does not support color");
		getch();
		return (-1);
	}
	printf("sc_1");
	start_color();
	init_pair(1, 5, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	return (0);
}

void	Ncurses::end_win(void)
{
	endwin(); // Выход из curses-режима. Обязательная команда.
}

// void Ncurses::help(void)
// {
// 	move(37, 2);
// 	printw("1. Move left / right - left / right arrow!");
// 	move(38, 2);
// 	printw("2. Shot / Space button!");
// 	move(39, 2);
// 	printw("3. Exit / ESC button!");
// 	move(40, 2);
// 	printw("4. Cheat_mod / C button!");
// 	move(42, 2);
// 	attron(COLOR_PAIR(2));
// 	printw("HAVE FUN :-)");
// 	attroff(COLOR_PAIR(2));
// }