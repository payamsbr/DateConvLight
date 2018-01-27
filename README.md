# DateConvLight
A light weight library for some one who needs to convert Gregorian(machine) 
original date to Iranian(Persian/Farsi/Shamsi/Jalali) date with benefit of supporting leap years.
also support a back way conversion which comes handy for someone who need to adjust
devices time (for example an RTC module <DS1307>) with a Persian date that shall be internally converted.

<h3> example </h3>

<pre style='color:#000000;background:#ffffff;'><span style='color:#696969; '>/*</span>
<span style='color:#696969; '>&#xa0;* this example show the simplest way to converting a</span>
<span style='color:#696969; '>&#xa0;* GREGORIAN Date in format of YYYY/M/D (ex.2010/2/20)</span>
<span style='color:#696969; '>&#xa0;* to its SHAMSI equivalent. check library root folder for more</span>
<span style='color:#696969; '>&#xa0;* informations.</span>
<span style='color:#696969; '>&#xa0;*/</span>

<span style='color:#004a43; '>#</span><span style='color:#004a43; '>include </span><span style='color:#800000; '>"</span><span style='color:#40015a; '>DateConvL.h</span><span style='color:#800000; '>"</span>

uint16_t current_year<span style='color:#808030; '>,</span> current_month<span style='color:#808030; '>,</span> current_day<span style='color:#800080; '>;</span>
DateConvL dateC<span style='color:#800080; '>;</span>

<span style='color:#800000; font-weight:bold; '>void</span> setup<span style='color:#808030; '>(</span><span style='color:#808030; '>)</span> <span style='color:#800080; '>{</span>
  Serial<span style='color:#808030; '>.</span>begin<span style='color:#808030; '>(</span><span style='color:#008c00; '>9600</span><span style='color:#808030; '>)</span><span style='color:#800080; '>;</span>
  SetCurrentDate<span style='color:#808030; '>(</span><span style='color:#808030; '>)</span><span style='color:#800080; '>;</span>
  dateC<span style='color:#808030; '>.</span>ToShamsi<span style='color:#808030; '>(</span>current_year<span style='color:#808030; '>,</span>current_month<span style='color:#808030; '>,</span>current_day<span style='color:#808030; '>)</span><span style='color:#800080; '>;</span> <span style='color:#696969; '>// converts global values of date and stores them to dateC</span>
  Serial<span style='color:#808030; '>.</span>print<span style='color:#808030; '>(</span>dateC<span style='color:#808030; '>.</span>global_year<span style='color:#808030; '>,</span> DEC<span style='color:#808030; '>)</span><span style='color:#800080; '>;</span>
  Serial<span style='color:#808030; '>.</span>print<span style='color:#808030; '>(</span><span style='color:#0000e6; '>'/'</span><span style='color:#808030; '>)</span><span style='color:#800080; '>;</span>
  Serial<span style='color:#808030; '>.</span>print<span style='color:#808030; '>(</span>dateC<span style='color:#808030; '>.</span>global_month<span style='color:#808030; '>,</span> DEC<span style='color:#808030; '>)</span><span style='color:#800080; '>;</span>
  Serial<span style='color:#808030; '>.</span>print<span style='color:#808030; '>(</span><span style='color:#0000e6; '>'/'</span><span style='color:#808030; '>)</span><span style='color:#800080; '>;</span>
  Serial<span style='color:#808030; '>.</span>print<span style='color:#808030; '>(</span>dateC<span style='color:#808030; '>.</span>global_day<span style='color:#808030; '>,</span> DEC<span style='color:#808030; '>)</span><span style='color:#800080; '>;</span>
  Serial<span style='color:#808030; '>.</span>println<span style='color:#808030; '>(</span><span style='color:#808030; '>)</span><span style='color:#800080; '>;</span>
<span style='color:#800080; '>}</span>

<span style='color:#800000; font-weight:bold; '>void</span> loop<span style='color:#808030; '>(</span><span style='color:#808030; '>)</span> <span style='color:#800080; '>{</span><span style='color:#800080; '>}</span>


<span style='color:#696969; '>/*</span>
<span style='color:#696969; '>&#xa0;* this function get current time and set date integers declared above</span>
<span style='color:#696969; '>&#xa0;* IT IS NOT A PART OF LIBRARY but used to display current shamsi date</span>
<span style='color:#696969; '>&#xa0;* come from : </span><span style='color:#5555dd; '>https://gist.github.com/djohnson001/6df673a8d7f8ac04246a</span><span style='color:#696969; '></span>
<span style='color:#696969; '>&#xa0;*/</span>
<span style='color:#603000; '>String</span> SetCurrentDate<span style='color:#808030; '>(</span><span style='color:#808030; '>)</span>
<span style='color:#800080; '>{</span>
  <span style='color:#800000; font-weight:bold; '>char</span> <span style='color:#800000; font-weight:bold; '>const</span> <span style='color:#808030; '>*</span>date <span style='color:#808030; '>=</span> __DATE__<span style='color:#800080; '>;</span>
  <span style='color:#800000; font-weight:bold; '>char</span> s_month<span style='color:#808030; '>[</span><span style='color:#008c00; '>5</span><span style='color:#808030; '>]</span><span style='color:#800080; '>;</span>
  <span style='color:#800000; font-weight:bold; '>int</span> _month<span style='color:#808030; '>,</span> _day<span style='color:#808030; '>,</span> _year<span style='color:#800080; '>;</span>
  <span style='color:#800000; font-weight:bold; '>static</span> <span style='color:#800000; font-weight:bold; '>const</span> <span style='color:#800000; font-weight:bold; '>char</span> month_names<span style='color:#808030; '>[</span><span style='color:#808030; '>]</span> <span style='color:#808030; '>=</span> <span style='color:#800000; '>"</span><span style='color:#0000e6; '>JanFebMarAprMayJunJulAugSepOctNovDec</span><span style='color:#800000; '>"</span><span style='color:#800080; '>;</span>
  <span style='color:#603000; '>sscanf</span><span style='color:#808030; '>(</span>date<span style='color:#808030; '>,</span> <span style='color:#800000; '>"</span><span style='color:#007997; '>%s</span><span style='color:#0000e6; '> </span><span style='color:#007997; '>%d</span><span style='color:#0000e6; '> </span><span style='color:#007997; '>%d</span><span style='color:#800000; '>"</span><span style='color:#808030; '>,</span> s_month<span style='color:#808030; '>,</span> <span style='color:#808030; '>&amp;</span>current_day<span style='color:#808030; '>,</span> <span style='color:#808030; '>&amp;</span>current_year<span style='color:#808030; '>)</span><span style='color:#800080; '>;</span>
  current_month <span style='color:#808030; '>=</span> <span style='color:#808030; '>(</span><span style='color:#808030; '>(</span><span style='color:#603000; '>strstr</span><span style='color:#808030; '>(</span>month_names<span style='color:#808030; '>,</span> s_month<span style='color:#808030; '>)</span><span style='color:#808030; '>-</span>month_names<span style='color:#808030; '>)</span><span style='color:#808030; '>/</span><span style='color:#008c00; '>3</span><span style='color:#808030; '>)</span> <span style='color:#808030; '>+</span> <span style='color:#008c00; '>1</span><span style='color:#800080; '>;</span>
<span style='color:#800080; '>}</span>
</pre>
