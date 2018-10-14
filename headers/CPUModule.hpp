// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   CPUModule.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: dpozinen <dpozinen@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/14 10:08:37 by dpozinen          #+#    #+#             //
//   Updated: 2018/10/14 10:08:38 by dpozinen         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef CPUMODULE_HPP
# define CPUMODULE_HPP

#include "header.hpp"

class	CPUModule : public IMonitorModule
{
	private:
		std::string		_generalInfo; // Intel(R) Core(TM) i5-6500 CPU @ 3.20GHz
		std::string		_usage; // CPU usage: 26.43% user, 31.3% sys, 42.52% idle

	public:
		CPUModule();
		~CPUModule();

		void			makeAll(void);
		void			update(void);
		void			makeGeneralInfo(void);
		void			makeUsage(void);
		std::string		getUsage(void) const;
		std::string		getGeneralInfo(void) const;

};

#endif