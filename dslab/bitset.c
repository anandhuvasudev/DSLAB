#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20

int superSet[MAX_SIZE], superSetSize = 0;
int setA[MAX_SIZE], setASize = 0;
int setB[MAX_SIZE], setBSize = 0;
int bitStringA[MAX_SIZE], bitStringB[MAX_SIZE];

void getUniversalSet();
void getSet(int arr[], int *size);
int  checkSetInUniversal(int arr[], int size);
void generateBitStrings();
void setUnion();
void setIntersection();
void setDifferenceAminusB();
void setDifferenceBminusA();
void printBitString(int arr[], int size);
void printSetFromBitString(int arr[], int size);

void getUniversalSet() {
    printf("enter Universal Set Size : ");
    scanf("%d", &superSetSize);
    if (superSetSize > MAX_SIZE) {
        printf("error: size exceeds maximum limit.\n");
        exit(1);
    }

	 printf("enter %d elements for the Universal Set:\n", superSetSize);
    for (int i = 0; i < superSetSize; i++) {
        printf("element %d: ", i + 1);
        scanf("%d", &superSet[i]);
    }
}

void getSet(int arr[], int *size) {
    printf("enter %d elements (must be in the Universal Set):\n", *size);
    for (int i = 0; i < *size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

int checkSetInUniversal(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int found = 0;
        for (int j = 0; j < superSetSize; j++) {
            if (arr[i] == superSet[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("error: element %d is not in the Universal Set. Please enter the set again.\n", arr[i]);
            return 0;
        }
    }
    return 1;
}

void generateBitStrings() {
    for (int i = 0; i < superSetSize; i++) {
        bitStringA[i] = 0;
        bitStringB[i] = 0;
    }

    for (int i = 0; i < setASize; i++) {
        for (int j = 0; j < superSetSize; j++) {
            if (setA[i] == superSet[j]) {
                bitStringA[j] = 1;
                break;
            }
        }
    }

    for (int i = 0; i < setBSize; i++) {
        for (int j = 0; j < superSetSize; j++) {
            if (setB[i] == superSet[j]) {
                bitStringB[j] = 1;
                break;
            }
        }
    }

    printf("set a bit string: ");
    printBitString(bitStringA, superSetSize);
    printf("set b bit string: ");
    printBitString(bitStringB, superSetSize);
}

void setUnion() {
    int bitStringUnion[MAX_SIZE];
    for (int i = 0; i < superSetSize; i++) {
        bitStringUnion[i] = bitStringA[i] | bitStringB[i];
    }
    printf("union: ");
    printBitString(bitStringUnion, superSetSize);
    printf("union result (values): ");
    printSetFromBitString(bitStringUnion, superSetSize);
}

void setIntersection() {
    int bitStringIntersection[MAX_SIZE];
    for (int i = 0; i < superSetSize; i++) {
        bitStringIntersection[i] = bitStringA[i] & bitStringB[i];
    }
    printf("intersection: ");
    printBitString(bitStringIntersection, superSetSize);
    printf("intersection result (values): ");
    printSetFromBitString(bitStringIntersection, superSetSize);
}

void setDifferenceAminusB() {
    int bitStringDifferenceAminusB[MAX_SIZE];
    for (int i = 0; i < superSetSize; i++) {
        bitStringDifferenceAminusB[i] = bitStringA[i] & (1 - bitStringB[i]);
    }
    printf("difference (a - b): ");
    printBitString(bitStringDifferenceAminusB, superSetSize);
    printf("difference result (a - b, values): ");
    printSetFromBitString(bitStringDifferenceAminusB, superSetSize);
}

void setDifferenceBminusA() {
    int bitStringDifferenceBminusA[MAX_SIZE];
    for (int i = 0; i < superSetSize; i++) {
        bitStringDifferenceBminusA[i] = bitStringB[i] & (1 - bitStringA[i]);
    }
    printf("difference (B - A): ");
    printBitString(bitStringDifferenceBminusA, superSetSize);
    printf("difference result (B - A, values): ");
    printSetFromBitString(bitStringDifferenceBminusA, superSetSize);
}

void printBitString(int arr[], int size) {
    printf("{");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("}\n");
}

void printSetFromBitString(int arr[], int size) {
    int first = 1;
    printf("{");
    for (int i = 0; i < size; i++) {
        if (arr[i] == 1) {
            if (!first) {
                printf(", ");
            }
            printf("%d", superSet[i]);
            first = 0;
        }
    }
    printf("}\n");
}

int main() {
    getUniversalSet();

    do {
        printf("enter set a size (max %d): ", superSetSize);
        scanf("%d", &setASize);
        if (setASize > superSetSize) {
            printf("error: set a size cannot exceed universal set size.\n");
        }
    } while (setASize > superSetSize);

    do {
        getSet(setA, &setASize);
    } while (checkSetInUniversal(setA, setASize) == 0);

    do {
        printf("enter Set B Size (max %d): ", superSetSize);
        scanf("%d", &setBSize);
        if (setBSize > superSetSize) {
            printf("error: Set B size cannot exceed Universal Set size.\n");
        }
    } while (setBSize > superSetSize);

    do {
        getSet(setB, &setBSize);
    } while (checkSetInUniversal(setB, setBSize) == 0);

    generateBitStrings();
    printf("\n");
    setUnion();
    printf("\n");
    setIntersection();
    printf("\n");
    setDifferenceAminusB();
printf("\n");
    setDifferenceBminusA();

    return 0;
}
