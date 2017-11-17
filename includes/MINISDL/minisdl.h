/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minisdl.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeletan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 02:26:08 by adeletan          #+#    #+#             */
/*   Updated: 2017/11/16 06:17:08 by adeletan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MINISDL_H

# define MINISDL_H

# include "libft.h"
# include <stdint.h>
# include "SDL.h"
# include "SDL_image.h"
# include "SDL_ttf.h"

# define SCREENWIDTH    1920
# define SCREENHEIGHT   1280
# define SQUAREWIDTH    20
# define SQUAREHEIGHT   20

typedef struct MSDL_H
{
	SDL_Window				*window;
	SDL_Renderer			*renderer;
	struct MSDL_Texture_H	*textures;
}				MSDL;			

typedef struct	MSDL_Sprites_H
{
	char					*name;
	SDL_Rect				info;
	SDL_Surface				*sprite;
	struct MSDL_Sprites_H	*next;				
}				MSDL_Texture;

int				MSDL_Init(uint32_t sdl, int sdlimage, int sdlttf);
MSDL			*MSDL_CreateWindow(int w, int h, uint32_t flags);
MSDL_Sprites	*MSDL_InitSprites(void);
MSDL_Sprites	*MSDL_GetSpritesGlobal(MSDL_Sprites *sprites);
MSDL_Sprites	*MSDL_AppendSprites(void);
int				*MSDL_DeleteSprites(const char *name);
MSDL_Sprites	*MSDL_GetSprites(const char *name);
void			*MSDL_DeleteSprites(void);

#endif
