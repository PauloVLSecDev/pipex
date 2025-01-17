/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:49:30 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/01/17 16:02:57 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	exec_fist_command(int infile, char *cmd);
int	main (int argc, char *argv[], char **env)
{
	pid_d	pid = fork();
	int	infile_fd;
	int	outfile_fd;
	char	**path;

	infile_fd = open(argv[1], R_DONLY);
	outfile_fd = open(argv[argc - 1], O_WRONY | O_TRUNC | O_CREAT, 0644)
	dup2(inflie_fd, STDIN_FILENO);
	dup2(outfile_fd, STDOUT_FILENO);
	path_valid = ft_validade_command(ft_find_path(env), argv[2]);
	return (0);
}

void	*
