/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:37:41 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/01/27 21:31:15 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"
# include <stdio.h>



void	check_permission_infile(char *argv)
{
	//infile need only permission for read
	if (access(argv, F_OK) == -1)
		ft_printf("%s No such file or directory\n", argv);
		exit(127);
	if (access(argv, R_OK) == -1)
	{
		ft_printf("%s Permission denied\n", argv);
		exit(1);
	}
	//the erro logical this here
	return;
}

void	check_permission_outfile(char *argv)
{
	if (access(argv, F_OK) == -1)
	{
		ft_printf("%s No such file or directory\n", argv);
		exit(127);
	}
	if (access(argv, W_OK | F_OK) == -1)
	{
		ft_printf("%s Permission denied\n", argv);
		exit(1);
	}
	return;
}
void	exit_code(char *menssage, int	code)
{
	if (menssage)
		ft_printf(menssage);
	exit(code);
}
