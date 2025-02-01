/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:37:41 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/02/01 19:50:55 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

void	close_pipe(int *pipe_fd)
{
	if (pipe_fd)
	{
		close(pipe_fd[0]);
		close(pipe_fd[1]);
       	} 
}
int	cmd_exist(char *cmd, char **env, int *pipe_fd)
{
	char *cmd_args;
	char **path_valid;

	if (!cmd || !*cmd)
	{
		close_pipe(pipe_fd);
		return (127);
	}
	path_valid = ft_find_path(env);
	if (!path_valid)
	{
		close_pipe(pipe_fd);		
		return (127);
	}
	cmd_args = ft_validade_command(path_valid, cmd);
	free(path_valid);
	if (!cmd_args || !cmd_args[0])
	{
		close_pipe(pipe_fd);
		free(cmd_args);
		return(127);
	}
	return (0);
}
int check_permission_infile(char *infile)
{
	//infile need only permission for read
	if (access(infile, F_OK) == -1)
	{
		ft_putstr_fd(infile, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		return (2);
	}
	if (access(infile, R_OK) == -1)
	{
		ft_putstr_fd(infile, 2);
		ft_putstr_fd(": Permission denied\n", 2);
		return (1);
	}
	return (0);
}

int	check_permission_outfile(char *outfile)
{
	if (access(outfile, F_OK) == -1)
	{
		if (ft_strncmp(outfile, "/", ft_strlen(outfile)) == 0)
		{
			ft_putstr_fd(outfile, 2);
			ft_putstr_fd(": Is directory \n", 2);
			return (1);
		}
		else
		{
			ft_putstr_fd(outfile, 2);
			ft_putstr_fd(": No such file or directory\n", 2);
		}
		return (0);
	}
	if (access(outfile, W_OK | F_OK) == -1)
	{
		ft_putstr_fd(outfile, 2);
		ft_putstr_fd(": Permission denied\n", 2);
		return (1);
	}
	return (0);
}
void	exit_code(void *args, int code, char *cmd)
{
	if (code == 127)
	{
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": Command not found\n", 2);
		close_pipe((int *)args);
	}
	if (args)
	{
		ft_putstr_fd((char *)args, 2);
		ft_putstr_fd("\n", 2);
	}
	exit(code);
}
