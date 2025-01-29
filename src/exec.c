/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:49:30 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/01/28 21:11:00 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/*
void	dup_files(int infile_fd, int outfile_fd)
{
	if (dup2(inflie_fd, STDIN_FILENO) == -1 || (dup2(outfile_fd, STDOUT_FILENO) == -1))
		return (2);
	close(infile_fd);
	close(outfile_fd);
}
*/

void	parent_process(int *pfd, char **argv, char **env)
{
	char **splited_cmd;
	char *path;
	int	ofd;
	
	check_permission_outfile(argv[4]);
	ofd = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (ofd == -1)
		exit_code(NULL, EXIT_FAILURE);
	if (dup2(pfd[0], STDIN_FILENO) == -1 || dup2(ofd, STDOUT_FILENO) == -1)
		exit_code("dup error in parent process", EXIT_FAILURE);
	close(ofd);
	close(pfd[0]);
	splited_cmd = split_cmd(argv[3]);
	path = ft_validade_command(ft_find_path(env), argv[3]);
	if (execve(path, splited_cmd, env) == -1)
	{
		free(path);
		exit(127);
	}
	free(path);
}

void	child_process(int *pfd, char **argv, char **env)
{
	char **cmd2_with_flag;
	char *path;
	int	ifd;
	
	check_permission_infile(argv[1]);
	ifd = open(argv[1], O_RDONLY);
	if (ifd == -1)
		exit_code(NULL, EXIT_FAILURE);
	if (dup2(ifd, STDIN_FILENO) == -1 || dup2(pfd[1], STDOUT_FILENO) == -1)
		exit_code("dup error in child process", EXIT_FAILURE);
	close(ifd); 
	close(pfd[1]);
	cmd2_with_flag = split_cmd(argv[2]);
	path = ft_validade_command(ft_find_path(env), argv[2]);
	if (execve(path, cmd2_with_flag, env) == -1)
	{
		free(path);
		exit(127);
	}
	free(path);
}
