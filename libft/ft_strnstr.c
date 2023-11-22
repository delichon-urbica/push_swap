/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:42:58 by lde-ross          #+#    #+#             */
/*   Updated: 2023/01/16 15:02:37 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haylist, const char *needle, size_t len)
{
	size_t	i;
	int		needle_l;

	if (!*needle)
		return ((char *)haylist);
	if (len == 0)
		return (0);
	i = 0;
	needle_l = ft_strlen((char *)needle);
	while (haylist[i] && i < len - needle_l + 1)
	{
		if (ft_strncmp((char *)&haylist[i], (char *)needle, needle_l) == 0)
			return ((char *)&haylist[i]);
		i++;
	}
	return (0);
}
