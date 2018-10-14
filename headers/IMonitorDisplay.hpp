// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   IMonitorDisplay.hpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: dpozinen <dpozinen@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/13 17:44:02 by dpozinen          #+#    #+#             //
//   Updated: 2018/10/13 17:44:03 by dpozinen         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef IMONDISP_HPP
# define IMONDISP_HPP
# include <iostream>

class IMonitorDisplay
{
	virtual void create_frame(void) = 0;
	virtual void start_ncurses(void) = 0;
	virtual int use_color(void) = 0;
	virtual void end_win(void) = 0;
	// void	score(int score, int level, int life, int enem, int hp);
	// void	help(void);
	virtual void data(void) = 0;
	virtual void general(std::string name, std::string ver, std::string buld) = 0;
	virtual void ram(void) = 0;
	virtual void cpu(void) = 0;
};

#endif