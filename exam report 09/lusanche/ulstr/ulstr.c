/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 09:10:53 by exam              #+#    #+#             */
/*   Updated: 2019/07/02 09:16:56 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ulstr(char *s)
{
	char	c;
	
	while (*s)
	{
		c = *s;
		if (*s >= 'a' && *s <= 'z')
			c = *s - 32;
		else if (*s >= 'A' && *s <= 'Z')
			c = *s + 32;
		write(1, &c, 1);
		++s;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		ulstr(av[1]);
	write(1, "\n", 1);
	return (0);
}