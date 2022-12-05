#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "main.h"

char* suits[] = { "spade", "heart", "club",   "diamond" };
char* letterCards[] = { "J", "Q", "K",   "A", "2",  "Joker (Black)", "Joker (Red)"};
const int cardCount = 54;
int perHand = 17;
int faces = 13;
int faceCount[6][14];
int points[6];

int maxDeck[3][20];
int maxLength[6][3];

const int numTally = 5;
const int QUARTET = 0;
const int TRIPLE = 1;
const int DUAL_TRIPLE = 2;
const int TRI_DOUBLE = 3;
const int PENT_SINGLE = 4;

char* tallies[] = { "Quartets", "Triples", "2xTri",   "3xDual", "5xSingle"};
char* lengthTallies[] = { "Quartet", "Triple", "Double"};

const int MAX_QUARTET = 0;
const int MAX_TRIPLE = 1;
const int MAX_DOUBLE = 2;

int tally[6][5];
int maxTally[6][5];

int totalTally[5];
int lTotalTally[5];
int pTotalTally[5];

void shuffle(int *array, int n);
void selectionSort(int arr[], int n);
char* intToDesc(int card);
int intToFace(int card);
void printAllHands(int hands[3][perHand], int handsFull[3][perHand + 3], int extraHand[3]);
void cardSetup(int hands[3][perHand], int handsFull[3][perHand + 3], int cards[cardCount], int extraHand[3]);
void countFaces(int hands[3][perHand], int handsFull[3][perHand + 3]);
void selectionSort(int arr[], int n);
void swap(int* xp, int* yp);
void findPatterns();
void processData(int hands[3][perHand], int handsFull[3][perHand + 3]);
void addToTally(int l1, int p1, int p2, int hands[3][perHand], int handsFull[3][perHand + 3]);

int lMaxTally[5];
int pMaxTally[5];

int lMaxHand[5][21];
int pMaxHand[5][17];

int lMaxLengthTally[5];
int pMaxLengthTally[5];

int lMaxLengthHand[5][21];
int pMaxLengthHand[5][17];

void printLHand(int hands[perHand + 3]);
void printPHand(int hands[perHand]);

int main() {
    int cards[cardCount];
    srand(time(NULL));
    memset(totalTally, 0, sizeof(totalTally));
    memset(lTotalTally, 0, sizeof(lTotalTally));
    memset(pTotalTally, 0, sizeof(pTotalTally));
    memset(lMaxTally, 0, sizeof(lMaxTally));
    memset(pMaxTally, 0, sizeof(pMaxTally));
    memset(lMaxLengthTally, 0, sizeof(lMaxLengthTally));
    memset(pMaxLengthTally, 0, sizeof(pMaxLengthTally));

    for (int i = 0; i < cardCount; i++) {
        cards[i] = i;
    }

    int ITER = 100000;

    int hands[3][perHand];
    int handsFull[3][perHand + 3];
    int extraHand[3];

    for (int k = 0; k < ITER; k++) {
        cardSetup(hands, handsFull, cards, extraHand);
        countFaces(hands, handsFull);

        findPatterns();
        processData(hands, handsFull);
    }

    for(int i = 0; i < numTally; i++) {
        printf("%s\n", tallies[i]);
        printPHand(pMaxHand[i]);
        printLHand(lMaxHand[i]);
    }

    for(int i = 0; i < 3; i++) {
        printf("MAX %s\n", tallies[i]);
        printPHand(pMaxLengthHand[i]);
        printLHand(lMaxLengthHand[i]);
    }

    printf("%10s%10s%10s%10s%10s\n", "Triple", "Quartet", "qS", "tD", "dT");

    printf("%10d%10d%10d%10d%10d\n", totalTally[TRIPLE], totalTally[QUARTET], totalTally[PENT_SINGLE], totalTally[TRI_DOUBLE], totalTally[DUAL_TRIPLE]);
    printf("%10.2f%10.2f%10.2f%10.2f%10.2f\n", totalTally[TRIPLE] * 1.0 / ITER / 3.0 / 3.0, totalTally[QUARTET] * 1.0 / ITER / 3.0 / 3.0, totalTally[PENT_SINGLE] * 1.0 / ITER / 3.0 / 3.0, totalTally[TRI_DOUBLE] * 1.0 / ITER / 3.0 / 3.0, totalTally[DUAL_TRIPLE] * 1.0 / ITER / 3.0 / 3.0);

    printf("%10.2f%10.2f%10.2f%10.2f%10.2f\n", pTotalTally[TRIPLE] * 1.0 / ITER / 2.0 / 3.0, pTotalTally[QUARTET] * 1.0 / ITER / 2.0 / 3.0, pTotalTally[PENT_SINGLE] * 1.0 / ITER / 2.0 / 3.0, pTotalTally[TRI_DOUBLE] * 1.0 / ITER / 2.0 / 3.0, pTotalTally[DUAL_TRIPLE] * 1.0 / ITER / 2.0 / 3.0);
    printf("%10.2f%10.2f%10.2f%10.2f%10.2f\n", lTotalTally[TRIPLE] * 1.0 / ITER / 3.0, lTotalTally[QUARTET] * 1.0 / ITER / 3.0, lTotalTally[PENT_SINGLE] * 1.0 / ITER / 3.0, lTotalTally[TRI_DOUBLE] * 1.0 / ITER / 3.0, lTotalTally[DUAL_TRIPLE] * 1.0 / ITER / 3.0);

    return 0;
}

void printPHand(int hands[perHand]) {
    for(int j = 0; j < perHand; j++) {
        printf("%2d ", hands[j]);
    }
    printf("\n");

    for(int j = 0; j < perHand; j++) {
        printf("%2d ", intToFace(hands[j]));
    }
    printf("\n");
}

void printLHand(int hands[perHand + 3]) {
    for(int j = 0; j < perHand + 3; j++) {
        printf("%2d ", hands[j]);
    }
    printf("\n");

    for(int j = 0; j < perHand + 3; j++) {
        printf("%2d ", intToFace(hands[j]));
    }
    printf("\n");
}

void processData(int hands[3][perHand], int handsFull[3][perHand + 3]) {
    //p1 as landlord
    addToTally(0, 1, 2, hands, handsFull);

    //p2
    addToTally(2, 0, 1, hands, handsFull);

    //p3
    addToTally(1, 0, 2, hands, handsFull);
}

//p1 is landlord
void addToTally(int l1, int p1, int p2, int hands[3][perHand], int handsFull[3][perHand + 3]) {
    for (int i = 0; i < numTally; i++){
        if (lMaxTally[i] < tally[l1 * 2 + 1][i]) {
            lMaxTally[i] = tally[l1 * 2 + 1][i];
            memcpy(lMaxHand[i], handsFull[l1], (perHand + 3) * sizeof(int));
        }
        if (pMaxTally[i] < tally[p1 * 2][i]) {
            pMaxTally[i] = tally[p1 * 2][i];
            memcpy(pMaxHand[i], hands[p1], perHand * sizeof(int));
        }
        if (pMaxTally[i] < tally[p2 * 2][i]) {
            pMaxTally[i] = tally[p2 * 2][i];
            memcpy(pMaxHand[i], hands[p2], perHand * sizeof(int));
        }

        lTotalTally[i] += tally[l1 * 2 + 1][i];
        pTotalTally[i] += tally[p1 * 2][i] + tally[p2 * 2][i];

        totalTally[i] += tally[p1 * 2][i] + tally[p2 * 2][i]+ tally[l1 * 2 + 1][i];
    }

    for (int i = 0; i < 3; i++){
        if (lMaxLengthTally[i] < maxLength[l1 * 2 + 1][i]) {
            lMaxLengthTally[i] = maxLength[l1 * 2 + 1][i];
            memcpy(lMaxLengthHand[i], handsFull[l1], (perHand + 3) * sizeof(int));
        }
        if (pMaxLengthTally[i] < maxLength[p1 * 2][i]) {
            pMaxLengthTally[i] = maxLength[p1 * 2][i];
            memcpy(pMaxLengthHand[i], hands[p1], perHand * sizeof(int));
        }
        if (pMaxLengthTally[i] < maxLength[p2 * 2][i]) {
            pMaxLengthTally[i] = maxLength[p2 * 2][i];
            memcpy(pMaxLengthHand[i], hands[p2], perHand * sizeof(int));
        }
    }
}

void findPatterns() {
    memset(tally, 0, sizeof(tally));
    memset(maxLength, 0, sizeof(maxLength));

    for(int i = 0; i < 6; i++) {
        //triples and quads
        for (int j = 0; j < faces; j++) {
            if (faceCount[i][j] > 3) {
                tally[i][QUARTET]++;
            }

            if (faceCount[i][j] > 2) {
                tally[i][TRIPLE]++;
            }
        }

        //triple double
        for (int j = 0; j < faces - 2; j++) {
            if (faceCount[i][j] > 1 && faceCount[i][j + 1] > 1 && faceCount[i][j + 2] > 1) {
                tally[i][TRI_DOUBLE]++;

                int counter = j;
                int length = 3;
                while (counter < faces - 1 && faceCount[i][counter + 1] > 1) {
                    length++;
                    counter++;
                }

                if (length > maxLength[i][MAX_DOUBLE]) {
                    maxLength[i][MAX_DOUBLE] = length;
                }

                j += 2;
            }
        }

        //double triple
        for (int j = 0; j < faces - 1; j++) {
            if (faceCount[i][j] > 2 && faceCount[i][j + 1] > 2) {
                tally[i][DUAL_TRIPLE]++;

                int counter = j;
                int length = 2;
                while (counter < faces - 1 && faceCount[i][counter + 1] > 2) {
                    length++;
                    counter++;
                }

                if (length > maxLength[i][MAX_TRIPLE]) {
                    maxLength[i][MAX_TRIPLE] = length;
                }

                j++;
            }

            if (faceCount[i][j] > 3) {
                int counter = j;
                int length = 1;
                while (counter < faces - 1 && faceCount[i][counter + 1] > 3) {
                    length++;
                    counter++;
                }

                if (length > maxLength[i][MAX_QUARTET]) {
                    maxLength[i][MAX_QUARTET] = length;
                }
            }
        }

        //quintSingle
        for (int j = 0; j < faces - 4; j++) {
            if (faceCount[i][j] && faceCount[i][j + 1] && faceCount[i][j + 2] && faceCount[i][j + 3] && faceCount[i][j + 4] ) {
                tally[i][PENT_SINGLE]++;
                j += 4;
            }
        }
    }

    /*
    printf("%4s%4s%4s%4s%4s\n", "T", "Q", "qS", "tD", "dT");

    for(int i = 0; i < 6; i++) {
        printf("%4d%4d%4d%4d%4d\n", tally[i][TRIPLE], tally[i][QUARTET], tally[i][PENT_SINGLE], tally[i][TRI_DOUBLE], tally[i][DUAL_TRIPLE]);
    }

    printf("%4s%4s%4s\n", "M_T", "M_D", "M_S");

    for(int i = 0; i < 6; i++) {
        printf("%4d%4d%4d\n", maxLength[i][MAX_TRIPLE], maxLength[i][MAX_DOUBLE], maxLength[i][MAX_SINGLE]);
    }
     */

}

void countFaces(int hands[3][perHand], int handsFull[3][perHand + 3]) {
    memset(faceCount, 0, sizeof(faceCount));

    for(int i = 0; i < 3; i++) {
        for (int j = 0; j < perHand - 1; j++) {
            int count = 1;
            while (intToFace(hands[i][j]) == intToFace(hands[i][j + 1])) {
                count++;
                j++;
            }
            faceCount[i * 2][intToFace(hands[i][j]) - 3] = count;
        }

        if (intToFace(hands[i][perHand - 2]) > 15) {
            faceCount[i * 2][13] = 2;
        }
        else if (intToFace(hands[i][perHand - 1]) > 15) {
            faceCount[i * 2][13] = 1;
        }

        for (int j = 0; j < perHand + 3 - 1; j++) {
            int count = 1;
            while (intToFace(handsFull[i][j]) == intToFace(handsFull[i][j + 1])) {
                count++;
                j++;
            }
            faceCount[i * 2 + 1][intToFace(handsFull[i][j]) - 3] = count;
        }

        if (intToFace(handsFull[i][perHand + 3 - 2]) > 15) {
            faceCount[i * 2 + 1][13] = 2;
        }
        else if (intToFace(handsFull[i][perHand + 3 - 1]) > 15) {
            faceCount[i * 2 + 1][13] = 1;
        }
    }
}

void cardSetup(int hands[3][perHand], int handsFull[3][perHand + 3], int cards[cardCount], int extraHand[3]) {
    shuffle(cards, cardCount);
    memcpy(hands[0], cards, perHand * sizeof(int));
    memcpy(hands[1], &cards[perHand], perHand * sizeof(int));
    memcpy(hands[2], &cards[perHand * 2], perHand * sizeof(int));
    memcpy(extraHand, &cards[51], 3 * sizeof(int));

    for (int i = 0; i < 3; i++) {
        memcpy(handsFull[i], hands[i], perHand * sizeof(int));
        memcpy(&handsFull[i][perHand], extraHand, 3 * sizeof(int));
        selectionSort(hands[i], perHand);
        selectionSort(handsFull[i], perHand + 3);
    }

    selectionSort(extraHand, 3);
}

void printAllHands(int hands[3][perHand], int handsFull[3][perHand + 3], int extraHand[3]) {
    for(int i = 0; i < 3; i++) {
        printf("Hand%d ", i);
        /*

        for(int j = 0; j < perHand; j++) {
            printf("%d ", hands[i][j]);
        }
        printf("\n");
         */

        for(int j = 0; j < perHand; j++) {
            printf("%2d ", intToFace(hands[i][j]));
        }
        printf("\n");

        printf("EXTRA%d ", i);
        /*

        for(int j = 0; j < perHand; j++) {
            printf("%d ", hands[i][j]);
        }
        printf("\n");
         */

        for(int j = 0; j < perHand + 3; j++) {
            printf("%2d ", intToFace(handsFull[i][j]));
        }
        printf("\n");

        /*
        for(int j = 0; j < perHand; j++) {
            printf("%s ", intToDesc(hands[i][j]));
        }

        printf("\n");
         */
    }

    printf("EXTRA ");
    for (int i = 0; i < 3; i++) {
        printf("%2d ", intToFace(extraHand[i]));;
    }
    printf("\n");
}

int intToFace(int card) {
    int face = card / 4 + 3;
    if (card == 53) face = 17;
    return face;
}

//spade heart club diamond
char* intToDesc(int card) {
    int face = intToFace(card);
    int suit = card % 4;
    static char cardName[15];

    if (face < 11) {
        sprintf(cardName, "%2d of %s", face, suits[suit]);
    } else if (face < 16) {
        sprintf(cardName, "%2s of %s", letterCards[face - 11], suits[suit]);
    } else {
        //printf("face = %d\n", face);
        sprintf(cardName, "%s", letterCards[face - 11]);
    }

    return cardName;
}

void shuffle(int *array, int n) {
    if (n > 1) {
        int i;
        for (i = 0; i < n - 1; i++) {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

void swap(int* xp, int* yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}