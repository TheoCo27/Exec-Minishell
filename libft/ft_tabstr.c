/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 16:32:01 by tcohen            #+#    #+#             */
/*   Updated: 2024/09/16 16:47:58 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_tabstr_len(char **tabstr)
{
	size_t	i;
	char	**temp_tab;

	temp_tab = tabstr;
	i = 0;
	if (tabstr == NULL)
		return (0);
	while (*temp_tab)
	{
		i++;
		temp_tab++;
	}
	return (i);
}

char	**ft_tabstr_copy(char **tabstr)
{
	size_t	tab_len;
	char	**tab_copy;
	size_t	i;

	i = 0;
	tab_len = ft_tabstr_len(tabstr);
	if (tab_len == 0)
		return (NULL);
	tab_copy = (char **)malloc((tab_len + 1) * sizeof(char *));
	if (!tab_copy)
		return (NULL);
	while (i < tab_len)
	{
		tab_copy[i] = ft_strdup(tabstr[i]);
		if (!tab_copy[i])
			return (ft_free_all(tab_copy), NULL);
		i++;
	}
	tab_copy[tab_len] = NULL;
	return (tab_copy);
}

void	ft_print_tabstr(char **tabstr)
{
	char	**temp;

	temp = tabstr;
	if (temp == NULL)
		return ;
	while (*temp)
	{
		ft_putendl_fd(*temp, 1);
		temp++;
	}
}
