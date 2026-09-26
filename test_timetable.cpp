// TDD demonstration for US-02 (Automatic conflict detection).
//
// Q7(b) evidence:
// 1. test_room_conflict_detected was written FIRST, before is_room_conflict()
//    existed -> compiling/running it failed (undefined reference).
// 2. is_room_conflict() was implemented in timetable.h to make it pass.
// 3. Re-running this file now shows a PASS.

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../third_party/doctest.h"
#include "timetable.h"

TEST_CASE("room conflict is detected when same room, overlapping time") {
    std::vector<TimetableEntry> existing = {
        {"CS101", "Room-1", "Dr. Ali", 9, 10}
    };
    TimetableEntry new_entry{"CS102", "Room-1", "Dr. Ahmed", 9, 10};

    CHECK(is_room_conflict(new_entry, existing) == true);
}

TEST_CASE("no room conflict when room is free") {
    std::vector<TimetableEntry> existing = {
        {"CS101", "Room-1", "Dr. Ali", 9, 10}
    };
    TimetableEntry new_entry{"CS102", "Room-2", "Dr. Ahmed", 9, 10};

    CHECK(is_room_conflict(new_entry, existing) == false);
}

TEST_CASE("instructor conflict is detected") {
    std::vector<TimetableEntry> existing = {
        {"CS101", "Room-1", "Dr. Ali", 9, 10}
    };
    TimetableEntry new_entry{"CS103", "Room-2", "Dr. Ali", 9, 10};

    CHECK(is_instructor_conflict(new_entry, existing) == true);
}

TEST_CASE("create_timetable_entry is rejected on conflict") {
    std::vector<TimetableEntry> existing = {
        {"CS101", "Room-1", "Dr. Ali", 9, 10}
    };
    TimetableEntry new_entry{"CS102", "Room-1", "Dr. Ahmed", 9, 10};

    auto result = create_timetable_entry(new_entry, existing);

    CHECK(result.success == false);
    CHECK(result.reason == "Room conflict");
}

TEST_CASE("create_timetable_entry is published when no conflict") {
    std::vector<TimetableEntry> existing = {
        {"CS101", "Room-1", "Dr. Ali", 9, 10}
    };
    TimetableEntry new_entry{"CS102", "Room-2", "Dr. Ahmed", 9, 10};

    auto result = create_timetable_entry(new_entry, existing);

    CHECK(result.success == true);
    CHECK(existing.size() == 2);
}
