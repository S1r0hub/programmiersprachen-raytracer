#ifndef BOX_HPP
#define BOX_HPP

#include <glm/vec3.hpp>
#include "shape.hpp"

class Box : public Shape
{
    typedef glm::vec3 vec3;
    typedef std::string str;

    public:
        Box();

        Box(vec3 const& min, vec3 const& max);

        // with name and color
        Box(str const& name, vec3 const& min, vec3 const& max, Color const& color = Color{0,0,0});

        Box(float min_x, float min_y, float min_z, float max_x, float max_y, float max_z);

        // with name and color
        Box(str const& name, float min_x, float min_y, float min_z, float max_x, float max_y, float max_z, Color const& color = Color{0,0,0});

        // 5.8
        ~Box() { /*std::cout << "dtor Box" << std::endl;*/ }
        
        float area() const override;
        float volume() const override;

        // getter
        vec3 const& getMinimum() const;
        vec3 const& getMaximum() const;

        // setter
        void setMinimum(vec3 const& min);
        void setMaximum(vec3 const& min);

        std::ostream& print(std::ostream& os) const override;

        // 6.3
        bool intersect(Ray const& ray, float& t) const override;

    private:
        vec3 min_;
        vec3 max_;
};

#endif