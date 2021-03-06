/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouz <adouz@1337.MA>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 12:08:01 by adouz             #+#    #+#             */
/*   Updated: 2018/10/19 17:53:25 by adouz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	char	z;

	z = 0;
	if (n == -2147483648)
	{
		z = 1;
		n += 1;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		c = (n % 10) + z + '0';
		write(fd, &c, 1);
	}
	if (n <= 9)
	{
		c = n + '0';
		write(fd, &c, 1);
	}
}
