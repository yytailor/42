/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operateur2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 17:48:46 by ytailor           #+#    #+#             */
/*   Updated: 2014/01/26 18:45:00 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh2.h"

int				ft_read_in(char *cm, char *str, t_env *list)
{
	char		**file;
	int			i;
	int			*fd;
	int			save;

	file = ft_strsplit(str, '<');
	i = -1;
	while (file[++i])
		file[i] = cut_file(file[i]);
	fd = (int*)malloc(sizeof(int) * i);
	ft_open_files(file, fd, 3);
	save = dup(0);
	i = -1;
	while (fd[++i])
	{
		dup2(fd[i], 0);
		ft_run(ft_strsplit(cm, ' '), ft_get_list(list));
	}
	dup2(save, 0);
	i = -1;
	while (fd[++i])
		close(fd[i]);
	return (1);
}

int				ft_redirect_left(char *str, t_env *list)
{
	int			i;
	char		*first;
	char		*second;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '<' && str[i + 1] != '<')
		{
			first = ft_strnew(i);
			first = ft_strncpy(first, str, (i - 1));
			str += i + 2;
			second = ft_strnew(ft_strlen(str));
			second = ft_strcpy(second, str);
			if (ft_check_line(first) == 0 &&
				ft_error(*ft_strsplit(first, ' '), ft_get_list(list)) != NULL)
				return (ft_read_in(first, second, list));
			return (0);
		}
	}
	return (0);
}
