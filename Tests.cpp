#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "vector.h"
#include "functions_test2.h"

TEST_CASE ("main.cpp") 
{
	SECTION("Testing inserts into vector constructor")
	{
		student stud1("Name", "Surname");

		REQUIRE ("Name" == stud1.getName());

		REQUIRE ("Surname" == stud1.getSurname());
	}
	SECTION("Testing copy constructor")
	{
		student stud1("Name", "Surname");
		student stud2("", "");

		stud2 = stud1;

		REQUIRE(stud1.getName() == stud2.getName());

		REQUIRE(stud1.getSurname() == stud2.getSurname());

	}
	SECTION("Testing counting and copy constructor")
	{
		student stud1("Name Surname 9 9 9 9 9 9 9");
		student stud2("", "");
		stud1.setFinal(FinalCounter(stud1));
		stud2 = stud1;

		REQUIRE(stud1.getName() == stud2.getName());

		REQUIRE(stud1.getSurname() == stud2.getSurname());

		REQUIRE(stud1.getFinal() == stud2.getFinal());

		REQUIRE(stud1.getExam() == stud2.getExam()); 

		REQUIRE (stud1.getFinal() == 9);

		REQUIRE (stud1.getExam() == 9);

	}
	SECTION("The sorting is working correctly")
	{
        student stud1("Vardas3 Pavarde3 8 6");
        student stud2("Vardas1 Pavarde1 4 8 9");
        student stud3("Vardas2 Pavarde2 4 4 4 9");

        std::vector<student> s{stud1, stud2, stud3};

        std::sort(s.begin(), s.end(), sortStudents);

        REQUIRE(s.at(0).getName() == "Vardas1");
        REQUIRE(s.at(0).getSurname() == "Pavarde1");

        REQUIRE(s.at(1).getName() == "Vardas2");
        REQUIRE(s.at(1).getSurname() == "Pavarde2");

        REQUIRE(s.at(2).getName() == "Vardas3");
        REQUIRE(s.at(2).getSurname() == "Pavarde3");
    }
}