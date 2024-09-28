/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_while_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:14:26 by theog             #+#    #+#             */
/*   Updated: 2024/09/28 19:20:59 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int     ft_close_allpipes(t_info_exec  *lst)
{
    t_info_exec *cmd;

    cmd = lst;
    while(cmd)
    {
        close(cmd->pipe_fd[0]);
        close(cmd->pipe_fd[1]);
        cmd = cmd->next;
    }
    return (0);
}
int     ft_close_wrongpipes(t_info_exec *cmd)
{
    t_info_exec *next_cmd;
    t_info_exec *prev_cmd;

    next_cmd = cmd->next;
    prev_cmd = cmd->prev;

    close(cmd->pipe_fd[0]);
    while(next_cmd)
    {
        ft_close_pipe(next_cmd->pipe_fd);
        next_cmd = next_cmd->next;
    }
    if (prev_cmd != NULL)
    {
        close(prev_cmd->pipe_fd[1]);
        prev_cmd = prev_cmd->prev;
    }
    while(prev_cmd)
    {
        ft_close_pipe(prev_cmd->pipe_fd);
        prev_cmd = prev_cmd->prev;
    }
    return (0);
}

void    ft_set_pipes(t_info_exec **lst)
{
    t_info_exec *cmd;
    size_t      lst_size;
    size_t      i = 0;

    cmd = *lst;
    lst_size = ft_pipelst_size(cmd);
    while(cmd)
    {
        ft_pipe(cmd->pipe_fd, lst, cmd);
        cmd = cmd->next;
    }

}

int ft_while_fork(t_info_exec **lst_cmd, char **env)
{
    t_info_exec *cmd;
    t_info_exec *last;

    cmd = *lst_cmd;
    last = ft_pipelst_last(cmd);
    if (ft_pipelst_size(cmd) == 1)
        return (ft_only_child(cmd, env), 0);
    while(cmd)
    {
        cmd->pid = fork();
        if (cmd->pid < 0)
        {
            ft_putendl_fd("Error fork", 2);
            exit (1);
        }
        if (cmd->pid == 0 && cmd == *lst_cmd)
            ft_exec_child(cmd, lst_cmd, env, 0);
        if (cmd->pid == 0 && cmd == last)
            ft_exec_child(cmd, lst_cmd, env, 1);  
        if (cmd->pid == 0 )
            ft_exec_child(cmd, lst_cmd, env, 2);
        cmd = cmd->next;
    }
    return (0);
}

int	ft_exec_child(t_info_exec *cmd, t_info_exec **lst, char **env, int status)
{
	//ft_check_argv(argv[2], fd);
	//cmd->in_out_fd = ft_open(argv[1], 'r', cmd);
    ft_close_wrongpipes(cmd);
    if (status != 0)
	    if (ft_dup2(cmd->prev->pipe_fd[0], 0) == -1)
		    return (ft_close_allpipes(*lst), 1);
    // ici call ft_redirection
    if (status != 1)
	    if (ft_dup2(cmd->pipe_fd[1], 1) == -1)
		    return (ft_close_allpipes(*lst), 1);
	ft_cmd_arg(cmd->cmd, cmd);
	if (ft_path(env, cmd) == 1)
		return (ft_close_allpipes(*lst), 1);
	ft_execve(cmd);
	return (0);
}