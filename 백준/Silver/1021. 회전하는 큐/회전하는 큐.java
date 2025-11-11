import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        LinkedList<Integer> deque = new LinkedList<>();
        for(int i=1; i<=n; i++) deque.addLast(i);

        int count = 0;
        st = new StringTokenizer(br.readLine());
        while(m-- > 0){
            int num = Integer.parseInt(st.nextToken());

            int idx = deque.indexOf(num);
            if(idx <= deque.size()/2){
                while(deque.getFirst() != num){
                    deque.addLast(deque.pollFirst());
                    count++;
                }
                deque.pollFirst();
            } else {
                while(deque.getFirst() != num){
                    deque.addFirst(deque.pollLast());
                    count++;
                }
                deque.pollFirst();
            }
        }

        System.out.println(count);
    }

}
