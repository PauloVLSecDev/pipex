/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:49:30 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/01/24 15:40:12 by pvitor-l         ###   ########.fr       */
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

void	parent_process(int *p_fd, char **argv, char **env)
{
	char **splited_cmd;
	char *path;
	int	out_fd;
	
	out_fd = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (out_fd == -1)
		exit_with_menssage("invalid fd", EXIT_FAILURE);
	if (dup2(p_fd[0], STDIN_FILENO) == -1 || dup2(out_fd, STDOUT_FILENO) == -1)
		exit_with_menssage("dup error in first process", EXIT_FAILURE);
	close(out_fd);
	close(p_fd[0]);
	close(p_fd[1]);
	splited_cmd = split_cmd(argv[3]);
	path = ft_validade_command(ft_find_path(env), argv[3]);
	if (execve(path, splited_cmd, env) == -1)
	{	
		free(path);
		exit(EXIT_FAILURE);
	}
	free(path);

}

void	child_process(int *p_fd, char **argv, char **env)
{
	char **cmd2_with_flag;
	char *path;
	int	in_fd;
	
	in_fd = open(argv[1], O_RDONLY);
	if (in_fd == -1)
		exit_with_menssage("invalid fd ", EXIT_FAILURE);
	if (dup2(in_fd, STDIN_FILENO) == -1 || dup2(p_fd[1], STDOUT_FILENO) == -1)
		exit_with_menssage("dup error in second process", EXIT_FAILURE);
	close(in_fd); 
	close(p_fd[1]);
	close(p_fd[0]);
	cmd2_with_flag = split_cmd(argv[3]);
	path = ft_validade_command(ft_find_path(env), argv[3]);
	if (execve(path, cmd2_with_flag, env) == -1)
	{
		free(path);
		exit(EXIT_FAILURE);
	}
	free(path);

}
