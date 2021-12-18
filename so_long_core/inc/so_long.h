/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 15:37:50 by ercordho          #+#    #+#             */
/*   Updated: 2021/12/18 02:03:13 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef __APPLE__
#  define __APPLE__ 0
# endif

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# if __APPLE__ == 1
#  include "../../minilibx-mac/mlx.h"
#  define W_KEY			13
#  define A_KEY			0
#  define S_KEY			1
#  define D_KEY			2
#  define ESC_KEY		53
# else
#  include "../../minilibx-linux/mlx.h"
#  define W_KEY 		119
#  define A_KEY			97
#  define S_KEY			115
#  define D_KEY 		100
#  define ESC_KEY 		65307
# endif

/*
**	EXT
*/
# define EXT			".ber"

/*
**	IMG SIZE
*/
# define IMG_SIZE		35

/*
**	SET MAP ID
*/
# define SET			"PEC01"

/*
**	GNL BUFFER
*/
# define BUFFER_SIZE	1

/*
**	SPRITES PATHS
*/
# define PLAYER			"sprites/player.xpm"
# define EXIT			"sprites/exit.xpm"
# define ITEM			"sprites/item.xpm"
# define GROUND			"sprites/ground.xpm"
# define WALL			"sprites/wall.xpm"

typedef struct s_file
{
	const char			*set;
	int					file_descriptor;
	const char			*file_path;
	const char			*file_ext;
	char				*line;
	const char			*content;
	int					pos_x;
	int					pos_y;
}						t_file;

typedef struct s_dot
{
	int					x;
	int					y;
	int					z;
}						t_dot;

typedef struct s_move
{
	t_dot				up;
	t_dot				right;
	t_dot				down;
	t_dot				left;
}						t_move;

typedef struct s_map
{
	char				**content;
	int					pos_y;
	int					pos_x;
	int					length;
	int					count_of_player;
	int					count_of_exit;
	int					count_of_item;
	int					count_of_empty;
	int					count_of_move;
	t_dot				player_pos;
	int					is_finish;
	int					walkable_surface;
}						t_map;

typedef struct s_img
{
	void				*ptr;
	void				*data;
	int					ll;
	int					bpp;
	int					endian;
}						t_img;

typedef struct s_sprite
{
	t_img				*img;
	const char			**paths;
}						t_sprites;

typedef struct s_mlx
{
	void				*ptr;
	void				*win;
	t_move				move;
	t_map				map;
	t_img				img;
	t_sprites			sprites;
	int					end;
}						t_mlx;

/*
**	ASCII
*/
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_ischarset(const char *set, char c);
int			ft_isdigit(int c);

/*
**	DOT
*/
t_dot		dot_add(t_dot a, t_dot b);

/*
**	DRAW
*/
int			draw_map(t_mlx *mlx);

/*
**	ERROR
*/
int			error_bad_ext(const char *ext, int file_descriptor);
int			error_extract_file_content(t_file *file);
int			error_fee_many_arg(int argc);
int			error_file_not_found(const char *file_path);
void		error_malloc(void);
int			error_map_is_empty(void);
int			error_map_is_too_small(long map_len);
int			error_map_isnt_rectangular(long x, long y);
int			error_no_ext(int file_descriptor);
int			error_parse_map_count_of_exit(long count_of_exit);
int			error_parse_map_count_of_item(void);
int			error_parse_map_count_of_player(long count_of_player);
int			error_parse_map_len(t_map map, long line_len);
int			error_parse_map_min_len(long line_pos, long line_len);
int			error_parse_map_side(t_map map);
int			error_parse_map_uppper_lower(t_map map);
int			error_sprites_not_found(const char *file_path);
void		error_too_much_movement(t_mlx *mlx);

/*
**	EVENTS
*/
int			close_windows(t_mlx *mlx);
void		eventhandler(t_mlx *mlx);
int			get_key_down(int keycode, t_mlx *mlx);
void		move_player(t_mlx *mlx, t_dot move);

/*
**	FILE
*/
char		*file_get_content(t_file *file, int line_can_be_empty);
int			file_get_data(t_file *file, int line_can_be_empty);
const char	*file_get_ext(t_file file);
int			file_init_data(t_file *file);

/*
**	INIT
*/
int			init_map(t_map *map, const char *map_content);
int			init_mlx(t_mlx	*mlx);
void		init_move(t_move *move);
int			init_sprites(t_sprites *sprites, void *mlx_ptr, int i);

/*
**	MEMORY
*/
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		ft_memdel(void **ptr);
void		ft_memdels(void **ptr, void **content);
void		*ft_memset(void *ptr, int c, size_t start, size_t end);
void		*ft_memsetmal(int c, size_t len);
void		*ft_realloc(void *ptr, size_t n_size, size_t o_size);

/*
**	PARSE
*/
int			parse_file(t_file *file, const char *set, const char *file_path);
int			parse_map(t_map *map, const char *map_content);

/*
**	READ
*/
int			get_next_line(int file_descriptor, char **line);

/*
**	STRING
*/
int			countwords(const char *str, const char *set);
char		**ft_split(const char *str, const char *set);
char		*ft_strcat(char *dst, const char *src);	
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strdup(const char *str);
size_t		ft_strlen(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strslen(const char **strs);

/*
**	success
*/
int			success_extract_file_content(t_file *file);
int			success_file_found(const char *file_path);
int			success_game_is_finish(t_mlx *mlx);
int			success_map_check(const char **map);
int			success_sprites_found(const char *file_path);

/*
**	WRITE
*/
size_t		ft_putchar(char c);
size_t		ft_putendl(const char *str);
size_t		ft_putendls(const char **strs);
size_t		ft_putnbr(long nbr);
size_t		ft_putstr(const char *str);
size_t		ft_putstrs(const char **strs);

/*
**
*/
void		so_long(t_map map);

#endif
