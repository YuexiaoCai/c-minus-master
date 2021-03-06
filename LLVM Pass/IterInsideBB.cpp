#include "llvm/IR/Function.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

namespace {
  
  struct IterInsideBB : public FunctionPass {
    static char ID; 
    IterInsideBB() : FunctionPass(ID) {}

    bool runOnFunction(Function &F) override {
    	errs() << "Function name: ";
    	errs() << F.getName() << '\n';
    	for(Function::iterator bb = F.begin(), e = F.end(); bb!=e; bb++)
    	{
    		errs()<<"BasicBlock name = "<< bb->getName() <<"\n";
    		errs()<<"BasicBlock size = "<< bb->size() << "\n\n";

    		for(BasicBlock::iterator i = bb->begin(), i2 = bb->end(); i!=i2; i++)
    		{
    			outs()<<"    "<< *i <<"\n";
    		}
    	}
    	return false;
    }
  };
}

char IterInsideBB::ID = 0;
static RegisterPass<IterInsideBB> X("IterInsideBB", "Iterate inside basicblocks inside a Function");