/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 17:44:59 by ytailor           #+#    #+#             */
/*   Updated: 2014/01/26 18:05:11 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh2.h"

int					ft_init(t_env **list)
{
	*list = NULL;
	*list = ft_insert_env(environ);
	if (*list == NULL)
	{
		ft_putstr("error : env not found\n");
		return (0);
	}
	ft_putstr("$>");
	return (1);
}

int					ft_check_line(const char *str)
{
	while (*str == ' ')
		str++;
	if (*str == '\0')
		return (1);
	return (0);
}

t_env				*ft_insert_env(char **env)
{
	t_env			*list;
	int				i;

	i = 0;
	list = NULL;
	while (env[i] != '\0')
	{
		list = insert_data(list, env[i]);
		i++;
	}
	return (list);
}

char				*cut_file(char *s)
{
	char			*str;
	int				i;
	int				j;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * ft_strlen(s));
	while (s[i])
	{
		if (s[i] == ' ')
			i++;
		str[j] = s[i];
		i++;
		j++;
	}
	return (str);
}
