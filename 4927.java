import java.math.BigInteger;
import java.util.Scanner;


public class Main {
    static int n;
    static BigInteger[] a = new BigInteger[3001];
    static BigInteger[] c = new BigInteger[3001];
    //static BigInteger[] prime = new BigInteger[3001];
    static BigInteger ans = BigInteger.ZERO;
    static Scanner sc = new Scanner(System.in);
    public static void init(){
        int i, j, k, r;
        n = sc.nextInt();
        for(i = 1; i <= n; i++)a[i] = sc.nextBigInteger();
        a[0] = BigInteger.ZERO;
        c[1] = BigInteger.ONE;c[n] = BigInteger.ONE;
        /*
        for (i=n-1;i>=2;i--)
        {
            j=i;k=2;
            while (j>1)
            {
                if (j%k==0)
                    while (j%k==0){j/=k;prime[k] = prime[k].add(BigInteger.ONE);}
                k++;
            }
            j=n-i;k=2;
            while (j>1)
            {
                if (j%k==0)
                    while (j%k==0){j/=k;prime[k] = prime[k].subtract(BigInteger.ONE);}
                k++;
            }
            for (c[i]=BigInteger.ONE,j=1;j<=n;j++){
                //System.out.println(prime[j]);
                if (prime[j].compareTo(BigInteger.ZERO) != 0){
                   for (k=1;prime[j].compareTo(BigInteger.valueOf(k)) != -1;k++){
                       c[i] = c[i].multiply(BigInteger.valueOf(j));
                      // System.out.println(BigInteger.valueOf(j));
                   }
                }
            }
        } */
        for(i = 2; i < n; i++){
            //c[i] = BigInteger.ONE;
            c[i] = (c[i-1].multiply(BigInteger.valueOf(n-i+1))).divide(BigInteger.valueOf(i-1));
            //System.out.println("!"+c[i]);
        }
    }
    public static void work(){
        int i, j;
        ans = BigInteger.ZERO;
        for (i=1;i<=n;i++){
            if (i%2 == 1){
                ans=ans.add(c[(n-i+1)].multiply(a[(n-i+1)]));
            }
            else{
                ans=ans.subtract(c[(n-i+1)].multiply(a[(n-i+1)]));
            }
        }
        System.out.println(ans);
    }
    public static void main(String[] args){
        int i, t;
        
        t = sc.nextInt();
        for(i = 1; i <= t; i++){
            init();
            work();
        } 
        sc.close();
    }
}