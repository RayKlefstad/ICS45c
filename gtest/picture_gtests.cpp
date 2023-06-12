#include <gtest/gtest.h>

#include <string>

#include "alloc.hpp"
#include "circle.hpp"
#include "picture.hpp"
#include "rectangle.hpp"
#include "square.hpp"
#include "triangle.hpp"

class PictureTests : public testing::Test {
protected:
    AllocationTracker tracker;

    virtual void TearDown() override {
        if (!testing::Test::HasFailure()) {
            // Only check this when there are no failures because failures themselves produce
            // allocations in gtest.
            EXPECT_EQ(tracker.get_allocations().size(), 0) << "You have a memory leak!";
            EXPECT_EQ(tracker.get_mismatching_deletes(), 0)
                << "You have mismatching delete[]/new or delete/new[]!";
            EXPECT_EQ(tracker.get_double_deletes(), 0) << "You tried to delete a pointer twice!";
        }
    }
};

TEST_F(PictureTests, Constructor) {
    Picture p;
}

TEST_F(PictureTests, TotalArea) {
    Picture p;

    ASSERT_EQ(p.total_area(), 0.0);

    p.add(Rectangle{{0, 0}, "rect1", 3, 5});
    ASSERT_EQ(p.total_area(), 15);
    p.add(Rectangle{{3, 5}, "rect2", 1, 2});
    ASSERT_EQ(p.total_area(), 17);
    p.add(Square{{0, 0}, "square1", 5});
    ASSERT_EQ(p.total_area(), 42);
    p.add(Square{{1, -2}, "square2", 7});
    ASSERT_EQ(p.total_area(), 91);
    p.add(Triangle{{0, 0}, "triangle1", 1, 2});
    ASSERT_EQ(p.total_area(), 92);
    p.add(Triangle{{5, 7}, "triangle2", 5, 1});
    ASSERT_EQ(p.total_area(), 94.5);
    p.add(Circle{{0, 0}, "circle1", 1});
    ASSERT_NEAR(p.total_area(), 97.64, 0.01);
    p.add(Circle{{5, 2}, "circle2", 3});
    ASSERT_NEAR(p.total_area(), 125.92, 0.01);
}

TEST_F(PictureTests, PrintAll) {
    Picture p;
    std::stringstream individual;

    const auto testcase = [&](Shape const& shape) {
        p.add(shape);
        shape.print(individual);

        std::stringstream collective;
        p.print_all(collective);

        ASSERT_EQ(collective.str(), individual.str());
    };

    testcase(Rectangle{{0, 0}, "rect1", 3, 5});
    testcase(Square{{0, 0}, "square1", 5});
    testcase(Triangle{{0, 0}, "triangle1", 1, 2});
    testcase(Circle{{0, 0}, "circle1", 1});
}

TEST_F(PictureTests, DrawAll) {
    Picture p;
    std::stringstream individual;

    const auto testcase = [&](Shape const& shape) {
        p.add(shape);
        shape.draw(individual);

        std::stringstream collective;
        p.draw_all(collective);

        ASSERT_EQ(collective.str(), individual.str());
    };

    testcase(Rectangle{{0, 0}, "rect1", 3, 5});
    testcase(Square{{0, 0}, "square1", 5});
    testcase(Triangle{{0, 0}, "triangle1", 1, 2});
    testcase(Circle{{0, 0}, "circle1", 1});
}

std::string to_string(const Picture& p) {
    std::stringstream out;
    p.print_all(out);
    return out.str();
}

TEST_F(PictureTests, Swap) {
    Picture p1, p2;

    p1.add(Rectangle{{0, 0}, "p1_rect1", 3, 5});
    p1.add(Rectangle{{1, 1}, "p1_rect2", 10, 20});
    p1.add(Circle{{1, 1}, "p1_square1", 1});

    p2.add(Triangle{{0, 1}, "p2_triangle1", 2, 2});
    p2.add(Triangle{{-1, 1}, "p2_triangle2", 1, 3});
    p2.add(Square{{5, 2}, "p2_square2", 4});

    const std::string p1_str = to_string(p1);
    const std::string p2_str = to_string(p2);

    p1.swap(p2);

    EXPECT_EQ(p1_str, to_string(p2));
    EXPECT_EQ(p2_str, to_string(p1));
}


TEST_F(PictureTests, MoveConstructor) {
    Picture p;
    p.add(Rectangle{{0, 0}, "p_rect1", 3, 5});
    p.add(Rectangle{{1, 1}, "p2_rect2", 10, 20});
    p.add(Circle{{1, 1}, "p2_square1", 1});

    std::string p_str = to_string(p);
    Picture p2{std::move(p)};
    EXPECT_EQ(to_string(p2), p_str);
}

TEST_F(PictureTests, MoveAssignment) {
    Picture p;
    p.add(Rectangle{{0, 0}, "p_rect1", 3, 5});
    p.add(Rectangle{{1, 1}, "p2_rect2", 10, 20});
    p.add(Circle{{1, 1}, "p2_square1", 1});
    std::string p_str = to_string(p);

    Picture p2;
    p2 = std::move(p);
    EXPECT_EQ(to_string(p2), p_str);
    p = Picture();
    EXPECT_EQ(to_string(p), "");

    Picture p3;
    p3.add(Triangle{{0, 1}, "p3_triangle1", 2, 2});
    p3.add(Triangle{{-1, 1}, "p3_triangle2", 1, 3});
    p3.add(Square{{5, 2}, "p3_square2", 4});
    std::string p3_str = to_string(p3);
    p2 = std::move(p2);
    p2 = std::move(p3);

    EXPECT_EQ(to_string(p2), p3_str);
}
