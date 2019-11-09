#include "RawMap.h"
#include "Shape.h"


bool shapeIsTunnel(Shape shape)
{
	if (shape < SHAPE_SOLID)
	{
		return true;
	}
	else if (shape >= SHAPE_SOLID)
	{
		return false;
	}
}

bool shapeIsCavern(Shape shape)
{
	return (shape >= SHAPE_FIRST_CAVERN);
}

unsigned int shapeGetCavernIndex(Shape shape)
{
	return  (shape - SHAPE_FIRST_CAVERN);
}

Shape shapeGetCavernShape(unsigned int cavern_index)
{
	return (cavern_index + SHAPE_FIRST_CAVERN);
}

char shapeGetMapChar(Shape shape)
{
	
	if (shapeIsCavern(shape) == true)
	{
		if (shape % 2 == 0)
		{
			return ':';
		}
		else
			return '.';
	}
	else
	{
		const int NUMBER_TUNNEL_SHAPES = 17;
		char returnValue[NUMBER_TUNNEL_SHAPES] = { 'O', 'N', 'S', 'E', 'W', '|', '-', '\\', '/', '/', '\\', '>', '<', '^', 'v', '+', ' ' };
		return returnValue[shape];
	}
}

Shape shapeCalculate(bool is_open_north, bool is_open_south, bool is_open_east, bool is_open_west)
{
	if (is_open_north == false && is_open_south == false && is_open_east == false && is_open_west == false)
	{
		return SHAPE_BUBBLE;
	}
	else if (is_open_north == true && is_open_south == false && is_open_east == false && is_open_west == false)
	{
		return SHAPE_N_DEAD_END;
	}
	else if (is_open_north == false && is_open_south == true && is_open_east == false && is_open_west == false)
	{
		return SHAPE_S_DEAD_END;
	}
	else if (is_open_north == false && is_open_south == false && is_open_east == true && is_open_west == false)
	{
		return SHAPE_E_DEAD_END;
	}
	else if (is_open_north == false && is_open_south == false && is_open_east == false && is_open_west == true)
	{
		return SHAPE_W_DEAD_END;
	}
	else if (is_open_north == true && is_open_south == true && is_open_east == false && is_open_west == false)
	{
		return SHAPE_NS_STRAIGHT;
	}
	else if (is_open_north == false && is_open_south == false && is_open_east == true && is_open_west == true)
	{
		return SHAPE_EW_STRAIGHT;
	}
	else if (is_open_north == true && is_open_south == false && is_open_east == true && is_open_west == false)
	{
		return SHAPE_NE_CORNER;
	}
	else if (is_open_north == true && is_open_south == false && is_open_east == false && is_open_west == true)
	{
		return SHAPE_NW_CORNER;
	}
	else if (is_open_north == false && is_open_south == true && is_open_east == true && is_open_west == false)
	{
		return SHAPE_SE_CORNER;
	}
	else if (is_open_north == false && is_open_south == true && is_open_east == false && is_open_west == true)
	{
		return SHAPE_SW_CORNER;
	}
	else if (is_open_north == true && is_open_south == true && is_open_east == true && is_open_west == false)
	{
		return SHAPE_NSE_T_JUNCTION;
	}
	else if (is_open_north == true && is_open_south == true && is_open_east == false && is_open_west == true)
	{
		return SHAPE_NSW_T_JUNCTION;
	}
	else if (is_open_north == true && is_open_south == false && is_open_east == true && is_open_west == true)
	{
		return SHAPE_NEW_T_JUNCTION;
	}
	else if (is_open_north == false && is_open_south == true && is_open_east == true && is_open_west == true)
	{
		return SHAPE_SEW_T_JUNCTION;
	}
	else if (is_open_north == true && is_open_south == true && is_open_east == true && is_open_west == true)
	{
		return SHAPE_NSEW_CROSSROAD;
	}
}

bool shapeIsTunnelStraight(Shape shape)
{
	return(shape == SHAPE_NS_STRAIGHT || shape == SHAPE_EW_STRAIGHT);
}

bool shapeIsTunnelDirection(Shape shape, Direction direction)
{
	assert(shapeIsTunnel(shape));
	assert(direction < DIRECTION_COUNT);
	{
		bool arr[16][4];

		for (int i = 0; i < 16; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if ((i == 0 || i == 2 || i == 3 || i == 4 || i == 6 || i == 9 || i == 10 || i == 14) && j == 0)
					arr[i][j] = false;
				else if ((i == 0 || i == 1 || i == 3 || i == 4 || i == 6 || i == 7 || i == 8 || i == 13) && j == 1)
					arr[i][j] = false;
				else if ((i == 0 || i == 1 || i == 2 || i == 4 || i == 5 || i == 8 || i == 10 || i == 12) && j == 2)
					arr[i][j] = false;
				else if ((i == 0 || i == 1 || i == 2 || i == 3 || i == 5 || i == 7 || i == 9 || i == 11) && j == 3)
					arr[i][j] = false;
				else
					arr[i][j] = true;
			}
		}
		return(arr[shape][direction]);
	}
}
