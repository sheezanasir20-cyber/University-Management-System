// Sprint 2 - Student Academic Profile
// Feature: US-07 (auto result transfer), US-09 (history view), US-10 (auto profile update)
#pragma once

#include <string>
#include <map>

struct StudentProfile {
    std::string student_id;
    std::map<std::string, double> attendance;  // course -> percentage
    std::map<std::string, double> grades;      // course -> mark
};

// US-10: automatically update profile when new attendance data arrives from Timetable module
inline void update_attendance(StudentProfile& profile, const std::string& course, double percentage) {
    profile.attendance[course] = percentage;
}

// US-07 + US-10: automatically transfer a submitted exam result into the
// student's profile the moment it's recorded by the Examination module.
inline void receive_exam_result(StudentProfile& profile, const std::string& course, double mark) {
    profile.grades[course] = mark;
}

struct AcademicHistory {
    std::string student_id;
    std::map<std::string, double> attendance;
    std::map<std::string, double> grades;
};

// US-09: consolidated view of a student's attendance and grades in one place
inline AcademicHistory get_academic_history(const StudentProfile& profile) {
    return {profile.student_id, profile.attendance, profile.grades};
}
