/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:58:40 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/01/09 21:06:44 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**find_path(char **env)
{
	char	**path;

	if (!env)
		return (NULL);
	while (*env && ft_strncmp(*env, "PATH", ft_strlen("PATH")))
		env++;
	if (!*env)
		return (NULL);
	path = ft_split(*env, ':');
	return (path);
}
char	*join_path(char **path, char *cmd)
{
	char	*join_slash;
	char	*together_all;

	join_slash = ft_join(path, "/");
	together_all = ft_join(join_slash, cmd);
	return (together_all);
}

void	*validade_command(char **path, char **env, char *cmd);
{
	int	i;
	char	*new_path;
	i = 0;
	
	while (path[i] != NULL)	
	{
		new_path = join_path(path[i], cmd);
		if (access(new_path, R_OK | X_OK) == 0)
			execve(path[i], argv[1], NULL);
		free(new_path);
		i++;
	}
	return :
}
