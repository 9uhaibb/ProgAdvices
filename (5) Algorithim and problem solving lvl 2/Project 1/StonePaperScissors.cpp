#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void ResetColor ()
{
    system("cls");
    system("color 0F");
}
enum enWinner{ Player = 1,Computer = 2,Draw = 3};
enum enGameChoice{ Stone = 1, Paper = 2, Scissors = 3};

struct stRoundInfo
{
    short RoundNumber = 0;
    enGameChoice PlayerChoice;
    enGameChoice ComputerChoice;
    enWinner Winner;
    string WinnerName;
};

struct stGameResult
{
    short GameRounds = 0;
    short PlayerWonTimes = 0;
    short ComputerWonTimes = 0;
    short DrawTimes = 0;
    enWinner FinalWinner ;
};

short ReadHowManyRounds()
{
    short GameRounds = 1;
    cout << "How Many Rounds ? (1 - 10)";
    cin >> GameRounds;
    return GameRounds;
}

int RandomNumber(int From, int To)
{
    int randNumber = rand() % (To - From + 1) + From;
    return randNumber;
}

enGameChoice GetComputerChoice()
{
    return (enGameChoice)RandomNumber(1, 3);
}
enGameChoice GetPlayerChoice()
{
    short Choice = 1;
    do
    {
        cout << "choose : [1] Stone. [2] Paper. [3] Scissors.";
        cin >> Choice;
    } while (Choice > 3 || Choice < 1);
    return (enGameChoice)Choice;
}

enWinner WhoWonTheRound(stRoundInfo RoundInfo)
{
    if (RoundInfo.ComputerChoice == RoundInfo.PlayerChoice)
    {
        return enWinner::Draw;
    }

    switch (RoundInfo.PlayerChoice)
    {
    case enGameChoice::Stone:
    {
        if (RoundInfo.ComputerChoice == enGameChoice::Scissors)
        {
            return enWinner::Player;
        }
        break;
    }
    case enGameChoice::Paper:
    {
        if (RoundInfo.ComputerChoice == enGameChoice::Stone)
        {
            return enWinner::Player;
        }
        break;
    }
    case enGameChoice::Scissors:
    {
        if (RoundInfo.ComputerChoice == enGameChoice::Paper)
        {
            return enWinner::Player;
        }
        break;
    }
    }
    return enWinner::Computer;
}

enWinner WhoWonTheGame(short PlayerWinTimes, short ComputerWintTimes, short DrawTimes)
{
    if (PlayerWinTimes > ComputerWintTimes)
    {
        return enWinner::Player;
    }
    else if (PlayerWinTimes < ComputerWintTimes)
    {
        return enWinner::Computer;
    }
    else
    {
        return enWinner::Draw;
    }
}

stGameResult FillGameResults(int HowManyRounds, short PlayerWinTimes, short ComputerWintTimes, short DrawTimes)
{
    stGameResult GameResults;
    GameResults.ComputerWonTimes = ComputerWintTimes;
    GameResults.DrawTimes = DrawTimes;
    GameResults.FinalWinner = WhoWonTheGame(PlayerWinTimes, ComputerWintTimes, DrawTimes);
    GameResults.GameRounds = HowManyRounds;
    GameResults.PlayerWonTimes = PlayerWinTimes;

    return GameResults;
}

void SetWinnerScreenColor(enWinner Winner)
{
    switch (Winner)
    {
    case enWinner::Player:
        system("color 2F"); // أخضر عند فوز اللاعب
        break;
    case enWinner::Computer:
        system("color 4F"); // أحمر عند فوز الكمبيوتر
        break;
    case enWinner::Draw:
        system("color 6F"); // أصفر عند التعادل
        break;
    default:
        system("color 07"); // الافتراضي (رمادي)
        break;
    }
}
string ChoiceName(enGameChoice Choice)
{
    string arrGameChoises[3] = {"Stone", "Paper", "Scissors"};
    return arrGameChoises[Choice - 1];
}
string WinnerName(enWinner Winner) {
    switch (Winner) {
        case enWinner::Player:
            return "Player";
        case enWinner::Computer:
            return "Computer";
        case enWinner::Draw:
            return "Draw";
        default:
            return "Unknown";
    }
}

void PrintRoundResults(stRoundInfo RoundInfo)
{
    cout << "\n____________________Round [" << RoundInfo.RoundNumber << "]____________________\n\n";
    cout << "Player Choice : " << ChoiceName(RoundInfo.PlayerChoice) << endl;
    cout << "Computer Choice : " << ChoiceName(RoundInfo.ComputerChoice) << endl;
    cout << "Round Winner : [" << WinnerName(RoundInfo.Winner) << "]" << endl;
    cout << "_________________________________________________________________________________\n";
    SetWinnerScreenColor(RoundInfo.Winner);
}

stGameResult PlayGame(int HowManyRounds)
{
    stRoundInfo RoundInfo;
    short PlayerWinTimes = 0, ComputerWintTimes = 0, DrawTimes = 0;

    for (short GameRound = 1; GameRound <= HowManyRounds; GameRound++)
    {
        cout << "Round [" << GameRound << "] Begins : \n";
        RoundInfo.ComputerChoice = GetComputerChoice();
        RoundInfo.PlayerChoice = GetPlayerChoice();
        RoundInfo.RoundNumber = GameRound;
        RoundInfo.Winner = WhoWonTheRound(RoundInfo);
        RoundInfo.WinnerName = WhoWonTheGame(PlayerWinTimes, ComputerWintTimes, DrawTimes);

        if (RoundInfo.Winner == enWinner::Player)
        {
            PlayerWinTimes++;
        }
        else if (RoundInfo.Winner == enWinner::Computer)
        {
            ComputerWintTimes++;
        }
        else
        {
            DrawTimes++;
        }
        PrintRoundResults(RoundInfo);
    }
    return FillGameResults(HowManyRounds, PlayerWinTimes, ComputerWintTimes, DrawTimes);
}

void ShowGameOverScreen()
{
    cout << "       " << "__________________________________________________________\n\n";
    cout << "       " << "                 +++ G a m e  O v e r +++\n";
    cout << "       " << "__________________________________________________________\n\n";
}
void ShowFinalGameResults (stGameResult GameResults)
{
    cout << "       " << "_____________________ [Game Results ]_____________________\n\n";
    cout << "       " << "Game Rounds        : " << GameResults.GameRounds << endl;
    cout << "       " << "Player1 won times  : " << GameResults.PlayerWonTimes << endl;
    cout << "       " << "Computer won times : " << GameResults.ComputerWonTimes << endl;
    cout << "       " << "Draw times         : " << GameResults.DrawTimes << endl;
    cout << "       " << "Final Winner       : " << WinnerName(GameResults.FinalWinner) << endl;
    cout << "       " << "___________________________________________________________\n";
    SetWinnerScreenColor(GameResults.FinalWinner);
}

void StartGame()
{
    char PlayAgain;
    do
    {
        ResetColor();
        stGameResult GameResults = PlayGame(ReadHowManyRounds());
        ShowGameOverScreen();
        ShowFinalGameResults(GameResults);

        cout << "Do you want to play again? (Y/N). \n";
        cin >> PlayAgain;

    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{
    srand((unsigned)time(NULL));

    StartGame();
}