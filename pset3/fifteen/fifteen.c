/**
 * fifteen.c
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(int n);
void draw(int n);
bool move(int tile, int n);
bool won(int n);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init(d);

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw(d);

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won(d))
        {
            printf("ftw!\n");
            return 0;
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = get_int();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile, d))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(int n)
{
    
    int count = ((n * n) - 1); //count is decremented as the 2d array is built, boardSet helps determine if 1 & 2 should be switched
    bool boardSet;
    
    if(count % 2 != 0)
    {
        boardSet = true; //if there are an even number of tiles, 1 & 2 should be switched on the board
    }
    
    for(int i = 0; i < n; i++) //first loop for rows
    {
        for(int j = 0; j < n; j++) //second loop for columns
        {
            if(count > 2) //before count has reached 2
            {
                board[i][j] = count;
                count--;
            }
            else if(count == 2) //determine if 1 & 2 need to be switched
            {
                if(boardSet)
                {
                    board[i][j + 1] = count;
                    count--;
                }
                else
                {
                    board[i][j] = count;
                    count--;
                }
            }
            else if(count == 1)
            {
                if(boardSet)
                {
                    board[i][j - 1] = count;
                    count--;
                }
                else
                {
                    board[i][j] = count;
                    count--;
                }
            }
            else
            {
                board[i][j] = 0; // zero to be used for empty tile, underscore char used in zero's place
            }
        }
    }
}

/**
 * Prints the board in its current state.
 */
void draw(int n)
{
    
    for(int i = 0; i < n; i++) //print rows
    {
        for(int j = 0; j < n; j++) //print columns
        {
            if(board[i][j] == 0)
            {
                printf("%c    ", '_');
            }
            else
            {
                if(board[i][j] < 10)
                {
                    printf("%d    ", board[i][j]); //extra formated space for proper spacing
                }
                else 
                {
                    printf("%d   ", board[i][j]);
                }
            }
        }
        
        printf("\n\n");
    }
    
    printf("\n");
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile, int n)
{
    if(tile > ((n * n) - 1) || tile < 1) //check to ensure valid number & prevent crash
    {
        return false;
    }
    
    int i_index, j_index, nineI_index, nineJ_index;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(tile == board[i][j]) //linear search to find tile in array
            {
                i_index = i;
                j_index = j;
            }
            if(0 == board[i][j]) //linear search to find empty tile in array
            {
                nineI_index = i;
                nineJ_index = j;
            }
        }
    }
    
        
    if(i_index == nineI_index) //if selected tile and empty tile are in the same ROW ...
    {
        if((j_index + 1) == nineJ_index) //and they are one space away from eachother ...
        {
            board[nineI_index][nineJ_index] = board[i_index][j_index]; //they will be moved!
            board[i_index][j_index] = 0;
            return true;
        }
        else if((j_index - 1) == nineJ_index)
        {
            board[nineI_index][nineJ_index] = board[i_index][j_index];
            board[i_index][j_index] = 0;
    
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(j_index == nineJ_index) //if selected tile and empty tile are in the same COLUMN ...
    {
        if((i_index + 1) == nineI_index) //and they are one space away from eachother ...
        {
            board[nineI_index][nineJ_index] = board[i_index][j_index]; //they will be moved!
            board[i_index][j_index] = 0;
            return true;
        }
        else if((i_index - 1)== nineI_index)
        {
            board[nineI_index][nineJ_index] = board[i_index][j_index];
            board[i_index][j_index] = 0;
            return true;
        }
        else 
        {
            return false;
        }
    }
    
    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(int n)
{
    int winning = 1; //count through the array to ensure proper order

    for(int i = 0; i < n; i++) //Rows
    {
        for(int j = 0; j < n; j++) //Columns
        {
            if(winning == board[i][j]) //if winning count and array match ...
            {
                if(winning == ((n * n) - 1) ) //and the winning count has reached the last number in the game ...
                {
                    return true; //You win!
                }
                else
                {
                    winning++;
                }
            }
            else
            {
                return false;
            }
        }
    }
    
    return false;
}
