#!/bin/sh
test_cases=( \
"{A,B}{C,D}" \
"{A,B,C}" \
"{A,B{C,D}}" \
"{ABC}" \
"ABC" "}ABC" \
"{ABC" "}{" \
"{}" \
"A,B,C" \
"{A{B,C}" \
"{A,}" \
"{A,B},{C,D}" \
"{A,B}{C,D}" \
"tom{DICK,harry}SAM{louis,JOHN}peter" \
"{one{two{three{four{five{six{seven{eight{nine{ten{eleven{twelve{thirteen{fourteen{fifteen{sixteen{seventeen{eighteen{nineteen{twenty{twentyone{twentytwo{twentythree{twentyfour{\
twentyfive{twentysix{twentyseven{twentyeight{twentynine{thirty{thirtyone{thirtytwo{thirtythree{thirtyfour{thirtyfive{thirtysix{thirtyseven{thirtyeight{thirtynine{forty{fortyone{fortytwo{"\
"fortythree{fortyfour{fortyfive{fortysix{fortyseven{fortyeight{fortynine{fifty{fiftyone{fiftytwo{fiftythree{fiftyfour{fiftyfive{fiftysix{fiftyseven{fiftyeight}fiftynine}sixty}sixtyone}sixtytwo}"\
"sixtythree}sixtyfour}sixtyfive}sixtysix}sixtyseven}sixtyeight}sixtynine}seventy}seventyone}seventytwo}seventythree}seventyfour}seventyfive}seventysix}seventyseven}seventyeight}seventynine}eighty}"\
"eightyone}eighttwo}eightythree}eightyfour}eightfive}eightysix}eightyseven}eightyeight}eightynine}ninety}ninetyone}ninetytwo}ninetythree}ninetyfour}ninetyfive}ninetysix}ninetyseven}ninetyeight}ninetynine}"\
"hundered}hunderedone}hundredtwo}hundredthree}hundredfour}hundredfive}hundredsix}hundredseven}hundredeight}hundrednine}hundredten}hundredeleven}hundredtwelve}hundredthirteen}hundredforteen}hundredfifteen}" \
"A{B,C}DE{F,G,H}I" \
"A{B,C}D,E{F,G,H}I" \
)

for i in "${test_cases[@]}"
do
	echo $i
	echo $i | ./okc_be.tsk
	echo "================="
done