package javaHomework;
import java.util.*;
class stud{
	String name;
	int math,cs,eng;
	stud(int m,int c,int e,String n){
		math=m;cs=c;eng=e;name=n;
	}
	stud(){}
	void print() {
		System.out.println("姓名:"+name+",数学"+math+",英语"+eng+",计算机"+cs);
	}
}

public class Homework091803 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		stud[] list=new stud[4];
		int i,m,c,e;
		String name;
		for(i=0;i<4;i++) {
			System.out.println("输入姓名:");
			name=sc.nextLine();
			System.out.println("输入数学成绩:");
			m=sc.nextInt();
			
			System.out.println("输入英语成绩:");
			e=sc.nextInt();
			
			System.out.println("输入计算机成绩:");
			c=sc.nextInt();
			
			sc.nextLine();
			
			list[i]=new stud(m,c,e,name);
		}
		for(stud a:list) {
			a.print();
		}
	}

}
