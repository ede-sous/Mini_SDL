/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeletan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 02:26:53 by adeletan          #+#    #+#             */
/*   Updated: 2017/11/16 05:37:15 by adeletan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minisdl.h"

int main(int ac, char *av[])
{
	MSDL	*main;
	(void)av;
	(void)ac;
	MSDL_Init(SDL_INIT_VIDEO, ~0, 0);
	main = MSDL_CreateWindow(500, 500, SDL_WINDOW_RESIZABLE);
	return (0);
}
