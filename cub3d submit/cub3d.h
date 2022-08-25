typedef struct	s_img {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct	s_vec2 {
	double		x;
	double		y;
}				t_vec2;

typedef struct	s_ray2 {
	t_vec2		pos;
	t_vec2		way;
}				t_ray2;

typedef struct	s_player {
	t_vec2		pos;
	t_vec2		dir;
	t_vec2		plane;
	int			is_moving;
	int			is_sidling;
	int			is_rotating;
}				t_player;

typedef struct	s_texture {
	t_img		img;
	int			width;
	int			height;
}				t_texture;

typedef struct	s_game {
	void		*mlx;
	void		*win;
	t_img		img;
	int			screen_width;
	int			screen_height;
	t_player	player;
	char		**map;
	int			map_row;
	int			map_col;
	t_img		tex_n;
	t_img		tex_s;
	t_img		tex_w;
	t_img		tex_e;
	int			tex_width;
	int			tex_height;
	uint32_t	sky_color;
	uint32_t	ground_color;
	double		height_base;

	int			sprite_num;
	t_vec2		*sprites;
	int			sprite_width;
	int			sprite_height;
	t_img		tex_sprite;
	double		*z_buffer;
	double		*sprite_dists;
}				t_game;

typedef struct	s_sprite_vis_info {
	double		transform_x;
	double		transform_y;
	int			screen_x;
	int			height;
	int			draw_start_y;
	int			draw_end_y;
	int			width;
	int			draw_start_x;
	int			draw_end_x;
}				t_sprite_vis_info;

typedef struct	s_ray {
	double		camera_x;
	t_vec2		dir;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		perp_wall_dist;
	int			side;
	int			step_x;
	int			step_y;
	double		delta_dist_x;
	double		delta_dist_y;
	t_img		*tex;
}				t_ray;

typedef struct	s_wall_vis_info {
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		wall_x;
	int			texture_x;
	double		step;
	double		texture_pos_y;
	int			texture_y;
}	