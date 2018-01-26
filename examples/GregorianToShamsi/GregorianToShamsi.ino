/*
 * this example show the simplest way to converting a
 * GREGORIAN Date in format of YYYY/M/D (ex.2010/2/20)
 * to its SHAMSI equivalent. check library root folder for more
 * informations.
 */

#include "DateConvL.h"

uint16_t current_year, current_month, current_day;
DateConvL dateC;

void setup() {
  Serial.begin(9600);
  SetCurrentDate();
  dateC.ToShamsi(current_year,current_month,current_day); // converts global values of date and stores them to dateC
  Serial.print(dateC.global_year, DEC);
  Serial.print('/');
  Serial.print(dateC.global_month, DEC);
  Serial.print('/');
  Serial.print(dateC.global_day, DEC);
  Serial.println();
}

void loop() {}


/*
 * this function get current time and set date integers declared above
 * IT IS NOT A PART OF LIBRARY but used to display current shamsi date
 * come from : https://gist.github.com/djohnson001/6df673a8d7f8ac04246a
 */
String SetCurrentDate()
{
  char const *date = __DATE__;
  char s_month[5];
  int _month, _day, _year;
  static const char month_names[] = "JanFebMarAprMayJunJulAugSepOctNovDec";
  sscanf(date, "%s %d %d", s_month, &current_day, &current_year);
  current_month = ((strstr(month_names, s_month)-month_names)/3) + 1;
}
