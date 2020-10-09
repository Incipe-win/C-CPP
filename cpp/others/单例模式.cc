#include <iostream>

using namespace std;

class ChairMan {
private:
  ChairMan() { cout << "创建国家主席" << endl; }
  static ChairMan *singleMan;
  ChairMan(const ChairMan &cm) {}

public:
  static ChairMan *getInstance() { return singleMan; }
};

ChairMan *ChairMan::singleMan = new ChairMan;

void test01() {
  ChairMan *cm1 = ChairMan::getInstance();
  ChairMan *cm2 = ChairMan::getInstance();
  if (cm1 == cm2) {
    cout << "equal" << endl;
  } else {
    cout << "not equal" << endl;
  }

  // ChairMan *cm3 = new ChairMan(*cm2);
}

int main() {
  cout << "Main调用" << endl;
  test01();
  return 0;
}