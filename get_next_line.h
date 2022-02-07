/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorel <jmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 10:17:58 by jmorel            #+#    #+#             */
/*   Updated: 2022/01/25 16:19:33 by jmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int		ft_strlen_gnl(char *str);
char	*ft_strchr_gnl(char	*s, int c);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_free_gnl(char *line);
char	*the_line_gnl(char *line);
char	*the_end_of_the_line_gnl(char *line);
char	*other_gnl(int fd, char *buffer);
char	*get_next_line(int fd);
#endif
