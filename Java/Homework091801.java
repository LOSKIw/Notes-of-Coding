package javaHomework;

import java.util.*;
import java.util.Arrays;
public class Homework091801 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		System.out.println("输入元素数量:");
		int num=sc.nextInt();
		int i;
		int a[]=new int[num];
		System.out.println("输入元素:");
		for(i=0;i<num;i++) {
			a[i]=sc.nextInt();
		}
		Arrays.sort(a);
		for(i=0;i<num;i++) {
			System.out.print(a[i]+" ");
		}
	}
}
