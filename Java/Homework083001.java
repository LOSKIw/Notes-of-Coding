package javaHomework;

class student{
	private int year,num,grade_math,grade_cs,grade_eng;
	private String name;
	
	student(int n,int y,int gm,int gc,int ge,String na){
		name=na;
		num=n;
		year=y;
		grade_math=gm;
		grade_cs=gc;
		grade_eng=ge;
	}
	
	student(){
		grade_math=grade_cs=grade_eng=0;
		name=null;
		num=0;
		year=2000;
	}
	
	int sum(){
		return grade_math+grade_cs+grade_eng;
	}
	
	int age(){
		return ((2019-year>0)?(2019-year):-1);
	}
	
	String get_name(){
		return name;
	}
	
	void print(){
		System.out.println("ѧ������:"+name);
		System.out.println("ѧ��ѧ��:"+num);
		System.out.println("��ѧ�ɼ�:"+grade_math);
		System.out.println("������ɼ�:"+grade_cs);
		System.out.println("Ӣ��ɼ�:"+grade_eng);
	}
	
}

public class Homework083001 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		student Li=new student(10001,1999,90,80,70,"�");
		System.out.println(Li.get_name()+"���ܳɼ�Ϊ:"+Li.sum());
		System.out.println(Li.get_name()+"������Ϊ:"+Li.age());
		Li.print();
	}

}
