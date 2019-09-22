package javaHomework;
import java.util.*;

public class Homework091203 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		String a=new String();
		System.out.println("请输入字符串:");
		a=sc.nextLine();
		int i=0,num=0,c=0,o=0;
		a=a.toLowerCase();
		while(i<a.length()) {
			if(a.charAt(i)<='z'&&a.charAt(i)>='a')
				c++;
			else if(a.charAt(i)<='9'&&a.charAt(i)>='0')
				num++;
			else
				o++;
			i++;
		}
		System.out.println("有"+num+"个数字，"+c+"个字母，"+o+"个其它字符");
	}

}
