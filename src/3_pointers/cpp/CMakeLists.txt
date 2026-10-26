add_executable(raw_pointer
    ../../2_oop/cpp/person.cpp
    raw_pointer.cpp
 )
 add_executable(unique_pointer
    ../../2_oop/cpp/person.cpp
    unique_pointer.cpp
 )
 add_executable(shared_pointer
    ../../2_oop/cpp/person.cpp
    shared_pointer.cpp
 )
 add_executable(weak_pointer
    ../../2_oop/cpp/person.cpp
    weak_pointer.cpp
 )
 add_executable(person_shared_ptr_cycle
    person_shared_ptr_cycle.cpp
 )
 add_executable(person_weak_ptr
    person_weak_ptr.cpp
 )


target_include_directories(raw_pointer PRIVATE ../../2_oop/cpp)
target_include_directories(unique_pointer PRIVATE ../../2_oop/cpp)
target_include_directories(shared_pointer PRIVATE ../../2_oop/cpp)
target_include_directories(weak_pointer PRIVATE ../../2_oop/cpp)
target_include_directories(person_shared_ptr_cycle PRIVATE ../../2_oop/cpp)
target_include_directories(person_weak_ptr PRIVATE ../../2_oop/cpp)
