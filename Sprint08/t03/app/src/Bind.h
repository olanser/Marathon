#pragma once


#include <iostream>

namespace SpecializedFunctions {
    
namespace Math {
    
template <typename T>
auto pow2= std::bind([](T a) {return (a * a);}, std::placeholders::_1);

template <typename T>
T add(const T arg1, const T arg2) {
    return arg1 + arg2;
}

auto iDontWontToCalculate = std::bind(SpecializedFunctions::Math::add<int>, 2, 2);
}
  // end namespace Math
  
namespace Output {
    
template <typename T>
void output3Arguments(const T& arg1, const T& arg2, const T& arg3) {
    std::cout << arg1 << " "   << arg2 << " " << arg3 << std::endl;
}

template <typename T>
void outputPrintWords(const T& arg1, const T& arg2, const T& arg3, const T& arg4) {
    std::cout << arg1 << " "   << arg2 << " "<< arg3 << " " << arg4 << std::endl;
}

template <typename T>
auto outputWeird3Arguments = std::bind(SpecializedFunctions::Output::output3Arguments<T>, std::placeholders::_2,std::placeholders::_3,std::placeholders::_1);

auto outputFusRoDah = std::bind(SpecializedFunctions::Output::output3Arguments<std::string>, "Fus", "Ro", "Dah");

auto outputLovelyWords = std::bind(SpecializedFunctions::Output::outputPrintWords<std::string>, "I", "Love", "you", "!");

}  // end namespace Output
}  // end namespace SpecializedFunctions
