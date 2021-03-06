/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 01:32:28 by lscariot          #+#    #+#             */
/*   Updated: 2016/02/27 12:13:46 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <sys/stat.h>
# include <dirent.h>
# include <sys/types.h>
# include <pwd.h>
# include <unistd.h>
# include <grp.h>
# include <time.h>
# include <uuid/uuid.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct	s_args
{
	int		l;
	int		br;
	int		a;
	int		r;
	int		t;
	int		i;
	char	**link;
	int		fns;
	int		rec;
}				t_args;

typedef struct	s_lenmax
{
	int		name;
	int		links;
	int		user;
	int		group;
	int		size;
	int		month;
	int		number;
	int		hour;
}				t_lenmax;

typedef	struct	s_files
{
	char			*name;
	char			*time;
	char			*modes;
	char			*links;
	char			*user;
	char			*group;
	char			*size;
	char			*month;
	char			*number;
	char			*hour;
	int				nb_blocks;
	struct s_files	*next;
}				t_files;

int				ft_check_args(int ac, char **av, t_args *args);
t_files			*ft_readdirr(char *filename, t_args args, int *err);
t_files			*ft_infofile(t_files *file, char *adress);
void			ft_show_files(char *fl, t_files *files, t_args args, int err);
t_files			*ft_list_simple_bot(t_files *files, char *filename);
t_files			*ft_list_big_bot(t_files *files, char *adress, char *file);
void			ft_tri_links(t_args *args);
void			ft_error_tri(t_args *args);
void			ft_tri_files(t_files *files, t_args args);
void			ft_tri_time(t_files *files, t_args args);
void			ft_swap_list(t_files *dest, t_files *src, int l, int *fail);
void			ft_free_files(t_files *files);
void			ft_recursive(char *filename, t_args args, int *err);
int				ft_isdir(char *filename);
int				ft_isopen(char *filename);
int				ft_isperm(char *filename);
int				ft_isfile(char *filename);
void			ft_free_list(t_files *files, t_args args);
void			ft_free_args(t_args *args);
void			ft_free_one(t_files *files, int l);
void			ft_free_tab(char **tab);
char			*ft_print_time(time_t *time, t_files *file);
int				ft_count_total(t_files *files);
t_lenmax		ft_maxlen(t_files *files);
int				ft_list_len(t_files *files);
char			*ft_show_modes(int mode);
int				ft_check_errors(char *filename, t_args args, int *err);
void			ft_one_file(char *filename, t_args args);
void			ft_set_vars(int *i, int *f, int *l);
t_files			*ft_norme_read(char *fname, char *n, t_files *fes, t_args a);
void			ft_file_name_norme(char *fl, t_args args, int *i, int err);

void			ft_show_l(t_files *files, t_lenmax max);
void			ft_putspace(int s, char	*str);
void			ft_spaceput(int s, char	*str);
int				ft_mn(char *month);
int				ft_dn(char *day);
int				ft_tcp(char *link, char *time1, char *time2);
int				ft_rtp(char *link, char *time1, char *time2);
long			ft_get_time(char *file);
void			ft_tri(t_files *files, t_args args);
char			*ft_readlink(char *name, char *ln);
char			*ft_s(int b, int a);

void			ft_error_opt(char c);
void			ft_error_file(char *file);
void			ft_error_perm(char *file, t_args args);

void			ft_m_0(char *m, int mode);
void			ft_m_3(char *m, int mode);
void			ft_m_6(char *m, int mode);
void			ft_m_9(char *m, int mode);

void			ft_no_link(t_args *args);
int				ft_dir_recursive(char *chemin, char *filename);
#endif
