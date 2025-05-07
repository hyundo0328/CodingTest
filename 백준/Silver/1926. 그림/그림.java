import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

  public static int n;
  public static int m;
  public static final int[] dx = {1,0,-1,0};
  public static final int[] dy = {0,1,0,-1};
  public static int[][] board = new int[502][502];
  public static boolean[][] vis = new boolean[502][502];

  private static class Pair{
    int x;
    int y;
    Pair(int x, int y){
      this.x = x;
      this.y = y;
    }
  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    n = Integer.parseInt(st.nextToken());
    m = Integer.parseInt(st.nextToken());

    for(int i=0; i<n; i++){
      st = new StringTokenizer(br.readLine());
      for(int j=0; j<m; j++){
        board[i][j] = Integer.parseInt(st.nextToken());
      }
    }

    int count = 0;
    int max = 0;
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        if(board[i][j] == 0 || vis[i][j]) continue;

        count++;
        vis[i][j] = true;

        int width = bfs(i, j);

        max = Math.max(max, width);
      }
    }

    System.out.println(count);
    System.out.println(max);
  }

  public static int bfs(int x, int y){
    Queue<Pair> Q = new LinkedList<>();
    Q.add(new Pair(x, y));

    int width = 0;
    while(!Q.isEmpty()){
      Pair cur = Q.peek(); Q.poll();

      for(int k=0; k<4; k++){
        int nxtX = cur.x + dx[k];
        int nxtY = cur.y + dy[k];

        if(nxtX < 0 || nxtY < 0 || nxtX > n || nxtY > m) continue;
        if(board[nxtX][nxtY] == 0 || vis[nxtX][nxtY]) continue;

        vis[nxtX][nxtY] = true;
        Q.add(new Pair(nxtX, nxtY));
        width++;
      }
    }
    width++;

    return width;
  }
}
