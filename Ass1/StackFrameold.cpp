#include "StackFrame.h"
#include <iostream>
#include <fstream>
#include "errors.h"
#include "constants.h"
using namespace std;

StackFrame::StackFrame() : opStackMaxSize(OPERAND_STACK_MAX_SIZE), localVarArrSize(LOCAL_VARIABLE_ARRAY_SIZE) {}

float stackk[32];
float arr[256];
int ind_arr[256];
int line = 0;
int linee = 0;

void StackFrame::run(string filename) {
    for (int i = 0; i < 256; i++){

        ind_arr[i] = -999999;
    }
    ifstream file(filename);
    string s;
    
    
    if(file.is_open()){
        while (!file.eof()){
            string s1 = "";
            string s2 = "";
            getline(file, s);
            // for (int i = 0; i < line; i++){
            //     cout << stackk[i] << " ";
            // }
            // cout << endl;
            linee++;
            if(s.compare("f2i") == 0 || s.compare("i2f") == 0){
               s2 += s;
            }
            else{
                int i = 0;
                int n = s.length();
                for (i = 0; i < n; i++){
                    if(s[i] == ' ') break;
                    else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
                        s2 += s[i];
                    }  
                }

                for (int j = i+1; j < n; j++){
                    if(s[j] == ' ') break;
                    else if((s[j] >= '0' && s[j] <= '9') || s[j] == '.' || s[j] == '-') s1 += s[j];
                }
            }

            //cout << "s1: " << s1 << endl << "s2: " << s2 << endl;
            if (s1 != ""){
                if (s2.compare("iconst") == 0){
                    if(line == 32) throw StackFull(linee);
                    else{
                        stackk[line] = StackFrame::iconst(s1);
                        line++;
                        stackk[line] = 0;
                        line++;
                    }
                }
                else if (s2.compare("fconst") == 0){
                    if(line == 32) throw StackFull(linee);
                    else{
                        stackk[line] = StackFrame::fconst(s1);
                        line++;
                        stackk[line] = 1;
                        line++;
                    }
                }
                else if (s2.compare("iload") == 0){
                    //cout << "iloadin" << endl;
                    int count = 0;
                    for (int i = 0; i < 256; i++){
                        if(stoi(s1) != ind_arr[i]) count++;
                    }
                    if(count == 32) throw UndefinedVariable(linee);
                    if(stackk[line - 1] != 0){
                        throw TypeMisMatch(linee);
                    }
                    
                    if(stoi(s1) >= 256) throw ArrayOutOfRange(linee);
                    
                    if(line == 32) throw StackFull(linee);
                    if(stackk[line - 1] == 0){
                        StackFrame::iload(s1);
                        //cout << "iloadin" << endl;
                    }
                    
                }
                else if (s2.compare("fload") == 0){  
                    int count = 0;
                    for (int i = 0; i < 256; i++){
                        if(stoi(s1) != ind_arr[i]) {
                            count++;
                        }
                        //cout << ind_arr[i] << endl;
                    }
                    //cout << "count: " << count << endl;
                    if(count == 256) throw UndefinedVariable(linee);
                    if(stoi(s1) >= 256) throw ArrayOutOfRange(linee);
                    if(stackk[line - 1] == 0){
                        throw TypeMisMatch(linee);
                    }
                    if(line == 32) throw StackFull(linee);
                    if(stackk[line - 1] != 0){
                        StackFrame::fload(s1);
                    }
                }
                else if (s2.compare("istore") == 0){
                    //cout << "istore" << endl;
                    if(line == 0) throw StackEmpty(linee);
                    if(stackk[line - 1] != 0){
                        throw TypeMisMatch(linee);
                    }
                    if(stoi(s1) >= 256) throw ArrayOutOfRange(linee);
                    if(stackk[line - 1] == 0){
                        StackFrame::istore(s1);
                    }
                    //cout << "arr: " << arr[0] << endl;
                }

                else if (s2.compare("fstore") == 0){
                    if(line == 0) throw StackEmpty(linee);
                    if(stackk[line - 1] == 0 && stackk[line - 3] == 0){
                        throw TypeMisMatch(linee);
                    }
                    if(stoi(s1) >= 256) throw ArrayOutOfRange(linee);
                    if(stackk[line - 1] != 0 || stackk[line - 3] != 0){
                        StackFrame::fstore(s1);
                    }
                }
                else if (s2.compare("val") == 0){
                    if (stoi(s1) >= 256) throw ArrayOutOfRange(linee);
                    // if (stoi(s1) == 0) cout << arr[0] << endl;
                    // if(stoi(s1) != 0){
                    //     //int ind = stoi(s1) * 2;
                    int count = 0;
                    for (int i = 0; i < 256; i++){
                        if(stoi(s1) != ind_arr[i]) count++;
                    }
                    if(count == 256) throw UndefinedVariable(linee);
                    cout << arr[stoi(s1)] << endl;
                    //}

                }
            }

            else{
                if (s2.compare("iadd") == 0){
                    if (line == 2 || line == 0) throw StackEmpty(linee); 
                    if(stackk[line - 1] != 0 || stackk[line - 3] != 0){
                        throw TypeMisMatch(linee);
                    }
                    
                    if(stackk[line - 1] == 0 && stackk[line - 3] == 0){
                        StackFrame::iadd();
                    }
                }
                else if (s2.compare("fadd") == 0){
                    if (line == 2 || line == 0) throw StackEmpty(linee);
                    //if(stackk[line - 1] == 0 && stackk[line - 3] == 0){
                    //    throw TypeMisMatch(linee);
                    //}
                    
                    //if(stackk[line - 1] != 0 || stackk[line - 3] != 0){
                    StackFrame::fadd();
                    //}
                    
                }
                else if (s2.compare("isub") == 0){
                    if (line == 2 || line == 0) throw StackEmpty(linee);
                    if(stackk[line - 1] != 0 || stackk[line - 3] != 0){
                        throw TypeMisMatch(linee);
                    }
                     
                    if(stackk[line - 1] == 0 && stackk[line - 3] == 0){
                        StackFrame::isub();
                    }
                }
                else if (s2.compare("fsub") == 0){
                    
                    if (line == 2 || line == 0) throw StackEmpty(linee);
                    //if(stackk[line - 1] == 0 && stackk[line - 3] == 0){
                    //    throw TypeMisMatch(linee);
                    //}
                    //if(stackk[line - 1] != 0 || stackk[line - 3] != 0){
                    StackFrame::fsub();
                    //}
                }
                else if (s2.compare("imul") == 0){
                    if (line == 2 || line == 0) throw StackEmpty(linee);
                    if(stackk[line - 1] != 0 || stackk[line - 3] != 0){
                        throw TypeMisMatch(linee);
                    }
                     
                    if(stackk[line - 1] == 0 && stackk[line - 3] == 0){
                        StackFrame::imul();
                    }
                }
                else if (s2.compare("fmul") == 0){
                    if (line == 2 || line == 0) throw StackEmpty(linee);
                    //if(stackk[line - 1] == 0 && stackk[line - 3] == 0){
                    //    throw TypeMisMatch(linee);
                    //}
                    
                    //if(stackk[line - 1] != 0 || stackk[line - 3] != 0){
                    StackFrame::fmul();
                    //}
                }
                else if (s2.compare("idiv") == 0){
                    
                    if (line == 2 || line == 0) throw StackEmpty(linee);
                    if(stackk[line - 1] != 0 || stackk[line - 3] != 0){
                        throw TypeMisMatch(linee);
                    } 
                    if (stackk[line - 2] == 0){
                        throw DivideByZero(linee);
                    }
                    if(stackk[line - 1] == 0 && stackk[line - 3] == 0){
                        StackFrame::idiv();
                    }
                    
                }
                else if (s2.compare("fdiv") == 0){
                    
                    if (line == 2 || line == 0) throw StackEmpty(linee);
                    //if(stackk[line - 1] == 0 || stackk[line - 3] == 0){
                    //    throw TypeMisMatch(linee);
                    //} 
                    if (stackk[line - 2] == 0){
                        throw DivideByZero(linee);
                    }
                    //if(stackk[line - 1] != 0 || stackk[line - 3] != 0){
                    StackFrame::fdiv();
                    //}
                }
                else if (s2.compare("irem") == 0){
                    
                    if (line == 2 || line == 0) throw StackEmpty(linee);
                    if(stackk[line - 1] != 0 || stackk[line - 3] != 0){
                        throw TypeMisMatch(linee);
                    } 
                    if (stackk[line - 2] == 0){
                        throw DivideByZero(linee);
                    }
                    if(stackk[line - 1] == 0 && stackk[line - 3] == 0){
                        StackFrame::irem();
                    }
                }
                else if (s2.compare("ineg") == 0){
                    
                    if (line == 2 || line == 0) throw StackEmpty(linee); 
                     if(stackk[line - 1] != 0 || stackk[line - 3] != 0){
                        throw TypeMisMatch(linee);
                    }
                    if(stackk[line - 1] == 0 && stackk[line - 3] == 0){
                        StackFrame::ineg();
                    }
                    //StackFrame::ineg();
                }
                else if (s2.compare("fneg") == 0){
                    
                    if (line == 2 || line == 0) throw StackEmpty(linee);
                    //if(stackk[line - 1] == 0 && stackk[line - 3] == 0){
                    //    throw TypeMisMatch(linee);
                    //}
                    //if(stackk[line - 1] != 0 || stackk[line - 3] != 0){
                    StackFrame::fneg();
                    //}
                }
                else if (s2.compare("iand") == 0){
                    
                    if (line == 2 || line == 0) throw StackEmpty(linee);
                    if(stackk[line - 1] != 0 || stackk[line - 3] != 0){
                        throw TypeMisMatch(linee);
                    } 
                    if(stackk[line - 1] == 0 && stackk[line - 3] == 0){
                        StackFrame::iand();
                    }
                }
                else if (s2.compare("ior") == 0){
                    
                    if (line == 2 || line == 0) throw StackEmpty(linee); 
                    if(stackk[line - 1] != 0 || stackk[line - 3] != 0){
                        throw TypeMisMatch(linee);
                    }
                    if(stackk[line - 1] == 0 && stackk[line - 3] == 0){
                        StackFrame::ior();
                    }
                }
                else if (s2.compare("ieq") == 0){
                    
                    if (line == 2 || line == 0) throw StackEmpty(linee); 
                    if(stackk[line - 1] != 0 || stackk[line - 3] != 0){
                        throw TypeMisMatch(linee);
                    }
                    if(stackk[line - 1] == 0 && stackk[line - 3] == 0){
                        StackFrame::ieq();
                    }
                }
                else if (s2.compare("feq") == 0){
                    
                    if (line == 2 || line == 0) throw StackEmpty(linee);
                    //if(stackk[line - 1] == 0 && stackk[line - 3] == 0){
                    //    throw TypeMisMatch(linee);
                    //}
                    if(stackk[line - 1] != 0 || stackk[line - 3] != 0){
                        StackFrame::feq();
                    }
                }
                else if (s2.compare("ineq") == 0){
                    
                    if (line == 2 || line == 0) throw StackEmpty(linee); 
                    if(stackk[line - 1] != 0 || stackk[line - 3] != 0){
                        throw TypeMisMatch(linee);
                    }
                    if(stackk[line - 1] == 0 && stackk[line - 3] == 0){
                        StackFrame::ineq();
                    }
                }
                else if (s2.compare("fneq") == 0){
                    
                    if (line == 2 || line == 0) throw StackEmpty(linee);
                    //if(stackk[line - 1] == 0 && stackk[line - 3] == 0){
                    //    throw TypeMisMatch(linee);
                    //}
                    //if(stackk[line - 1] != 0 || stackk[line - 3] != 0){
                    StackFrame::fneq();
                    //}
                }
                 else if (s2.compare("ilt") == 0){
                     
                    if (line == 2 || line == 0) throw StackEmpty(linee); 
                    if(stackk[line - 1] != 0 || stackk[line - 3] != 0){
                        throw TypeMisMatch(linee);
                    }
                    if(stackk[line - 1] == 0 && stackk[line - 3] == 0){
                        StackFrame::ilt();
                    }
                }
                 else if (s2.compare("flt") == 0){
                     
                    if (line == 2 || line == 0) throw StackEmpty(linee);
                    //if(stackk[line - 1] == 0 && stackk[line - 3] == 0){
                    //    throw TypeMisMatch(linee);
                    //}
                    //if(stackk[line - 1] != 0 || stackk[line - 3] != 0){
                    StackFrame::flt();
                    //}
                }
                 else if (s2.compare("igt") == 0){
                     
                    if (line == 2 || line == 0) throw StackEmpty(linee); 
                    if(stackk[line - 1] != 0 || stackk[line - 3] != 0){
                        throw TypeMisMatch(linee);
                    }
                    if(stackk[line - 1] == 0 && stackk[line - 3] == 0){
                        StackFrame::igt();
                    }
                }
                 else if (s2.compare("fgt") == 0){
                     
                    if (line == 2 || line == 0) throw StackEmpty(linee);
                    //if(stackk[line - 1] == 0 && stackk[line - 3] == 0){
                    //    throw TypeMisMatch(linee);
                    //}
                    //if(stackk[line - 1] != 0 || stackk[line - 3] != 0){
                    StackFrame::fgt();
                    //}
                }
                 else if (s2.compare("ibnot") == 0){
                     
                    if (line == 2 || line == 0) throw StackEmpty(linee); 
                    //if(stackk[line - 1] != 0 || stackk[line - 3] != 0){
                    //    throw TypeMisMatch(linee);
                    //}
                    //if(stackk[line - 1] == 0 && stackk[line - 3] == 0){
                    StackFrame::ibnot();
                    //}
                }
                else if (s2.compare("i2f") == 0){
                    if(line == 0) throw StackEmpty(linee);
                    if(stackk[line - 1] != 0) throw TypeMisMatch(linee);
                    else StackFrame::i2f();
                }
                else if (s2.compare("f2i") == 0){
                    if(line == 0) throw StackEmpty(linee);
                    if(stackk[line - 1] == 0) throw TypeMisMatch(linee);
                    else StackFrame::f2i();
                }
                else if (s2.compare("top") == 0){
                   // cout << "line: " << line << endl;
                    if(line == 0) throw StackEmpty(linee);
                    else StackFrame::top();
                }
            }
        }
        file.close();
    }
    else{
        //std::cout << "cant read" << endl;
    }
}
int StackFrame::iconst(string s){
    int a = stoi(s);
    return a;
}
float StackFrame::fconst(string s){
    float a = stof(s);
    return a;
}
void StackFrame::top(){
    // if(line == 1) cout << stack[0] << endl;
    // else 
    cout << stackk[line - 2] << endl;
}
void StackFrame::iadd(){
    
    int lastEle = stackk[line - 2];
    int seLastEle = stackk[line - 4];

    int sum = lastEle + seLastEle;
    line = line - 4;
    stackk[line] = sum;

    line++;
    stackk[line] = 0;
    line++;
}
void StackFrame::fadd(){
    float lastEle = stackk[line - 2];
    float seLastEle = stackk[line - 4];
    float sum = lastEle + seLastEle;
    line = line - 4;
    stackk[line] = sum;
    line++;
    stackk[line] = 1;
    line++; 
}
void StackFrame::isub(){
    
    int lastEle = stackk[line - 2];
    int seLastEle = stackk[line - 4];
    
    int sub = seLastEle - lastEle;
    line = line - 4;
    stackk[line] = sub;

    line++;
    stackk[line] = 0;
    line++;
}
void StackFrame::fsub(){
    
    float lastEle = stackk[line - 2];
    float seLastEle = stackk[line - 4];
    
    float sub = seLastEle - lastEle;
    line = line - 4;
    stackk[line] = sub;

    line++;
    stackk[line] = 1;
    line++;

}
void StackFrame::imul(){
    
    int lastEle = stackk[line - 2];
    int seLastEle = stackk[line - 4];
    
    int mul = seLastEle * lastEle;
    line = line - 4;
    stackk[line] = mul;

    line++;
    stackk[line] = 0;
    line++;
}
void StackFrame::fmul(){
    
    float lastEle = stackk[line - 2];
    float seLastEle = stackk[line - 4];
    
    float mul = seLastEle * lastEle;
    line = line - 4;
    stackk[line] = mul;
    line++;
    stackk[line] = 1;
    line++;

    
}
void StackFrame::idiv(){
    
    int lastEle = stackk[line - 2];
    int seLastEle = stackk[line - 4];
    
    int mul = seLastEle / lastEle;
    line = line - 4;
    stackk[line] = mul;

    line++;
    stackk[line] = 0;
    line++;
}
void StackFrame::fdiv(){
    
    float lastEle = stackk[line - 2];
    float seLastEle = stackk[line - 4];
    
    float mul = seLastEle / lastEle;
    line = line - 4;
    stackk[line] = mul;

    line++;
    stackk[line] = 1;
    line++;
}
int StackFrame::iidiv(){
    
    int lastEle = stackk[line - 2];
    int seLastEle = stackk[line - 4];
    
    int mul = seLastEle / lastEle;
    return mul;
}
void StackFrame::irem(){
    
    int lastEle = stackk[line - 2];
    int seLastEle = stackk[line - 4];
    
    int rem = seLastEle - (StackFrame::iidiv()) * lastEle;
    line = line - 4;
    stackk[line] = rem;

    line++;
    stackk[line] = 0;
    line++;
}
void StackFrame::ineg(){
    int lastEle = -stackk[line - 2];
    int seLastEle = -stackk[line - 4];
    
    stackk[line-2] = lastEle;
    stackk[line-4] = seLastEle;

}
void StackFrame::fneg(){
    float lastEle = -stackk[line - 2];
    float seLastEle = -stackk[line - 4];
    
    stackk[line-2] = lastEle;
    stackk[line-4] = seLastEle;
}
void StackFrame::iand(){
    int lastEle = stackk[line - 2];
    int seLastEle = stackk[line - 4];

    int andd = seLastEle&lastEle;
    line = line - 4;
    stackk[line] = andd;

    line++;
    stackk[line] = 0;
    line++;
}
void StackFrame::ior(){
    int lastEle = stackk[line - 2];
    int seLastEle = stackk[line - 4];

    int orr = seLastEle|lastEle;
    line = line - 4;
    stackk[line] = orr;

    line++;
    stackk[line] = 0;
    line++;
}
void StackFrame::ieq(){
    int lastEle = stackk[line - 2];
    int seLastEle = stackk[line - 4];

    int returnValue;
    if(seLastEle == lastEle){
        returnValue = 1;
    }
    else returnValue = 0;
    
    line = line - 4;
    stackk[line] = returnValue;

    line++;
    stackk[line] = 0;
    line++;
}
void StackFrame::feq(){
    float lastEle = stackk[line - 2];
    float seLastEle = stackk[line - 4];

    float returnValue;
    if(seLastEle == lastEle){
        returnValue = 1;
    }
    else returnValue = 0;
    
    line = line - 4;
    stackk[line] = returnValue;

    line++;
    stackk[line] = 1;
    line++;
}
void StackFrame::ineq(){
    int lastEle = stackk[line - 2];
    int seLastEle = stackk[line - 4];

    int returnValue;
    if(seLastEle != lastEle){
        returnValue = 1;
    }
    else returnValue = 0;
    
    line = line - 4;
    stackk[line] = returnValue;

    line++;
    stackk[line] = 0;
    line++;
}
void StackFrame::fneq(){
    float lastEle = stackk[line - 2];
    float seLastEle = stackk[line - 4];

    int returnValue;
    if(seLastEle != lastEle){
        returnValue = 1;
    }
    else returnValue = 0;
    
    line = line - 4;
    stackk[line] = returnValue;

    line++;
    stackk[line] = 0;
    line++;
}
void StackFrame::ilt(){
    int lastEle = stackk[line - 2];
    int seLastEle = stackk[line - 4];

    int returnValue;
    if(seLastEle < lastEle){
        returnValue = 1;
    }
    else returnValue = 0;
    
    line = line - 4;
    stackk[line] = returnValue;

    line++;
    stackk[line] = 0;
    line++;
}
void StackFrame::flt(){
    float lastEle = stackk[line - 2];
    float seLastEle = stackk[line - 4];

    int returnValue;
    if(seLastEle < lastEle){
        returnValue = 1;
    }
    else returnValue = 0;
    
    line = line - 4;
    stackk[line] = returnValue;

    line++;
    stackk[line] = 0;
    line++;
}
void StackFrame::igt(){
    int lastEle = stackk[line - 2];
    int seLastEle = stackk[line - 4];

    int returnValue;
    if(seLastEle > lastEle){
        returnValue = 1;
    }
    else returnValue = 0;
    
    line = line - 4;
    stackk[line] = returnValue;

    line++;
    stackk[line] = 0;
    line++;
}
void StackFrame::fgt(){
    float lastEle = stackk[line - 2];
    float seLastEle = stackk[line - 4];

    int returnValue;
    if(seLastEle > lastEle){
        returnValue = 1;
    }
    else returnValue = 0;
    
    line = line - 4;
    stackk[line] = returnValue;

    line++;
    stackk[line] = 0;
    line++;
}
void StackFrame::ibnot(){
    int lastEle = stackk[line - 2];

    int returnValue;
    if(lastEle == 0){
        returnValue = 1;
    }
    else returnValue = 0;
    
    line = line - 2;
    stackk[line] = returnValue;

    line++;
    stackk[line] = 0;
    line++;
}
void StackFrame::istore(string s){
    int idx = stoi(s);
    arr[idx] = stackk[line - 2];
    idx++;
    arr[idx] = 0;
    line = line - 2;
    ind_arr[idx] =stackk[line - 2];
}
void StackFrame::fstore(string s){
    int idx = stoi(s);
    arr[idx] = stackk[line - 2];
    idx++;
    arr[idx] = 1;
    line = line - 2;
    ind_arr[idx] =stackk[line - 2];
}
void StackFrame::iload(string s){
    //cout << "line: " << line << endl;
    stackk[line] = arr[stoi(s)];
    line++;
    stackk[line] = 0;
    line++;
}
void StackFrame::fload(string s){
    stackk[line] = arr[stoi(s)];
    line++;
    stackk[line] = 1;
    line++;
}
void StackFrame::i2f(){
    float a = stackk[line - 2];
    stackk[line - 2] = a;
    stackk[line - 1] = 1; 
}
void StackFrame::f2i(){
    int a = stackk[line - 2];
    stackk[line - 2] = a;
    stackk[line - 1] = 0;
}
    