import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        LinkedList<Integer> queue = new LinkedList<>();
        StringBuilder sb = new StringBuilder();
        while(n-- > 0){
            StringTokenizer st = new StringTokenizer(br.readLine());
            String cmd = st.nextToken();

            if(cmd.equals("push")){
                int num = Integer.parseInt(st.nextToken());
                queue.offer(num);
            } else if (cmd.equals("pop")){
                if(queue.isEmpty()) sb.append(-1).append("\n");
                else sb.append(queue.poll()).append("\n");
            } else if (cmd.equals("size")) {
                sb.append(queue.size()).append("\n");
            } else if (cmd.equals("empty")){
                if(queue.isEmpty()) sb.append(1).append("\n");
                else sb.append(0).append("\n");
            } else if (cmd.equals("front")){
                if(queue.isEmpty()) sb.append(-1).append("\n");
                else sb.append(queue.getFirst()).append("\n");
            } else if (cmd.equals("back")){
                if(queue.isEmpty()) sb.append(-1).append("\n");
                else sb.append(queue.getLast()).append("\n");
            }
        }
        
        System.out.println(sb);
    }
    
}