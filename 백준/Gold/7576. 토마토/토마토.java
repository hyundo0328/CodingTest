import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static int n;
    public static int m;
    public static int[] dx = {1, 0, -1, 0};
    public static int[] dy = {0, 1, 0, -1};
    public static int[][] board = new int[1002][1002];
    public static int[][] dis = new int[1002][1002];
    public static Queue<int []> queue = new LinkedList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        m = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());

        for(int i=0; i<n; i++){
            Arrays.fill(dis[i], -1);
            st = new StringTokenizer(br.readLine());
            for(int j=0; j<m; j++){
                board[i][j] = Integer.parseInt(st.nextToken());

                if(board[i][j] == 1){
                    dis[i][j] = 0;
                    queue.add(new int[]{i, j});
                }
            }
        }

        bfs();
        result();
    }

    public static void bfs(){
        while(!queue.isEmpty()){
            int[] cur = queue.poll();

            for(int dir=0; dir<4; dir++){
                int nx = cur[0] + dx[dir];
                int ny = cur[1] + dy[dir];

                if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if(board[nx][ny] == -1) continue;
                if(dis[nx][ny] != -1 || dis[nx][ny] > dis[cur[0]][cur[1]] + 1) continue;

                dis[nx][ny] = dis[cur[0]][cur[1]] + 1;
                queue.add(new int[]{nx, ny});
            }
        }
    }

    public static void result(){
        int max = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 0 && dis[i][j] == -1){
                    System.out.println(-1);
                    return;
                }

                max = Math.max(max, dis[i][j]);
            }
        }

        System.out.println(max);
    }

}