#ifndef SHAPE_HPP
#define SHAPE_HPP

class Shape
{
    public:
        float virtual area() = 0;
        float virtual volume() = 0;
};

#endif