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
		System.out.println("����:"+name+",��ѧ"+math+",Ӣ��"+eng+",�����"+cs);
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
			System.out.println("����:");
			name=sc.nextLine();
			System.out.println("��ѧ�ĳɼ�:");
			m=sc.nextInt();
			
			System.out.println("Ӣ��ĳɼ�:");
			e=sc.nextInt();
			
			System.out.println("������ĳɼ�:");
			c=sc.nextInt();
			
			sc.nextLine();
			
			list.add(new pupel(m,c,e,name));
		}
		for(pupel a:list) {
			a.print();
		}
	}

}
