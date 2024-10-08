typedef struct s_square
{
	int	x;
	int	y;
	int	score;
}	t_square


int	square_area(char *buffer)
{
	if (buffer =);
}

int	ft_movement(char *buff, int row, int col)
{
	int	moves;

	moves = 0;
	if (row > 0)
		moves += size[1] + 1; // width + 1 characters
	if (col > 0)
		moves += col; // width
	if (*buff == '\n')
		return (0); // invalid move
	else
		return (moves);
			// number of movements in the string that represents the map.
}

int	ft_result(char *buff, char *size)
{
	int	row;
	int	col;

	if (col == 0 && row == 0)
		ft_movement()
}


typedef struct
{
	char	char1;
	char	char2;
	char	char3;
} Threechars;

// find the largest square we can make starting at X

// AVOID REPETITION
// score = min(adyacent) + 1;

// If col = 0 && row = 0 --> check below and to the right and below-right
// If col = 0 && row > 0 --> check below-right
// If col > 0 && row = 0 --> check right
// Else check right and below-right
