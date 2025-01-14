/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:16:42 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/01/14 20:13:37 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <stdio.h>
#include <string.h>

int	main (int argc, char *argv[], char **env)
{
	char	**path;
	char	*path_absolute;

	if(argc != 5)
		perror("something wrong format correct is: ./pipex file1 cmd1 cmd2 file2"); 
	
	path = ft_find_path(env);
	path_absolute = ft_validade_command(path, argv[2], env);

	return (0);
}
