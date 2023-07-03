/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaudet <bmaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 17:48:00 by bmaudet           #+#    #+#             */
/*   Updated: 2021/06/07 17:48:02 by bmaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*get_next_str(char *str)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (0);
	}
	if (go_malloc((void *)&dest, (sizeof(char) * ((ft_strlen(str) - i) + 1))))
		return (0);
	i++;
	while (str[i])
		dest[j++] = str[i++];
	dest[j] = '\0';
	free(str);
	return (dest);
}

char	*get_line_return(char *str, char **buff)
{
	int		i;
	char	*dest;

	i = 0;
	free(*buff);
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (go_malloc((void *)&dest, (sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	get_next_line(int fd, char **line)
{
	char			*buff;
	static char		*str;
	int				i;

	i = 1;
	if (fd < 0 || !line || 32 <= 0)
		return (-1);
	if (go_malloc((void *)&buff, (sizeof(char) * (32 + 1))))
		return (-1);
	while (!check_return(str) && i != 0)
	{
		i = read(fd, buff, 32);
		if (i == -1)
		{
			free(buff);
			return (-1);
		}
		buff[i] = '\0';
		str = ft_strjoin(str, buff);
	}
	*line = get_line_return(str, &buff);
	str = get_next_str(str);
	if (i == 0)
		return (0);
	return (1);
}
