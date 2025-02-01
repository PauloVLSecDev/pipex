/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:25:21 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/02/01 17:02:36 by pvitor-l         ###   ########.fr       */
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

void	ft_free_split(char **array);
char	*get_valid_path(char **env, char *cmd);
char	**ft_find_path(char **env);
char	*ft_validade_command(char **path, char *cmd);
char	**split_cmd(char *cmd);
int	check_permission_infile(char *infile);
int	check_permission_outfile(char *outfile);
void	parent_process(int *pfd, char **argv, char **env);
void	child_process(int *pfd, char **argv, char **env);
void	exit_code(void *args, int code, char *cmd);
int	cmd_exist(char *cmd, char **env, int *pipe_fd);
void	close_pipe(int *pipe_fd);
#endif
