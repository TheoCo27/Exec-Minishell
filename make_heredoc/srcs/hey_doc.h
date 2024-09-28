/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hey_doc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 18:21:51 by tcohen            #+#    #+#             */
/*   Updated: 2024/09/24 19:54:31 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_heredoc
{
	char	*heredoc_name;
	int		fd_heredoc;
}			t_heredoc;

#include "../libft/libft.h"