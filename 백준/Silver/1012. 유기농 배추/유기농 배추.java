import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static int[] dx = {1,0,-1,0};
    public static int[] dy = {0,1,0,-1};
    public static int[][] board = new int[52][52];
    public static boolean[][] vis = new boolean[52][52];
    public static int n, m, k, cnt;
    public static Queue<int []> queue = new LinkedList<>();
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        int t = Integer.parseInt(br.readLine());
        while(t-- > 0){
            StringTokenizer st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            k = Integer.parseInt(st.nextToken());

            cnt = 0; queue = new LinkedList<>();
            for(int i=0; i<n; i++){
                Arrays.fill(board[i], 0);
                Arrays.fill(vis[i], false);
            }

            while(k-- > 0){
                st = new StringTokenizer(br.readLine());
                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());

                board[x][y] = 1;
            }

            area();
        }
    }

    public static void bfs(){
        while(!queue.isEmpty()){
            int[] cur = queue.poll();

            for(int dir=0; dir<4; dir++){
                int nx = cur[0] + dx[dir];
                int ny = cur[1] + dy[dir];

                if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if(board[nx][ny] == 0 || vis[nx][ny]) continue;

                vis[nx][ny] = true;
                queue.add(new int[]{nx, ny});
            }
        }
    }

    public static void area(){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 0 || vis[i][j]) continue;

                cnt++;
                vis[i][j] = true;
                queue.add(new int[]{i,j});

                bfs();
            }
        }

        System.out.println(cnt);
    }

}
