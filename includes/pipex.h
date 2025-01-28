/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:25:21 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/01/27 21:15:54 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H 
# define EXIT_FAILURE

# include <unistd.h> 
# include <fcntl.h> 
# include <stdlib.h> 
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>
# include "../libft/libft.h"

char	**ft_find_path(char **env);
char	*ft_validade_command(char **path, char *cmd);
char	**split_cmd(char *cmd);
void		exit_code(char *menssage, int	exit_code);
void	check_permission_infile(char *argv);
void	check_permission_outfile(char *argv);
void	parent_process(int *pfd, char **argv, char **env);
void	child_process(int *pfd, char **argv, char **env);
void	exit_with_menssage(char *menssage, int	exit_code);
#endif
