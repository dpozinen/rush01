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

SRC = main.cpp
SRCDIR = src
SRCS = $(addprefix $(SRCDIR)/, $(SRC:.cpp=.o))

HRSDIR = headers

OBJDIR = objects
OBJS = $(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJS) $(HRSDIR)/*
	@g++ $(FLAGS) -lncurses $(OBJS) -o $(NAME) -I $(HRSDIR)

$(OBJS) : $(OBJDIR)/%.o : $(SRCDIR)/%.cpp $(HRSDIR)/*
	@g++ $(FLAGS) -o $@ -c $< -I $(HRSDIR)

$(OBJDIR):
	@mkdir $(OBJDIR)

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean $(NAME)