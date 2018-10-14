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
// top -l 1 -n0 | grep -e "Processes" -e "CPU usage"
class	CPUModule : public IMonitorModule
{
	private:
		std::string		_generalInfo;
		// std::string		_topOutput;
		// std::string		_processes;
		std::string		_usage; // top -l 1 | grep "CPU usage"

	public:
		CPUModule();
		~CPUModule();

		void			makeAll(void);
		void			update(void);
		void			makeGeneralInfo(void);
		// void		makeProcesses(void);
		void			makeUsage(void);
		std::string		getUsage(void) const;
		std::string		getGeneralInfo(void) const;

};

#endif