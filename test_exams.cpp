#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../third_party/doctest.h"
#include "timetable.h"
#include "exams.h"

TEST_CASE("exam scheduling rejected on class clash") {
    std::vector<TimetableEntry> timetable = {
        {"CS101", "Room-1", "Dr. Ali", 9, 10}
    };
    TimetableEntry exam{"CS101-Final", "Room-1", "-", 9, 11};

    auto result = schedule_exam(exam, timetable);

    CHECK(result.success == false);
}

TEST_CASE("exam scheduling accepted when no clash") {
    std::vector<TimetableEntry> timetable = {
        {"CS101", "Room-1", "Dr. Ali", 9, 10}
    };
    TimetableEntry exam{"CS101-Final", "Room-2", "-", 9, 11};

    auto result = schedule_exam(exam, timetable);

    CHECK(result.success == true);
}

TEST_CASE("submit_result rejects unenrolled student") {
    std::vector<std::string> enrolled = {"S001", "S002"};
    auto result = submit_result("S999", 85, enrolled);

    CHECK(result.success == false);
    CHECK(result.reason == "Student not enrolled");
}

TEST_CASE("submit_result rejects out-of-range mark") {
    std::vector<std::string> enrolled = {"S001"};
    auto result = submit_result("S001", 150, enrolled);

    CHECK(result.success == false);
    CHECK(result.reason == "Invalid mark");
}

TEST_CASE("submit_result accepts valid mark") {
    std::vector<std::string> enrolled = {"S001"};
    auto result = submit_result("S001", 78, enrolled);

    CHECK(result.success == true);
}

// --- Verifies the refactor in exams.h preserved correct behavior ---
TEST_CASE("is_valid_mark behaves correctly after refactor") {
    CHECK(is_valid_mark(50) == true);
    CHECK(is_valid_mark(-5) == false);
    CHECK(is_valid_mark(101) == false);
}
