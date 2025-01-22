/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:49:30 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/01/22 20:04:32 by pvitor-l         ###   ########.fr       */
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

void	second_process(int *p_fd, int fdO, char **env, char *cmd)
{
	char **splited_cmd;
	char *path;
	
	if (dup2(p_fd[0], STDIN_FILENO) == -1 || dup2(fdO, STDOUT_FILENO) == -1)
		exit_with_menssage("dup error in first process", EXIT_FAILURE);
	close(p_fd[1]);
	splited_cmd = split_cmd(cmd);
	path = ft_validade_command(ft_find_path(env), cmd);
	if (execve(path, splited_cmd, env) == -1)
	{	
		free(path);
		exit(EXIT_FAILURE);
	}
	free(path);

}

void	first_process(int *p_fd, int fdI, char **env, char *cmd)
{
	char **splited_cmd;
	char *path;
	
	if (dup2(fdI, STDIN_FILENO) == -1 || dup2(p_fd[1], STDOUT_FILENO) == -1)
		exit_with_menssage("dup error in second process", EXIT_FAILURE);
	close(p_fd[0]);
	splited_cmd = split_cmd(cmd);
	path = ft_validade_command(ft_find_path(env), cmd);
	if (execve(path, splited_cmd, env) == -1)
	{
		free(path);
		exit(EXIT_FAILURE);
	}
	free(path);

}
