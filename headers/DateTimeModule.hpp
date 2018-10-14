// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   DateTimeModule.hpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: dpozinen <dpozinen@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/14 09:40:18 by dpozinen          #+#    #+#             //
//   Updated: 2018/10/14 09:40:19 by dpozinen         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef DATETIMEMODULE_HPP
# define DATETIMEMODULE_HPP

#include "header.hpp"

class	DateTimeModule : public IMonitorModule
{
	private:
		// std::string _dateTime; // Sun Oct 14 12:46:58 2018
		std::string _date; // Sun Oct 14 12:46:58 2018
		std::string _time; // Sun Oct 14 12:46:58 2018

	public:
		DateTimeModule();
		~DateTimeModule();
		void	update(void);
		void	makeAll(void);
		void	makeDate(void);
		void	makeTime(void);
		std::string	getDate(void) const;
		std::string	getTime(void) const;
};

#endif