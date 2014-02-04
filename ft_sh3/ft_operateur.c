/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operateur.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 18:24:02 by ytailor           #+#    #+#             */
/*   Updated: 2014/01/26 18:33:07 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_sh2.h"
#include <fcntl.h>

int				ft_operator(t_env *list, char *line)
{
	int			i;
	char		*first;
	char		*second;

	i = -1;
	while (line[++i] != '\0')
	{
		if (line[i] == ';' && i > 0 && line[i + 1])
		{
			first = ft_strnew(i);
			first = ft_strncpy(first, line, (i - 1));
			line += i + 1;
			second = ft_strnew(ft_strlen(line));
			second = ft_strcpy(second, line);
			if (ft_check_line(first) == 0)
				ft_while(first, list);
			if (ft_operator(list, second) == 0 && ft_check_line(second) == 0)
				ft_while(second, list);
			return (1);
		}
	}
	return (0);
}

int				ft_redir(char *str, t_env *list)
{
	int			i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '<' && str[i + 1] != '<')
			return (ft_redirect_left(str, list));
		if (str[i] == '<' && str[i + 1] == '<')
			return (1);
		if (str[i] == '>' && str[i + 1] == '>')
			return (ft_redirect_right(str, list, 2));
		if (str[i] == '>' && str[i + 1] != '>')
			return (ft_redirect_right(str, list, 1));
		i++;
	}
	return (0);
}

void			ft_open_files(char **file, int *fd, int flag)
{
	int			i;

	i = -1;
	if (flag == 1)
	{
		while (file[++i])
			fd[i] = open(file[i], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	if (flag == 2)
	{
		while (file[++i])
			fd[i] = open(file[i], O_WRONLY | O_CREAT | O_APPEND, 0644);
	}
	if (flag == 3)
	{
		while (file[++i])
			fd[i] = open(file[i], O_RDONLY | O_APPEND, 0644);
	}
}

int				ft_write_file(char *cm, char *str, t_env *list, int flag)
{
	char		**file;
	int			i;
	int			*fd;
	int			save;

	file = ft_strsplit(str, '>');
	i = -1;
	while (file[++i])
		file[i] = cut_file(file[i]);
	fd = (int*)malloc(sizeof(int) * i);
	ft_open_files(file, fd, flag);
	save = dup(1);
	i = -1;
	while (fd[++i])
	{
		dup2(fd[i], 1);
		ft_run(ft_strsplit(cm, ' '), ft_get_list(list));
	}
	dup2(save, 1);
	i = -1;
	while (fd[++i])
		close(fd[i]);
	return (1);
}

int				ft_redirect_right(char *str, t_env *list, int flag)
{
	int			i;
	char		*first;
	char		*second;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '>' && str[i + 1] != '>')
		{
			first = ft_strnew(i);
			first = ft_strncpy(first, str, (i - 1));
			str += i + 2;
			second = ft_strnew(ft_strlen(str));
			second = ft_strcpy(second, str);
			if (ft_check_line(first) == 0 &&
				ft_error(*ft_strsplit(first, ' '), ft_get_list(list)) != NULL)
				return (ft_write_file(first, second, list, flag));
			return (0);
		}
	}
	return (0);
}
