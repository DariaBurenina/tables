#include "gtest.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    int isOK = RUN_ALL_TESTS();

	system("pause");

	return isOK;
}
