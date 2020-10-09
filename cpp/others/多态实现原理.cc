#include <iostream>

using namespace std;

class Animals {
public:
  virtual void speak() { cout << "Animals are speaking..." << endl; }
  virtual void eat() { cout << "Animals are eating..." << endl; }
  virtual void play() { cout << "Animals are playing..." << endl; }
  // void speak() { cout << "Animals is speaking..." << endl; }
};

class Cat : public Animals {
public:
  void speak() { cout << "Cat is speaking..." << endl; }
  void eat() { cout << "Cat is eating..." << endl; }
  void play() { cout << "Cat are playing..." << endl; }
};

void doSpeak(Animals &animal) { animal.speak(); }

void test01() {
  // Cat cat;
  // doSpeak(cat);

  // Animals animal;
  // doSpeak(animal);

  Animals *animal = new Cat;
  ((void (*)())(*(int *)*(int *)animal))();
  // animal->speak();

  // animal->Animals::speak();

  ((void (*)())(*((int *)*(int *)animal + 2)))();
  ((void (*)())(*((int *)*(int *)animal + 4)))();
}

int main() {
  test01();
  // cout << sizeof(Animals) << endl;
  return 0;
}


// cl /d1 reportSingleClassLayoutAnimals c.cc
// cl /d1 reportSingleClassLayoutCat c.cc