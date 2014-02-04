/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 18:35:53 by ytailor           #+#    #+#             */
/*   Updated: 2014/01/26 18:27:29 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh2.h"

void		ft_print_list(const t_env *list)
{
	while (list != NULL)
	{
		ft_putstr(list->name);
		ft_putchar('=');
		ft_putendl(list->value);
		list = list->next;
	}
}

void		ft_setenv(t_env *list, char **tab, char *line)
{
	t_env	*tmp;

	if (ft_count_word(line, ' ') != 4)
	{
		ft_putstr("ft_minishell2: setenv usage : name value overwrite\n");
		return ;
	}
	tmp = list;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->name, tab[1]) == 0)
		{
			if (ft_strcmp(tab[3], "1") == 0)
				tmp->value = tab[2];
			return ;
		}
		tmp = tmp->next;
	}
	tmp = insert_env(list, tab[1], tab[2]);
}

void		ft_unsetenv(t_env **list, char **tab, char *line)
{
	t_env	*tmp;

	tmp = *list;
	if (ft_count_word(line, ' ') != 2)
	{
		ft_putstr("ft_minishell2 : unsetenv usage : name\n");
		return ;
	}
		while (tmp != NULL)
		{
			if (ft_strcmp(tmp->name, tab[1]) == 0)
			{
				if (tmp->prev == NULL)
					*list = (*list)->next;
				if (tmp->prev != NULL)
					(tmp->prev)->next = tmp->next;
				if (tmp->next != NULL)
					(tmp->next)->prev = tmp->prev;
				return ;
			}
			tmp = tmp->next;
		}
}

t_env		*create_env(char *name, char *value)
{
	t_env	*tmp;

	tmp = (t_env *)malloc(sizeof(t_env));
	tmp->name = name;
	tmp->egal = '=';
	tmp->value = value;
	tmp->prev = NULL;
	tmp->next = NULL;
	return (tmp);
}

t_env		*insert_env(t_env *list, char *name, char *value)
{
	t_env	*tmp;
	t_env	*new_element;

	tmp = list;
	new_element = create_env(name, value);
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
