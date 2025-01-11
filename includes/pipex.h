/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:25:21 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/01/10 19:56:21 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H 

# include <stdlib.h> 
# include <unistd.h> 
# include <fcntl.h> 
# include <stdlib.h> 
# include <stdio.h>
# include <string.h>
# include "../libft/libft.h"

char	**ft_find_path(char **env);
char	*ft_join_path(char **path, char *cmd);
void	*ft_validade_command(char **path, char **env, char **cmd);

#endif
