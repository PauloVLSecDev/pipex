/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:16:42 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/01/07 15:36:09 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main (int argc, char *argv[])
{
	if(argc == 5)
	{
		char *process_c =  argv[1];
		ft_printf("so pra testar mesmo %s\n", process_c);
	}
	else
		perror("misssing something");
	return (0);
}
