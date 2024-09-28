/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:44:50 by tcohen            #+#    #+#             */
/*   Updated: 2024/09/28 19:28:15 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// static void	ft_exit(int fork_nb, int pid1, int fd[2])
// {
// 	if (fork_nb == 0)
// 	{
// 		ft_close_pipe(fd);
// 		perror("fork pid[0] failed");
// 		exit(1);
// 	}
// 	if (fork_nb == 1)
// 	{
// 		ft_close_pipe(fd);
// 		perror("fork pid[1] failed");
// 		waitpid(pid1, NULL, 0);
// 		exit(2);
// 	}
// }


//test doublement chaîné
// int main(int argc, char **argv, char **env)
// {
// 	t_info_exec	*lst;
// 	t_info_exec	*cmd;
// 	size_t		lst_size;

// 	ft_check_argc(argc);
//  	lst = NULL;
//  	lst = ft_make_pipelst(argv);
//  	if (!lst)
//  		return (1);
//  	lst_size = ft_pipelst_size(lst);
// 	ft_pipelst_reverse_printcmd(&lst);

int	main(int argc, char **argv, char **env)
{
	t_info_exec	*lst;
	t_info_exec	*temp_lst;
	size_t		lst_size;

	ft_check_argc(argc);
	lst = NULL;
	lst = ft_make_pipelst(argv);
	ft_set_pipes(&lst);
	if (!lst)
		return (1);
	lst_size = ft_pipelst_size(lst);
	printf("lst-size = %lu\n", lst_size);
	ft_while_fork(&lst, env);
	// temp_lst = lst;
	// while(lst_size > 0)
	// {
	// 	temp_lst->pid = fork();
	// 	if (lst_size == 1)
	// 		return(ft_only_child(argv, env, fd, temp_lst));
	// }
	if (ft_pipelst_size(lst) > 1)
    	ft_close_allpipes(lst);
    ft_wait_pids(lst);
    ft_pipelst_clear(&lst);
}


// int main(int argc, char **argv)
// {
// 	t_info_exec	*lst;

// 	ft_check_argc(argc);
// 	lst = ft_make_pipelst(argv);
// 	ft_pipelst_printcmd(&lst);
// 	ft_pipelst_clear(&lst);
// 	return (0);
// }

// int	main(int argc, char **argv, char **env)
// {
// 	t_info_exec	cmd[2];
// 	int			fd[2];
// 	int			pid[2];

// 	ft_check_argc(argc);
// 	ft_pipe(fd);
// 	ft_set_cmds(&cmd[0], &cmd[1], fd, env);
// 	pid[0] = fork();
// 	if (pid[0] < 0)
// 		ft_exit(0, pid[0], fd);
// 	if (pid[0] == 0)
// 		ft_first_child(argv, env, fd, &cmd[0]);
// 	pid[1] = fork();
// 	if (pid[1] < 0)
// 		ft_exit(1, pid[0], fd);
// 	if (pid[1] == 0)
// 		ft_2nd_child(argv, env, fd, &cmd[1]);
// 	ft_close_pipe(fd);
// 	ft_wait_pids(pid[0], pid[1]);
// 	return (0);
// }
