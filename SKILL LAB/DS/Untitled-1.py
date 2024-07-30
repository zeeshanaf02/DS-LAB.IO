class Student:
    students = {}
    i = 0

    def __init__(self, name, reg, m1, m2, m3):
        self.n = name
        self.r = reg
        self.m1 = m1
        self.m2 = m2
        self.m3 = m3
        self.total = self.m1 + self.m2 + self.m3
        self.avg = self.total / 3
        Student.students[reg] = self

    def student_data(self):
        Student.i += 1
        self.n = input(f"Enter the name of student {Student.i}: ")
        self.r = int(input("Enter the register number: "))
        self.m1, self.m2, self.m3 = map(int, input("Enter the marks of three subjects (separated by spaces): ").split())
        Student(self.n, self.r, self.m1, self.m2, self.m3)

    @staticmethod
    def rankofall():
        Student.rank_list = sorted(Student.students.values(), key=lambda x: x.avg, reverse=True)
        for i, student in enumerate(Student.rank_list, start=1):
            print(f"Rank {i}: {student.n} - Average Marks: {student.avg:.2f}")

    @staticmethod
    def rank(reg):
        for i, student in enumerate(Student.rank_list, start=1):
            if student.r == reg:
                print(f"Rank of {student.n} is: {i}")
                return
        print(f"Student with register number {reg} not found.")

    @staticmethod
    def compare(reg1, reg2):
        student1 = Student.students.get(reg1)
        student2 = Student.students.get(reg2)
        if student1 and student2:
            if student1.avg > student2.avg:
                print(f"{student1.n} has higher marks than {student2.n}")
            elif student1.avg < student2.avg:
                print(f"{student2.n} has higher marks than {student1.n}")
            else:
                print(f"{student1.n} and {student2.n} have the same average marks.")
        else:
            print("Invalid register numbers. Please check.")

def main():
    print("Enter the number of students:")
    n = int(input())
    for _ in range(n):
        s1 = Student("", 0, 0, 0, 0)
        s1.student_data()
    Student.rankofall()

    while True:
        print("1. Rank of a student\n2. Compare two students\n3. Exit")
        ch = int(input("Enter your choice: "))
        if ch == 1:
            reg = int(input("Enter the register number of the student: "))
            Student.rank(reg)
        elif ch == 2:
            reg1 = int(input("Enter the register number of student 1: "))
            reg2 = int(input("Enter the register number of student 2: "))
            Student.compare(reg1, reg2)
        elif ch == 3:
            print("Exiting the program.")
            break
        else:
            print("Invalid choice, please try again.")

if __name__ == "__main__":
    main()
