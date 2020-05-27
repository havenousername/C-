// Preprocessor directive
#include <iostream>


// Main function
int main(){
    // Expression statements
    std::cout << "Year 2049: Technological singurarity is not far apart from humanity.\n";
    std::cout << "           However there is one thing which still nobody feels - happiness.\n";
    std::cout << "           You have bought yesterday new model of Sara - artificial intelegent woman, which would like to hang out with you.\n";
    std::cout << "           However, in order to gain her love, you need to solve some task. You need to enter the correct numbers to continue...\n";
    // Declaration statements
    const int CodeA = 4;
    const int CodeB = 3;
    const int CodeC = 2;

    const int CodeAdd = CodeA + CodeB + CodeC;
    const int CodeMul = CodeA * CodeB * CodeC;
    
    // Expression state 
    std::cout << "+ There are three lines in the code\n";
    std::cout << "+ The codes adds-up to: "<< CodeAdd << std::endl;
    std::cout << "+ The codes multiply to give: " << CodeMul << std::endl; 
    
    int PlayerGuessOne = 0;
    int PlayerGuessTwo = 0;
    int PlayerGuessThree = 0;
    bool IsRightValue = false;
    while(!IsRightValue){
        std::cout << "Please enter 3 number guesses(separeted by spaces)\n";
        std::cin >> PlayerGuessOne >> PlayerGuessTwo >> PlayerGuessThree;
        IsRightValue = !(std::cin.fail() || std::cin.peek() != '\n' || PlayerGuessOne > 0);
        if(!IsRightValue) std::cout << "Something went wrong. Your number is not Natural.\n";
        std::cin.clear();
        std::cin.ignore(999, '\n');
    }
    std::cout << "You have entered: " << PlayerGuessOne << std::endl;
    

    return 0;
}
