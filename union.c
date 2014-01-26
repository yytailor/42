/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 13:16:28 by ytailor           #+#    #+#             */
/*   Updated: 2014/01/21 15:16:45 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

int			ft_check_c(char *s, char c, int pos)
{
	int		i;
	int		nb;

	i = -1;
	nb = 0;
	while (s[++i])
	{
		if (s[i] == c)
			nb++;
	}
	if (nb > 1)
	{
		pos--;
		while (s[pos])
		{
			if (s[pos] == c)
				return (nb);
			pos--;
		}
		return (1);
	}
	return (nb);
}

void		ft_union(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i])
	{
		if (ft_check_c(s1, s1[i], i) == 1)
			ft_putchar(s1[i]);
		i++;
	}
	i = 0;
	while (s2[i])
	{
		if (ft_check_c(s1, s2[i], i) == 0 && ft_check_c(s2, s2[i], i) == 1)
			ft_putchar(s2[i]);
		i++;
	}
}

int			main(int ac, char **av)
{
	if (ac == 3)
	{
		ft_union(av[1], av[2]);
	}
	ft_putchar('\n');
	return (0);
}
