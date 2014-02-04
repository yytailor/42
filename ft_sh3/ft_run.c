/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 17:53:45 by ytailor           #+#    #+#             */
/*   Updated: 2014/01/28 13:22:26 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh2.h"

char				*ft_checkncut(char *str, char **f)
{
	int				i;
	int				j;
	char			*s;

	i = ft_strlen(str);
	while (str[i] != '/' && i != 0)
		i--;
	if (i == 0)
		return (NULL);
	*f = ft_strnew(ft_strlen(str) - i + 1);
	j = -1;
	s = ft_strnew(i + 1);
	while (++j < i)
		s[j] = str[j];
	i = -1;
	j++;
	while (j != ((int)ft_strlen(str)))
	{
		(*f)[++i] = str[j];
		j++;
	}
	return (s);
}

int					ft_slash_search(char *str)
{
	int				i;

	i = ft_strlen(str);
	while (str[i] != '/' && i != 0)
		i--;
	if (i == 0)
		return (0);
	return (1);
}

int					ft_checkpath(char **tab, char **env, char **path)
{
	char			*f;
	char			*path2;

	if ((path2 = ft_checkncut(tab[0], &f)) != NULL)
	{
		if (((*path) = ft_error(f, env)) == NULL)
			return (0);
		if (ft_strcmp(path2, (*path)) == 0)
			return (1);
	}
	ft_putstr("ft_minishell2: command not found: ");
	ft_putendl(tab[0]);
	return (0);
}
