all: build-C

build-C:	main.c ../ex0/ft_strcpy.c ../ex1/ft_strncpy.c ../ex2/ft_strcmp.c ../ex3/ft_strncmp.c ../ex4/ft_strcat.c ../ex5/ft_strncat.c ../ex6/ft_strstr.c	../ex7/ft_atoi.c
	cc -Werror -Wall -Wextra $^ -o Tests-C-Strings-le-Retour
