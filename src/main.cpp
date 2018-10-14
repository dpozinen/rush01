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

void	initModules(std::vector<IMonitorModule*> *modules)
{
	(*modules).push_back(new DateTimeModule());
	(*modules).push_back(new HostUserModule());
	(*modules).push_back(new OSModule());
	(*modules).push_back(new CPUModule());
}

void	delModules(std::vector<IMonitorModule*> modules)
{
	delete modules[0];
	delete modules[1];
	delete modules[2];
	delete modules[3];
}

int		main(void)
{
	std::vector<IMonitorModule*> modules;
	std::vector<IMonitorModule*>::iterator it;

	initModules(&modules);

	for (it = modules.begin(); it != modules.end(); ++it)
		(*it)->makeAll();

	int i = 0;
	while (i < 5) // while true
	{
		for (it = modules.begin(); it != modules.end(); ++it)
			(*it)->update();
		// print() ?;
		std::cout << i << std::endl;
		i++;
	}
	delModules(modules);
	// OSModule om;

	// om.makeAll();
	// std::cout << om.getName();
	// std::cout << om.getVersion();
	// std::cout << om.getBuild();

	// HostUserModule hsm;
	// hsm.makeAll();
	// std::cout << hsm.getHostName() << std::endl;
	// std::cout << hsm.getUserName() << std::endl;

	// DateTimeModule dtm;
	// dtm.makeAll();
	// std::cout << dtm.getDateTime() << std::endl;
	// sleep(1);
	// dtm.update();
	// std::cout << dtm.getDateTime() << std::endl;
	// sleep(1);
	// dtm.update();
	// std::cout << dtm.getDateTime() << std::endl;

	// CPUModule cpum;
	// cpum.makeAll();
	// cpum.makeGeneralInfo();
	// for (int i = 0; i < 5; i++)
	// {
		// std::cout << cpum.getUsage();
		// std::cout << cpum.getGeneralInfo();
	// 	cpum.update();
	// }


	return 0;
}