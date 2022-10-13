int		main(int argc, char **argv)
{
    t_game  game;
    
    if (argc == 3)
    {
        draw_walls(&game);
    }
    mlx_hook(game.win, KeyPress, KeyPressMask, key_press_hook, &game);
	mlx_hook(game.win, KeyRelease, KeyReleaseMask, key_release_hook, &game);
	mlx_hook(game.win, ClientMessage, 1L << 17, exit_game, &game);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
}