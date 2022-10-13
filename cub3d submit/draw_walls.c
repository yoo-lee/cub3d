void    initialize_ray(t_game )
{
	// カメラ平面上のx座標 (3D表示時の画面のx座標)  -1.0~1.0
	ray->camera_x = 2 * x / (double)game->screen_width - 1;
	ray->dir.x = game->player.dir.x + game->player.plane.x * ray->camera_x;
	ray->dir.y = game->player.dir.y + game->player.plane.y * ray->camera_x;
    ray->map_x = (int)game->player.pos.x;
    ray->map_y = (int)game->player.pos.y;
    deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX))
    deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY))
}

void    ray(t_game *game, t_ray ray)
{
 while (game -> map[x][y])
 {   
    if (ray -> side_dist_x < ray -> delta_dist_y)   
    ray -> side_dist_x += ray->delta_dist_x;
    
}

void    draw_walls(t_game *game)
{
    t_ray   ray;
    

}