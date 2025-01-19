/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:58:40 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/01/19 19:16:42 by pvitor-l         ###   ########.fr       */
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

char	**split_cmd(char *cmd)
{
	char	**get_commands;

	if (!cmd)
		return (NULL);
	get_commands = ft_split(cmd, ' ');
	if(!get_commands || !*get_commands)
		return (NULL);
	return (get_commands);
}
static char	*ft_join_path(char *path, char *cmd)
{
	char	*join_slash;
	char	**cmd_split;
	char	*together_all;

	join_slash = ft_strjoin(path, "/");
	cmd_split = split_cmd(cmd);
	together_all = ft_strjoin(join_slash, cmd_split[0]);
	return (together_all);
}

char	*ft_validade_command(char **path, char *cmd)
{
	char	*path_found;
	char	**get_cmd_and_flag;

	get_cmd_and_flag = split_cmd(cmd);
	while (*path != NULL)
	{
		path_found = ft_join_path(*path, get_cmd_and_flag[0]);
		if (access(path_found, F_OK | X_OK) == 0)
			return(path_found);
		free(path_found);
		path++;
	}
	return (NULL);
}
