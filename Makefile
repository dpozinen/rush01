#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpozinen <dpozinen@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/01 09:34:59 by dpozinen          #+#    #+#              #
#    Updated: 2018/10/01 09:34:59 by dpozinen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = monitor

SRC = main.cpp OSModule.cpp HostUserModule.cpp DateTimeModule.cpp CPUModule.cpp Ncurses.cpp
SRCDIR = src
SRCS = $(addprefix $(SRCDIR)/, $(SRC:.cpp=.o))

NCUR = -lncurses

HRSDIR = headers

OBJDIR = objects
OBJS = $(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))

FLAGS = -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJS) $(HRSDIR)/*
	@clang++ $(FLAGS) -lncurses $(OBJS) -o $(NAME) -I $(HRSDIR)

$(OBJS) : $(OBJDIR)/%.o : $(SRCDIR)/%.cpp $(HRSDIR)/*
	@clang++ $(FLAGS) -o $@ -c $< -I $(HRSDIR)

$(OBJDIR):
	@mkdir $(OBJDIR)

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean $(NAME)