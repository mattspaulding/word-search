#define _CRT_SECURE_NO_WARNINGS
// Word Search

#include <stdio.h>

// Useful constants.
#define SIZE 300

const int DX_SIZE = 8;
const int DX[] = { -1,-1,-1,0,0,1,1,1 };
const int DY[] = { -1,0,1,-1,1,-1,0,1 };
char dictionary[300000][20];


// Function prototypes
int checkNextLetter(int grid[][SIZE]);
int checkCols(int grid[][SIZE]);
int checkBox(int grid[][SIZE], int startRow, int startCol);
int checkBoxes(int grid[][SIZE]);
int validSudoku(int grid[][SIZE]);

int main() {

	// Get number of cases.
	int i, j, loop, numCases;
	//scanf("%d", &numCases);

	static const char dictionaryFilename[] = "dictionary.txt";
	FILE *dictionaryFile = fopen(dictionaryFilename, "r");
	char dictionaryLine[500];
	fgets(dictionaryLine, sizeof dictionaryLine, dictionaryFile);
	int numWords;
	sscanf(dictionaryLine, "%d", &numWords);
	for (int index = 0; index < numWords; index++) {
		fgets(dictionaryLine, sizeof dictionaryLine, dictionaryFile);
		int len = strlen(dictionaryLine);
		dictionaryLine[len - 1] = '\0';
		strcpy(dictionary[index],dictionaryLine);
		
	}

	static const char filename[] = "input.io";
	FILE *file = fopen(filename, "r");
	char line[500];
	fgets(line, sizeof line, file);
	numCases = line[0] - '0';


	// Process each case.
	for (loop = 0; loop < numCases; loop++) {
		printf("Words Found Grid #%d:\n", loop+1);
		char grid[SIZE][SIZE];
		char line[SIZE + 1];
		fgets(line, sizeof line, file);
		int x = line[0] - '0';
		int y = line[2] - '0';

		// Read in grid.
		for (i = 0; i < x; i++) {
			//scanf("%s", line);
			fgets(line, sizeof line, file);
			for (j = 0; j < y; j++)
				grid[i][j] = line[j];
		}

		// Output the result.
		for (i = 0; i < x; i++)
		{
			for (j = 0; j < y; j++)
			{
				for (int k = 0; k < DX_SIZE; k++)
				{
					int m = 0;
					int currentX = i;
					int currentY = j;
					char possibleWord[SIZE];
					memset(possibleWord, 0, sizeof(possibleWord));
					possibleWord[0] = grid[i][j];

					possibleWord[m] = grid[i][j];
					while (1)
					{
						m++;
						int nextX = currentX + DX[k];
						int nextY = currentY + DY[k];
						// (nextx, nexty) represents the adjacent location in
						// direction k.

							// Check boundries
						if (nextX > -1 && nextY>-1 && nextX < x&&nextY < y)
						{
							possibleWord[m] = grid[nextX][nextY];
							currentX = nextX;
							currentY = nextY;
							if (m >1)
							{
								int word= searchForWordInDictionary(possibleWord);
							}

						}
						else {
							break;
						}
					}
				}
			}
		}


	}
	getchar();
	return 0;
}

int searchForWordInDictionary(char possibleWord[])
{
	for (int i = 0; i < 300000; ++i)
	{
		if (!strcmp(dictionary[i], possibleWord))
		{
			printf("%s\n", possibleWord);
		}
	}
	return 0;
}