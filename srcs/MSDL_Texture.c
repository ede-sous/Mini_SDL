/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MSDL_Texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeletan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 05:46:44 by adeletan          #+#    #+#             */
/*   Updated: 2017/11/16 06:17:34 by adeletan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minisdl.h"

MSDL_Sprites	*MSDL_InitSprite(void)
{
	MSDL_Sprites	*Sprite;
	if (!(texture = (MSDL_Texture*)malloc(sizeof(*texture))))
		return (NULL);
	texture->name = NULL;
	texture->info->w = 0;
	texture->info->h = 0;
	texture->info->x = 0;
	texture->info->y = 0;
	texture->texture = NULL;
	texture->next = NULL;
	return (texture);
}

MSDL_Texture	*MSDL_GetTextureGlobal(MSDL_Texture	*texture)
{
	static MSDL_Texture *currenttexture = NULL;

	if (texture)
		currenttexture = texture;
	if (currenttexture == NULL)
		currenttexture = MSDL_InitTexture();
	return (currenttexture);
}

MSDL_Texture *MSDL_AppendTexture(void)
{
	MSDL_Texture *current;

	current = MSDL_GetTextureGlobal(NULL);
	while (current->next)
		current = current->next;
	current->next = MSDL_InitTexture();
	return (current->next);
}

int		MSDL_DeleteTexture(const char *name)
{
	MSDL_Texture	*texture;
	MSDL_Texture	*prev;
	if (!name)
		return (0);
	texture = MSDL_GetTextureGlobal(NULL);
	prev = texture;
	while (texture && ft_strcmp(texture->name, name) != 0)
	{
		prev = texture;
		texture = texture->next;
	}
	if (texture)
	{
		ft_strdel(&(texture->name));
		SDL_DestroyTexture(texture->texture);
		if (texture->next)
			prev->next = texture->next;
		else
			prev->next = NULL;
		free(texture);
		return (1);
	}
	return (0);
}

MSDL_Texture	*MSDL_GetTexture(const char *name)
{
	MSDL_Texture	*texure;

	texture = MSDL_GetTextureGlobal(NULL);
	if (!name)
		return (NULL)
	while (texture && ft_strcmp(texture->name, name) != 0)
		texture = texture->next;
	if (texture)
		return (texture);
	return (NULL);	
}

void		MSDL_DeleteTextures(void)
{
	MSDL_Texture	*texture;
	MSDL_Texture	*prev;

	texture = MSDL_GetTextureGlobal(NULL);
	prev = texture;
	while (texture)
	{
		if (texture->name)
			ft_strdel(texture->name);
		if (texture->texture)
			SDL_DestroyTexture(texture->texture);
		texture = texture->next;
		free(prev);
		prev = texture;	
	}
}

MSDL_Texture	*MSDL_CreateTextureFromImage(const char *name, const char *path)
{
	return (NULL);
}
