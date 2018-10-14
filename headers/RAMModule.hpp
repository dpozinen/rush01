// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   RAMModule.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: dpozinen <dpozinen@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/14 13:04:12 by dpozinen          #+#    #+#             //
//   Updated: 2018/10/14 13:04:13 by dpozinen         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef RAMMODULE_HPP
# define RAMMODULE_HPP

#include "header.hpp"

class	RAMModule : public IMonitorModule
{
	private:
		std::string			_used; // 8162M
		std::string			_unused; // 28M unused.
		std::string			_fullSize;

	public:
		RAMModule();
		~RAMModule();
		void	update(Ncurses &nc);
		void	makeAll(void);
		void	makeCurUsed(void);
		void	makeFullSize(void);

		std::string	getUnused(void) const;
		std::string	getUsed(void) const;
		std::string	getFullSize(void) const;
};

#endif