/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:59:29 by tcohen            #+#    #+#             */
/*   Updated: 2024/10/01 00:31:15 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hey_doc.h"

int	ft_open(char *file_name, char mode)
{
	int	fd;

	if (mode == 'w')
		fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (mode == 'r')
		fd = open(file_name, O_RDONLY);
	if (mode == 'h')
		fd = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (fd < 0)
	{
		perror(file_name);
		exit (2);
	}
	return (fd);
}

char	*ft_anti_fuck_heredoc(char *file_name)
{
	while(access(file_name, F_OK) == 0)
	{
		file_name = ft_strfree_s1_join(file_name, "1");
		if (!file_name)
			return (free(file_name), NULL);
	}
	return (file_name);
}

int ft_fill_heredoc(char *limiter, int fd)
{
	char	*line;
	size_t	limiter_len;
	
	line = NULL;
	limiter_len = ft_strlen(limiter);
	while(1)
	{
		ft_putstr_fd("heredoc> ", 1);
		line = get_next_line(0);
		if (!line)
			break;
		if (ft_strncmp(line, limiter, limiter_len) == 0 && line[limiter_len] == '\n')
		{
			free(line);
			break;
		}
		ft_putstr_fd(line, fd);
		free(line);
	}
	return (0);
}

int ft_destroy_heredoc(t_heredoc *h)
{
	close(h->fd_heredoc);
	unlink(h->heredoc_name);
	free(h->heredoc_name);
	free(h);
	return (0);
}
t_heredoc *ft_make_heredoc(void)
{
	t_heredoc *h;

	h = malloc(sizeof(t_heredoc) * 1);
	if (!h)
		return (NULL);
	h->heredoc_name = ft_strdup("heredoc");
	if (!h->heredoc_name)
		return (NULL);
	h->heredoc_name = ft_anti_fuck_heredoc(h->heredoc_name);
	if (!h->heredoc_name)
		return (NULL);
	h->fd_heredoc = ft_open(h->heredoc_name, 'h');
	return (h);
}

int main(int argc, char **argv)
{
	t_heredoc *h;
	char *line;
	int i = 1;

	char c = 'a';
	line = &c;
	if (argc < 2)
	{
		ft_putstr_fd("error need ./hey_doc <your_limiter>", 2);
		exit(1);
	}
	h = ft_make_heredoc();
	while(argv[i])
	{
		ft_fill_heredoc(argv[i], h->fd_heredoc);
		i++;
	}
	close(h->fd_heredoc);
	h->fd_heredoc = ft_open(h->heredoc_name, 'r');
	while(line)
	{
		line = get_next_line(h->fd_heredoc);
		if (!line)
			break;
		ft_putstr_fd(line, 1);
		free(line);
	}
	ft_destroy_heredoc(h);
	return (0);

}

// int	main(void)
// {
// 	char buffer[1024];
// 	int read_output;

// 	while((read_output = read(0, buffer, sizeof(buffer) - 1)) > 0)
// 	{
// 		buffer[read_output] = '\0';
// 		printf("ligne lue : %s\n", buffer);
// 	}
// 	printf("fin du heredoc");
// 	return (0);
// }
