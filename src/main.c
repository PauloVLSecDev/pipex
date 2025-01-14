/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:16:42 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/01/14 16:37:57 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <stdio.h>
#include <string.h>

int	main (int argc, char *argv[], char **env)
{
	if(argc != 5)
		perror("something wrong format correct is: ./pipex file1 cmd1 cmd2 file2"); 

	char	**path;
	char	*path_absolute;
	
	path = ft_find_path(env);
	path_absolute = ft_validade_command(path, argv[2]);

	ft_printf("retorrno da função ft_find_path %s\n", path[4]);
	ft_printf("caminho com comando  %s\n", path_absolute);

	return (0);
}
