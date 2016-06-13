#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

#define M_PI 3.14159265358979323846 // pi

#include <memory>       // shared_ptr
#include "shape.hpp"
#include "box.hpp"
#include "sphere.hpp"
#include <glm/vec3.hpp>
#include <iostream>

template<typename T> using sptr = std::shared_ptr<T>;
typedef glm::vec3 vec3;

TEST_CASE("Aufgabe 5.2 - sphere and box", "[sphereTest] [boxTest]")
{
    SECTION("Box")
    {
        sptr<Shape> box1 = std::make_shared<Box>(Box{0,0,0,2,2,2});
        REQUIRE(box1->area() == 24);
        REQUIRE(box1->volume() == 8);

        sptr<Shape> box2 = std::make_shared<Box>(Box{vec3{0.5,0.5,0.5},vec3{1.0,3.0,4}});

        REQUIRE(box2->area() == Approx(23.5f));
        REQUIRE(box2->volume() == Approx(4.375f));
    }

    SECTION("Sphere")
    {
        sptr<Shape> sphere1 = std::make_shared<Sphere>(Sphere{0,0,0,5});
        REQUIRE(sphere1->area() == Approx(314.159));
        REQUIRE(sphere1->volume() == Approx(523.599));

        sptr<Shape> sphere2 = std::make_shared<Sphere>(Sphere{vec3{0,0,0},10});
        REQUIRE(sphere2->area() == Approx(1256.637));
        REQUIRE(sphere2->volume() == Approx(4188.79));
    }
}

int main(int argc, char *argv[])
{
    return Catch::Session().run(argc, argv);
}
