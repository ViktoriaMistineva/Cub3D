#include "../cub.h"

int key_esc(int key, t_all *all)
{
	exit(0);
}

void	key_w_s(t_all *all, double movespeed, int key)
{
	if (key == KEY_W)
	{
		
		if (all->map[(int)all->param_map->posY]
				[(int)(all->param_map->posX + all->param_map->dirX * movespeed)] == '0')
			all->param_map->posX += all->param_map->dirX * movespeed;
		
		if (all->map[(int)(all->param_map->posY + all->param_map->dirY
					* movespeed)][(int)all->param_map->posX] == '0')
			all->param_map->posY += all->param_map->dirY * movespeed;
	}
	if (key == KEY_S)
	{
		if (all->map[(int)all->param_map->posY]
				[(int)(all->param_map->posX - all->param_map->dirX * movespeed)] == '0')
			all->param_map->posX -= all->param_map->dirX * movespeed;
			
		if (all->map[(int)(all->param_map->posY - all->param_map->dirY
					* movespeed)][(int)all->param_map->posX] == '0')
			all->param_map->posY -= all->param_map->dirY * movespeed;
	}
}

void	key_a_d(t_all *all, double movespeed, int key)
{
	if (key == KEY_A)
	{
		if (all->map[(int)(all->param_map->posY)]
				[(int)(all->param_map->posX
				 - all->param_map->planeX * movespeed)] == '0')
			all->param_map->posX -= all->param_map->planeX * movespeed;
		if (all->map[(int)(all->param_map->posY 
				+ all->param_map->planeY
				* movespeed)][(int)(all->param_map->posX)] == '0')
			all->param_map->posY -= all->param_map->planeY * movespeed;
	}
	if (key == KEY_D)
	{
		if (all->map[(int)(all->param_map->posY)]
				[(int)(all->param_map->posX + all->param_map->planeX * movespeed)] == '0')
			all->param_map->posX += all->param_map->planeX * movespeed;
		if (all->map[(int)(all->param_map->posY - all->param_map->planeY
					* movespeed)][(int)(all->param_map->posX)] == '0')
			all->param_map->posY += all->param_map->planeY * movespeed;
	}
}

void	key_left_right(int key, t_all *all, double rotspeed)
{
	double oldDirX;

	if (key == KEY_LEFT)
	{
		oldDirX = all->param_map->dirX;
		all->param_map->dirX = all->param_map->dirX * cos(-rotspeed) - all->param_map->dirY * sin(-rotspeed);
		all->param_map->dirY = oldDirX * sin(-rotspeed) + all->param_map->dirY * cos(-rotspeed);
		all->algo_data->old_plane_x = all->param_map->planeX;
		all->param_map->planeX = all->param_map->planeX * cos(-rotspeed) - all->param_map->planeY * sin(-rotspeed);
		all->param_map->planeY = all->algo_data->old_plane_x * sin(-rotspeed) + all->param_map->planeY * cos(-rotspeed);
	}
	if (key == KEY_RIGHT)
	{
		oldDirX = all->param_map->dirX;
		all->param_map->dirX = all->param_map->dirX * cos(rotspeed) - all->param_map->dirY * sin(rotspeed);
		all->param_map->dirY = oldDirX * sin(rotspeed) + all->param_map->dirY * cos(rotspeed);
		all->algo_data->old_plane_x = all->param_map->planeX;
		all->param_map->planeX = all->param_map->planeX * cos(rotspeed) - all->param_map->planeY * sin(rotspeed);
		all->param_map->planeY = all->algo_data->old_plane_x * sin(rotspeed) + all->param_map->planeY * cos(rotspeed);
	}
}

int		move(int key, t_all *all)
{
	double	movespeed;
	double	rotspeed;

	movespeed = 0.3;
	rotspeed = 0.1;
	if(key == KEY_ESC)
		key_esc(key, all);
	if (key == KEY_W || key == KEY_S)
		key_w_s(all, movespeed, key);
	if (key == KEY_A|| key == KEY_D)
		key_a_d(all, movespeed, key);
	if (key == KEY_LEFT || key == KEY_RIGHT)
		key_left_right(key, all, rotspeed);
	return (1);
}