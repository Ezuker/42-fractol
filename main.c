/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:18:26 by bcarolle          #+#    #+#             */
/*   Updated: 2023/11/30 20:03:13 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_option(void)
{
	ft_printf("\033[38;2;255;0;0m	 _____               _   _       _\n");
	ft_printf("\033[38;2;255;128;0m	| ____|             | | ( )     | |\n");
	ft_printf("\033[38;2;255;255;0m	|__ _ __ __ _    ___| |_ \\| ___ | |\n");
	ft_printf("\033[38;2;128;255;0m	|  __| '__/ _` |/ __| __|  / _ \\| |\n");
	ft_printf("\033[38;2;0;255;0m	| |  | | | (_| | (__| |_  | (_) | |\n");
	ft_printf("\033[38;2;0;255;128m	|_|  |_|  \\__,_|\\___|\\__|  \\___/|_|\n");
	ft_printf("\033[38;2;20;100;20m\n");
	ft_printf("\n	Good usage -> ./fractol [Fractal Name]\n");
	ft_printf("\nChoose a fractal :\n\n");
	ft_printf(" => Mandelbrot\n");
	ft_printf(" => Julia\n");
	ft_printf(" => Other\n\n");
}

int	main(int argc, char **argv)
{

	(void)argv;
	if (argc < 2)
	{
		print_option();
		exit(1);
	}
	if (!ft_strcmp(argv[1], "Mandelbrot"))
	{
		mandelbrot();
	}
	else if (!ft_strcmp(argv[1], "Julia"))
	{
		ft_printf("In progress...\n");
	}
	else if (!ft_strcmp(argv[1], "Other"))
	{
		ft_printf("In progress...\n");
	}
}
