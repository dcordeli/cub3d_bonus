/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 22:03:29 by dcordeli          #+#    #+#             */
/*   Updated: 2020/12/09 22:03:32 by dcordeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc(char *ptr, size_t size)
{
	char *new_ptr;

	if (ptr == NULL)
	{
		new_ptr = (char *)malloc((size + 1) * sizeof(char));
		if (new_ptr == NULL)
			return (NULL);
		new_ptr[0] = 0;
	}
	else
	{
		new_ptr = (char *)malloc((ft_strlen(ptr) + size + 1) *
				sizeof(char));
		if (new_ptr == NULL)
			return (NULL);
		ft_strlcpy(new_ptr, ptr, ft_strlen(ptr) + size + 1);
		free(ptr);
	}
	return (new_ptr);
}
