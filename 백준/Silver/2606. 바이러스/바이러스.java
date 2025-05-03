import java.io.*;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer strToken;
        int N = Integer.parseInt(br.readLine());
        int arr[] = new int[N];
        if(N != 0)
            arr[0] = 1;
        int M = Integer.parseInt(br.readLine());
        int arr2[][] = new int[M][2];
        for(int i = 0;i < M;i++){
            strToken = new StringTokenizer(br.readLine());
            arr2[i][0] = Integer.parseInt(strToken.nextToken());
            arr2[i][1] = Integer.parseInt(strToken.nextToken());
        }
        for(int i = 0;i < M;i++){
            for(int j = 0;j < M;j++){
                if(arr[arr2[j][0] - 1] == 1 || arr[arr2[j][1] - 1] == 1){
                    arr[arr2[j][0] - 1] = 1;
                    arr[arr2[j][1] - 1] = 1;
                }
            }
        }
        int cnt = -1;
        for(int i : arr)
            if(i == 1)
                cnt++;
        if(N != 0)
            bw.write(cnt+"");
        else bw.write("0");


        bw.flush();
        bw.close();
    }

}