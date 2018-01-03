//穷举1到n的排列
//2015.3.20
import java.io.*;
import java.util.*;
public class t{
	private static int n;
	private static int[] a=new int[10];
	public static void search(int m){
		if(m==n-1){
			out();
		}else{
				for(int i=m;i<n;i++){
					swap(m,i);
					search(m+1);
					swap(m,i);
				}
		}

	}
	public static void out(){
		for(int i=0;i<n;i++){
			System.out.print(a[i]);
		}
		System.out.println();
	}
	public static void swap(int i,int j){
		int temp;
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}
	public static void main(String[] args) {
		Scanner cin=new Scanner(new BufferedInputStream(System.in));
		n=cin.nextInt();
		for(int i=0;i<n;i++){
			a[i]=i+1;
		}
		search(0);
	}
}