import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int[] arr = new int[N];
        long start = 0;
        long end = 0;
        long result = 0;
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            if(arr[i] > end)
                end = arr[i];
        }
        end++;

        while(start < end) {
            long mid = (start + end)/2;
            long count = 0;
            for(int i = 0; i < N; i++) {
                long min = arr[i] - mid;
                if(min > 0)
                    count += min;
            }
            if(count < M) end = mid;
            else {
                result = mid;
                start = mid + 1;
            }
        }
        bw.write((result) + "");

        bw.flush();
        bw.close();
    }
}