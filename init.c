#include "fillit.h"

unsigned short	get_width(const char *str)
{
}

unsigned short  get_height(const char *str)
{
}

unsigned short  get_value(const char *str)
{

}

t_tetriminos     init_tetriminos(const char *str, char letter)
{
        t_teriminos      tetriminos;

        tetriminos.letter = letter;
        tetriminos.width = get_width(str);
        tetriminos.height = get_height(str);
        tetriminos.value = get_value(str);
        return (tetriminos);
}

