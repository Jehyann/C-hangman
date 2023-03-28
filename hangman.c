#include <stdio.h>
#include <string.h>

int main() {
    
    // word to guess
    char word[50];
    printf("Please enter a word to guess: ");
    fflush(stdout);
    scanf("%s", word);
    printf("\n");

    // set to 0 bc nothing is guessed yet
    int lenWord = strlen(word) ;
    int hidden[lenWord];
    for (int i=0; i < lenWord; ++i) {
        hidden[i] = 0;
    }

    // loop till game over (no hp)
    int hp = 10;
    while (hp >= 0) {

        // printing the letters, if not found "-"
        printf("The word is : ");
        for(int j=0; j < lenWord; ++j) {
            if (hidden[j]) {
            printf("%c", word[j]);
        }
        else {
            printf("-");
        }
        }
        printf("\n");

        // take player's guess
        char playerGuess;
        printf("Choose your letter to find the word : ");
        fflush(stdout);
        scanf(" %c", &playerGuess);

        // check if guess in word
        if(strchr(word, playerGuess) != NULL) {
            for(int k=0; k < lenWord; ++k) {
                if (word[k] == playerGuess) {
	            hidden[k] = 1;
                }
            }
        }
        else {
            printf("\nThis letter is not in the word ! HP left : %d.\n", hp);
            hp = hp - 1;
        }

        // check if won
        for(int m = 0; m < lenWord; ++m) {
            if (!hidden[m]) {
            break;
            }
        }
    }

    if (hp <= 0) {
        printf("You loose !");
    }
    return 0;
}