// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SDL.hpp			                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: dpozinen <dpozinen@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/13 17:46:35 by dpozinen          #+#    #+#             //
//   Updated: 2018/10/13 17:46:35 by dpozinen         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SDL_HPP
# define SDL_HPP

#include "IMonitorDisplay.hpp"

class	SDL : public IMonitorDisplay
{
	public:
		SDL();
		~SDL();
		void end_win(void);
		int use_color(void);
		void create_frame(void);
		void start_ncurses(void);
		// void	score(int score, int level, int life, int enem, int hp);
		// void	help(void);
		void data(std::string data, std::string time);
		void cpu(std::string info, std::string u_usage);
		void general(std::string name, std::string ver, std::string buld);
		void ram(std::string all_ram, std::string used, std::string unused);
};

#endif