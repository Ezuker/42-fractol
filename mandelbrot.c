/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 20:00:50 by bcarolle          #+#    #+#             */
/*   Updated: 2023/12/01 13:15:57 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel_mandelbrot(double x, double y, mlx_image_t *img)
{
	t_complex	pixel;
	t_complex	temp;
	t_complex	c;
	double		i;

	pixel.real = 0;
	pixel.img = 0;
	c.real = MANDELBROTXMIN + (x / WIDTH) * (MANDELBROTXMAX - MANDELBROTXMIN);
	c.img = MANDELBROTYMIN + (y / HEIGHT) * (MANDELBROTYMAX - MANDELBROTYMIN);
	i = 0.0;
	while (i < 1000.0 && pow_2(pixel) <= 4)
	{
		temp = pixel;
		pixel.real = temp.real * temp.real - temp.img * temp.img + c.real;
		pixel.img = 2 * temp.real * temp.img + c.img;
		i++;
	}
	if (i != 1000.0)
		i = i + 1 - log(log2(sqrt(pow_2(pixel))));
	if (i == 1000.0)
	{
		mlx_put_pixel(img, x, y, 0x000000FF);
		mlx_put_pixel(img, x, HEIGHT - y, 0x000000FF);
	}
	else
	{
		mlx_put_pixel(img, x, y, get_color(i));
		mlx_put_pixel(img, x, HEIGHT - y, get_color(i));
	}
}

void	put_mandelbrot(mlx_image_t *img)
{
	double	x;
	double	y;

	x = 0.0;
	y = 0.0;
	while (x < WIDTH)
	{
		while (y < (HEIGHT / 2) + 2)
		{
			put_pixel_mandelbrot(x, y, img);
			y++;
		}
		y = 0.0;
		x++;
	}
	ft_printf("Fait !");
}

void	mandelbrot(void)
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	mlx = mlx_init(WIDTH, HEIGHT, "Fractol", true);
	if (!mlx)
		return ;
	img = mlx_new_image(mlx, WIDTH - 1, HEIGHT - 1);
	memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));
	put_mandelbrot(img);
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
		exit(1);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
