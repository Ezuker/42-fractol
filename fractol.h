/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:19:23 by bcarolle          #+#    #+#             */
/*   Updated: 2023/12/01 13:09:10 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 1920
# define HEIGHT 1000
# define MANDELBROTXMIN -2.1
# define MANDELBROTXMAX 0.6
# define MANDELBROTYMIN -1.2
# define MANDELBROTYMAX 1.2
# define BUFFER_SIZE 1000

# include "./MLX/include/MLX42/MLX42_Int.h"
# include "./MLX/include/MLX42/MLX42.h"
# include "./ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include <math.h>

typedef struct s_complex
{
	double	real;
	double	img;
}				t_complex;

void		mandelbrot(void);
double		pow_2(t_complex z);
t_complex	mandelbrot_calcul(t_complex pixel, t_complex c);
uint32_t	get_color(double iter);

#endif
