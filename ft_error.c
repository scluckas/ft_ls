/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 12:47:54 by lscariot          #+#    #+#             */
/*   Updated: 2016/02/23 13:34:41 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_error_opt(char c)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(c);
	ft_putstr("\nusage: ft_ls [-Ralrt] [file ...]\n");
	exit(0);
}

void	ft_error_file(char *file)
{
	ft_putstr("ft_ls: ");
	ft_putstr(file);
	ft_putendl(": No such file or directory");
}

void    ft_error_tri(t_args *args)
{
	int i;

	i = 0;
	while (args->fns > i)
	{
		if (!ft_isdir(args->link[i]))
			ft_error_file(args->link[i]);
		i++;
	}
}
