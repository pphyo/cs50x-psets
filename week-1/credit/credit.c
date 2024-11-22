#include <cs50.h>
#include <stdio.h>

int getCardNumberLength(long cardNumber);
void printInvalid();
bool checkChecksum(long cardNumber);
bool checkAmex(bool isCredit, int length, int startNumber);
bool checkMaster(bool isCredit, int length, int startNumber);
bool checkVisa(bool isCredit, int length, int startNumber);
int getStartNumber(long cardNumber);

int main(void)
{
    long cardNumber = get_long("Number: ");

    int length = getCardNumberLength(cardNumber);
    if(length == 13 || length == 15 || length == 16) {

        bool isCredit = checkChecksum(cardNumber);
        int startNumber = getStartNumber(cardNumber);

        if(checkAmex(isCredit, length, startNumber)) {
            printf("AMEX\n");
        } else if(checkMaster(isCredit, length, startNumber)) {
            printf("MASTERCARD\n");
        } else if(checkVisa(isCredit, length, startNumber)) {
            printf("VISA\n");
        } else {
            printInvalid();
        }

    } else {
        printInvalid();
    }

}

void printInvalid() {
    printf("INVALID\n");
}

int getCardNumberLength(long cardNumber) {
    int length = 0;
    while(cardNumber > 0) {
        cardNumber = cardNumber / 10;
        length ++;
    }

    return length;
}

bool checkAmex(bool isCredit, int length, int startNumber) {
    return isCredit == true && length == 13 && (startNumber == 34 || startNumber == 37);
}

bool checkMaster(bool isCredit, int length, int startNumber) {
    return isCredit == true && length == 16 && (startNumber == 51 || startNumber == 52 || startNumber == 53 || startNumber == 54 || startNumber == 55);
}

bool checkVisa(bool isCredit, int length, int startNumber) {
    return isCredit == true && (length == 13 || length == 16) && startNumber == 4;
}

bool checkChecksum(long cardNumber) {

    int counter = 0, secondToLastDigit = 0, otherDigit = 0, sum = 0;
    long number = 0;

    while(cardNumber > 0) {

        number = cardNumber;
        cardNumber = cardNumber / 10;
        int mod = number % 10;

        if(counter % 2 == 0) {
            otherDigit += mod;
        } else {

            int result = mod * 2;

            if(result > 10) {
                secondToLastDigit += (result / 10) + (result % 10);
            } else {
                secondToLastDigit += result;
            }

        }

        counter++;
    }

    sum = secondToLastDigit + otherDigit;

    return sum > 0 ? true : false;
}

int getStartNumber(long cardNumber) {

    int start = 0;
    while(cardNumber > 100) {
        cardNumber = cardNumber / 10;
    }
    start = cardNumber;

    int visaNumber = start / 10;

    if(visaNumber == 4) {
        start = visaNumber;
    }

    return start;
}
