#include "fillit.h"
#include "stdio.h"

unsigned short	get_width(unsigned short value)
{
	unsigned short width;
        int             i;

        width = 1;
        i = 0;

        while (i < 3)
        {
                if (value & (0b100010001000100 >> (1 * i)))
                        width += 1;
                else
                        break ;
                i += 1;
        }
	printf("width: %d\n", width);
        return (width);
}

unsigned short  get_height(unsigned short value)
{
	unsigned short height;
	int		i;

	height = 1;
	i = 0;
	while (i < 3)
	{
		if (value & (0b111100000000 >> (4 * i)))
			height += 1;
		else
			break ;
		i += 1;
	}
	printf("height: %d\n", height);
	return (height);
}

unsigned short  get_value(const char *str)
{
	unsigned short value;

	value = 0;
	while (*str) {
        	if (*str == '#' || *str == '.')
                {
                        value = value << 1;
                        if (*str == '#')
                                value = value | 1;
                }
                str += 1;
        }
	while (!(value & 0b1000100010001000))
		value = value << 1;
	while (!(value & 0b1111000000000000))
		value = value << 4;
	printf("value: %d\n", value);
	return (value);
}

t_tetriminos     init_tetriminos(const char *str, char letter)
{
        t_tetriminos      tetriminos;

        tetriminos.letter = letter;
        tetriminos.value = get_value(str);
	tetriminos.width = get_width(tetriminos.value);
        tetriminos.height = get_height(tetriminos.value);
        return (tetriminos);
}
