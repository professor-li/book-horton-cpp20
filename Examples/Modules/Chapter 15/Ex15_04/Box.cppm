export module boxes:box;

import <iostream>;

export class Box
{
public:
  Box() : Box{ 1.0, 1.0, 1.0 } {}
  Box(double l, double w, double h) : m_length {l}, m_width {w}, m_height {h} {}

  // Function to show the volume of an object
  void showVolume() const
  { std::cout << "Box usable volume is " << volume() << std::endl; }

  // Function to calculate the volume of a Box object
  virtual double volume(int i = 5) const
  { 
    std::cout << "(Box argument = " << i << ") ";
    return m_length * m_width * m_height;
  }

protected:      // Should be private in production-quality code (add getters to access)
  double m_length, m_width, m_height;
};

