#ifndef TRACER_H
#define TRACER_H

#include<fstream>
#include<iostream>
#include<string>
#include<time.h>

using namespace std;

/*
    Usage : to easily debug your module, follow the three easy steps
        -- include this file, i.e., 'tracer.h' in your source file
        -- declare new Tracer object at the start of a function/operation/context : Tracer t("context_name");
        -- you could also use the tracer's debug function : t.debug("reached this point");
        -- at the end of the context, the tracer's destructor logs the "exiting" message
*/

class Tracer{
private:
    string context_name;
    ostream &out;
    clock_t start_time;
    clock_t ignore_time;
public:
    Tracer(string module_name, ostream &fout) : out(fout){        
        context_name = module_name;
        cout << endl << context_name << endl ;
        start_time = clock();
        ignore_time = 0;
    }
    
    void debug(string debug_msg){
        clock_t temp = clock();
        cout << endl << debug_msg << endl ;
        ignore_time += (clock() - temp);
    }
    
    void pause(){
        clock_t temp = clock();
        cin.get();
        ignore_time += (clock() - temp);
    }
    
    virtual ~Tracer(){  
        clock_t end_time = clock();
        cout << endl << (end_time - start_time - ignore_time) << " Clock Cycles : " << "Exiting " << context_name << endl ;
    }
};

#endif 
