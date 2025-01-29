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
# include <stdio.h>

int check_permission_infile(char *argv)
{
	//infile need only permission for read
	if (access(argv, F_OK) == -1)
	{
		ft_printf("%s No such file or directory\n", argv);
		return (0);
	}
	if (access(argv, R_OK) == -1)
	{
		ft_printf("%s Permission denied\n", argv);
		return (1);
	}
	return (0);
}

int	check_permission_outfile(char *argv)
{
	if (access(argv, F_OK) == -1)
	{
		if (ft_strncmp(argv, "/", ft_strlen(argv)) == 0)
		{
			ft_printf("%s Is directory\n", argv);
			return (1);
		}
		else
			ft_printf("%s No such file or directory\n", argv);
		return (1);
	}
	if (access(argv, W_OK | F_OK) == -1)
	{
		ft_printf("%s Permission denied\n", argv);
		return (1);
	}
	return (0);
}
void	exit_code(char *menssage, int	code)
{
	if (menssage)
		ft_printf("%s\n", menssage);
	exit(code);
}
