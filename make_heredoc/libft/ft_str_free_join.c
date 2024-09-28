/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_free_join.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:16:06 by tcohen            #+#    #+#             */
/*   Updated: 2024/09/04 16:27:14 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfree_s1_join(char *s1_to_free, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*str_joined;

	s1_len = ft_strlen(s1_to_free);
	s2_len = ft_strlen(s2);
	str_joined = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!str_joined)
		return (free(s1_to_free), NULL);
	ft_strcpy(str_joined, s1_to_free);
	free(s1_to_free);
	ft_strcpy(&str_joined[s1_len], s2);
	return (str_joined);
}
