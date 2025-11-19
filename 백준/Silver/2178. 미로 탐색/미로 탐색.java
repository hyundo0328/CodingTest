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

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        for(int i=0; i<n; i++){
            String str = br.readLine();
            for(int j=0; j<m; j++) {
                board[i][j] = str.charAt(j) - '0';
            }
        }

        Queue<int []> queue = new LinkedList<>();
        queue.add(new int[]{0,0});
        dis[0][0] = 1;

        while(!queue.isEmpty()){
            int[] cur = queue.poll();

            for(int dir=0; dir<4; dir++){
                int nx = cur[0] + dx[dir];
                int ny = cur[1] + dy[dir];

                if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if(board[nx][ny] == 0 || dis[nx][ny] != 0) continue;

                dis[nx][ny] = dis[cur[0]][cur[1]] + 1;
                queue.add(new int[]{nx, ny});
            }
        }

        System.out.println(dis[n-1][m-1]);
    }
}