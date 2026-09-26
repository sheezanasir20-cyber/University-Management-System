// TDD demonstration for US-10 (Automatic profile update).
// Written before receive_exam_result() existed; initial run failed to
// compile, then passed once the function was implemented.

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../third_party/doctest.h"
#include "student_profile.h"

TEST_CASE("attendance updates profile automatically") {
    StudentProfile profile{"S001"};
    update_attendance(profile, "CS101", 92.5);

    CHECK(profile.attendance["CS101"] == doctest::Approx(92.5));
}

TEST_CASE("exam result updates profile automatically") {
    StudentProfile profile{"S001"};
    receive_exam_result(profile, "CS101", 88);

    CHECK(profile.grades["CS101"] == doctest::Approx(88));
}

TEST_CASE("academic history combines attendance and grades") {
    StudentProfile profile{"S001"};
    update_attendance(profile, "CS101", 92.5);
    receive_exam_result(profile, "CS101", 88);

    auto history = get_academic_history(profile);

    CHECK(history.attendance["CS101"] == doctest::Approx(92.5));
    CHECK(history.grades["CS101"] == doctest::Approx(88));
    CHECK(history.student_id == "S001");
}
