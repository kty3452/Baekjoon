import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), k = sc.nextInt();

        LinkedList<Integer> list = new LinkedList<>();
        for (int i = 1; i <= n; i++) list.add(i);

        System.out.print("<");
        int index = 0;
        while (!list.isEmpty()) {
            index = (index + k - 1) % list.size();
            System.out.print(list.remove(index));
            if (!list.isEmpty()) System.out.print(", ");
        }
        System.out.println(">");
    }
}
