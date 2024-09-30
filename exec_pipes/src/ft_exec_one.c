/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 02:11:10 by theog             #+#    #+#             */
/*   Updated: 2024/09/30 03:09:26 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_only_child(t_info_exec *cmd, char **env, t_info_exec **lst)
{
    int status;

    status = 0;
    cmd->pid = fork();
    if (cmd->pid == 0)
    {
        //ft_check_argv(argv[1], fd);
        // cmd->in_out_fd = ft_open(argv[4], 'w', cmd);
        // if (ft_dup2(fd[0], 0) == -1)
        // 	return (ft_close_all(fd, cmd->in_out_fd), 1);
        // if (ft_dup2(cmd->in_out_fd, 1) == -1)
        // 	return (ft_close_all(fd, cmd->in_out_fd), 1);
        ft_cmd_arg(cmd->cmd, cmd, lst);
        if (ft_path(env, cmd) == 1)
            return(ft_pipelst_clear(lst), 1);
            // return (ft_close_all(fd, cmd->in_out_fd), 1);
	    ft_execve(cmd, lst);
    }
    status = ft_wait_pids(*lst, status);
    ft_pipelst_clear(lst);
	return (status);
}