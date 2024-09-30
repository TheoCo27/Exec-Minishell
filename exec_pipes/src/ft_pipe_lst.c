/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:09:56 by tcohen            #+#    #+#             */
/*   Updated: 2024/09/30 02:15:00 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_info_exec	*ft_pipelst_new(char *cmd)
{
	t_info_exec	*new;

	new = (t_info_exec *)malloc(sizeof(t_info_exec));
	if (!new)
		return (NULL);
	ft_bzero(new, sizeof(t_info_exec));
	new->cmd = cmd;
	new->next = NULL;
	new->prev = NULL;
	new->pid = -1;
	return (new);
}

t_info_exec	*ft_pipelst_last(t_info_exec *lst)
{
	t_info_exec	*tmp;

	tmp = lst;
	while(tmp)
	{
		if (tmp->next == NULL)
			break ;
		tmp = tmp->next;
	}
	return (tmp);
}

void	ft_pipelst_addback(t_info_exec **lst, t_info_exec *new)
{
	t_info_exec	*last;

	if (!lst || !*lst)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	last = ft_pipelst_last(*lst);
	last->next = new;
	new->prev = last;
}

void	ft_pipelst_clear(t_info_exec **lst)
{
	t_info_exec	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		//ici free le contenue du node;
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}

void	ft_pipelst_printcmd(t_info_exec	**lst)
{
	t_info_exec	*temp;
	int			count;

	temp = *lst;
	count = 1;
	while(temp)
	{
		ft_putnbr_fd(count, 1);
		ft_putstr_fd(" .", 1);
		ft_putendl_fd(temp->cmd, 1);
		temp = temp->next;
		count++;
	}
}

void	ft_pipelst_reverse_printcmd(t_info_exec	**lst)
{
	t_info_exec	*temp;
	int			count;

	temp = *lst;
	temp = ft_pipelst_last(temp);
	count = 1;
	while(temp)
	{
		ft_putnbr_fd(count, 1);
		ft_putstr_fd(" .", 1);
		ft_putendl_fd(temp->cmd, 1);
		temp = temp->prev;
		count++;
	}
}

t_info_exec	*ft_make_pipelst(char **argv)
{
	size_t		i;
	t_info_exec	*lst;
	t_info_exec	*new;

	i = 1;
	lst = NULL;
	while(argv[i])
	{
		new = ft_pipelst_new(argv[i]);
		if (!new)
			return (ft_pipelst_clear(&lst), NULL);
		ft_pipelst_addback(&lst, new);
		i++;
	}
	return (lst);
}

size_t	ft_pipelst_size(t_info_exec *lst)
{
	t_info_exec	*temp;
	size_t		lst_size;

	temp = lst;
	lst_size = 0;
	while(temp)
	{
		temp->index = lst_size;
		lst_size++;
		temp = temp->next;
	}
	return(lst_size);
}
