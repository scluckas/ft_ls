/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 16:34:08 by lscariot          #+#    #+#             */
/*   Updated: 2016/02/27 12:40:19 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_files		*ft_list_simple_bot(t_files *files, char *filename)
{
	t_files *new_file;
	t_files *tmp;

	new_file = malloc(sizeof(t_files));
	if (!new_file)
		return (NULL);
	new_file->name = ft_strdup(filename);
	new_file->next = NULL;
	if (!files)
		return (new_file);
	else
	{
		tmp = files;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_file;
		return (files);
	}
	return (new_file);
}

t_files		*ft_list_big_bot(t_files *files, char *adress, char *file)
{
	t_files *new_file;
	t_files *tmp;

	new_file = malloc(sizeof(t_files));
	if (!new_file)
		return (NULL);
	new_file->name = ft_strdup(file);
	new_file->time = ft_strdup(file);
	ft_infofile(new_file, adress);
	if (!files)
		return (new_file);
	else
	{
		tmp = files;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_file;
		return (files);
	}
	return (new_file);
}
