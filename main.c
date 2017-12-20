/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 21:43:01 by lowczarc          #+#    #+#             */
/*   Updated: 2017/12/20 16:18:19 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>

int		main(void)
{
	//setlocale(LC_ALL, "");
/*	
	int	i;
	int j;
	i = ft_printf("%Stest ! bonjour ! %0-+- -1578.678s ! truc ! %0-0 54.58ll%\n", L"éponge", "le manger, c'est bon, mangez en !");
	j = printf("%Stest !%d bonjour ! % -0+--1578.678s ! truc ! %0-0 54.58ll%\n", L"éponge", "le manger, c'est bon, mangez en !");
	printf("%d, %d", i, j);
	return (0);*/
	/*ft_printf("%.16b\n", t);
	while (ret[i])
		ft_printf("%.8hhb ", ret[i++]);*/
	ft_printf("%d\n", ft_printf("phrase : %s\n", "bonjour je suis un cahier"));
//	ft_printf("%hhu, %+.5d\n", 1000, 100);
//	ft_printf("%.16b\n%.16b\n", L'é', 50089);
//	ft_printf("%s, %S\n", ret, L"éhéo ,matelos !");
//	printf("%u, %S\n", 1000, L"éhéo ,matelos !");
}
