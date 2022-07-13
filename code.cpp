#include <iostream>
#include <ctime>


void printIntro(int Difficulty)
{
    //Print intro message to the terminal

    std::cout << "\n\nYou are a secret agent breaking into the CIA server level " << Difficulty;
    std::cout << "\nEnter the correct code to continue...\n\n";

}

bool playGame(int Difficulty)
{
    printIntro(Difficulty);

    //Declaration vars
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProd = CodeA * CodeB * CodeC;


    //Tips
    std::cout << "+ There are 3 numbers in the code";
    std::cout << "\n+ The codes add-up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to give: " << CodeProd << std::endl;
    std::cout << "\n+ You must type the code one number at a time \n";

    //Inputs vars
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;


    std::cout << "\nYou entered: " << GuessA << GuessB << GuessC;


    //Sum prod vars
    const int GuessSum = GuessA + GuessB + GuessC;
    const int GuessProd = GuessA * GuessB * GuessC;

    //Win lose IF
    if (GuessSum == CodeSum && GuessProd == CodeProd)
    {
        std::cout << "\nWell done you got all the files! Keep it going!";
        return true;
    }
    else
    {
        std::cout << "\nYou entered the wrong code!! try again";
        return false;
    }

}

int main ()

{
    srand(time(NULL)); // create new random sequence based on time of day
    int LevelDifficulty = 1;
    const int MaxDifficulty = 4;

    while (LevelDifficulty <= MaxDifficulty) // Loop until all levels completed
    {
        bool bLevelComplete = playGame(LevelDifficulty);
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
    }

    std::cout << "\n *** Congratulations agent! You got all the files! Now get the hell out of there!!***\n";

    return 0;
}
