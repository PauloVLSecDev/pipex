/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:37:41 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/01/17 15:52:00 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

void	args_error(int	exit_code)
{
	ft_printf("./expected: ./pipex <file_in> <cmd1> <cmd2> <cmdn> <file_out>");
	exit(exit_code);
}

void	exit_with_menssage(char *menssage, int	exit_code);
{
	if(menssage)
		ft_printf(menssage);
	exit(exit_code);
}
