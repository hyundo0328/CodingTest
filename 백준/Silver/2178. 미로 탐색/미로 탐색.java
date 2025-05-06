import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

  public static final int[] dx = {1,0,-1,0};
  public static final int[] dy = {0,1,0,-1};
  public static int[][] board = new int[102][102];
  public static int[][] dis = new int[102][102];

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

    int n = Integer.parseInt(st.nextToken());
    int m = Integer.parseInt(st.nextToken());
    for(int i=0; i<n; i++){
      String tmp = br.readLine();
      for(int j=0; j<m; j++){
        board[i][j] = Integer.parseInt(String.valueOf(tmp.charAt(j)));
      }
    }

    Queue<Pair> Q = new LinkedList<>();
    Q.add(new Pair(0,0));
    dis[0][0] = 1;

    while(!Q.isEmpty()){
      Pair cur = Q.peek(); Q.poll();

      for(int i=0; i<4; i++){
        int nxtX = cur.x + dx[i];
        int nxtY = cur.y + dy[i];

        if(nxtX < 0 || nxtY < 0 || nxtX > n || nxtY > m) continue;
        if(board[nxtX][nxtY] == 0 || dis[nxtX][nxtY] != 0) continue;

        Q.add(new Pair(nxtX, nxtY));
        dis[nxtX][nxtY] = dis[cur.x][cur.y] + 1;
      }
    }

    System.out.println(dis[n-1][m-1]);
  }
}
