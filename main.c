/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 21:43:01 by lowczarc          #+#    #+#             */
/*   Updated: 2017/12/08 16:27:13 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
/*	
	int	i;
	int j;
	i = ft_printf("%Stest ! bonjour ! %0-+- -1578.678s ! truc ! %0-0 54.58ll%\n", L"éponge", "le manger, c'est bon, mangez en !");
	j = printf("%Stest !%d bonjour ! % -0+--1578.678s ! truc ! %0-0 54.58ll%\n", L"éponge", "le manger, c'est bon, mangez en !");
	printf("%d, %d", i, j);
	return (0);*/
	ft_printf("%lu, %010d\n", 100000000000, -100);
	printf("%lu, %010d\n", 100000000000, -100);
}
