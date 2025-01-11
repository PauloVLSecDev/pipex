/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:16:42 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/01/10 19:59:10 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main (int argc, char *argv[], char **env)
{
	if(argc == 5)
		perror("something wrong format correct is: ./pipex file1 cmd1 cmd2 file2"); 
	char	*process_c;
	char	**path;
	char	*path_absolute;
	
	process_c =  argv[1];
	path = ft_find_path(env);
	path_absolute = ft_validade_command(path, env, argv[2]);

	ft_printf("primeiro argv %s\n", process_c);
	ft_printf("caminho  %s\n", path);

	perror("missing something");
	return (0);
}
