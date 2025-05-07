import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

  public static int n;
  public static List<Integer>[] adj = new ArrayList[100002];
  public static int[] p = new int[100002];

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = null;

    adj = new ArrayList[100002];
    for(int i=0; i<100002; i++){
      adj[i] = new ArrayList<>();
    }

    n = Integer.parseInt(br.readLine());
    for(int i=0; i<n-1; i++){
      st = new StringTokenizer(br.readLine());
      int u = Integer.parseInt(st.nextToken());
      int v = Integer.parseInt(st.nextToken());

      adj[u].add(v);
      adj[v].add(u);
    }

    dfs(1);
    for(int i=2; i<=n; i++){
      System.out.println(p[i]);
    }
  }

  public static void dfs(int cur){
    for(int nxt:adj[cur]){
      if(p[cur] == nxt) continue;

      p[nxt] = cur;
      dfs(nxt);
    }
  }
}
