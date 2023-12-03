

char check(char board[][3])
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != '.')
            return board[i][0];

        if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != '.')
            return board[0][i];

        if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != '.')
            return board[0][0];

        if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != '.')
            return board[0][2];
    }

    return '\0';
}

int main()
{
    char board[3][3] = {{'X', '0', '0'},
                        {'X', 'X', '0'},
                        {'X', '.', '.'}};
}