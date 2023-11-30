/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:19:23 by bcarolle          #+#    #+#             */
/*   Updated: 2023/11/30 17:16:19 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 1920
# define HEIGHT 900
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

#endif
