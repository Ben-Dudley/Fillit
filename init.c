#include "fillit.h"

t_tetrimino     init_tetrimino(const char *buff, char letter)
{
        t_terimino      tetrimino;

        tetrimino.letter = letter;
        tetrimino.width = get_width(buff);
        tetrimino.height = get_height(buff);
        tetrimino.value = get_value(buff);
        return (tetrimino);
}

