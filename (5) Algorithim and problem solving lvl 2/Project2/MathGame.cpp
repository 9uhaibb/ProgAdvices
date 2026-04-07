#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

enum enOperationType {Add = 1, Subtract = 2, Multiply = 3, Divide = 4, MixOp = 5};
enum enLevel {Easy = 1, Mid = 2, Hard = 3, MixLvl = 4};

struct stQuestion 
{
    int Number1 = 0;
    int Number2 = 0;
    enOperationType OperationType ;
    enLevel Level;
    int CorrectAnswer = 0;
    int PlayerAnswer = 0;
    bool AnswerResult = false;
};
struct stQuizz 
{
    stQuestion QuestionList[100]; 
    short NumberOfQuestions;
    enOperationType OperationType;
    enLevel Level ;
    short NumberOfRightAnswers = 0;
    short NumberOFWrongAnswers = 0;
    bool isPass = false;
};

void ResetScreen ()
{
    system ("cls");
    system ("color 0F");
}

int RandomNumber(int From, int To)
{
    int randNumber = rand() % (To - From + 1) + From;
    return randNumber;
}

int ReadNumberOfQuestions ()
{
    int Number;
    do 
    {
    cout << "How many questions? (1 - 10)\n";
    cin >> Number;
    } while (Number <  1 || Number > 10 );
    return Number;
}

enLevel ReadLevel ()
{
    int Number;
    do 
    {
    cout << "Choose : [1] Easy. [2] Medume. [3] Hard. [4] Mix.\n";
    cin >> Number;
    } while (Number <  1 || Number > 4 );
    return (enLevel)Number;
}

enOperationType ReadOperationType ()
{
    int Number;
    do 
    {
    cout << "Choose : [1] Add. [2] Subtract. [3] Multiply. [4] Divide. [5] Mix\n";
    cin >> Number;
    } while (Number <  1 || Number > 5 );
    return (enOperationType)Number;

}

float SimpleCalculator (int Number1, int Number2, enOperationType OpType)
{
    switch (OpType)
    {
        case enOperationType::Add:
            return Number1 + Number2;
        case enOperationType::Subtract:
            return Number1 - Number2;
        case enOperationType::Multiply:
            return Number1 * Number2;
        case enOperationType::Divide:
            return Number1 / Number2;
    }
}

stQuestion GenerateQuestion(enLevel Level, enOperationType OpType)
{
    stQuestion Question;
    if (Level == enLevel::MixLvl)
    {
        Level = (enLevel)RandomNumber(1, 3);
    }
    if (OpType == enOperationType::MixOp)
    {
        OpType = (enOperationType)RandomNumber(1, 4);
    }

    Question.OperationType = OpType;
    Question.Level = Level;

    switch (Level)
    {
        case enLevel::Easy:
            Question.Number1 = RandomNumber(1, 10);
            Question.Number2 = RandomNumber(1, 10);
            break;
        case enLevel::Mid:
            Question.Number1 = RandomNumber(10, 50);
            Question.Number2 = RandomNumber(10, 50);
            break;
        case enLevel::Hard:
            Question.Number1 = RandomNumber(50, 100);
            Question.Number2 = RandomNumber(50, 100);
            break;
    }

    Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, OpType);
    return Question;
}

void GenerateQuizzQuestions (stQuizz &Quizz)
{
    for (short QuestionNumber = 0; QuestionNumber < Quizz.NumberOfQuestions; QuestionNumber++)
    {
        Quizz.QuestionList[QuestionNumber] = GenerateQuestion (Quizz.Level, Quizz.OperationType);
    }
}

string GetOpTypeSymbol (enOperationType OpType)
{
    switch (OpType)
    {
        case enOperationType::Add :
         return "+";
        case enOperationType::Subtract :
         return "-";
        case enOperationType::Multiply :
         return "x";
        case enOperationType::Divide :
         return "/";
    default:
        return "Mix";
    }
}

void PrintTheQuestion (stQuizz &Quizz, short QuestionNumber)
{
    cout << endl;
    cout << "Question [" << QuestionNumber + 1  << "/" << Quizz.NumberOfQuestions << "]\n\n";
    cout << Quizz.QuestionList[QuestionNumber].Number1 << endl;
    cout << Quizz.QuestionList[QuestionNumber].Number2 << " ";
    cout << GetOpTypeSymbol(Quizz.QuestionList[QuestionNumber].OperationType);
    cout << "\n______" << endl;
}

int ReadPlayerAnswer ()
{
    int Answer = 0;
    cin >> Answer; return Answer;
}

void SetScreenColor (bool RightAnswer)
{
    if (RightAnswer)
        system("color 2F"); // Green
    else 
        system ("color 4F"); // Red
        cout << "\a";
}

void CorrectTheQuestionAnswer (stQuizz &Quizz , short QuestionNumber)
{
    if (Quizz.QuestionList[QuestionNumber].PlayerAnswer != Quizz.QuestionList[QuestionNumber].CorrectAnswer)
    {
        Quizz.QuestionList[QuestionNumber].AnswerResult = false;
        Quizz.NumberOFWrongAnswers++;
        cout << "Wrong answer :( \n";
        cout << "The right answer is : " << Quizz.QuestionList[QuestionNumber].CorrectAnswer;
        cout << endl; 
    }
    else 
    {
        Quizz.QuestionList[QuestionNumber].AnswerResult = true;
        Quizz.NumberOfRightAnswers++;
        cout << "Right answer :)\n";
    }
    cout << endl;
    SetScreenColor(Quizz.QuestionList[QuestionNumber].AnswerResult);
}

void AskAndCorrectQuestionListAnswer (stQuizz &Quizz)
{
    for (short QuestionNumber = 0; QuestionNumber < Quizz.NumberOfQuestions; QuestionNumber++)
    {
        PrintTheQuestion (Quizz, QuestionNumber);

        Quizz.QuestionList[QuestionNumber].PlayerAnswer = ReadPlayerAnswer ();
        CorrectTheQuestionAnswer(Quizz, QuestionNumber);
    }
    Quizz.isPass = (Quizz.NumberOfRightAnswers >= Quizz.NumberOFWrongAnswers);
    /*
    if (Quizz.NumberOfRightAnswers >= Quizz.NumberOFWrongAnswers)
    {
        Quizz.isPass = true;
    }
    else 
    {
        Quizz.isPass = false;
    }
    */
}

void PrintPassFail (bool pass)
{
    if (pass)
        cout << "Pass.\n";
    else 
        cout << "Fail.\n";
    
    SetScreenColor(pass);
}

void PrintQuizzResults (stQuizz & Quizz)
{
    cout << "\n";
    cout << "________________________________\n\n";
    cout << "Final result is : "; PrintPassFail (Quizz.isPass);
    cout << "_________________________________\n\n";

    cout << "Number of Questions: " << Quizz.NumberOfQuestions << endl;
    cout << "Questions Level: " << Quizz.Level << endl;
    cout << "Operation Type: " << Quizz.OperationType << endl;
    cout << "Number of right answers : " << Quizz.NumberOfRightAnswers << endl;
    cout << "Number of wrong answers : " << Quizz.NumberOFWrongAnswers << endl;
    cout << "_________________________________\n";
}

void PlayMathGame ()
{
    stQuizz Quizz;
    Quizz.NumberOfQuestions = ReadNumberOfQuestions ();
    Quizz.Level = ReadLevel ();
    Quizz.OperationType = ReadOperationType ();

    GenerateQuizzQuestions (Quizz);
    AskAndCorrectQuestionListAnswer (Quizz);

    PrintQuizzResults (Quizz);
}

void StartGame ()
{
    char PlayAgain = 'Y';
    do 
    {
        ResetScreen ();
        PlayMathGame ();

        cout << endl << "Do you want to play again? (Y/N) ";
        cin >> PlayAgain;
    } while (PlayAgain == 'Y'|| PlayAgain == 'y');
}

int main ()
{
    srand((unsigned)time(NULL));

    StartGame ();

}