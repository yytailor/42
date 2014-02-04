/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 17:42:44 by ytailor           #+#    #+#             */
/*   Updated: 2014/01/26 18:47:32 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh2.h"

int			ft_count_env(const t_env *list)
{
	int		i;

	i = 0;
	while (list != NULL)
	{
		i++;
		list = list->next;
	}
	return (i);
}

int			*ft_count_line(const t_env *list, const int i)
{
	int		*tab;

	tab = (int*)malloc(sizeof(int) * i);
	while (list->next != NULL)
	{
		tab[i - 1] = ft_strlen(list->name);
		tab[i - 1] += ft_strlen(list->value);
		tab[i - 1] += 1;
		list = list->next;
	}
	return (tab);
}

char		**ft_get_list(const t_env *list)
{
	char	**env;
	int		*tab_line;
	int		linum;
	int		i;

	i = 0;
	linum = ft_count_env(list);
	env = (char **)malloc(sizeof(char*) * linum);
	tab_line = ft_count_line(list, linum);
	while (list != NULL)
	{
		env[i] = (char *)malloc(sizeof(char) * tab_line[i]);
		env[i] = ft_strjoin(list->name, "=");
		env[i] = ft_strjoin(env[i], list->value);
		list = list->next;
		i++;
	}
	return (env);
}
