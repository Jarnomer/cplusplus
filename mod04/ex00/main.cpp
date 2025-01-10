#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void) {
  std::cout << "\nTesting constructors...\n\n";
  const Animal *meta = new Animal();
  const Animal *dog = new Dog();
  const Animal *cat = new Cat();

  std::cout << "\nTesting methods...\n\n";
  std::cout << "getType: " << meta->getType() << std::endl;
  std::cout << "getType: " << dog->getType() << std::endl;
  std::cout << "getType: " << cat->getType() << std::endl;

  std::cout << "\n";
  meta->makeSound();
  cat->makeSound();
  dog->makeSound();

  std::cout << "\nDeconstructors...\n\n";
  delete meta;
  delete dog;
  delete cat;

  std::cout << "\nTesting wrong constructors...\n\n";
  const WrongAnimal *wmeta = new WrongAnimal();
  const WrongAnimal *wcat = new WrongCat();

  std::cout << "\nTesting wrong methods...\n\n";
  std::cout << "getType: " << wmeta->getType() << std::endl;
  std::cout << "getType: " << wcat->getType() << std::endl;

  std::cout << "\n";
  wcat->makeSound();
  wmeta->makeSound();

  std::cout << "\nDeconstructors...\n\n";
  delete wmeta;
  delete wcat;
  return 0;
}
