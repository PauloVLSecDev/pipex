/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:41:36 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/01/22 20:12:19 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <stdio.h>
#include <string.h>

int	main (int argc, char *argv[], char **env)
{
	int	infile_fd;
	int	outfile_fd;
	int	pipe_fd[2];

	if(argc != 5)
	{
		ft_printf("socorro\n ");
	}
	if (pipe(pipe_fd) == -1)
		exit_with_menssage("error in function pipe", 111);
	infile_fd = open(argv[1], O_RDONLY);
	outfile_fd = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (infile_fd == -1 || outfile_fd == -1)
		exit_with_menssage("invalid fd", EXIT_FAILURE);
	pid_t	pid = fork();
	if (pid == 0)
		first_process(pipe_fd, infile_fd, env, argv[2]);
	else
		second_process(pipe_fd, outfile_fd,  env, argv[3]);
	return (0);
}
