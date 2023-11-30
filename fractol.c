/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:18:26 by bcarolle          #+#    #+#             */
/*   Updated: 2023/11/30 18:00:56 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	mandelbrot_calcul(t_complex pixel, t_complex c)
{
	t_complex	result;

	result.real = (pixel.real * pixel.real) - (pixel.img * pixel.img) + c.real;
	result.img = 2 * pixel.real * pixel.img + c.img;
	return (result);
}
// char *	get_hexa(int number)
// {
// 	int	modulo;
// 	int	total;

// 	if (number >= 16)
// 	{
// 		modulo = number % 16;
// 		write_hexa(modulo, xORX);
// 	}
// 	else
// 		write_hexa(n, xORX);
// 	return (total);
// }

uint32_t	get_color(double iter, double max_iter)
{
	uint32_t	hue;
	int			saturation;
	int			value;

	hue = (int)(255 * iter / max_iter);
	saturation = 255;
	value = 255;
	if (iter == max_iter)
		value = 0;
	return (hue * saturation * value);
}

double	pow_2(t_complex z)
{
	return (z.real * z.real + (z.img * z.img));
}

void	put_pixel_mandelbrot(double x, double y, mlx_image_t *img)
{
	t_complex	pixel;
	t_complex	temp;
	t_complex	c;
	double		i;

	pixel.real = 0;
	pixel.img = 0;
	c.real = MANDELBROTXMIN + (x / WIDTH * 0.900) * (MANDELBROTXMAX - MANDELBROTXMIN);
	c.img = MANDELBROTYMIN + (y / HEIGHT * 0.900) * (MANDELBROTYMAX - MANDELBROTYMIN);
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
		mlx_put_pixel(img, x, y, get_color(i, 1000.0));
		mlx_put_pixel(img, x, HEIGHT - y, get_color(i, 1000.0));
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

char	*get_option(void)
{
	char	*buffer;
	int		n_byte;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	ft_printf("\033[38;2;255;0;0m _____               _   _       _\n");
	ft_printf("\033[38;2;255;128;0m| ____|             | | ( )     | |\n");
	ft_printf("\033[38;2;255;255;0m|__ _ __ __ _    ___| |_ \\| ___ | |\n");
	ft_printf("\033[38;2;128;255;0m|  __| '__/ _` |/ __| __|  / _ \\| |\n");
	ft_printf("\033[38;2;0;255;0m| |  | | | (_| | (__| |_  | (_) | |\n");
	ft_printf("\033[38;2;0;255;128m|_|  |_|  \\__,_|\\___|\\__|  \\___/|_|");
	ft_printf("\n\n\033[38;2;20;100;20m");
	ft_printf("	Choose a fractal :\n\n");
	ft_printf(" => Mandelbrot\n");
	ft_printf(" => Julia\n");
	n_byte = read(0, buffer, BUFFER_SIZE);
	buffer[n_byte] = '\0';
	return (buffer);
}

int	main(void)
{
	char	*option;

	option = get_option();
	if (!ft_strcmp(option, "Mandelbrot\n"))
	{
		mandelbrot();
	}
	else if (!ft_strcmp(option, "Julia\n"))
	{
		ft_printf("In progress...\n");
		free(option);
		option = get_option();
	}
	else
	{
		free(option);
		option = get_option();
	}
	free(option);
}
