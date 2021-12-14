#include "gtest/gtest.h"
#include <iostream>
#include "Vec.h"

/// This is a test class

 /**
  *It will be used to test the addition and subtraction operators of the _vec3<double> class.
  *GTest will automatically call the constructor and the SetUp function prior to each test,
  *and TearDown and the destructor afterwards.
 */
class VecTestClass : public ::testing::Test {
protected:
  
    /**
     *Constructor
     */
    VecTestClass() : a{0,1,2}, b{0,0,1} {  }
    
    /**
     *Destructor
     */
    ~VecTestClass() override { /* nothing to do */  }
  
    /**
     * Performs addition/subtraction of double3 objects,
     * and compares with the direct addition/subtraction of double3 elements.
     */
    void SetUp() override {
     
        // test addition
        double3 c = a+b;
        add_matches = true;  // set default
        
        for (int i=0;i<3;i++)
            if (c[i] != a[i] + b[i])
        add_matches=false;  // invalidate if component doesn't match
      
        // test subtraction
        double3 d = a-b;
        sub_matches = true;  // set default
      
        for (int i=0;i<3;i++)
            if (d[i] != a[i] - b[i])
        sub_matches=false;
    }
    
    /**
     * Optional code to call after each test prior to destructor.
     */
    void TearDown() override {/* optional code to call after each test prior to destructor */}

    double3 a;                             /*!< This is a vec3_ object, as defined in Vec.h, and it uses double as template */
    double3 b;                             /*!< This is a vec3_ object, as defined in Vec.h, and it uses double as template */
    bool sub_matches = false;    /*!< Does the subtraction result match our expectation? */
    bool add_matches = false;    /*!< Does the addition result match our expectation? */
};

/// Tests the dot() function of the _vec3 class
TEST(VecTest, VecDot) {
      
    double3 a{0,1,2};
    double3 b{0,0,1};
    
    EXPECT_EQ(dot(a,b), 2);
}

/// Uses the VecTestClass class to test the + operator of the _vec3 class
/// @param[in] VectTestClass Class for testing the _vec3 class
TEST_F(VecTestClass, VecAdd) { // makes a VecTestClass, checks value of add_matches
    EXPECT_EQ(add_matches, true);
}

/// Uses the VecTestClass class to test the - operator of the _vec3 class
/// @param[in] VectTestClass Class for testing the _vec3 class
TEST_F(VecTestClass, VecSub) {
  EXPECT_EQ(sub_matches, true);
}

/// Runs several unit tests through GTest
/// @param[in] argc Argument count - number of inputs to command line at runtime
/// @param[in] argv Argument vector - an array of character pointers listing all command line arguments
/// @return A call to run all GTest tests
int main(int argc, char **argv) {
  
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
