import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int S = 0;

        int count = Integer.parseInt(br.readLine());

        while (count-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String op = st.nextToken();

            if (op.equals("add")) {
                int x = Integer.parseInt(st.nextToken());
                S |= (1 << x);
            } else if (op.equals("remove")) {
                int x = Integer.parseInt(st.nextToken());
                S &= ~(1 << x);
            } else if (op.equals("check")) {
                int x = Integer.parseInt(st.nextToken());
                bw.write(((S & (1 << x)) != 0 ? "1\n" : "0\n"));
            } else if (op.equals("toggle")) {
                int x = Integer.parseInt(st.nextToken());
                S ^= (1 << x);
            } else if (op.equals("all")) {
                S = (1 << 21) - 1;
            } else if (op.equals("empty")) {
                S = 0;
            }
        }

        bw.flush();
        bw.close();
    }
}
