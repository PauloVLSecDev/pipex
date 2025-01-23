/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:22:29 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/01/23 20:28:21 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
# include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*s3;
	size_t		size;
	int			i;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	s3 = (char *)malloc(size + 1);
	if (!s3)
		free(s3);
		return (NULL);
	while (*s1)
		s3[i++] = *s1++;
	while (*s2)
		s3[i++] = *s2++;
	s3[i] = '\0';
	return (s3);
}

int	main(void)
{
	char *isto = "juntar";
	char *isso = " juntado";

	printf("printou %s", ft_strjoin(isto, isso));
	free(isto);
	free(isso);
}


