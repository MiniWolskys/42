/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/09 06:25:52 by srison            #+#    #+#             */
/*   Updated: 2015/06/14 13:37:20 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"

#define BUFF_SIZE 2048

static void		check_cat(char *str)
{
	int			fd;

	if (!strncmp(str, "null", 4))
		fd = 0;
	else
		fd = open(str, O_RDONLY);
	ft_cat(fd);
}

static void		check_is(void)
{
	int			i = -1;
	int			out = 1;

	while (++i < 128)
	{
		if (ft_isalpha(i) != isalpha(i))
			out	= 0;
		if (ft_isascii(i) != isascii(i))
			out	= 0;
		if (ft_isalnum(i) != isalnum(i))
			out	= 0;
		if (ft_isdigit(i) != isdigit(i))
			out	= 0;
		if (ft_islower(i) != islower(i))
			out	= 0;
		if (ft_isupper(i) != isupper(i))
			out	= 0;
		if (ft_isprint(i) != isprint(i))
			out	= 0;
	}
	printf(!out ? "KO\n" : "OK\n");
}

static void		check_to(char *str)
{
	int		i = -1;

	while (str && str[++i])
	{
		putchar(ft_toupper(str[i]));
		printf(" | ");
		putchar(ft_tolower(str[i]));
		putchar('\n');
	}
}

static void		check_mem(char *str)
{
	char		*s2;
	if (!strncmp(str, "null", 4))
		str = NULL;
	if (str)
	{
		s2 = strdup(str);
		str = malloc(sizeof(*str) * (strlen("Salut") + strlen(str) + 1));
		str = strcat(str, s2);
	}
	s2 = strdup("Salut");
	printf("%s\n", ft_memset(str, 100, 4));
	printf("%s\n", ft_memcpy(str, s2, 5));
	free(s2);
}

static void		check_puts(char *str)
{
	if (!strncmp(str, "null", 4))
		str = NULL;
	ft_puts(str);
}

static void		check_str(char *str)
{
	char		*s2;
	if (!strncmp(str, "null", 4))
		str = NULL;
	printf("%d\n", ft_strlen(str));
	printf("%s\n", ft_strdup(str));
	if (str)
	{
		s2 = strdup(str);
		str = malloc(sizeof(*str) * (strlen("Bouh !") + strlen(str) + 1));
		str = strcat(str, s2);
	}
	s2 = strdup("Salut");
	printf("%d\n", ft_strcmp(str, s2));
	printf("%s\n", ft_strcat(str, s2));
	free(s2);
	printf("%s\n", ft_strcat(str, NULL));
}

int				main(int ac, char **av)
{
	char		*buff = malloc(sizeof(*buff) * BUFF_SIZE + 1);

	strcat(buff, "Empty");
	while (strncmp(buff, "exit", 4))
	{
		printf("\033[0;32mType list for help or one call to test, or exit to leave.\033[0m\n");
		if (!read(0, buff, BUFF_SIZE))
			return (1);
		else if (!strncmp(buff, "list", 4))
			printf("\"is_\"\n\"to_\"\n\"mem\"\n\"puts\"\n\"str\"\n\"cat\"\n");
		else if (!strncmp(buff, "is_", 3))
			check_is();
		else if (!strncmp(buff, "to_", 3))
			check_to(av[ac - 1]);
		else if (!strncmp(buff, "mem", 3))
			check_mem(av[ac - 1]);
		else if (!strncmp(buff, "puts", 4))
			check_puts(av[ac - 1]);
		else if (!strncmp(buff, "str", 3))
			check_str(av[ac - 1]);
		else if (!strncmp(buff, "cat", 3))
			check_cat(av[ac - 1]);
		else if (strncmp(buff, "exit", 4))
			printf("Error, unknow parameter.\n");
	}
	return (0);
}
