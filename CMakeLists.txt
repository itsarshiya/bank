cmake_minimum_required(VERSION 3.15)
project(bank)

set(CMAKE_CXX_STANDARD 14)

find_package(nlohmann_json 3.2.0 REQUIRED)
find_package(GTest REQUIRED)

include_directories(include ${GTEST_INCLUDE_DIRS})

set(SOURCES
    bank.cpp
    BankAccounts/BankAccount.cpp
    BankAccounts/Savings/Savings.cpp
    BankAccounts/Checking/Checking.cpp
    Person/Person.cpp
    cli/cli.cpp
    cli/ie/Export.cpp
    cli/ie/Import.cpp
)

set(HEADERS
    BankAccounts/BankAccount.h
    BankAccounts/Savings/Savings.h
    BankAccounts/Checking/Checking.h
    Person/Person.h
    cli/cli.h
    cli/ie/Export.h
    cli/ie/Import.h
)

add_executable(bank ${SOURCES} ${HEADERS})

target_link_libraries(bank PRIVATE nlohmann_json::nlohmann_json)

set(TEST_SOURCES
    tests/Tests.cpp
    BankAccounts/BankAccount.cpp
    BankAccounts/Savings/Savings.cpp
    BankAccounts/Checking/Checking.cpp
    Person/Person.cpp
    cli/ie/Export.cpp
    cli/ie/Import.cpp
)

add_executable(tests ${TEST_SOURCES})
target_link_libraries(tests PRIVATE GTest::GTest GTest::Main)
target_link_libraries(tests PRIVATE nlohmann_json::nlohmann_json)