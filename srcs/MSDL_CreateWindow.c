/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MSDL_CreateWindow.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeletan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 05:17:58 by adeletan          #+#    #+#             */
/*   Updated: 2017/11/16 05:46:21 by adeletan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minisdl.h"

MSDL	*MSDL_CreateWindow(int w, int h, uint32_t flags)
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	MSDL			*msdl;

	SDL_CreateWindowAndRenderer(w, h, flags, &window, &renderer);
	if (!window || !renderer)
		return (NULL);
	if (!(msdl = (MSDL*)malloc(sizeof(*msdl))))
		return (NULL);
	msdl->window = window;
	msdl->renderer = renderer;
	return (msdl);
}
