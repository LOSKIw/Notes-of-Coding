package javaHomework;
import java.util.*;
class pupel{
	String name;
	int math,cs,eng;
	pupel(int m,int c,int e,String n){
		math=m;cs=c;eng=e;name=n;
	}
	pupel(){}
	void print() {
		System.out.println("姓名:"+name+",数学"+math+",英语"+eng+",计算机"+cs);
	}
}
public class Homework091804 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		Vector <pupel> list=new Vector();
		int i,m,c,e;
		String name;
		for(i=0;i<4;i++) {
			System.out.println("姓名:");
			name=sc.nextLine();
			System.out.println("数学的成绩:");
			m=sc.nextInt();
			
			System.out.println("英语的成绩:");
			e=sc.nextInt();
			
			System.out.println("计算机的成绩:");
			c=sc.nextInt();
			
			sc.nextLine();
			
			list.add(new pupel(m,c,e,name));
		}
		for(pupel a:list) {
			a.print();
		}
	}

}
