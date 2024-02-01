#include <stdio.h>
#include <stdlib.h>
#include <string.h>


enum tiles
{
	Grassland,
	River,
	NorthWestRiverBend,
	SouthWestRiverBend,
	NorthEastRiverBend,
	SouthEastRiverBend,
	NorthEastSouthFork,
	NorthWestSouthFork,
	WestNorthEastFork,
	WestSouthEastFork,
	FourWayFork
};

void createMap(int xLen, int yLen, int grid[], int map[xLen][yLen])
{
	int size = xLen * yLen;
	for (int i = 0; i < size; i++)
	{
		int sum = grid[i];

		map[0][i] = sum;
	}
	
}

void displayMap(int xLen, int yLen, int map[xLen][yLen])
{
	int const doubleWideCell = 10;
	for (int i = 0; i < yLen; i++) 
	{
        for (int j = 0; j < xLen; j++)
		{
			if (map[i][j] != doubleWideCell)
			{
				printf(" %d ", map[i][j]);
			}
			else
			{
				printf("%d ", map[i][j]);
			}
			
			
        }

		printf("\n");
	}

}

void checkSize(int xLen, int yLen, int const maxSize)
{
	if (xLen > maxSize || yLen > maxSize)
	{
		puts("Invalid input!");
		abort();
	}
}

void checkTiles(int max, int size, int grid[size])
{
	for (int i = 0; i < size; i++)
	{
		if (grid[i] > max)
		{
			puts("Invalid input!");
			abort();
		}
		
	}
	
}

void getGrid(int size, int grid[size])
{
	for (int i = 0; i < size; i++)
	{
		scanf(" %d",&grid[i]);
	}
}



void changeMap(int xLen, int yLen, int map[yLen][xLen])
{
	enum tiles Tile;
	for (int i = 1; i < yLen; i++)
	{
		for (int j = 1; j < xLen; j++)
		{
			if (map[i][j-1] == 1 && map[i-1][j] == 1 && map[i][j+1] == 0 && map[i+1][j] == 0)
			{
				Tile = NorthWestRiverBend;
				map[i][j] = Tile;
			}
			else if (map[i][j-1] == 1 && map[i-1][j] == 0 && map[i][j+1] == 0 && map[i+1][j] == 1)
			{
				Tile = NorthWestRiverBend;
				map[i][j] = Tile;
			}
			else if (map[i][j-1] == 0 && map[i-1][j] == 1 && map[i][j+1] == 1 && map[i+1][j] == 0)
			{
				Tile = NorthWestRiverBend;
				map[i][j] = Tile;
			}
			else if (map[i][j-1] == 0 && map[i-1][j] == 0 && map[i][j+1] == 1 && map[i+1][j] == 1)
			{
				Tile = NorthWestRiverBend;
				map[i][j] = Tile;
			}
			else if (map[i][j-1] == 0 && map[i-1][j] == 1 && map[i][j+1] == 1 && map[i+1][j] == 1)
			{
				Tile = NorthWestRiverBend;
				map[i][j] = Tile;
			}
			else if (map[i][j-1] == 1 && map[i-1][j] == 1 && map[i][j+1] == 0 && map[i+1][j] == 1)
			{
				Tile = NorthWestRiverBend;
				map[i][j] = Tile;
			}
			else if (map[i][j-1] == 1 && map[i-1][j] == 1 && map[i][j+1] == 1 && map[i+1][j] == 0)
			{
				Tile = NorthWestRiverBend;
				map[i][j] = Tile;
			}
			else if (map[i][j-1] == 1 && map[i-1][j] == 0 && map[i][j+1] == 1 && map[i+1][j] == 1)
			{
				Tile = NorthWestRiverBend;
				map[i][j] = Tile;
			}
			else if (map[i][j-1] == 1 && map[i-1][j] == 1 && map[i][j+1] == 1 && map[i+1][j] == 1)
			{
				Tile = NorthWestRiverBend;
				map[i][j] = Tile;
			}
		}
		
		
	}
	
}


int main()
{
	char modeInput[3];

	int maxTile = 10;
	int maxTileInput;

	int xLen;
	int yLen;
	int size = 0;

	int const maxSize = 16000;

	fgets(modeInput,3,stdin);
	

	scanf(" %d %d\n", &xLen, &yLen);
	checkSize(xLen,yLen,maxSize);

	scanf(" %d\n", &maxTileInput);
	
	printf("%s\n",modeInput);
	printf("%d %d\n",xLen,yLen);
	printf("%d\n",maxTileInput);

	size = xLen * yLen;

	int grid[size];

	getGrid(size,grid);
	checkTiles(maxTile,size,grid);

	int map[xLen][yLen];

	for (int i = 0; i < xLen; i++)
	{
		for (int j = 0; j < yLen; j++)
		{
			map[j][i] = 0;
		}
		
	}
	
	createMap(xLen,yLen,grid,map);
	changeMap(xLen,yLen,map);
	displayMap(xLen,yLen,map);

    return 0;

}
