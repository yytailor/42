/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 13:09:02 by ytailor           #+#    #+#             */
/*   Updated: 2014/01/26 18:45:43 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH2_H
# define FT_SH2_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <dirent.h>
# include "libft/includes/libft.h"

extern char			**environ;

typedef struct		s_env
{
	struct s_env	*prev;
	struct s_env	*next;
	char			*name;
	char			egal;
	char			*value;
}					t_env;

/*
** main.c
*/
int					ft_run(char **tab, char **env);
int					ft_fork(char **tab, char **env, int flag, char *path);

/*
** ft_init.c
*/
int					ft_init(t_env **list);
int					ft_check_line(const char *str);
t_env				*ft_insert_env(char **env);
char				*cut_file(char *s);

/*
** ft_run.c
*/

char				*ft_checkncut(char *str, char **f);
int					ft_slash_search(char *str);
int					ft_checkpath(char **tab, char **env, char **path);

/*
** ft_list.c
*/
char				*ft_cut_name(char *env);
char				*ft_cut_value(char *env);
int					ft_strchr_count(const char *s, int c);
t_env				*create_env(char *name, char *value);
t_env				*insert_env(t_env *list, char *name, char *value);

/*
** ft_while.c
*/
int					ft_cd_check(char *line);
void				ft_while(char *line, t_env *list);
char				*ft_searchenv(char **env, char *s);
char				*ft_error(char *tab, char **env);
char				*ft_check_argv(char *argv, char *env);

/*
**  ft_env.c
*/
void				ft_print_list(const t_env *list);
void				ft_setenv(t_env *list, char **tab, char *line);
void				ft_unsetenv(t_env **list, char **tab, char *line);
t_env				*create_data(char *env);
t_env				*insert_data(t_env *list, char *env);

/*
** ft_change_directory.c
*/
void				ft_cd(t_env **env, char *buf, size_t size, int i);
void				ft_change_directory(t_env **env, char **argv, char *line);
int					ft_check_folder(char *argv);
char				*ft_search_name(t_env *env, char *name);
void				ft_setenv_cpy(t_env **list, char *name, char *value);

/*
** ft_list_to_tab.c
*/
char				**ft_get_list(const t_env *list);
int					*ft_count_line(const t_env *list, const int i);
int					ft_count_env(const t_env *list);

/*
** ft_operateur.c
*/
int					ft_operator(t_env *list, char *line);
int					ft_redir(char *str, t_env *list);
int					ft_redirect_right(char *str, t_env *list, int flag);
void				ft_open_files(char **file, int *fd, int flag);
int					ft_write_file(char *cm, char *str, t_env *list, int flag);

/*
** ft_operateur2.c
*/
int					ft_read_in(char *cm, char *str, t_env *list);
int					ft_redirect_left(char *str, t_env *list);

#endif /* !FT_SH2_H */
