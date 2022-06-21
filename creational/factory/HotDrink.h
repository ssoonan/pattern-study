#include <iostream>
#include <memory>

using namespace std;

struct HotDrink
{
  virtual void prepare(int volume) = 0;
};

struct Tea : HotDrink
{
  void prepare(int volume) override {
    cout << "티백에 끓인 " << volume << "ml 물을 넣으세요" << endl;
  }
};


struct Coffee : HotDrink
{
  void prepare(int volume) override {
    cout << "원두를 갈고 끓인 " << volume << "ml 물을 넣으세요" << endl;
  }
};

