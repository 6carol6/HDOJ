import java.util.Scanner;


public class Main {
    public static void main(String[] args){
        String str;
        Scanner sc = new Scanner(System.in);
        int count = 0;
        while(sc.hasNext()){
            str = sc.next();
            //System.out.println(str);
            str = str.toLowerCase();
            while(str.contains("doge")){
                str = str.substring(str.indexOf("doge")+4);
                count++;
            }
            //str = sc.next();
        }
        System.out.println(count);
    }
}