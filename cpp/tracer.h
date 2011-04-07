#ifndef TRACER_H
#define TRACER_H

#include<fstream>
#include<iostream>
#include<string>

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
public:
    Tracer(string module_name){        
        context_name = module_name;
        cout << endl << context_name << endl ;
    }
    
    void debug(string debug_msg){
        cout << endl << debug_msg << endl ;
    }
    
    virtual ~Tracer(){        
        cout << endl << "Exiting " << context_name << endl ;
    }
};

#endif 
