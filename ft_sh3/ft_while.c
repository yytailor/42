/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_while.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 18:38:34 by ytailor           #+#    #+#             */
/*   Updated: 2014/01/26 18:03:19 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh2.h"

int			ft_cd_check(char *line)
{
	if (ft_strncmp(line, "cd", 2) == 0)
	{
		if (line[2] == '\0' || line[2] == ' ')
			return (0);
	}
	return (-1);
}

void		ft_while(char *line, t_env *list)
{
	if (ft_redir(line, list) == 0)
	{
		if (ft_strcmp(line, "exit") == 0 || ft_strcmp(line, "quit") == 0)
			exit(0);
		if (ft_strncmp(line, "setenv", 6) == 0)
			ft_setenv(list, ft_strsplit(line, ' '), line);
		else if (ft_strncmp(line, "unsetenv", 8) == 0)
			ft_unsetenv(&list, ft_strsplit(line, ' '), line);
		else if (ft_strcmp(line, "env") == 0)
			ft_print_list(list);
		else if ((ft_cd_check(line)) == 0)
			ft_change_directory(&list, ft_strsplit(line, ' '), line);
		else
			ft_run(ft_strsplit(line, ' '), ft_get_list(list));
	}
}

char		*ft_searchenv(char **env, char *s)
{
	char	*pos;
	int		count;

	while (*env && *s)
	{
		count = 0;
		if ((pos = ft_strchr(*env, '=')))
		{
			count = ft_strlen(*env) - ft_strlen(pos);
			if (ft_strncmp(*env, s, count) == 0)
				return (*env + count + 1);
		}
		env++;
	}
	return (NULL);
}

char		*ft_error(char *tab, char **env)
{
	char	*str;
	char	*path;

	path = ft_searchenv(env, "PATH");
	if ((str = ft_check_argv(tab, path)) == NULL)
	{
		ft_putstr("ft_minishell2: command not found: ");
		ft_putendl(tab);
		return (NULL);
	}
	return (str);
}

char		*ft_check_argv(char *argv, char *path)
{
	DIR				*file;
	struct dirent	*temp;
	char			**value;
	int				i;

	i = 0;
	value = ft_strsplit(path, ':');
	while (value[i] != '\0')
	{
		if ((file = opendir(value[i])) == NULL)
			return (NULL);
		while ((temp = readdir(file)))
		{
			if (ft_strcmp(argv, temp->d_name) == 0)
				return (value[i]);
		}
		i++;
	}
	return (NULL);
}
