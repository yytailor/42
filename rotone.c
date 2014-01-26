/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 11:59:10 by ytailor           #+#    #+#             */
/*   Updated: 2014/01/21 12:08:25 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		ft_putchar(str[i]);
}

void		ft_rotone(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] >= 65 && str[i] <= 90)
		{
			str[i] = str[i] + 1;
			if (str[i] == 91)
				str[i] = 65;
		}

		if (str[i] >= 97 && str[i] <= 122)
		{
			str[i] = str[i] + 1;
			if (str[i] == 123)
				str[i] = 97;
		}
		ft_putchar(str[i]);
	}
}

int			main(int ac, char **av)
{
	if (ac == 2)
		ft_rotone(av[1]);
	ft_putchar('\n');
	return (0);
}
