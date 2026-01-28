//
// Created by Vanhuljo on 21/02/2023.
// Schrijf een programma waarbij je een struct declareert met de naam student.
// Deze struct bevat het studentennummer, de studierichting,
// welk jaar van de bachelor (1ste bachelor, 2de bachelor, 3de bacholor of geïndividualiseerd traject)
// en het huidige academiejaar (i.e. 2022-2023).
// Definieer een enum om het jaar van de bachelor mee aan te duiden.
//
// Als het programma wordt uitgevoerd kan de gebruiker het studentennummer, studierichting,
// jaar van de bachelor en huidig academiejaar ingevoerd worden.
// Deze gegevens worden opgeslagen in een variabele van het datatype struct student.
//

#include "stdio.h"
#include "ctype.h"

struct student {
    int studentNumber;
    char studentClass[20];
    int startedsStudentYear, lastStudentYear;
    char school[20];

    enum {
        first_bachelor = 'F',
        second_bachelor = 'S',
        third_bachelor = 'L',
        indu_bachelor = 'I'
    } bachelorYear;
} schoolInformation;

char gender;

int main() {
    printf("Hello give me your school: \n");
    (void) scanf("%s", &schoolInformation.school);
    printf("Hello give me your studentnumber: \n");
    (void) scanf("%d", &schoolInformation.studentNumber);
    printf("Hello give me your Class: \n");
    (void) scanf("%s", &schoolInformation.studentClass);
    printf("Hello give me your started student year: \n");
    (void) scanf("%d", &schoolInformation.startedsStudentYear);
    printf("Hello give me your last student year: \n");
    (void) scanf("%d", &schoolInformation.lastStudentYear);
    printf("What Student are you? (first = f,second = s,last = l,indiv = i) \n");
    getchar();
    (void) scanf("%c", &gender);
    gender = toupper(gender);
    schoolInformation.bachelorYear = gender == first_bachelor ? first_bachelor : gender == second_bachelor ? second_bachelor : third_bachelor;

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
           "==================================================\n"
           "| Your school: \t\t %s \n"
           "| Your email: \t\t %d@student.%s.be \n| Your Class: \t\t %s \n| Your Years: \t\t %d - %d\n| Your status: \t\t %c",
           schoolInformation.school, schoolInformation.studentNumber, schoolInformation.school,
           schoolInformation.studentClass,
           schoolInformation.startedsStudentYear, schoolInformation.lastStudentYear, gender);

    printf("\n ==================================================\n");
    return 0;
}