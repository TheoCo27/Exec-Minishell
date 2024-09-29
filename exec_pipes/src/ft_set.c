/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:04:24 by tcohen            #+#    #+#             */
/*   Updated: 2024/09/29 16:09:15 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_execve_stuff(t_info_exec *info)
{
	info->path = ft_strdup(info->cmd);
	if (!info->path)
		return (ft_free_all(info->arg), 1);
	info->cmd = ft_strdup(info->cmd);
	if (!info->cmd)
		return (free(info->path), ft_free_all(info->arg), 1);
	info->t_path = ft_split(info->cmd, ' ');
	if (!info->t_path)
		return (free(info->cmd), free(info->path), ft_free_all(info->arg), 1);
	return (0);
}
