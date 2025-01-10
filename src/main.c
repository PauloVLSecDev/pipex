/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:16:42 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/01/09 19:18:22 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main (int argc, char *argv[], char **env)
{
	if(argc == 5)
	{
		char *process_c =  argv[1];
		char **result = validade_command(env);
		char *ft_end = ft_strjoin("/", argv[2]);
		char *ft_join = ft_strjoin(result[4], ft_end);
		ft_printf("primeiro argv %s\n", process_c);
		ft_printf("caminho  %s\n", result[4]);
		ft_printf("caminho definitivo %s\n", ft_join);
	}
	else
		perror("missing something");
	return (0);
}
