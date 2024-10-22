#include <gtest/gtest.h>
#include "BitArray.h"
#include <random>

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(bta, construct_copy) {
    BitArray array1(1000, 2);
    BitArray array2;
    BitArray array3(array1);
    ASSERT_EQ(array1, array3);
    array2.push_back(true);
    ASSERT_EQ(array2.to_string(), "1");
}

TEST(bta, size) {
    BitArray array(1, 0);
    ASSERT_EQ(array.size_array(), 1);
    array = BitArray(100, 0);
    ASSERT_EQ(array.size_array(), 100);
    array = BitArray(1000, 0);
    ASSERT_EQ(array.size_array(), 1000);
}

TEST(bta, clear) {
    BitArray array(10000, 7);
    array.clear();
    ASSERT_EQ(array.count(), 0);

    array.set();
    array.clear();

    ASSERT_EQ(array.count(), 0);
}

TEST(bta, resize) {
    BitArray array(10000, 7);
    array.resize(32, false);
    ASSERT_EQ(array.to_string(), "00000000000000000000000000000111");
    ASSERT_EQ(array.size_array(), 32);

    array.resize(34, true);
    ASSERT_EQ(array.to_string(), "0000000000000000000000000000011111");
    ASSERT_EQ(array.size_array(), 34);

    array.resize(33);
    ASSERT_EQ(array.to_string(), "000000000000000000000000000001111");
    ASSERT_EQ(array.size_array(), 33);

    array.resize(34, false);
    ASSERT_EQ(array.to_string(), "0000000000000000000000000000011110");
    ASSERT_EQ(array.size_array(), 34);
}

TEST(bta, swap) {
    BitArray array1(1234, 111);
    BitArray array2(4321, 423);
    BitArray array3(array1);


    ASSERT_NE(array1, array2);
    ASSERT_EQ(array1, array3);


    array2.swap(array3);

    ASSERT_NE(array1, array3);
    ASSERT_EQ(array1, array2);


    array1.swap(array2);

    ASSERT_NE(array1, array3);
    ASSERT_EQ(array1, array2);

}

TEST(bta, set_reset) {
    BitArray array(34, 3);

    array.set(0, true);

    ASSERT_EQ(array.to_string(), "1000000000000000000000000000001100");

    array.set(31, false);

    ASSERT_EQ(array.to_string(), "1000000000000000000000000000001000");

    array.set(33, true);

    ASSERT_EQ(array.to_string(), "1000000000000000000000000000001001");

    array.set();

    ASSERT_EQ(array.to_string(), "1111111111111111111111111111111111");

    array.reset(0);

    ASSERT_EQ(array.to_string(), "0111111111111111111111111111111111");

    array.reset(32);

    ASSERT_EQ(array.to_string(), "0111111111111111111111111111111101");

    array.reset();

    ASSERT_EQ(array.to_string(), "0000000000000000000000000000000000");

}

TEST(bta, any_none) {
    BitArray array(34, 3);


    ASSERT_EQ(array.any(), true);
    ASSERT_EQ(array.none(), false);

    array.set(0, false);

    ASSERT_EQ(array.any(), true);
    ASSERT_EQ(array.none(), false);

    array.set(31, false);

    ASSERT_EQ(array.any(), true);
    ASSERT_EQ(array.none(), false);

    array.set(30, false);

    ASSERT_EQ(array.any(), false);
    ASSERT_EQ(array.none(), true);

    array.set();

    ASSERT_EQ(array.any(), true);
    ASSERT_EQ(array.none(), false);

    array.reset();

    ASSERT_EQ(array.any(), false);
    ASSERT_EQ(array.none(), true);
}

TEST(bta, inverse) {
    BitArray array(63, 123123);

    ASSERT_EQ(array.to_string(), "000000000000000111100000111100110000000000000000000000000000000");

    array = ~array;

    ASSERT_EQ(array.to_string(), "111111111111111000011111000011001111111111111111111111111111111");
}

TEST(bta, count) {

    BitArray array(63, 123123);

    ASSERT_EQ(array.count(), 10);

    array.reset();

    ASSERT_EQ(array.count(), 0);


    BitArray array2(32, 1);

    ASSERT_EQ(array2.count(), 1);
}


TEST(bta, empty) {
    BitArray array(0, 0);

    ASSERT_EQ(array.empty(), true);

    array.resize(1, true);

    ASSERT_EQ(array.empty(), false);

}

TEST(bta, push_back) {
    BitArray array(0, 0);

    ASSERT_EQ(array.count(), 0);

    array.push_back(true);

    ASSERT_EQ(array.to_string(), "1");

    array.push_back(false);

    ASSERT_EQ(array.to_string(), "10");

}

TEST(bta, operator_compare_pos) {
    BitArray array1(1000, 0);
    BitArray array2(1000, 1);
    BitArray array3(50, 1);
    BitArray array4(100, 1);
    BitArray array5(1000, 1);

    ASSERT_EQ(array1==array2, false);
    ASSERT_EQ(array3==array4, false);
    ASSERT_EQ(array2==array3, false);
    ASSERT_EQ(array2==array5, true);


    bool is = array2[0];

    ASSERT_EQ(is, false);

    is = array2[31];

    ASSERT_EQ(is, true);

    EXPECT_THROW(is = array2[100000], std::out_of_range);

}

TEST(bta, operators_bits) {
    BitArray array1(33, 123123);
    BitArray array2(33, 122122);

    //000000000000000111100000111100110
    //000000000000000111011101000010100

    //000000000000000111000000000000100 &
    //000000000000000111111101111110110 |
    //000000000000000000111101111110010 ^

    BitArray array3 = array1&array2;
    BitArray array4 = array1|array2;
    BitArray array5 = array1^array2;

    ASSERT_EQ(array3.to_string(), "000000000000000111000000000000100");
    ASSERT_EQ(array4.to_string(), "000000000000000111111101111110110");
    ASSERT_EQ(array5.to_string(), "000000000000000000111101111110010");


    BitArray array6(34, 123123);
    BitArray array7(33, 122122);


    EXPECT_THROW(array3 = array6&array7, std::invalid_argument);
    EXPECT_THROW(array3 = array6|array7, std::invalid_argument);
    EXPECT_THROW(array3 = array6^array7, std::invalid_argument);

}


TEST(bta, shifts) {
    BitArray array1(63, 123123);

    //000100000000000111100000111100110000000000000000000000000000100

    //001000000000001111000001111001100000000000000000000000000001000 << 1
    //000011110000011110011000000000000000000000000000010000000000000 << 10
    //000000000100000000000000000000000000000000000000000000000000000 << 50

    //000010000000000011110000011110011000000000000000000000000000010 >> 1
    //000000000000010000000000011110000011110011000000000000000000000 >> 10
    //000000000000000000000000000000000000000000000000000001000000000 >> 50

    array1.set(60, true);
    array1.set(3, true);

    BitArray array2 = array1 << 1;
    BitArray array3 = array1 << 10;
    BitArray array4 = array1 << 50;

    BitArray array5 = array1 >> 1;
    BitArray array6 = array1 >> 10;
    BitArray array7 = array1 >> 50;

    ASSERT_EQ(array2.to_string(), "001000000000001111000001111001100000000000000000000000000001000");
    ASSERT_EQ(array3.to_string(), "000001111000001111001100000000000000000000000000001000000000000");
    ASSERT_EQ(array4.to_string(), "000000000010000000000000000000000000000000000000000000000000000");

    ASSERT_EQ(array5.to_string(), "000010000000000011110000011110011000000000000000000000000000010");
    ASSERT_EQ(array6.to_string(), "000000000000010000000000011110000011110011000000000000000000000");
    ASSERT_EQ(array7.to_string(), "000000000000000000000000000000000000000000000000000001000000000");


    BitArray array8 = array1 << 500;
    BitArray array9 = array1 >> 500;


    ASSERT_EQ(array8.count(), 0);
    ASSERT_EQ(array9.count(), 0);

    BitArray array10 = array1 << 32;
    BitArray array11 = array1 >> 32;


    //00010000000000011110000011110011000000000000000000000000000100

    //00000000000000000000000000001000000000000000000000000000000000
    //00000000000000000000000000000000001000000000001111000001111001

    ASSERT_EQ(array10.to_string(), "000000000000000000000000000010000000000000000000000000000000000");
    ASSERT_EQ(array11.to_string(), "000000000000000000000000000000000001000000000001111000001111001");


}