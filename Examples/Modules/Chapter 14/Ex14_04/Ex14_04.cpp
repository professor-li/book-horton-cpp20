// Defaulting the default constructor in a derived class (working version)
import <iostream>;
import box;                 // For the Box class
import carton;              // For the Carton class

int main()
{
  // Create three Carton objects
  Carton carton1;                             std::cout << std::endl;
  Carton carton2 {4.0, 5.0, 6.0, "PET"};      std::cout << std::endl;
  Carton carton3 {2.0, "Folding boxboard"};   std::cout << std::endl;

  std::cout << "carton1 volume is " << carton1.volume() << std::endl;
  std::cout << "carton2 volume is " << carton2.volume() << std::endl;
  std::cout << "carton3 volume is " << carton3.volume() << std::endl;
}
