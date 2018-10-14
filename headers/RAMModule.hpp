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
		std::string		_curUsed; // PhysMem: 8162M used (1496M wired), 28M unused.
		std::string		_fullSize; // 8192

	public:
		void	update(void);
		void	makeAll(void);
		void	makeCurUsed(void);
		void	makeFullSize(void);
		std::string	getCurUsed(void) const;
		std::string	getFullSize(void) const;
};

#endif