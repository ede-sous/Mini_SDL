/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msdl_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeletan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 02:52:58 by adeletan          #+#    #+#             */
/*   Updated: 2017/11/16 05:14:51 by adeletan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minisdl.h"

static int MSDL_SDL_Init(uint32_t flags)
{
	(void)flags;
	#ifdef SDL_h_
	if (SDL_Init(flags) != 0)
	{
		ft_putendl_fd("SDL: Init error.", 2);
		return (1);
	}
	#else
   		ft_putendl_fd("SDL: Not included.", 2);
	#endif
	return (0);
}

static int		MSDL_IMAGE_Init(int sdlimage)
{
	(void)sdlimage;
	#ifdef _SDL_IMAGE_H
		if (sdlimage != -1 && IMG_Init(sdlimage) != sdlimage)
		{
			ft_putendl_fd("SDL_Image: Init error", 2);
			return (1);
		}
	#else
		ft_putendl_fd("SDL_IMAGE: Not included.", 2);
	#endif
	return (0);
}

static int MSDL_TTF_Init(int sdlttf)
{
	(void)sdlttf;
	#ifdef _SDL_TTF_H
		if (sdlttf != -1 && TTF_Init() == -1)
		{
			ft_putendl_fd("SDL_TTF: Not included", 2);
			return (1);
		}
	#else
		ft_putendl_fd("SDL_TTF: Not included.", 2);
	#endif
	return (0);
}

int		MSDL_Init(uint32_t sdl, int sdlimage, int sdlttf)
{
	if (MSDL_SDL_Init(sdl) != 0)
		return (1);
	if (MSDL_IMAGE_Init(sdlimage) != 0)
		return (2);
	if (MSDL_TTF_Init(sdlttf) != 0)
		return (3);
	return (0);
}
