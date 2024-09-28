/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:49:15 by tcohen            #+#    #+#             */
/*   Updated: 2024/09/28 17:30:15 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_check_argc(int argc)
{
	if (argc < 2)
	{
		ft_putstr_fd("Error Format need at least: ./pipex <cmd1>\n", 2);
		exit (1);
	}
}

int	ft_check_if_alpha(char *str)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (str[i])
	{
		check = ft_isalpha((int)str[i]);
		if (check == 1)
			break ;
		i++;
	}
	return (check);
}

void	ft_check_argv(char *cmd, int fd[2])
{
	int	check_alpha;

	check_alpha = 0;
	if (cmd[0] == '\0')
	{
		ft_close_pipe(fd);
		exit(1);
	}
	check_alpha = ft_check_if_alpha(cmd);
	if (check_alpha == 0)
	{
		ft_close_pipe(fd);
		exit (1);
	}
}
