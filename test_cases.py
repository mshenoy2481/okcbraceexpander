import os

test_cases=[ 
            "{A,B}{C,D}",
            "{A,B,C}",
            "{A,B{C,D}}", 
            "{ABC}", 
            "ABC",
            "}ABC",
            "{ABC" "}{",
            "{}",
            "{{,}}",
            "{Tom{Kim, Harry}}",
            "{Tom{K!m,Harry}}", 
            "A,B,C", 
            "{A{B,C}", 
            "{A,}", 
            "{A,B},{C,D}",
            "{{A,B}P,Q{C,D}}", 
            "{A,B}PQ{C,D}",
            "P{A,B}{C,D}Q", 
            "{A,B}P,Q{C,D}",
            "{P{A,B},{C,D}Q}",
            "tom{DICK,harry}SAM{louis,JOHN}peter", 
            "{one{two{three{four{five{six{seven{eight{nine{ten{eleven{twelve{thirteen{fourteen{fifteen{sixteen{seventeen{eighteen{nineteen{twenty{twentyone{twentytwo{twentythree{twentyfour{" \
            "twentyfive{twentysix{twentyseven{twentyeight{twentynine{thirty{thirtyone{thirtytwo{thirtythree{thirtyfour{thirtyfive{thirtysix{thirtyseven{thirtyeight{thirtynine{forty{fortyone{fortytwo{" \
            "fortythree{fortyfour{fortyfive{fortysix{fortyseven{fortyeight{fortynine{fifty{fiftyone{fiftytwo{fiftythree{fiftyfour{fiftyfive{fiftysix{fiftyseven{fiftyeight}fiftynine}sixty}sixtyone}sixtytwo}" \
            "sixtythree}sixtyfour}sixtyfive}sixtysix}sixtyseven}sixtyeight}sixtynine}seventy}seventyone}seventytwo}seventythree}seventyfour}seventyfive}seventysix}seventyseven}seventyeight}seventynine}eighty}" \
            "eightyone}eighttwo}eightythree}eightyfour}eightfive}eightysix}eightyseven}eightyeight}eightynine}ninety}ninetyone}ninetytwo}ninetythree}ninetyfour}ninetyfive}ninetysix}ninetyseven}ninetyeight}ninetynine}" \
            "hundered}hunderedone}hundredtwo}hundredthree}hundredfour}hundredfive}hundredsix}hundredseven}hundredeight}hundrednine}hundredten}hundredeleven}hundredtwelve}hundredthirteen}hundredforteen}hundredfifteen}",
            "A{B,C}DE{F,G,H}I",
            "A{B,C}D,E{F,G,H}I", 
            "     {QW{W{E,RT}P,W{E,R}OP}}   ", 
            "{A,B}{C,D}{E,F,G}H{I,J,K,L}", 
            "{A,B}{C,3}", 
            "N{{{{{A,B}}}}{C,D}}", 
            "Q{{W{{{{A,B}}L}}}{C,D}}",
            "Q{{{W,B}D{A,B}{{{{W,E,R}T}O{W},E,T,O,{Top,Tip,Tap,Tup}{SUP,SIP,Sap},Op,On}Pi,Kin}O}}"
            
  ]

def main():
    for i in range(0,len(test_cases)) :
        print(test_cases[i])
        cmd="echo \""+test_cases[i]+"\" | ./okc_be.tsk"
        os.system(cmd)
        print("==========================================")

if __name__ == "__main__":
    main()