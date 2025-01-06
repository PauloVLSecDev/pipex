/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:16:42 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/01/06 19:43:59 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main (int argc, const char *argv[])
{
	if(argc == 5)
	{
		char fd_init =  *argv[1];
		ft_printf("so pra testar mesmo %s", fd_init);
	}
	else 
		perror("misssing something");	
	return (0);
}
