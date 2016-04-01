//-------------------------------------------------------------
//
//SAME AS JSON LICENSE 
//
//
//likeright (L) 2009  Hernan Echegoyemberry
//
//
//Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
//The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
//
//The Software shall be used for Good, not Evil.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. 
//-------------------------------------------------------------

#include<stdio.h>
#include"delorean.h"

int main(void) {
    			int err=0;
    			
                TEST
                         //** ZONE OF ONLY FUNCTION CALLS HERE ** FUNCTIONS RETURNS =0 OK , !=0 ERR
                    
                         err=doThis()	_                           
                         err=doThat()	_RI(2)
                         err=doOther()	_
                         err=doThat()	_
                         err=doThis()	_  
                                                  
                DELOREAN     

                		//OPTIONAL pure C/C++ code, also BACK / GOON magic keywords                                
                		
                    	if(err!=0){
						
								printf(" catch zone !");
                    	
								GOON ;
						}
                    	
                END_TEST
        		
				getchar();
				
			    return 0;
    
}

int doThis(){
	int err=0;		
	printf("\ndoing this..");
	return err;
}

int doThat() {
	int err=1;		
	printf("\ndoing that..");
	return err;
}

int doOther(){
	int err=0;		
	printf("\ndoing other..");
	return err;	
}


