/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:58:40 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/02/04 19:56:06 by pvitor-l         ###   ########.fr       */
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
	if (!path)
		return (NULL);
	return (path);
}

char	**split_cmd(char *cmd)
{
	char	**get_commands;

	if (!cmd)
		return (NULL);
	get_commands = ft_split(cmd, ' ');
	if (!get_commands)
	{
		free_array(get_commands);
		return (NULL);
	}
	return (get_commands);
}

static char	*ft_join_path(char *path, char *cmd)
{
	char	*join_slash;
	char	*together_all;

	join_slash = ft_strjoin(path, "/");
	if (!join_slash)
		return (NULL);
	together_all = ft_strjoin(join_slash, cmd);
	free(join_slash);
	if (!together_all)
		return (NULL);
	return (together_all);
}

char	*ft_validade_command(char **path, char *cmd)
{
	char	*path_found;
	char	**get_cmd;

	get_cmd = split_cmd(cmd);
	if (!get_cmd)
		return (NULL);
	while (*path != NULL)
	{
		path_found = ft_join_path(*path, get_cmd[0]);
		if (!path_found)
			return (free_array(get_cmd), NULL);
		if (access(path_found, F_OK | X_OK) == 0)
			return (free_array(get_cmd), path_found);
		free(path_found);
		path++;
	}
	free_array(get_cmd);
	return (NULL);
}
