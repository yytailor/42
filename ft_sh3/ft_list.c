/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 18:38:21 by ytailor           #+#    #+#             */
/*   Updated: 2014/01/25 14:33:25 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh2.h"

t_env			*create_data(char *env)
{
	t_env		*tmp;

	tmp = (t_env *)malloc(sizeof(t_env));
	tmp->name = ft_cut_name(env);
	tmp->egal = '=';
	tmp->value = ft_cut_value(env);
	tmp->prev = NULL;
	tmp->next = NULL;
	return (tmp);
}

t_env			*insert_data(t_env *list, char *env)
{
	t_env		*tmp;
	t_env		*new_element;

	tmp = list;
	new_element = create_data(env);
	if (list == NULL)
		return (new_element);
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_element;
		new_element->prev = tmp;
	}
	return (list);
}

char			*ft_cut_name(char *env)
{
	char		*tmp;
	int			i;

	i = ft_strchr_count(env, '=');
	tmp = ft_strndup(env, i);
	return (tmp);
}

char			*ft_cut_value(char *env)
{
	char		*tmp;

	tmp = ft_strchr(env, '=');
	tmp = tmp + 1;
	return (tmp);
}

int				ft_strchr_count(const char *s, int c)
{
	int			i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}
