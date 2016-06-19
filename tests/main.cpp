#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

#include <glm/vec3.hpp>
#include <memory>       // shared_ptr
#include <iostream>

#include "shape.hpp"
#include "box.hpp"
#include "sphere.hpp"
#include "color.hpp"

// Aufgabe 5.6
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>
#include "ray.hpp"

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

        // testing getMinimum and getMaximum
        vec3 v1{0,0,0};
        vec3 v2{2,2,2};
        sptr<Box> box3 = std::make_shared<Box>(Box{v1,v2});
        REQUIRE(box3->getMinimum() == v1);
        REQUIRE(box3->getMaximum() == v2);

        // testing setMinimum and setMaximum
        box3->setMaximum(vec3{2,1,2});
        box3->setMinimum(vec3{2,1,2});
        REQUIRE(box3->getMaximum() == box3->getMinimum());
    }

    SECTION("Sphere")
    {
        sptr<Shape> sphere1 = std::make_shared<Sphere>(Sphere{0,0,0,5});
        REQUIRE(sphere1->area() == Approx(314.159));
        REQUIRE(sphere1->volume() == Approx(523.599));

        sptr<Shape> sphere2 = std::make_shared<Sphere>(Sphere{vec3{0,0,0},10});
        REQUIRE(sphere2->area() == Approx(1256.637));
        REQUIRE(sphere2->volume() == Approx(4188.79));

        // testing getRadius and getCenter
        vec3 v1{0,1,0};
        sptr<Sphere> sphere3 = std::make_shared<Sphere>(Sphere{v1,4});
        REQUIRE(sphere3->getRadius() == 4);
        REQUIRE(sphere3->getCenter() == v1);

        // testing setRadius and setCenter
        vec3 v2{8,4,3};
        sphere3->setRadius(8);
        sphere3->setCenter(v2);
        REQUIRE(sphere3->getRadius() == 8);
        REQUIRE(sphere3->getCenter() == v2);
    }
}

TEST_CASE("Aufgabe 5.3 - name_ and color_ for Sphere", "[protected attributes]")
{
    Box b1{"Coole Box", vec3{0,0,0}, vec3{2,2,2}, Color{1,0,1}};
    REQUIRE(b1.getName() == "Coole Box");
    REQUIRE(b1.getColor().r == 1);
    REQUIRE(b1.getColor().g == 0);
    REQUIRE(b1.getColor().b == 1);

    Sphere sp1{"Mega Sphere", vec3{0,0,0}, 12, Color{0,1,0}};
    REQUIRE(sp1.getName() == "Mega Sphere");
    REQUIRE(sp1.getColor().r == 0);
    REQUIRE(sp1.getColor().g == 1);
    REQUIRE(sp1.getColor().b == 0);
}

TEST_CASE("Aufgabe 5.4 and 5.5 - print method", "[functions]")
{
    std::cout << "" << std::endl;
    Box box{"The test box", vec3{0,0,0}, vec3{2,2,2}, Color{0,1,0}};
    std::cout << box << std::endl;

    Sphere sphere{"A badass sphere", vec3{2,5,3}, 5, Color{1,0,0}};
    std::cout << sphere << std::endl;
}

TEST_CASE("Aufgabe 5.6 - intersectRaySphere", "[intersect]")
{
    SECTION("basic test")
    {
        // Ray
        glm::vec3 ray_origin{0.0,0.0,0.0};
        // ray direction has to be normalized with
        // v = glm::normalize(some_vector)
        glm::vec3 ray_direction{0.0,0.0,1.0};

        // Sphere
        glm::vec3 sphere_center{0.0,0.0,5.0};
        float sphere_radius{1.0};

        float distance{0.0};
        auto result = glm::intersectRaySphere(
            ray_origin, ray_direction,
            sphere_center, sphere_radius * sphere_radius,
            distance);

        REQUIRE(distance == Approx(4.0f));
    }

    SECTION("intersect method test")
    {
        Sphere sphere{vec3{0.0,0.0,5.0}, 1.0};
        Ray ray{vec3{0.0,0.0,0.0},vec3{0.0,0.0,1.0}};
        float distance{0.0};
        auto result = sphere.intersect(ray, distance);

        REQUIRE(distance == Approx(4.0f));

        Sphere sphere2{vec3{0.0,3.0,3.0}, 2.0};
        Ray ray2{vec3{0.0,0.0,0.0},vec3{0.0,3.0,3.0}};
        float distance2{0.0};
        auto result2 = sphere2.intersect(ray2, distance2);

        REQUIRE(distance2 == Approx(2.24264f));
    }
}

TEST_CASE("Aufgabe 5.8 - virtual destructor for class shape", "[virtualdtor]")
{
    std::cout << "\n\n----------------------------------------------\n"
              << "--- 5.8 - constructor and destructor tests ---\n"
              << "----------------------------------------------\n" << std::endl;

    Color red(255,0,0);
    vec3 position(0.0,0.0,0.0);

    std::cout << "\n-------------- creating objects --------------\n" << std::endl;

    Sphere* s1 = new Sphere{"sphere0", position, 1.2f, red};
    Shape* s2 = new Sphere{"sphere1", position, 1.2f, red};

    std::cout << "\n-------------- printing objects --------------\n" << std::endl;

    s1->print(std::cout);
    s2->print(std::cout);

    std::cout << "\n-------------- deleting objects --------------\n" << std::endl;

    delete s1;
    delete s2;

    std::cout << "\n----------------------------------------------\n\n" << std::endl;
}

int main(int argc, char *argv[])
{
    return Catch::Session().run(argc, argv);
}
