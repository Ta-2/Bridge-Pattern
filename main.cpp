#include "Bridge.hpp"
#include <iostream>
#include <string.h>
using namespace std;

class Write_PI : public BridgeInterface {
public:
  Write_PI (string name) {name_m = name; }
  void OpenFile() override { fp = fopen(name_m.c_str(), "w"); }
  void Write() override { fputs("3.14159265359", fp); }
  void CloseFile() override { fclose(fp); }
};

class Write_e : public BridgeInterface {
public:
  Write_e (string name) {name_m = name; }
  void OpenFile() override { fp = fopen(name_m.c_str(), "w"); }
  void Write() override { fputs("2.71828182846", fp); }
  void CloseFile() override { fclose(fp); }
};

class Writer : public Bridge{
public:
  Writer (BridgeInterface *bi) : Bridge(bi) {}
};

class CountWriter : public Bridge {
public:
  CountWriter (BridgeInterface *bi) : Bridge(bi) {}
  void CountWrite (int count){
    bi->OpenFile();
    for(int i = 0; i < count; i++)bi->Write();
    bi->CloseFile();
  }
};

int main (){
  Writer *br1 = new Writer(new Write_PI("PI.txt"));
  Writer *br2 = new Writer(new Write_e("e.txt"));

  br1->Execute();
  br2->Execute();

  CountWriter *br3 = new CountWriter(new Write_PI("count_PI.txt"));
  CountWriter *br4 = new CountWriter(new Write_e("count_e.txt"));

  br3->CountWrite(3);
  br4->CountWrite(5);

  return 0;
}
