package javaHomework;

import java.util.Scanner;

public class Homework091204 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		StringBuffer S=new StringBuffer();
		System.out.println("ÇëÊäÈë×Ö·û´®S:");
		S.append(sc.nextLine());
		
		String s1=new String();
		System.out.println("ÇëÊäÈë×Ö·û´®s1:");
		s1=sc.nextLine();
		
		String s2=new String();
		System.out.println("ÇëÊäÈë×Ö·û´®s2:");
		s2=sc.nextLine();
		
		int i=0;
		int n=S.indexOf(s1);
		if(S.indexOf(s1)==-1) {
			System.out.println("²»º¬ÓĞ");
		}
		else {
			for(i=n;i<n+s2.length();i++) {
				S.deleteCharAt(i);
				S.insert(i, s2.charAt(i-n));
			}
			System.out.println(S);
		}
	}

}
