import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

  public static List<Integer>[] adj = new ArrayList[1002];
  public static boolean[] vis = new boolean[1002];

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = null;

    st = new StringTokenizer(br.readLine());
    int n = Integer.parseInt(st.nextToken());
    int m = Integer.parseInt(st.nextToken());

    for (int i = 1; i <= n; i++) {
      adj[i] = new ArrayList<>();
    }

    while(m-- > 0){
      st = new StringTokenizer(br.readLine());
      int u = Integer.parseInt(st.nextToken());
      int v = Integer.parseInt(st.nextToken());

      adj[u].add(v);
      adj[v].add(u);
    }

    int count = 0;
    for(int i=1; i<=n; i++){
      if(vis[i]) continue;
      vis[i] = true;
      Queue<Integer> Q = new LinkedList<>();
      Q.add(i);
      count++;

      while(!Q.isEmpty()){
        int cur = Q.peek(); Q.poll();
        for(Integer nxt:adj[cur]){
          if(vis[nxt]) continue;

          vis[nxt] = true;
          Q.add(nxt);
        }
      }
    }
    System.out.println(count);
  }
}
