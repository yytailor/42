/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_directory.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 18:38:00 by ytailor           #+#    #+#             */
/*   Updated: 2014/01/28 13:24:40 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh2.h"

void		ft_cd(t_env **env, char *buf, size_t size, int i)
{
	if (i == 1)
	{
		chdir(ft_search_name(*env, "OLDPWD"));
		ft_setenv_cpy(env, "OLDPWD", ft_search_name(*env, "PWD"));
		ft_setenv_cpy(env, "PWD", getcwd(buf, size));
	}
	else if (i == 2)
	{
		chdir(ft_search_name(*env, "HOME"));
		ft_setenv_cpy(env, "OLDPWD", ft_search_name(*env, "PWD"));
		ft_setenv_cpy(env, "PWD", getcwd(buf, size));
	}
}


void		ft_change_directory(t_env **env, char **argv, char *line)
{
	char	*buf;
	size_t	size;
	int		count;

	buf = NULL;
	size = 0;
	if ((count = ft_count_word(line, ' ')) <= 2)
	{
		if (count == 2)
		{
			if (ft_strcmp(argv[1], "-") == 0)
				ft_cd(env, buf, size, 1);
			if (ft_check_folder(argv[1]) == 0)
				return ;
			chdir(argv[1]);
			ft_setenv_cpy(env, "OLDPWD", ft_search_name(*env, "PWD"));
			ft_setenv_cpy(env, "PWD", getcwd(buf, size));
		}
		else
			ft_cd(env, buf, size, 2);
	}
}

int			ft_check_folder(char *argv)
{
	if (ft_strcmp(argv, "-") != 0)
	{
		if (access(argv, F_OK) == -1)
		{
			ft_printf("cd: no such file or directory: %s\n", argv);
			return (0);
		}
		if (access(argv, R_OK) == -1)
		{
			ft_printf("cd: permission denied: %s\n", argv);
			return (0);
		}
	}
	return (1);
}

char		*ft_search_name(t_env *env, char *name)
{
	t_env	*tmp;

	tmp = env;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->name, name) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return ("error");
}

void		ft_setenv_cpy(t_env **list, char *name, char *value)
{
	t_env	*tmp;

	tmp = *list;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->name, name) == 0)
		{
			tmp->value = value;
			return ;
		}
		tmp = tmp->next;
	}
}
