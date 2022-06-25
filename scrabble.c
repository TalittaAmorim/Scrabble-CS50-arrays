#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>


int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10}; // Array que vai armazenar a sequência de valores que vai ser atribuido as letras do alfabeto.

int compute_score(string word);

int main(void)
{

    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");


    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if(score1 < score2)
    {
        printf(" Vitória do jogador 2!");
    }
    else if(score1 > score2)
    {
        printf(" Vitória do jogador 1!");
    }
    else
    {
        printf(" EMAPATE!");
    }
}

int compute_score(string word)
{
    int score = 0;

    for(int i =0, t = strlen(word); i< t; i++)
    {
        if(isupper(word[i]))
        {
            score = score + POINTS[word[i] - 65]; /* A var de contagem vai somar com uma posição n que vai ser
            acessada no array POINTS que tem referencia as letras alfabéticaas por meio de uma operação que pegar um
            determinado caract(char) de uma palavra( que tem um valor de ASCII) 
            e diminuir com 65(valor inicial da sessão das letras maiúsculas em ASCII). Vai somando e quardando cada valor de char á char.
        */
        }
          if(islower(word[i]))
        {
            score = score + POINTS[word[i] - 97];  
        }

    }
    return score;
}
