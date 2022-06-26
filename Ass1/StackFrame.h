#ifndef __STACK_FRAME_H__
#define __STACK_FRAME_H__

#include <string>
using namespace std;
/*
StackFrame declaration
*/
class StackFrame {

    int opStackMaxSize; // max size of operand stack
    int localVarArrSize; // size of local variable array

    float stackk[32];
    float arr[256];
    int ind_arr[256];
    int line = 0;
    int linee = 0;

    void disp_arr(float * arr, int size);

public:
    /*
    Constructor of StackFrame
    */
    StackFrame();
    
    /*
    Run the method written in the testcase
    @param filename name of the file
    */
    void run(std::string filename);
    
    void del(string *s, int ind);
    void iadd();
    void fadd();
    void isub();
    void fsub();
    void imul();
    void fmul();
    void idiv();
    int iidiv();
    void fdiv();
    void irem();
    void ineg();
    void fneg();
    void iand();
    void ior();
    void ieq();
    void feq();
    void ineq();
    void fneq();
    void ilt();
    void flt();
    void igt();
    void fgt();
    void ibnot();
    int iconst(string s);
    float fconst(string s);
    void iload(string s);
    void fload(string s);
    void istore(string s);
    void fstore(string s);
    void i2f();
    void f2i();
    void val(int ind);
    void top();
    //void top(string s);


};

#endif // !__STACK_FRAME_H__