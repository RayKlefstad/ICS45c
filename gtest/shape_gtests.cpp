#include <gtest/gtest.h>

#include <sstream>

#include "circle.hpp"
#include "rectangle.hpp"
#include "shape.hpp"
#include "square.hpp"
#include "triangle.hpp"

TEST(CircleTests, Area) {
    EXPECT_NEAR(Circle({1, 2}, "", 3).area(), 28.27, 0.01);
}

TEST(CircleTests, Draw) {
    Circle c{{5, 10}, "circle", 3};

    std::stringstream out;
    c.draw(out);

    EXPECT_STREQ(out.str().c_str(),
                 "   *   \n"
                 " ***** \n"
                 " ***** \n"
                 "   *   \n");
}

TEST(CircleTests, Clone) {
    Circle c{{3, 2}, "foo", 10};

    Circle* clone = c.clone();
    delete clone;
}

TEST(CircleTests, Print) {
    Circle c{{3, 2}, "foo", 10};

    std::stringstream out;
    c.print(out);

    EXPECT_STREQ(out.str().c_str(), "foo(3, 2)\n");
}
