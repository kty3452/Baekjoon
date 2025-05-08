import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(br.readLine());
        int[] arr = Arrays.stream(br.readLine().split(" "))
                          .mapToInt(Integer::parseInt)
                          .toArray();
        Arrays.sort(arr);

        int m = Integer.parseInt(br.readLine());
        int[] query = Arrays.stream(br.readLine().split(" "))
                            .mapToInt(Integer::parseInt)
                            .toArray();

        for (int num : query) {
            sb.append(binarySearch(arr, num)).append("\n");
        }

        System.out.print(sb);
    }

    public static int binarySearch(int[] arr, int target) {
        int left = 0, right = arr.length - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] == target) return 1;
            if (arr[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return 0;
    }
}
