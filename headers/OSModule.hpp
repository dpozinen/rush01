// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   OSModule.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: dpozinen <dpozinen@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/13 19:17:50 by dpozinen          #+#    #+#             //
//   Updated: 2018/10/13 19:17:50 by dpozinen         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef OSMODULE_HPP
# define OSMODULE_HPP

#include <sys/types.h>
#include <sys/sysctl.h>
#include "IMonitorModule.hpp"
#include "header.hpp"

class	OSModule : public IMonitorModule
{
	private:
		std::string		_name;
		std::string		_version;
		std::string		_build;

	public:
		OSModule();
		~OSModule();
		void		makeName(void);
		void		makeVersion(void);
		void		makeBuild(void);
		std::string getName(void) const;
		std::string getBuild(void) const;
		std::string getVersion(void) const;
};

#endif