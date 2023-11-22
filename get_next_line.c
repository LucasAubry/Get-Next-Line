/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laubry <laubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:04:41 by laubry            #+#    #+#             */
/*   Updated: 2023/11/22 15:57:21 by laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

char	*ft_strjoin_and_free_s1(char *s1, char *buffer)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	dest = malloc(sizeof(char) * (ft_strlen_char(s1, '\n') + ft_strlen_char(buffer, '\n') + 1));
	if (dest != NULL)
	{
		while (s1 && s1[i] != '\0')
		{
			dest[i] = s1[i];
			i++;
		}
		while (buffer && buffer[j] && buffer[j] != '\n')
		{
			dest[i + j] = buffer[j];
			j++;
		}
		dest[i + j] = '\n';
		if (buffer[j] == '\n')
			j++;
		dest[i + j] = '\0';
	}
	return (ft_strjoin_and_free_s1_2(s1, dest));
}

int	ft_chr_line(char *buffer)
{
	int	i;

	i = 0;
	if (buffer == NULL)
		return (1);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		return (0);
	return (1);
}

void	ft_cut_buff(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	while (buffer[i] != '\0')
	{
		buffer[j] = buffer[i];
		i++;
		j++;
	}
	buffer[j] = '\0';
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1] = {0};
	int			bytes_read;
	char		*dest;

	bytes_read = 1;
	dest = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (ft_chr_line(buffer) == 0)
	{
		ft_cut_buff(buffer);
		dest = ft_strjoin_and_free_s1(dest, buffer);
	}
	while (bytes_read > 0 && ft_chr_line(buffer) == 1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (dest);
		buffer[bytes_read] = '\0';
		dest = ft_strjoin_and_free_s1(dest, buffer);
	}
	return (dest);
}
int main() {
	int fd = open("exemple.txt", O_RDONLY);
    char *ligne;
	int b;
	
	ligne = get_next_line(fd);
	printf("LigneLue: %s\n", ligne);
	free(ligne);

    // Appeler get_next_line jusqu'à ce que la fin du fichier soit atteinte
    // while ((ligne = get_next_line(fd)) != NULL) {
    //     printf("Ligne lue : %s\n", ligne);
    //     free(ligne);  // Libérer la mémoire allouée dynamiquement
    // }

    close(fd);

    return 0;
}


