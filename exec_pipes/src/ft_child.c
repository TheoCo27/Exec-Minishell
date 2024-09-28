/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:02:22 by tcohen            #+#    #+#             */
/*   Updated: 2024/09/28 16:19:20 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_cmd_arg(char *cmd, t_info_exec *info)
{
	char	**tab;

	tab = ft_split(cmd, ' ');
	if (!tab)
	{
		perror("malloc failed");
		ft_close_all(info->pipe_fd, info->in_out_fd);
		exit(1);
	}
	info->cmd = tab[0];
	info->arg = tab;
	return (0);
}

void	ft_cmd1(t_info_exec *cmd, int fd[2])
{
	close(fd[0]);
	ft_execve(cmd);
}

void	ft_cmd2(t_info_exec *cmd, int fd[2])
{
	close(fd[1]);
	ft_execve(cmd);
}

int	ft_first_child(char **argv, char **env, int fd[2], t_info_exec *cmd)
{
	ft_check_argv(argv[2], fd);
	cmd->in_out_fd = ft_open(argv[1], 'r', cmd);
	if (ft_dup2(fd[1], 1) == -1)
		return (ft_close_all(fd, cmd->in_out_fd), 1);
	if (ft_dup2(cmd->in_out_fd, 0) == -1)
		return (ft_close_all(fd, cmd->in_out_fd), 1);
	ft_cmd_arg(argv[2], cmd);
	if (ft_path(env, cmd) == 1)
		return (ft_close_all(fd, cmd->in_out_fd), 1);
	ft_cmd1(cmd, fd);
	return (0);
}

int	ft_2nd_child(char **argv, char **env, int fd[2], t_info_exec *cmd)
{
	ft_check_argv(argv[3], fd);
	cmd->in_out_fd = ft_open(argv[4], 'w', cmd);
	if (ft_dup2(fd[0], 0) == -1)
		return (ft_close_all(fd, cmd->in_out_fd), 1);
	if (ft_dup2(cmd->in_out_fd, 1) == -1)
		return (ft_close_all(fd, cmd->in_out_fd), 1);
	ft_cmd_arg(argv[3], cmd);
	if (ft_path(env, cmd) == 1)
		return (ft_close_all(fd, cmd->in_out_fd), 1);
	ft_cmd2(cmd, fd);
	return (0);
}
