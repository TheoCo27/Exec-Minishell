/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_secure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:48:02 by tcohen            #+#    #+#             */
/*   Updated: 2024/09/29 16:58:43 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_open(char *file_name, char mode, t_info_exec *info)
{
	int	fd;

	if (mode == 'w')
		fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (mode == 'r')
		fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		perror(file_name);
		ft_close_pipe(info->pipe_fd);
		exit (2);
	}
	return (fd);
}

int	ft_dup2(int old_fd, int new_fd)
{
	if (dup2(old_fd, new_fd) == -1)
	{
		close(old_fd);
		perror("dup2 failed");
		return (-1);
	}
	close(old_fd);
	return (0);
}

int	ft_execve(t_info_exec *cmd, t_info_exec **lst)
{
	if (execve(cmd->path, cmd->arg, cmd->env) == -1)
	{
		perror(cmd->path);
		ft_clean_info(cmd);
		ft_close_remaining_pipes(cmd, lst);
		ft_pipelst_clear(lst);
		exit (1);
	}
	return (-1);
}

int	ft_pipe(int fd[2], t_info_exec	**lst, t_info_exec *cmd)
{
	t_info_exec	*temp;

	temp = *lst;
	if (pipe(fd) == -1)
	{
		while(temp)
		{
			if (temp == cmd)
				break;
			ft_close_pipe(temp->pipe_fd);
		}
		t_pipelst_clear(lst);
		perror("pipe failed");
		exit(1);
	}
	return (0);
}
