------------------------------------------------------------------------------
   DELOREAN 
------------------------------------------------------------------------------
An Error Handler for C/C++ funtions, focused on code readability. It allows a clear control flow, adding Ignore, Retry, Jump, and Back functionality when a function returns error. It's macro based, written in C and targeting embedded systems.

Features

* Simple (clean code and really easy to learn)
* Lightweight (ready for embedded systems)
* Macro based (just include a header, and it's ready to use)
* Novel license
* It's optimized, but taking care of the 88mph limit
* Warning: right now there is not any intention to be backward compatible (still)

------------------------------------------------------------------------------

Do you call many successive functions in C language ?
and do you want to check if those functions return OK or ERROR?

let supose
```C
    ==0 mean OK 
    !=0 mean ERROR
```
so the code could be:

```C
    if(functionA()!=0)
     {error management}
    if(functionB()!=0)
     {error management}
    if(functionC()!=0)
     {error management}
    if(functionD()!=0)
     {error management}
    if(functionE()!=0)
     {error management}
```

But what if I wish to skip at error ?  
and what if I wish to "retry" the one that fail?  
and of course, what if I also want the code to be clean and beautiful ?  

this is another option of coding:
```C
    do{
       if(functionA()!=0)  {error=1;break;}
       if(functionB()!=0)  {error=2;break;}
       if(functionC()!=0)  {error=3;break;}
       if(functionD()!=0)  {error=4;break;}
       if(functionE()!=0)  {error=5;break;}
       break;
    }while(1)
```
{error management with a switch for example}

Mmmm but the code don't get any better at beauty, and furthermore I still can't "retry" easily...


What about something like this...
```C
    TEST
        functionA();
        functionB(); Repeat_If_Fail(4 times);
        functionC();
        functionD(); Jump_If_Fail();
        functionE();
    END_TEST
```
Does it looks better?

So you should take a look to **delorean.h**, it's even more compact :
```Pascal
    TEST
        functionA() _
        functionB() _R(4);
        functionC() _
        functionD() _
        functionE() _
    END_TEST
```
enjoy it
