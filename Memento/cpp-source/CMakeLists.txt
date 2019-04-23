project(Memento)

set(SOURCES main.cpp Memento.cpp Memento.h PasswordMemento.cpp PasswordMemento.h Originator.cpp Originator.h Caretaker.cpp Caretaker.h)
add_executable(Memento ${SOURCES} main.cpp)