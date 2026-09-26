// Sprint 2 - Student Academic Profile (STUB VERSION - commit 5, TDD red)
#pragma once

#include <string>
#include <map>

struct StudentProfile {
    std::string student_id;
    std::map<std::string, double> attendance;
    std::map<std::string, double> grades;
};

inline void update_attendance(StudentProfile& profile, const std::string& course, double percentage) {
    profile.attendance[course] = percentage;
}

// NOT YET IMPLEMENTED
inline void receive_exam_result(StudentProfile& profile, const std::string& course, double mark) {
    // TODO: transfer result into profile.grades
}

struct AcademicHistory {
    std::string student_id;
    std::map<std::string, double> attendance;
    std::map<std::string, double> grades;
};

// NOT YET IMPLEMENTED
inline AcademicHistory get_academic_history(const StudentProfile& profile) {
    return {profile.student_id, {}, {}};   // TODO: return real data
}
