#include <map>
#include "HotDrinkFactory.h"

// make_drink 함수가 사용자(이 예제에선 main)가 사용하는 코드
unique_ptr<HotDrink> make_drink(const HotDrinkFactory& hf) 
{
  return hf.make();
}

class DrinkFactory // 자바처럼 객체를 즉석에서 전달하기 어려우니 미리 세팅한 클래스
{
  map<string, unique_ptr<HotDrinkFactory>> hot_factories;
public:
  DrinkFactory()
  {
    hot_factories["coffee"] = make_unique<CoffeeFactory>();
    hot_factories["tea"] = make_unique<TeaFactory>();
  }
  unique_ptr<HotDrink> make_drink(const string& name)
  {
    auto drink = hot_factories[name]->make();
    drink->prepare(100);
    return drink;
  }
};


int main()
{
  /*
  TeaFactory tf;
  CoffeeFactory cf;
  auto c = make_drink(cf); // TODO: 이렇게 팩토리 변수 별도로 안 만들고 자바마냥 즉석에서 전달할 순 없나?
  auto t = make_drink(tf);
  c->prepare(100);
  t->prepare(100); */

  // or
  DrinkFactory df;
  auto cc = df.make_drink("coffee"); // 이 방법은 미리 변수화를 한 것임
  auto tt = df.make_drink("tea");

}