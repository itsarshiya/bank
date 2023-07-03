#include <gtest/gtest.h>
#include <fstream>
#include "../cli/ie/Export.h"

// Test case for the exportData() function
TEST(ExportDataTest, ExportToFile) {
    // Create some test data
    std::list<Person*> persons; // Update to list of Person pointers

    Person* person1 = new Person("Arshiya Sharifi", "arshiya", "test"); // Create Person pointers
    Person* person2 = new Person("Micheal Jackson", "jackson", "test");
    Person* person3 = new Person("developer", "admin", "test");

    persons.push_back(person1);
    persons.push_back(person2);
    persons.push_back(person3);

    std::string filePath = "test_data.json";


    // Call the exportData() function
    exportData(persons, filePath);

    // Check if the file has been created
    std::ifstream file(filePath);
    bool fileExists = file.good();
    file.close();

    // Assert that the file has been created
    ASSERT_TRUE(fileExists);

    // Clean up by deleting the test file
    std::remove(filePath.c_str());
}

int main(int argc, char** argv) {
    // Initialize Google Test
    ::testing::InitGoogleTest(&argc, argv);

    // Run all tests
    return RUN_ALL_TESTS();
}