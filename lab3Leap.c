#include <stdio.h>

int isLeap(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1;
    }
    return 0;
}

int countDays(int month, int day, int isLeap) {
    int daysInMonth[] = {31, (isLeap ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days = 0;
    for (int i = 0; i < month - 1; i++) {
        days += daysInMonth[i];
    }
    days += day;
    return days;
}

int main() {
    int year, month, day;
    while (1) {
        printf("Enter date ('YYYY MM DD'): ");
        scanf("%d %d %d", &year, &month, &day);
        if (year < 0) {
            printf("Year Can't be nevitive.");
            break;
            }
        int leap = isLeap(year);
        int daysElapsed = countDays(month, day, leap);
        printf("%d days of year %d have elapsed%s\n", daysElapsed, year, leap ? " [leap year]" : "");
    }
    return 0;
}
