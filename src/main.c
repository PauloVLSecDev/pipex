/* ************************************************************************** */ /*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:16:42 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/01/15 18:53:11 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <stdio.h>
#include <string.h>

int	main (int argc, char *argv[], char **env)
{
	pid_t	pid[0] = fork();
	int	infile_fd;
	int	outfile_fd;
	char	**path;

	infile_fd = open(argv[1], R_DONLY);
	outfile_fd = open(argv[argc - 1], O_WRONY | O_TRUNC | O_CREAT, 0644)
	if(argc != 5)
		args_error(EXIT_FEILURE);
	if (infile_fd == -1 || outfile_fd == -1)
		exit_with_menssage("invalid fd", EXIT_FEILURE);
	dup2(inflie_fd, STDIN_FILENO);
	dup2(outfile_fd, STDOUT_FILENO);
	path_valid = ft_validade_command(ft_find_path(env), argv[2]);
	return (0);
}

void	*
