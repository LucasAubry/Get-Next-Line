/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laubry <laubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:28:04 by laubry            #+#    #+#             */
/*   Updated: 2023/11/22 15:55:24 by laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

int		ft_strlen_char(char *src, char c);
char	*ft_strjoin_and_free_s1_2(char *s1, char *dest);
char	*ft_strjoin_and_free_s1(char *s1, char *buffer);
int		ft_chr_line(char *buffer);
void	ft_cut_buff(char *buffer);
char	*get_next_line(int fd);

#endif
