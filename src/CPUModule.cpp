// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   CPUModule.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: dpozinen <dpozinen@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/14 10:08:24 by dpozinen          #+#    #+#             //
//   Updated: 2018/10/14 10:08:24 by dpozinen         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "CPUModule.hpp"

CPUModule::CPUModule(){
}

CPUModule::~CPUModule(){
}

void	CPUModule::makeAll()
{
	makeUsage();
}

void	CPUModule::update()
{
	makeUsage();
}

void	CPUModule::makeGeneralInfo()
{
	FILE *pipe = popen("sysctl -n machdep.cpu.brand_string", "r");
	char	generalInfo[256];

	if (!pipe)
		return ; // TODO: throw
	while (!feof(pipe))
		fgets(generalInfo, 256, pipe);
	_generalInfo = generalInfo;
	pclose(pipe);
}

void	CPUModule::makeUsage()
{
	FILE *pipe = popen("top -l 1 -n0 | grep -E \"^CPU\"", "r");
	char	usage[256];

	if (!pipe)
		return ; // TODO: throw
	while (!feof(pipe))
		fgets(usage, 256, pipe);
	_usage = usage;
	pclose(pipe);
}

std::string	CPUModule::getGeneralInfo(void) const {
	return _generalInfo;
}

std::string	CPUModule::getUsage() const {
	return _usage;
}