package javaHomework;
import java.util.*;

public class Homework092101 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner a=new Scanner(System.in);
		String l=a.nextLine();
		int i=0,temp=0,col;
		
		while(i<l.length()&&l.charAt(i)!='\n'){
			if(i!=0){
				System.out.print("+");
			}
			temp=0;
			while(i<l.length()&&l.charAt(i)>='0'&&l.charAt(i)<='9'){
				temp=temp*10+l.charAt(i)-'0';
				i++;
			}
			col=temp;
			while(i<l.length()&&l.charAt(i)!='^') {i++;}
			i++;
			temp=0;
			while(i<l.length()&&l.charAt(i)>='0'&&l.charAt(i)<='9') {
				temp=temp*10+l.charAt(i)-'0';
				i++;
			}
			System.out.print(temp*col+"*x^"+(temp-1));
			i++;
		}
	}
}
