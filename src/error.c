/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:37:41 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/01/28 21:09:17 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

int	cmd_exist(char *cmd, char **env)
{
	char *cmd_args;

	if (!cmd || !*cmd)
		return (127);
	cmd_args = ft_validade_command(ft_find_path(env), cmd);
	if (!cmd_args || !cmd_args[0])
		return(127);
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
void	exit_code(char *menssage, int	code, char *cmd)
{
	if (code == 127)
	{
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": Command not found\n", 2);
	}
	if (menssage)
	{
		ft_putstr_fd(menssage, 2);
		ft_putstr_fd("\n", 2);
	}
	exit(code);
}
