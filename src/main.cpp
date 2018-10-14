#include "header.hpp"

#include "OSModule.hpp"
#include "HostUserModule.hpp"
#include "DateTimeModule.hpp"
#include "CPUModule.hpp"
#include "RAMModule.hpp"
#include "Ncurses.hpp" //in header
#include "SDL.hpp"


void initModules(std::vector<IMonitorModule *> *modules)
{
	(*modules).push_back(new DateTimeModule());
	(*modules).push_back(new HostUserModule());
	(*modules).push_back(new OSModule());
	(*modules).push_back(new CPUModule());
	(*modules).push_back(new RAMModule());

	std::vector<IMonitorModule *>::iterator it;
	for (it = (*modules).begin(); it != (*modules).end(); ++it)
		(*it)->makeAll();
}

void delModules(std::vector<IMonitorModule *> modules)
{
	std::vector<IMonitorModule *>::iterator it;

	for (it = modules.begin(); it != modules.end(); ++it)
		delete *it;
}

bool getFlag(int ac, char **args)
{
	if (ac == 1)
		return false; // default view == ncurses
	if (!strcmp(args[1], "-g"))
		return true;
	return false;
}

int main(int ac, char **argv)
{
	Ncurses nc;
	SDL		sdl;

	unsigned int _usleep;
	_usleep = 40000;

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
	keypad(stdscr, true);
	int k = 0;

	bool graphical = getFlag(ac, argv);
	std::vector<IMonitorModule *> modules;
	std::vector<IMonitorModule *>::iterator it;

	(void)graphical;

	initModules(&modules);
	int i = 0;
	while (1)
	{
		k = getch();
		if (k == 27)
			break;
		for (it = modules.begin(); it != modules.end(); ++it)
		{
			if (!graphical)
				(*it)->update(nc);
			else
				(*it)->update(sdl);
		}
		timeout(0);
		usleep(_usleep);

		move(42, 2);
		attron(COLOR_PAIR(2));
		printw("ESC to exit                          ");
		attroff(COLOR_PAIR(2));
		i++;
	}
	delModules(modules);
	nc.end_win();

	return 0;
}
