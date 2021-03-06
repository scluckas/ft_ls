/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 08:41:44 by lscariot          #+#    #+#             */
/*   Updated: 2016/02/27 12:05:51 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_spaceput(int s, char *str)
{
	int len;

	len = (s - ft_strlen(str)) + 1;
	ft_putchar(' ');
	ft_putstr(str);
	ft_putnchar(' ', len);
}

void	ft_putspace(int s, char *str)
{
	int len;

	len = (s - ft_strlen(str)) + 1;
	ft_putnchar(' ', len);
	ft_putstr(str);
}

void	ft_show_l(t_files *files, t_lenmax max)
{
	ft_putstr(files->modes);
	ft_putspace(max.links, files->links);
	ft_spaceput(max.user, files->user);
	ft_spaceput(max.group - 2, files->group);
	ft_putspace(max.size, files->size);
	ft_putspace(max.month, files->month);
	ft_putspace(max.number, files->number);
	ft_putspace(max.hour, files->hour);
	ft_putstr(" ");
}

void	ft_show_files(char *fl, t_files *files, t_args args, int err)
{
	t_files		*tmp;
	static int	i;
	t_lenmax	max;

	ft_file_name_norme(fl, args, &i, err);
	i++;
	if (files == NULL)
		return ;
	if (args.l)
	{
		max = ft_maxlen(files);
		ft_count_total(files);
	}
	while (files != NULL)
	{
		if (args.l)
			ft_show_l(files, max);
		ft_putendl(files->name);
		tmp = files;
		files = files->next;
	}
}
