/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:37:41 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/01/22 19:07:21 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"
# include <stdio.h>

void	args_error(int	exit_code)
{
//	ft_printf("./expected: ./pipex Infile cmd1 cmd2 Outfile");
	printf(" sr ");
	exit(exit_code);
}

void	exit_with_menssage(char *menssage, int	exit_code)
{
	if(menssage)
		ft_printf(menssage);
	exit(exit_code);
}
