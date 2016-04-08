//-------------------------------------------------------------
//SAME AS JSON LICENSE 
//
//likeright (L) 2009  Hernan Echegoyemberry
//
//Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
//The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
//
//The Software shall be used for Good, not Evil.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. 
//-------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include "delorean.h"
#include <string.h>
 
int init(void);
int func(int callCount, int state);



/**
*    
*    Reference
*
*    TEST      START TEST BLOCK DELIMITER
*
*    _         IF FAIL->JUMP
*    _I        IF FAIL->IGNORE AND CONTINUE
*    _R(X)     IF FAIL->RETRY TILL X TIMES, IF KEEP FAILING->JUMP 
*    _RI(X)    IF FAIL->RETRY TILL X TIMES, IF KEEP FAILING->IGNORE AND CONTINUE
*    DELOREAN  END OF CHECKED FUNCTIONS DELIMITER AND START OF FREE C CODE (WHERE ALSO <<GOON>> AND <<BACK>> MACROS CAN BE USED)
*    GOON      CONTINUE FROM THE NEXT FUNCTION TO THAT FAILED
*    BACK      RETRY FROM FAIL FUNCTION 
*
*    END_TEST  END TEST BLOCK DELIMITER
*
*/

#define MAX_CALLS           20
#define TIMES_TO_REPAIR     3
#define OK                  0
#define FAIL                1

char output[1000];

char *expectedOutput="\nInit!\n" 
"call:1 OK!!\n" 
"call:2 OK!!\n" 
"call:3 Error in try : 1!\n"
"jump!(or end)\n"
"I will goon\n"
"call:4 Error in try : 1!\n"
"call:5 OK!!\n"
"call:6 Error in try : 1!\n" 
"call:6 Error in try : 2!\n"
"call:6 OK by insistence, the 3 is the last\n"
"call:7 OK!!\n"
"call:8 Error in try : 1!\n" 
"call:8 Error in try : 2!\n" 
"call:9 Error in try : 1!\n" 
"call:9 Error in try : 2!\n"
"call:9 OK by insistence, the 3 is the last\n"
"call:10 Error in try : 1!\n"
"call:10 Error in try : 2!\n"
"jump!(or end)\n" 
"I will goon\n" 
"call:11 OK!!\n" 
"call:12 OK!!\n" 
"call:13 Error in try : 1!\n" 
"call:13 Error in try : 2!\n" 
"jump!(or end)\n" 
"I will back\n" 
"call:13 OK by insistence, the 3 is the last\n" 
"call:14 OK!!\n" 
"call:15 OK!!\n" 
"jump!(or end)\n" 
"I will back\n" 
"Done!";

static int callCount=0;

int main(void) {
    
                TEST
                         //              
                         //** ZONE OF ONLY FUNCTION CALLS HERE ** FUNCTIONS RETURNS =0 OK , !=0 ERR
                         //
                         init()              _     //Init variables
                         func(1,OK)          _     //function ok 
                         func(2,OK)          _I    //function ok
                         func(3,FAIL)        _     //function fail and *WILL JUMP* (but will be "go on" see below)
                         func(4,FAIL)        _I    //function fail, but ignore  and continue
                         func(5,OK)          _R(2)  //function ok
                         func(6,FAIL)        _R(4)  //function fail, but get ok with some attempts
                         func(7,OK)          _RI(2) //function ok
                         func(8,FAIL)        _RI(2) //function fail, retry 2 then ignore and continue
                         func(9,FAIL)        _RI(4) //function fail, and get ok with some attempts, would ignore fail anyway
                         func(10,FAIL)       _R(2)  //function fail, retry 2 and *WILL JUMP* (but will be back to next, and "go on" see below DELOREAN)
                         func(11,OK)         _I     //function ok
                         func(12,OK)         _      //function ok
                         func(13,FAIL)       _R(2)  //function fail, retry 2 and *WILL JUMP* (but will be back and RETRY see below DELOREAN) 
                         func(14,OK)         _      //function ok
                         func(15,OK)         _      //function ok
                
                DELOREAN     

                //OPTIONAL pure C/C++ code, also BACK / GOON magic keywords
                
                        sprintf(&output[strlen(output)],"\njump!(or end)");             
                        
                        if(callCount<12){                          
                             sprintf(&output[strlen(output)],"\nI will goon");          
                             GOON;        //continues from last jump         
                        }else{					               
                             sprintf(&output[strlen(output)],"\nI will back");                
                             BACK;        //back and retry from last jump         
                        }                                                            
                END_TEST
    

                sprintf(&output[strlen(output)],"\nDone!");
    		     		     		 	
    			printf("Result[ %s ]", (strcmp(output, expectedOutput)==0)? "ALL TEST OK" : strcat( output," \nsome test failed!!!!\n") );
    			getchar();
    return (EXIT_SUCCESS);
    
}

//-------------------------------------------------------------------------------------------------------------------------------
static int times[MAX_CALLS];  
//-------------------------------------------------------------------------------------------------------------------------------
int init(void){
    sprintf(&output[strlen(output)],"\nInit!");
    int i;
    for(i=0;i<MAX_CALLS;i++){
        times[callCount]=0;
    }
	return 0;
}
//-------------------------------------------------------------------------------------------------------------------------------
int func(int llam, int state){
	
    callCount=llam;
    
    if(callCount>=MAX_CALLS) return 1;

    times[callCount]++;

    if(state==OK){
        sprintf(&output[strlen(output)],"\ncall:%d OK!!",callCount);
        return OK;
        
    }else{
        if(times[callCount]>=TIMES_TO_REPAIR){		
            
            sprintf(&output[strlen(output)],"\ncall:%d OK by insistence, the %d is the last",callCount,TIMES_TO_REPAIR);
            times[callCount]=0;
            return OK;
        }else{
            sprintf(&output[strlen(output)],"\ncall:%d Error in try : %d!", callCount,times[callCount]);
            return FAIL;
        }
    }

}


