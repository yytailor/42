/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 18:39:22 by ytailor           #+#    #+#             */
/*   Updated: 2014/01/26 17:57:08 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh2.h"

int					main(void)
{
	char			*line;
	t_env			*list;

	if (ft_init(&list) == 0)
		return (0);
	while (get_next_line(0, &line))
	{
		if (ft_operator(list, line) == 0)
		{
			if (*line == '\0' || ft_check_line(line))
				ft_putstr("$>");
			else
			{
				ft_while(line, list);
				ft_putstr("$>");
			}
		}
		else
			ft_putstr("$>");
	}
	return (0);
}

int					ft_run(char **tab, char **env)
{
	char			*path;
	int				flag;

	if (ft_slash_search(tab[0]) == 1)
	{
		if ((flag = ft_checkpath(tab, env, &path)) == 0)
			return (0);
	}
	else if ((path = ft_error(tab[0], env)) == NULL)
		return (0);
	ft_fork(tab, env, flag, path);
	return (1);
}

int					ft_fork(char **tab, char **env, int flag, char *path)
{
	pid_t			parent;
	int				*status;
	char			*str;

	parent = fork();
	status = 0;
	if (parent > 0)
		wait(status);
	if (parent == 0)
	{
		path = ft_strjoin(path, "/");
		if (flag == 1)
			execve(tab[0], tab, env);
		else
		{
			str = ft_strjoin(path, tab[0]);
			execve(str, tab, env);
		}
	}
	return (0);
}
