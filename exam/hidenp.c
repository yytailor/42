/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 12:18:34 by ytailor           #+#    #+#             */
/*   Updated: 2014/01/21 13:10:56 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void        ft_putchar(char c)
{
    write(1, &c, 1);
}

void        ft_putstr(char *str)
{
    int     i;

    i = -1;
    while (str[++i])
		ft_putchar(str[i]);
}

int			ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int			ft_hidenp(char *str1, char *str2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str2[i])
	{
		if (str2[i] == str1[j])
			j++;
		i++;
	}
	if (str1 && j == ft_strlen(str1))
		return (1);
	return (0);
}

int			main(int ac, char **av)
{
	if (ac == 3)
	{
		if (ft_hidenp(av[1], av[2]) == 1)
			ft_putchar('1');
		else
			ft_putchar('0');
	}
	ft_putchar('\n');
	return (0);
}
