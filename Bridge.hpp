#ifndef BRD_HPP
#define BRD_HPP

#include <iostream>
#include <string.h>
using namespace std;

class BridgeInterface {
protected:
  FILE *fp;
  string name_m;
public:
  virtual ~BridgeInterface(){};
  virtual void OpenFile(){};
  virtual void Write(){};
  virtual void CloseFile(){};
};

class Bridge {
protected:
  BridgeInterface *bi;
public:
  Bridge (BridgeInterface * bi){ this->bi = bi; }
  void Execute(){
    bi->OpenFile();
    bi->Write();
    bi->CloseFile();
  };
};

#endif
