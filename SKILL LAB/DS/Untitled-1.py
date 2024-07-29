class Student:
    students={}
    i=0
    def __init__(self,name,reg,m1,m2,m3):
        self.n=name
        self.r=reg
        self.m1=m1
        self.m2=m2
        self.m3=m3
        self.total=self.m1+self.m2+self.m3
        self.avg=self.total/3
        Student.students[reg]=self
    def student_data(self):
        i+=1
        self.n=input("Enter the name of the student{i}:")
        self.r=int(input("Enter the register no:"))
        self.m1,self.m2.self.m3=map(int,input("Enter the marks of three subjects:").split())
        Student(self.n,self.r,self.m1,self.m2,self.m3)
    def rankofall(self,):
        Student.rank_list=sorted(self.avg,reverse=True)
        for i in Student.rank_list:
            print(f"Rank {i}:{self.name}-Average Marks:{self.avg}")
    def rank(self):
        for rank in Student.rank_list:
            print(f"Rank of {self.n} is :{self.rank}")
    def compare(self,other):
        if self.avg>other.avg:
            print(f"{self.n} has higher marks than {other.n}")
        else:
            print(f"{other.n} has higher marks than {self.n}")
def main():
    print("Enter the number of students:")
    n=int(input())
    for i in range(n):
        s1=Student()
        s1.student_data()
    Student.rankofall()
    while True:
        print("1.rank of the student\n2.compare 2 students\n3.Exit\n")
        print("Enter your choice:")
        ch=int(input())
        if ch==1:
            reg=int(input("Enter the register number of the student:"))
            Student.rank(reg)
        elif ch==2:
            reg1=int(input("Enter the register of student 1:"))
            reg2=int(input("Enter the register of student 2:"))
            Student.compare(reg1,reg2)
        elif ch==3:
            exit(0)
        else:
            print("invalid choice")

main()