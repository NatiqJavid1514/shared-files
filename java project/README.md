# Student Course Registration System (Java, console)

Compile:  javac *.java
Run:      java Main
Data is stored in ./data (students.csv, courses.csv, registrations.csv), loaded at start, auto-saved after every change.

Mandatory concepts -> where used
- Abstract class: Person (abstract getRole())
- Inheritance + overriding + runtime polymorphism: Student extends Person; toString/getRole overridden; FileManager calls Persistable.toCsv() on mixed objects
- Interface: Persistable (implemented by Student, Course, Registration)
- Encapsulation/constructors: private fields + getters, constructors in every class
- Collections: LinkedHashMap (students, courses), ArrayList (registrations, completed/registered codes)
- User-defined exception: RegistrationException
- File handling: FileManager (BufferedReader/PrintWriter, try-with-resources)

Menu: 1-8 as per spec, plus 9 Drop Course, 10 Mark Course Completed (needed to satisfy prerequisites), 11 Save & Exit.
