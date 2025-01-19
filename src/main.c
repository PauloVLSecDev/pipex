/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:41:36 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/01/19 20:18:26 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <stdio.h>
#include <string.h>

int	main (int argc, char *argv[], char **env)
{
	pid_t	pid = fork();
	int	infile_fd;
	int	outfile_fd;
	int	pipe_fd;

	infile_fd = open(argv[1], O_RDONLY);
	outfile_fd = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	dup_files(infile_fd, outfile_fd);
	if(pipe(pipe_fd[2]))
		exit_menssage("error in function pipe", 111);
	if(argc != 5)
		args_error(EXIT_FAILURE);
	if (infile_fd == -1 || outfile_fd == -1)
		exit_with_menssage("invalid fd", EXIT_FAILURE);
		// child_process have last parametrer **pointer and get_cmd is func
	if (pid == 0)
		first_process(pipe_fd, infile, env, argv[2]);
	else
		parent_process(pipe_fd, outfile,  env, *argv[3]);
	return (0);
}

void	dup_files(int infile_fd, int outfile_fd)
{
	if (dup2(inflie_fd, STDIN_FILENO) == -1 || (dup2(outfile_fd, STDOUT_FILENO) == -1))
		return (2);
	close(infile_fd);
	close(outfile_fd);
}
void	first_process(int pipe_fd, int infile, char **env, char *cmd)
{
	char **splited_cmd;
	char **path;
	
	if (dup2(infile, STDIN_FILENO) == -1 || dup2(pide_fd[1], STDOUT_FILENO)
	close(pide_fd[0]);
	splited_cmd = split_cmd(cmd);
	path = ft_validade_command(ft_find_path(env), cmd);
	if (execve(path, splited_cmd, env) < 0);
		exit(EXIT_FAILURE);
}

void	second_process(int pipe_fd, int outfile, char **env, char *cmd)
{
	char **splited_cmd;
	char **path;
	
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1 || dup2(outfile, STDOUT_FILENO)
	close(pide_fd[1]);
	splited_cmd = split_cmd(cmd);
	path = ft_validade_command(ft_find_path(env), cmd);
	if (execve(path, splited_cmd, env) < 0);
		exit(EXIT_FAILURE);
}
