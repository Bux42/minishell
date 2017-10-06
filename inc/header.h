/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 03:22:54 by videsvau          #+#    #+#             */
/*   Updated: 2017/10/06 17:24:37 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H

# define HEADER_H
# include "../libft/inc/libft.h"
# include <dirent.h>

typedef struct		s_bin
{
	char			**binpath;
	char			**env2;
	DIR				*od;
	pid_t			father;
	int				i;
	int				s;
	char			*exe;
	struct dirent	*fl;
}					t_bin;

int					g_ctrl;

void				add_env_exe(char **input, int i, t_list *chain);
int					contains(char *str, char c);
void				add_env(char **input);
int					valid_env(char *str);
void				free_list(t_list *env);
int					path_exe(char *path);
void				illegal_option(char *str);
void				check_input(char **input);
int					contains_env(t_list **env, char *prefix);
void				signal_event(int signo);

char				*bin_path(char *path, char *command);
char				**get_path(t_list **env);
char				**list_to_char(t_list **env);
void				free_char_array(char **env);
int					matching_name(char *env, char *name);
int					replace_var(char **input, t_list **env);
char				*replace_input(char *content);
char				*shlvl(char *content);
char				*new_env(char **input);

t_list				*alloc_env(char **env);
int					print_env(t_list **env, char **input);
int					set_env(char **input, t_list **env);
int					unset_env(char **input, t_list **env);
int					remove_between(t_list **cp, t_list **tmp);
int					remove_first(t_list **env, t_list **cp);
void				update_env(t_list *cp, char *env, char *value);

char				**custom_split(char *s);
char				*count_letters(int i, char *s);
int					right_pos(int j, char *s);
int					count_words(char *s);
int					space_char(char c);

int					special_command(char **input, t_list **env, char *str);
void				routine(t_list **env, char **input);
void				find_bin(t_list **env, char **input);
void				exe_bin(t_bin bin, t_list **env, char **input);

void				artificial_setenv(char *env, char *path, t_list **env2);
int					change_dir(char *path, t_list **env);
int					oldpwd(t_list **env);
void				custom_chdir(char *path, t_list **env);
void				change_custom_dir(char *name, char *path, t_list **env);
char				*get_home(t_list **env);
char				*variable_path(char *name, char *value);

int					path_exe(char *path);
int					path_error(char *name);
int					command_error(char *command);

char				*custom_pwd(void);
void				update_newpwd(t_list **env, char *newpwd);
int					print_pwd(void);
int					prompt(void);

int					color(char **input);

#endif
