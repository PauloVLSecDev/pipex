/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:58:40 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/01/14 15:57:07 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**ft_find_path(char **env)
{
	char	**path;

	if (!env)
		return (NULL);
	while (*env && ft_strncmp(*env, "PATH=", ft_strlen("PATH=")))
		env++;
	if (!*env)
		return (NULL);
	path = ft_split((*env) + 5, ':');
	return (path);
}
char	*ft_join_path(char *path, char *cmd)
{
	char	*join_slash;
	char	*together_all;

	join_slash = ft_strjoin(path, "/");
	together_all = ft_strjoin(join_slash, cmd);
	return (together_all);
}

char	*ft_validade_command(char **path, char *cmd)
{
	char	*new_path;

	while (*path != NULL)	
	{
		//	execve(path[i], cmd, env);
		new_path = ft_join_path(*path, cmd);
		if (access(new_path, F_OK | X_OK) == 0)
			return (new_path);
		free(new_path);
		path++;
	}
	return (NULL);
}
