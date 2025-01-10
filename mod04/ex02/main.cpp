#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void) {
  const unsigned int count = 4;
  const Animal *animal[count];
  unsigned int i = 0;
  // Animal a; // to test abstraction

  std::cout << "\nTesting constructors ...\n\n";
  for (i = 0; i < count / 2; i++) {
    std::cout << "Creating Dog at index " << i << "\n";
    animal[i] = new Dog();
    std::cout << "\n";
  }
  for (i = count / 2; i < count; i++) {
    std::cout << "Creating Dog at index " << i << "\n";
    animal[i] = new Cat();
    std::cout << "\n";
  }
  std::cout << "Deconstructors ...\n";
  for (unsigned int j = 0; j < count; j++) {
    std::cout << "\nDeconstructing animal at index " << j << "\n";
    delete animal[j];
  }

  std::cout << "\nTesting brains ...\n\n";
  Dog *dog = new Dog();
  std::cout << "\n";
  Cat *cat = new Cat();
  std::cout << "\n";

  unsigned int index = 5;
  dog->setIdea(index, "pizza");
  std::cout << dog->getType() << "'s idea at index: " << index
            << "   is: " << dog->getIdea(index) << "\n";
  std::cout << dog->getType()
            << "'s idea at index: 101 is: " << dog->getIdea(101);
  std::cout << dog->getType() << "'s idea at index: " << index - 1
            << "   is: " << dog->getIdea(index - 1) << "\n\n";

  index = 42;
  cat->setIdea(index, "beer");
  std::cout << cat->getType() << "'s idea at index: " << index
            << "  is: " << cat->getIdea(index) << "\n";
  std::cout << cat->getType()
            << "'s idea at index: -1  is: " << cat->getIdea(-1);
  std::cout << cat->getType() << "'s idea at index: " << index + 1
            << "  is: " << cat->getIdea(index - 1) << "\n";

  std::cout << "\nTesting dog copy constructor...\n\n";
  {
    index = 5;
    Dog *dublicate = new Dog(*dog);
    std::cout << "\n";
    std::cout << dublicate->getType() << "'s idea at index: " << index
            << " is: " << dublicate->getIdea(index) << "\n";
    std::cout << "\n";
    delete dublicate;
  }

  std::cout << "\nTesting dog copy assigment operator...\n\n";
  {
    index = 5;
    Dog *dublicate = new Dog();
    *dublicate = *dog;
    std::cout << "\n";
    std::cout << dublicate->getType() << "'s idea at index: " << index
            << " is: " << dublicate->getIdea(index) << "\n";
    std::cout << "\n";
    delete dublicate;
  }

  std::cout << "\nTesting cat copy constructor...\n\n";
  {
    index = 42;
    Cat *dublicate = new Cat(*cat);
    std::cout << "\n";
    std::cout << dublicate->getType() << "'s idea at index: " << index
            << " is: " << dublicate->getIdea(index) << "\n";
    std::cout << "\n";
    delete dublicate;
  }

  std::cout << "\nTesting cat copy assigment operator...\n\n";
  {
    index = 42;
    Cat *dublicate = new Cat();
    std::cout << "\n";
    *dublicate = *cat;
    std::cout << "\n";
    std::cout << dublicate->getType() << "'s idea at index: " << index
            << " is: " << dublicate->getIdea(index) << "\n";
    std::cout << "\n";
    delete dublicate;
  }

  std::cout << "\nDeconstructors ...\n\n";
  delete dog;
  std::cout << "\n";
  delete cat;
  return 0;
}
