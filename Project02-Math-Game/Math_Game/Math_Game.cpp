
#include <iostream>

using namespace std;

enum enLevels { Easy = 1, Med = 2, Hard = 3, Mix_L = 4 };
enum enOperation { Add = 1, Sub = 2, Mul = 3, Div = 4, Mix_O = 5 };

struct stvar {
    short NumberOfQuestions;
    enLevels Level;
    enOperation Operator;
    short countPass;
    short countFail;
};
stvar var;

int RandomNumber(int Frome, int To) {
    int randNum = rand() % (To - Frome + 1) + Frome;
    return randNum;
}
char RandomOperation() {
    int Op = RandomNumber(42, 47);
    if (Op == 44 || Op == 46)
        RandomOperation();
    else
        return char(Op);

}

short ReadNumQ() {
    short NQ;
    cout << "How Many Questions do you want to answer ? ";
    cin >> NQ;
    return NQ;
}
enLevels ReadLevel() {
    short Level;
    cout << "Enter Questions Level [1] Easy, [2] Med, [3] Hard, [4] Mix ? ";
    cin >> Level;

    return enLevels(Level);
}
enOperation ReadOperation() {
    short Operator;
    cout << "Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ? ";
    cin >> Operator;

    return enOperation(Operator);
}

void PrintResult(short answer, short result) {
    if (answer == result) {
        cout << "Right Answer :-) " << endl;
        var.countPass++;
        system("color 2F");
        
    }
    else {
        cout << "worng Answer :-( \a" << endl;
        var.countFail++;
        system("color 4F");
        cout << "The right answer is : " << result << endl;
        
    }
}
void add(short Frome, short To) {
    short num1 = RandomNumber(Frome, To);
    short num2 = RandomNumber(Frome, To);
    short result = num1 + num2;
    short answer = 0;
    cout << num1 << " + " << num2 << " = ";
    cin >> answer;
    PrintResult(answer,result);
}
void sub(short Frome, short To) {
    short num1 = RandomNumber(Frome, To);
    short num2 = RandomNumber(Frome, To);
    short result = num1 - num2;
    short answer = 0;
    cout << num1 << " - " << num2 << " = ";
    cin >> answer;
    PrintResult(answer, result);
}
void mul(short Frome, short To) {
    short num1 = RandomNumber(Frome, To);
    short num2 = RandomNumber(Frome, To);
    int result = num1 * num2;
    int answer = 0;
    cout << num1 << " * " << num2 << " = ";
    cin >> answer;
    PrintResult(answer, result);
}
void div0(short Frome, short To) {
    short num1 = RandomNumber(Frome, To);
    short num2 = RandomNumber(Frome, To);
    short result = (int) num1 / num2;
    short answer = 0;
    cout << num1 << " / " << num2 << " = ";
    cin >> answer;
    PrintResult(answer, result);
}
void mix_O(short Frome, short To) {
    switch (enOperation(RandomNumber(1, 4))) {
    case enOperation::Add:
        add(Frome, To);
        break;
    case enOperation::Sub:
        sub(Frome, To);
        break;
    case enOperation::Mul:
        mul(Frome, To);
        break;
    case enOperation::Div:
        div0(Frome, To);
        break;
    }
}

void Level_Add() {
    switch (var.Level) {
    case enLevels::Easy:
        add(1, 10);
        cout << endl;
        break;
    case enLevels::Med:
        add(10, 100);
        cout << endl;
        break;
    case enLevels::Hard:
        add(100, 1000);
        cout << endl;
        break;
    case enLevels::Mix_L:
        add(1, 1000);
        cout << endl;
        break;
    }

}
void Level_Sub() {
    switch (var.Level) {
    case enLevels::Easy:
        sub(1, 10);
        cout << endl;
        break;
    case enLevels::Med:
        sub(10, 100);
        cout << endl;
        break;
    case enLevels::Hard:
        sub(100, 1000);
        cout << endl;
        break;
    case enLevels::Mix_L:
        sub(1, 1000);
        cout << endl;
        break;
    }

}
void Level_Mul() {
    switch (var.Level) {
    case enLevels::Easy:
        mul(1, 10);
        cout << endl;
        break;
    case enLevels::Med:
        mul(10, 100);
        cout << endl;
        break;
    case enLevels::Hard:
        mul(100, 1000);
        cout << endl;
        break;
    case enLevels::Mix_L:
        mul(1, 1000);
        cout << endl;
        break;
    }

}
void Level_Div() {
    switch (var.Level) {
    case enLevels::Easy:
        div0(1, 10);
        cout << endl;
        break;
    case enLevels::Med:
        div0(10, 100);
        cout << endl;
        break;
    case enLevels::Hard:
        div0(100, 1000);
        cout << endl;
        break;
    case enLevels::Mix_L:
        div0(1, 1000);
        cout << endl;
        break;
    }

}
void Level_Mix_O() {
    switch (var.Level) {
    case enLevels::Easy:
        mix_O(1, 10);
        cout << endl;
        break;
    case enLevels::Med:
        mix_O(10, 100);
        cout << endl;
        break;
    case enLevels::Hard:
        mix_O(100, 1000);
        cout << endl;
        break;
    case enLevels::Mix_L:
        mix_O(1, 1000);
        cout << endl;
        break;
    }
}

void Question() {
    switch (var.Operator) {
    case enOperation::Add:
        Level_Add();
        break;
    case enOperation::Sub:
        Level_Sub();
        break;
    case enOperation::Mul:
        Level_Mul();
        break;
    case enOperation::Div:
        Level_Div();
        break;
    case enOperation::Mix_O:
        Level_Mix_O();
        break;
    }
}

string Operation(enOperation Operator) {
    string OperationType[5] = { "+","-","*","/","Mix" };
    return OperationType[(short)Operator - 1];
}
string Level(enLevels Level) {
    string NumberOfLevel[4] = { "Easy", "Med", "Hard","Mix" };
    return NumberOfLevel[(short)Level - 1];
}

void FinalResult() {
    
    cout << "\n*** Final Result is ";
    if (var.countPass >= var.countFail)
        cout << "PASS -:) ";
    else //if (var.countFail > var.countPass)
        cout << "failed -:( ";
    cout << "***\n" << endl;
}

void PrintResults() {
    cout << "\n----------------------------------\n";
    cout << "Number Of Questions     :" << var.NumberOfQuestions << endl;
    cout << "Questions Level         :" << Level(var.Level) << endl;
    cout << "opType                  :" << Operation(var.Operator) << endl;
    cout << "Number of Right Answers :" << var.countPass << endl;
    cout << "Number of Worng Answers :" << var.countFail << endl;
}

void Start() {
    

    var.NumberOfQuestions = ReadNumQ();
    var.Level = ReadLevel();
    var.Operator = ReadOperation();
    var.countPass = 0;
    var.countFail = 0;

    for(int i=1;i<=var.NumberOfQuestions;i++){
        cout << "Question [" << i << "/" << var.NumberOfQuestions << "]" << endl;
        Question();
    }
    FinalResult();
    PrintResults();
}

int main()
{
    srand((unsigned)time(NULL));
    Start();
    return 0;
}
