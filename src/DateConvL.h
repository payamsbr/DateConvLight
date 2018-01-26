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

#ifndef DateConvL_h
#define DateConvL_h

#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

class DateConvL {
	public:
		void ToShamsi(uint16_t,uint16_t,uint16_t);
		void ToGregorian(uint16_t,uint16_t,uint16_t);
		uint16_t global_year, global_month, global_day;
	private:
		const uint16_t grgSumOfDays[2][13]={
			{0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365},
			{0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366}};
		const uint16_t hshSumOfDays[2][13]={
			{0, 31, 62, 93, 124, 155, 186, 216, 246, 276, 306, 336, 365}, 
			{0, 31, 62, 93, 124, 155, 186, 216, 246, 276, 306, 336, 366}};
		boolean grgIsLeap (uint16_t);
		boolean hshIsLeap (uint16_t);
};

#endif


