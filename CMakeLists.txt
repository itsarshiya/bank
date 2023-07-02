cmake_minimum_required(VERSION 3.15)
project(bank)

set(CMAKE_CXX_STANDARD 14)

# include_directories(include/json.hpp)
find_package(nlohmann_json 3.2.0 REQUIRED)

set(SOURCES
    bank.cpp
    BankAccounts/BankAccount.cpp
    BankAccounts/Savings/Savings.cpp
    BankAccounts/Checking/Checking.cpp
    Person/Person.cpp
    cli/cli.cpp
    cli/ie/Export.cpp
)

set(HEADERS
    BankAccounts/BankAccount.h
    BankAccounts/Savings/Savings.h
    BankAccounts/Checking/Checking.h
    Person/Person.h
    cli/cli.h
    cli/ie/Export.h
)

add_executable(bank ${SOURCES} ${HEADERS})

target_link_libraries(bank PRIVATE nlohmann_json::nlohmann_json)