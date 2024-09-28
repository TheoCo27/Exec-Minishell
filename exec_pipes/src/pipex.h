/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:51:13 by tcohen            #+#    #+#             */
/*   Updated: 2024/09/28 19:19:39 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_info_exec
{
	char	*cmd;
	char	*path;
	char	**t_path;
	char	**arg;
	int		pipe_fd[2];
	int		in_out_fd;
	char	**env;
	size_t	index;
	int		pid;
	struct s_info_exec *next;
	struct s_info_exec *prev;
}			t_info_exec;

//ft_child.c
int		ft_cmd_arg(char *cmd, t_info_exec *info);
void	ft_cmd1(t_info_exec *cmd, int fd[2]);
void	ft_cmd2(t_info_exec *cmd, int fd[2]);
int		ft_first_child(char **argv, char **env, int fd[2], t_info_exec *cmd);
int		ft_2nd_child(char **argv, char **env, int fd[2], t_info_exec *cmd);
//ft_path.c
int		ft_getenv_path(char **env, t_info_exec *info);
int		ft_check_ifpath(t_info_exec *info);
int		ft_find_cmd(t_info_exec *info);
int		ft_path(char **env, t_info_exec *info);

//ft_secure.c
int		ft_open(char *file_name, char mode, t_info_exec *info);
int		ft_dup2(int old_fd, int new_fd);
int		ft_execve(t_info_exec *cmd);
int	ft_pipe(int fd[2], t_info_exec	**lst, t_info_exec *cmd);
// ft_all.c
void	ft_close_pipe(int pipe_fd[2]);
void	ft_close_all(int pipe_fd[2], int in_out_fd);
int		ft_wait_pids(t_info_exec *lst);
int		ft_clean_info(t_info_exec *cmd);
//ft_check.c
void	ft_check_argc(int argc);
void	ft_check_argv(char *cmd, int fd[2]);
int		ft_check_if_alpha(char *str);
//ft_set.c
void	ft_set_cmds(t_info_exec *lst, int *fd, char **env);
int		ft_execve_stuff(t_info_exec *info);
// ft_pipe_lst.c
t_info_exec	*ft_pipelst_new(char *cmd);
t_info_exec	*ft_pipelst_last(t_info_exec *lst);
void	ft_pipelst_addback(t_info_exec **lst, t_info_exec *new);
void	ft_pipelst_clear(t_info_exec **lst);
void	ft_pipelst_printcmd(t_info_exec	**lst);
void	ft_pipelst_reverse_printcmd(t_info_exec	**lst);
t_info_exec	*ft_make_pipelst(char **argv);
size_t	ft_pipelst_size(t_info_exec *lst);
//ft_exec_one.c
int	ft_only_child(t_info_exec *cmd, char **env);
//ft_while_cmd.c
int     ft_close_wrongpipes(t_info_exec *cmd);
int     ft_close_allpipes(t_info_exec  *lst);
int     ft_close_wrongpipes(t_info_exec *cmd);
void    ft_set_pipes(t_info_exec **lst);
int ft_while_fork(t_info_exec **lst_cmd, char **env);
int	ft_exec_child(t_info_exec *cmd, t_info_exec **lst, char **env, int status);


#endif