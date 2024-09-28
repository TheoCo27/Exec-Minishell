/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:27:54 by tcohen            #+#    #+#             */
/*   Updated: 2024/09/28 16:19:20 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close_pipe(int pipe_fd[2])
{
	close(pipe_fd[0]);
	close(pipe_fd[1]);
}

void	ft_close_all(int pipe_fd[2], int in_out_fd)
{
	ft_close_pipe(pipe_fd);
	close(in_out_fd);
}

int	ft_wait_pids(t_info_exec *lst)
{
	t_info_exec	*temp;

	temp = lst;
	while(temp)
	{
		waitpid(temp->pid, NULL, 0);
		temp = temp->next;
	}
	return (0);
}

int	ft_clean_info(t_info_exec *cmd)
{
	free(cmd->cmd);
	free(cmd->path);
	ft_free_all(cmd->arg);
	ft_free_all(cmd->t_path);
	return (0);
}
