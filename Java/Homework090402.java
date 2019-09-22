package javaHomework;

class rec{
	int len,wid;
	static int num=0;
	rec(int l,int w){
		len=l;
		wid=w;
		num++;
	}
	rec(int l){
		len=l;
		num++;
	}
	rec(){}
	int get_l() {
		return 2*(len+wid);
	}
	int get_s() {
		return len*wid;
	}
	static int get_n() {
		return num;
	}
}

class square extends rec{
	static int num=0;
	square(int l){
		super(l);
		num++;
	}
	int get_l() {
		return 4*len;
	}
	int get_s() {
		return len*len;
	}
	static int get_n() {
		return num;
	}
}

public class Homework090402 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		rec A=new rec(10,12);
		System.out.println("矩形周长为:"+A.get_l());
		System.out.println("矩形面积为:"+A.get_s());
		System.out.println("矩形个数为:"+A.get_n());
		rec B=new rec(12,24);
		System.out.println("矩形周长为:"+B.get_l());
		System.out.println("矩形面积为:"+B.get_s());
		System.out.println("矩形个数为:"+B.get_n());
		square C=new square(10);
		System.out.println("正方形周长为:"+C.get_l());
		System.out.println("正方形面积为:"+C.get_s());
		System.out.println("正方形个数为:"+C.get_n());
		System.out.println("矩形个数为:"+B.get_n());
	}

}
