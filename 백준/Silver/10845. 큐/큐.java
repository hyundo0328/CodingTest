import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = null;
    Queue<Integer> Q = new LinkedList<>();
    int n = Integer.parseInt(br.readLine());

    while (n-- > 0) {
      st = new StringTokenizer(br.readLine());
      String cmd = st.nextToken();
      switch (cmd) {
        case "push":
          int val = Integer.parseInt(st.nextToken());
          Q.add(val);
          break;
        case "pop":
          if (Q.isEmpty()) {
            System.out.println(-1);
          } else {
            System.out.println(Q.poll());
          }
          break;
        case "size":
          System.out.println(Q.size());
          break;
        case "empty":
          System.out.println(Q.isEmpty() ? 1 : 0);
          break;
        case "front":
          if (Q.isEmpty()) {
            System.out.println(-1);
          } else {
            System.out.println(Q.peek());
          }
          break;
        case "back":
          if (Q.isEmpty()) {
            System.out.println(-1);
          } else {
            System.out.println(((LinkedList<Integer>) Q).getLast());
          }
          break;
      }
    }
  }
}