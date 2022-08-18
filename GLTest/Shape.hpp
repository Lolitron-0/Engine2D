#pragma once
#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <vector>
#include <iostream>

class Shape 
{
				public:
								Shape(int pointCount)
												:mGlVertices(pointCount*2, .0f)
								{}
								virtual void draw() = 0;
				protected:
								std::vector<float> mGlVertices;	
};

#endif
