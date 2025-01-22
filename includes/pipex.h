/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:25:21 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/01/22 19:05:57 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H 
# define EXIT_FAILURE

# include <stdlib.h> 
# include <unistd.h> 
# include <fcntl.h> 
# include <stdlib.h> 
# include <stdio.h>
# include <string.h>
# include "../libft/libft.h"

char	**ft_find_path(char **env);
char	*ft_validade_command(char **path, char *cmd);
char	**split_cmd(char *cmd);
void		exit_with_menssage(char *menssage, int	exit_code);
void	args_error(int	exit_code);
void	second_process(int *p_fd, int otfd, char **env, char *cmd);
void	first_process(int *p_fd, int infd, char **env, char *cmd);
void	exit_with_menssage(char *menssage, int	exit_code);
#endif
