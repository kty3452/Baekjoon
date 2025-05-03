import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), k = sc.nextInt(), arr[] = new int[n],  arr2[] = new int[n], temp = 0;
        for(int i = 0;i < n;i++){
            int cnt = 0;
            while(true){
                if(temp >= n)
                    temp %= n;
                if(arr[temp] == 0)
                    cnt++;
                if(cnt == k)
                    break;
                temp++;
            }
            arr[temp] = 1;
            arr2[i] = temp + 1;
        }
        System.out.print("<");
        for(int i = 0;i < arr2.length-1;i++){
            System.out.print(arr2[i]+", ");
        }
        System.out.print(arr2[arr.length - 1]+">");
    }
}
