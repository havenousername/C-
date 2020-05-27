//
//  main.cpp
//  overloading
//
//  Created by Andrei Cristea on 2020. 04. 28..
//  Copyright © 2020. Andrei Cristea. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

struct vec{
  float x, y;
  
  vec(float x,float y)
    : x(x), y(y) {}
  vec Add(const vec& other) const{
    return vec(x + other.x, y + other.y);
  };
  vec Multiply(const vec& other) const{
    return vec(x * other.x, y * other.y);
  };
  vec operator+(const vec& other) const{
    return Add(other);
  };
  vec operator*(const vec& other) const{
    return Multiply(other);
  };
  
  bool operator==(const vec& other) const{
    return x == other.x && y == other.y;
  };
  
  bool operator!=(const vec& other) const{
    return !(*this == other);
  };
};

std::ostream& operator<<(std::ostream& stream, const vec& other){
  stream << other.x << ", " << other.y;
  return stream;
};

int main(int argc, const char * argv[]) {
  
  vec position(4.0f, 2.3f);
  vec speed(0.5f, 1.5f);
  vec powerup(1.1f, 1.1f);
  
  vec res1 = position.Add(speed.Multiply(powerup));
  vec res = position + speed * powerup;
  if (res == res1) {
      std::cout << res << std::endl;
  }
  
  return 0;
}
