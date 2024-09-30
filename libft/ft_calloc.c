/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:59:03 by tcohen            #+#    #+#             */
/*   Updated: 2024/06/04 18:44:48 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*temp;	
	size_t	total_size;

	if (count <= 0 || size <= 0)
		return (malloc(0));
	total_size = count * size;
	if (total_size / count != size)
		return (NULL);
	temp = malloc(total_size);
	if (!temp)
		return (NULL);
	ft_bzero(temp, total_size);
	return (temp);
}
