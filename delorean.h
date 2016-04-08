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


#ifndef _DELOREAN_H
#define	_DELOREAN_H

#ifdef	__cplusplus
extern "C" {
#endif



//inicia bloque
#define TEST     do{\
                    int BadLuckInChoosingName_StepFix;\
                    int BadLuckInChoosingName_Step=0;\
                    int BadLuckInChoosingName_TstVar;\
                    int BadLuckInChoosingName_Retry;\
                    int BadLuckInChoosingName_PlsBreak;\
                    do{\
                    do{\
                    int BadLuckInChoosingName_last=0;\
                    BadLuckInChoosingName_StepFix=1;\
                    PRE_FUNC



#define PRE_FUNC    BadLuckInChoosingName_StepFix++;\
                    BadLuckInChoosingName_Retry=0;\
                    do{\
                        if(BadLuckInChoosingName_last==0)\
                        {BadLuckInChoosingName_PlsBreak=0;}\
                        if(BadLuckInChoosingName_Step<BadLuckInChoosingName_StepFix)\
                        {\
                        BadLuckInChoosingName_Retry++;\
                        BadLuckInChoosingName_TstVar=


#define INTER_FUNC ;\
                   }\
                   else\
                   {BadLuckInChoosingName_TstVar=0;}\
                   if(BadLuckInChoosingName_TstVar!=0)\
                   {\
                     BadLuckInChoosingName_PlsBreak=1;\
                   }\


#define POST_FUNC1  INTER_FUNC\
                    if(BadLuckInChoosingName_PlsBreak!=0)\
                    {\
                       break;\
                    }\
                    }while(0);\
                    if(BadLuckInChoosingName_PlsBreak!=0)\
                    {\
                       break;\
                    }

#define POST_FUNC0  INTER_FUNC\
                    }while(0);


#define POST_FUNC00(X)  INTER_FUNC\
                     if(BadLuckInChoosingName_PlsBreak==0)\
                      {\
                        break;\
                      }\
                     }while(BadLuckInChoosingName_Retry<X);


#define POST_FUNC(X)   POST_FUNC00(X)\
                       if(BadLuckInChoosingName_PlsBreak!=0)\
                       {\
                        break;\
                       }



#define DELOREAN      0; BadLuckInChoosingName_last=1\
                      POST_FUNC0\
                       break;\
                      }while(1);\
        

//BACK PARA VOLVER A REINTENTAR DESDE LA INSTRUCCION QUE SALTA WOW!
#define BACK        if(BadLuckInChoosingName_PlsBreak!=0)\
                    {\
                        BadLuckInChoosingName_PlsBreak=0;\
                        BadLuckInChoosingName_Step=BadLuckInChoosingName_StepFix-1;\
                        continue;\
                    }
    
//GOON PARA SEGUIR A PARTIR DE LA SIGUIENTE INSTRUCCION QUE SALTA WOW!
#define GOON        if(BadLuckInChoosingName_PlsBreak!=0)\
                    {\
                        BadLuckInChoosingName_PlsBreak=0;\
                        BadLuckInChoosingName_Step=BadLuckInChoosingName_StepFix;\
                        continue;\
                    }

#define END_TEST     break;\
                   }while(1);\
                    break;\
                   }while(1);

//Ignora el error
#define _I POST_FUNC0\
           PRE_FUNC

//Ante un error salta al final
#define _  POST_FUNC1\
           PRE_FUNC

//Ante un error salta al final + EXTRA_CODE
#define __(EXTRA_CODE)  ;\
                 EXTRA_CODE\
                 POST_FUNC1\
                 PRE_FUNC
    

//Reintenta X veces antes de saltar al final
#define _R(X) POST_FUNC(X)\
              PRE_FUNC

//Reintenta X veces antes de continuar
#define _RI(X) POST_FUNC00(X)\
               PRE_FUNC




#ifdef	__cplusplus
}
#endif

#endif	/* _MACROS_H */

