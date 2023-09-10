#include "../minilibx_linux/mlx.h"

int main()
{
    void * mlx_con;
    void * mlx_win;

    mlx_con = mlx_init();
    mlx_win = mlx_new_window(mlx_con,500,500,"New Stranger X");
    mlx_loop(mlx_con);
}