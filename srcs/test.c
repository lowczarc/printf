/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:12:34 by lowczarc          #+#    #+#             */
/*   Updated: 2017/12/13 16:16:11 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int	main(void)
{
	setlocale(LC_ALL, "");
	printf ("%*.1*ls\n", 50, 10, L"Pour qui sont ces sont serpents qui sifflent sur vos têtes ?");
}
