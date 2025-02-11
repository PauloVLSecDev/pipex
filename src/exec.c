/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:49:30 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/02/05 17:41:59 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child_process(int *pfd, char **argv, char **env)
{
	char	**cmd1_with_flag;
	char	*path;
	int		ifd;

	ifd = open(argv[1], O_RDONLY);
	if (check_permission_infile(argv[1], ifd) != 0)
		exit(1);
	if (cmd_exist(argv[2], env, pfd) == 127)
		exit_code(pfd, 127, argv[2]);
	if (ifd == -1)
		exit_code(NULL, EXIT_FAILURE, NULL);
	if (dup2(ifd, STDIN_FILENO) == -1 || dup2(pfd[1], STDOUT_FILENO) == -1)
		exit_code("dup error in child process", EXIT_FAILURE, NULL);
	close(ifd);
	close(pfd[1]);
	cmd1_with_flag = split_cmd(argv[2]);
	path = ft_validade_command(ft_find_path(env), argv[2]);
	if (execve(path, cmd1_with_flag, env) == -1)
	{
		free(path);
		exit(127);
	}
	free(path);
}

void	parent_process(int *pfd, char **argv, char **env)
{
	char	**cmd2_with_flag;
	char	*path;
	int		ofd;

	ofd = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (check_permission_outfile(argv[4], ofd) != 0)
		exit(1);
	if (cmd_exist(argv[3], env, pfd) == 127)
		exit_code(NULL, 127, argv[3]);
	if (ofd == -1)
		exit_code(NULL, EXIT_FAILURE, NULL);
	if (dup2(pfd[0], STDIN_FILENO) == -1 || dup2(ofd, STDOUT_FILENO) == -1)
		exit_code("dup error in parent process", EXIT_FAILURE, NULL);
	close(ofd);
	close(pfd[0]);
	cmd2_with_flag = split_cmd(argv[3]);
	path = ft_validade_command(ft_find_path(env), argv[3]);
	if (execve(path, cmd2_with_flag, env) == -1)
	{
		free(path);
		exit(127);
	}
	free(path);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
		free(array[i++]);
	free(array);
}
