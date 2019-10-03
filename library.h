#define SIZE 8

enum colour /* Enum for different types a space on the board can be */
{
    WHITE,
    BLACK,
    NONE,
	OPTION
};

typedef struct position /* Struct with board positions */
{
    int row;
    int col;
}position;

typedef struct disk /* Struct with disk characteristics */
{
    enum colour type;
    position pos;
}disk;

typedef struct player /* Struct with player characteristics */
{
    char name[20];
    enum colour type;
}player;

player player1; /* PLayer 1 */
player player2; /* Player 2 */
disk board[SIZE][SIZE]; /* Game board */
	
void initializePlayers(); /* Function prototypes */
void initializeBoard();
void printBoard();
void optionRemover();
void placePiece(player current);
void playAndUpdatePiece();
void validMoves(player current);
void flipper(int i, int j, player current);
void endgame();
