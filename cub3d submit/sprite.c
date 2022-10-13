int				add_sprite(t_game *game, double x, double y)
{
	t_vec2	new;
	t_vec2	*new_sprites;

	new.x = x;
	new.y = y;
	if (!(new_sprites = malloc(sizeof(t_vec2) * (game->sprite_num + 1))))
		return (ERROR);
	if (game->sprites)
		ft_memcpy(new_sprites, game->sprites,
			sizeof(t_vec2) * game->sprite_num);
	free(game->sprites);
	new_sprites[game->sprite_num++] = new;
	game->sprites = new_sprites;
	return (0);
}




calc_sprite_dis(t_game *game)
{
    int i;

    i = 0;
    while (i < game-> sprite_num)
    {
        game->sprite_dis[i]
        (game->player.pos.x - game->sprites[i].x) *
        (game->player.pos.x - game->sprites[i].x) +
        (game->player.pos.y - game->sprites[i].y) *
		(game->player.pos.y - game->sprites[i].y));
		i++;
    }
}


//BUBBLE SORT
swap_stripe(t_game *game, int a)
{
    double  tmp;
    t_vec2  tmpvec2;
    
tmp = game->sprite_dists[a];
	game->sprite_dists[a] = game->sprite_dists[b];
	game->sprite_dists[b] = tmp;
	tmpvec2 = game->sprites[a];
	game->sprites[a] = game->sprites[b];
	game->sprites[b] = tmpvec2;
}

void    sort_sprites(t_game *game)
{
    double  *sprite_dis;
    int i;
    int flag;
    double tmp;

    calc_sprite_di(game)
    flag = 1;
    while (flag)
    {
        flag = 0;
        i = game->stripe_num - 1;
        while (i > 0)
        if (game sprite_dis[i] > sprite_dis[i-1])
        {
            swap_sprite(game, i, i-1);
            flag = 1;
        }
        i--;
    }
}
