/*
 * Light weight library to converting Persian(shamsi/farsi) Date to Gregorian(miladi)
 * and vice versa in benefit of leap support.
 * co-creator: payam sabouri. paysab@gmail.com
 * for more informations please check github page (included in readme)
 * and example(s) coming with this library
 *
 * payam.
 * 2:03 PM 1/26/2018
 */
 
 #include "DateConvL.h"

void DateConvL::ToShamsi(uint16_t grgYear,uint16_t grgMonth,uint16_t grgDay)
{
  int16_t hshYear = grgYear-621;
  int16_t hshMonth, hshDay;
  boolean grgLeap = grgIsLeap (grgYear);
  boolean hshLeap = hshIsLeap (hshYear-1);
  int16_t hshElapsed;
  int16_t grgElapsed = grgSumOfDays[(grgLeap ? 1:0)][grgMonth-1]+grgDay;
  uint8_t XmasToNorooz = (hshLeap && grgLeap) ? 80 : 79;
  
  if (grgElapsed <= XmasToNorooz) {
    hshElapsed = grgElapsed+286;
    hshYear--;
    if (hshLeap && !grgLeap)
      hshElapsed++;
  } else {
    hshElapsed = grgElapsed - XmasToNorooz;
    hshLeap = hshIsLeap (hshYear);
  }
  for (uint8_t i=1; i <= 12 ; i++) {
    if (hshSumOfDays [(hshLeap ? 1:0)][i] >= hshElapsed) {
      hshMonth = i;
      hshDay = hshElapsed - hshSumOfDays [(hshLeap ? 1:0)][i-1];
      break;
    }
  }
  
  global_year = hshYear;
  global_month = hshMonth;
  global_day = hshDay;
}


void DateConvL::ToGregorian (uint16_t hshYear,uint16_t hshMonth,uint16_t hshDay)
{
  int16_t grgYear = hshYear+621;
  int16_t grgMonth, grgDay;
  boolean hshLeap = hshIsLeap (hshYear);
  boolean grgLeap = grgIsLeap (grgYear);
  int16_t hshElapsed = hshSumOfDays [hshLeap ? 1:0][hshMonth-1]+hshDay;
  int16_t grgElapsed;
  
  if (hshMonth > 10 || (hshMonth == 10 && hshElapsed > 286+(grgLeap ? 1:0))) {
    grgElapsed = hshElapsed - (286 + (grgLeap ? 1:0));
    grgLeap = grgIsLeap (++grgYear);
  } else {
    hshLeap = hshIsLeap (hshYear-1);
    grgElapsed = hshElapsed + 79 + (hshLeap ? 1:0) - (grgIsLeap(grgYear-1) ? 1:0);
  }
  for (uint8_t i=1; i <= 12; i++) {
    if (grgSumOfDays [grgLeap ? 1:0][i] >= grgElapsed) {
      grgMonth = i;
      grgDay = grgElapsed - grgSumOfDays [grgLeap ? 1:0][i-1];
      break;
    }
  }
  
  global_year = grgYear;
  global_month = grgMonth;
  global_day = grgDay;
}

boolean DateConvL::grgIsLeap (uint16_t Year)
{
  return ((Year%4) == 0 && ((Year%100) != 0 || (Year%400) == 0));
}

boolean DateConvL::hshIsLeap (uint16_t Year)
{
  Year = (Year - 474) % 128;
  Year = ((Year >= 30) ? 0 : 29) + Year;
  Year = Year - floor(Year/33) - 1;
  return ((Year % 4) == 0);
}


