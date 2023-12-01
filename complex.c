/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 20:02:48 by bcarolle          #+#    #+#             */
/*   Updated: 2023/12/01 13:18:33 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	pow_2(t_complex z)
{
	return (z.real * z.real + (z.img * z.img));
}

t_complex	mandelbrot_calcul(t_complex pixel, t_complex c)
{
	t_complex	result;

	result.real = (pixel.real * pixel.real) - (pixel.img * pixel.img) + c.real;
	result.img = 2 * pixel.real * pixel.img + c.img;
	return (result);
}

uint32_t	get_color(double iter)
{
	uint8_t	r = (uint8_t)((0.0 - iter) * 255);
	uint8_t	g = (uint8_t)((0.2 - iter) * 255);
	uint8_t	b = (uint8_t)((1.0 - iter) * 255);
	uint8_t	a = 255;

	return ((a << 24) | (r << 16) | (g << 8) | b);
}
