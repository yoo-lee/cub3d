// screenはx座標を決めておいて その後、width 
// と　height でスクリーンを作る


int camerascreen()
{
    //calculate ray position and direction
    camera_x = 2 * x / screen_width -1;
    ray-> dir.x = dir.x + plane 
}
    double dir.x = ray->dir.x + planeX * camera_x;
    double dir.y = ray->dir.y + planeY * camera_x;


void	initialize_ray(t_game *game, t_ray *ray, int x)
{
	// カメラ平面上のx座標 (3D表示時の画面のx座標)  -1.0~1.0
	ray->camera_x = 2 * x / (double)game->screen_width - 1;
	ray->dir.x = game->player.dir.x + game->player.plane.x * ray->camera_x;
	ray->dir.y = game->player.dir.y + game->player.plane.y * ray->camera_x;
	// map: 現在対象としているマップ内の正方形を表す
	ray->map_x = (int)game->player.pos.x;
	ray->map_y = (int)game->player.pos.y;
	// deltaDistは, 光線が今の正方形から次の正方形に行くために移動する距離
	delta_dist_x = sqrt(1 + (dir.y * dir.y) / (dir.x * dir.x))
    delta_dist_y = sqrt(1 + (dir.x * dir.x) / (dir.y * dir.y))
    
	// step はどの方向に光線を動かすか。
	// とsideDistはプレイヤーの初期値
	ray->step_x = ray->dir.x < 0 ? -1 : 1;
	ray->side_dist_x = ray->dir.x < 0 ?
	  (game->player.pos.x - ray->map_x) * ray->delta_dist_x :
	  (ray->map_x + 1.0 - game->player.pos.x) * ray->delta_dist_x;
	ray->step_y = ray->dir.y < 0 ? -1 : 1;
	ray->side_dist_y = ray->dir.y < 0 ?
	  (game->player.pos.y - ray->map_y) * ray->delta_dist_y :
	  (ray->map_y + 1.0 - game->player.pos.y) * ray->delta_dist_y;
}


while (hit == 0)
      {
        //jump to next map square, either in x-direction, 
		// or in y-direction
        if (ray->side_dist_x < side_dist_y)
        {
          ray->side_dist_x += delta_dist_x;
          map_x += step_x;
          side = 0;
        }
        else
        {
          side_dist_y += delta_dist_y;
          map_y += step_y;
          side = 1;
        }
        //Check if ray has hit a wall
        if (worldMap[map_x][map_y] > 0) hit = 1;
      } 

// 壁までの光線の距離を計算する
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - game->player.pos.x +
			(1 - ray->step_x) / 2) / ray->dir.x;
	else
		ray->perp_wall_dist = (ray->map_y - game->player.pos.y +
			(1 - ray->step_y) / 2) / ray->dir.y;
	// 壁の当たった方角によってテクスチャを変更する
	if (ray->side == 0)
		ray->tex = (ray->step_x > 0) ? &game->tex_w : &game->tex_e;
	else
		ray->tex = (ray->step_y > 0) ? &game->tex_n : &game->tex_s;
}

void	calc_vis_info(t_game *game, t_ray ray, t_wall_vis_info *wall_vis, int x)
{
	// スクリーンに描画する必要のある縦線の長さを求める
	wall_vis->line_height = (int)(game->height_base / ray.perp_wall_dist);
	// 実際に描画すべき場所の開始位置と終了位置を計算
	wall_vis->draw_start = -wall_vis->line_height / 2 + game->screen_height / 2;
	if (wall_vis->draw_start < 0)
		wall_vis->draw_start = 0;
	wall_vis->draw_end = wall_vis->line_height / 2 + game->screen_height / 2;
	if (wall_vis->draw_end >= game->screen_height)
		wall_vis->draw_end = game->screen_height - 1;
	/* 当たった壁上の正確なx座標を求める */
	if (ray.side == 0)
	  wall_vis->wall_x = game->player.pos.y + ray.perp_wall_dist * ray.dir.y;
	else
	  wall_vis->wall_x = game->player.pos.x + ray.perp_wall_dist * ray.dir.x;
	wall_vis->wall_x -= floor(wall_vis->wall_x);  // 正方形のどの部分にヒットしたのか0.0~1.0で表す
	// テクスチャ上のx座標 (0~TEXTURE_WIDTH)
	wall_vis->texture_x = (int)(wall_vis->wall_x * ray.tex->width);
	if ((ray.side == 0 && ray.dir.x < 0) || (ray.side == 1 && ray.dir.y > 0))
	  wall_vis->texture_x = ray.tex->width - wall_vis->texture_x - 1;
	/* 各ピクセルにどのテクスチャのピクセルを描画するか計算する */
	// y方向の1ピクセルごとにテクスチャのy座標が動く量
	wall_vis->step = 1.0 * ray.tex->height / (double)wall_vis->line_height;
}

static void	draw_stripe(t_game *game, t_ray ray,
						t_wall_vis_info *wall_vis, int x)
{
	int				y;
	uint32_t		color;

	wall_vis->texture_pos_y =
		(wall_vis->draw_start - game->screen_height / 2
		+ wall_vis->line_height / 2) * wall_vis->step;
	y = 0;
	while (y < game->screen_height)
	{
		if (y <= game->screen_height / 2)
			my_mlx_pixel_put(&(game->img), x, y, game->sky_color);
		else
			my_mlx_pixel_put(&(game->img), x, y, game->ground_color);
		if (y >= wall_vis->draw_start && y < wall_vis->draw_end)
		{
			wall_vis->texture_y = (int)wall_vis->texture_pos_y;
			if (wall_vis->texture_y >= ray.tex->height)
				wall_vis->texture_y = ray.tex->height - 1;
			wall_vis->texture_pos_y += wall_vis->step;
			color = get_color(*ray.tex,
				wall_vis->texture_x, wall_vis->texture_y);
			my_mlx_pixel_put(&(game->img), x, y, color);
		}
		y++;
	}
}

void		draw_walls(t_game *game)
{
	int				x;
	t_ray			ray;
	t_wall_vis_info	wall_vis;

	x = 0;
	while (x < game->screen_width)
	{
		initialize_ray(game, &ray, x);
		simulate_ray(game, &ray);
		game->z_buffer[x] = ray.perp_wall_dist;
		calc_vis_info(game, ray, &wall_vis, x);
		draw_stripe(game, ray, &wall_vis, x);
		x++;
	}
}


typedef struct	s_ray {
	double		camera_x;
	t_vec
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
}	



