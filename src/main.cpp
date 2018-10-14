// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: dpozinen <dpozinen@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/13 17:24:22 by dpozinen          #+#    #+#             //
//   Updated: 2018/10/13 17:24:22 by dpozinen         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "header.hpp"

#include "OSModule.hpp"
#include "HostUserModule.hpp"
#include "DateTimeModule.hpp"
#include "CPUModule.hpp"

#include "Ncurses.hpp" //in header

void	initModules(std::vector<IMonitorModule*> *modules)
{
	(*modules).push_back(new DateTimeModule());
	(*modules).push_back(new HostUserModule());
	(*modules).push_back(new OSModule());
	(*modules).push_back(new CPUModule());

	std::vector<IMonitorModule*>::iterator it;
	for (it = (*modules).begin(); it != (*modules).end(); ++it)
		(*it)->makeAll();
}

void	delModules(std::vector<IMonitorModule*> modules)
{
	std::vector<IMonitorModule*>::iterator it;

	for (it = modules.begin(); it != modules.end(); ++it)
		delete *it;
}

bool	getFlag(int ac, char **args)
{
	if (ac == 1)
		return false; // default view == ncurses
	if (!strcmp(args[1], "-g"))
		return true;
	return false;
}

int		main(int ac, char **args)
{
	Ncurses nc;
	// DateTimeModule dt;

	nc.start_ncurses();
	if (nc.use_color() == -1)
	{
		return (-1);
	}
	nc.create_frame();
	move(42, 2);
	attron(COLOR_PAIR(1));
	printw("Press any button to start!");
	attroff(COLOR_PAIR(1));
	nc.data();
	nc.general();
	nc.cpu();
	nc.ram();
	keypad(stdscr, true);
	int k = 0;

	/* global ? */ bool	graphical = getFlag(ac, args);
	std::vector<IMonitorModule*> modules;
	std::vector<IMonitorModule*>::iterator it;

	(void)graphical;

	initModules(&modules);

	int i = 0;
	// while (i < 5) // while true
	// {
	// 	for (it = modules.begin(); it != modules.end(); ++it)
	// 		(*it)->update();
	// 	// print() ?;
	// 	std::cout << i << std::endl;
	// 	i++;
	// }
	// printf("1_nc\n");

	while (1)
	{
		k = getch();
		if (k == 27)
			break;
		for (it = modules.begin(); it != modules.end(); ++it)
		{
			(*it)->update();
			
		}
		// print() ?;
		// std::cout << i << std::endl;
		i++;
	}
	delModules(modules);
	nc.end_win();

	return 0;
}