package javaHomework;

class Emploee{
	int num;
	String name;
	Emploee(int n,String na){
		num=n;
		name=na;
	}
	Emploee(){};
	void print() {
		System.out.println("员工信息:");
		System.out.println("姓名:"+name);
		System.out.println("员工号:"+num);
	}
}

class Manager extends Emploee{
	String department;
	Manager(int n,String na,String de){
		super(n,na);
		department=de;
	}
	void print() {
		System.out.println("员工信息:");
		System.out.println("姓名:"+name);
		System.out.println("员工号:"+num);
		System.out.println("主管部门:"+department);
	}
}

public class Homework090401 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Emploee Xia=new Emploee(10001,"夏油轰");
		Xia.print();
		Manager Wu=new Manager(10002,"五桶鱼","财务部");
		Wu.print();

	}

}
