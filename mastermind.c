#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void feedBack(char trial[5], char master[5], int trials){
    int firstFeedback = 0;
    for (int i = 0; i < 4; i++){
        if (trial[i] == master[i]){
            firstFeedback += 1;}
    }
    int secondFeedback = 0;
    for (int j = 0; j < 4; j++){
        for (int k = 0; k < 4; k++){
            if(master[j] == trial[k]){
                secondFeedback++;
                break;}}
    }
    secondFeedback -= firstFeedback;
    printf("        Feedback: %d, %d \n",firstFeedback,secondFeedback);
    if (firstFeedback == 4 && secondFeedback == 0){
        printf("YOU WIN! \n");
        exit(0);
    }
    if (trials == 1){
        printf("YOU LOSE! The code is %s \n",master);
        exit(0);
    }
}

int main( int argc,char *argv[] )
{
    if (argc == 2){
        char *a = argv[1];
        char code[5];
        strcpy(code,a);
        printf("Available Colors: (B)lue (G)reen (O)range (P)urple (R)ed (Y)ellow \n");
        char try[5];
        for (int tryCount = 12; tryCount > 0; tryCount--){
            printf("\n");
            printf("No. guesses left: %d",tryCount);
            printf("\n");
            printf("Enter your guess: ");
            scanf("%s",try);
            feedBack(try,code,tryCount);}
    }
    else {
        exit(0);
    }
}
