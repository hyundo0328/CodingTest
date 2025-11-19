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
    public static int count = 0;
    public static int max = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        for(int i=0; i<n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j=0; j<m; j++) board[i][j] = Integer.parseInt(st.nextToken());
        }

        width();

        System.out.println(count);
        System.out.println(max);
    }

    public static void width(){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 0 || vis[i][j]) continue;

                count++;
                vis[i][j] = true;
                int wid = bfs(i, j);

                max = Math.max(max, wid);
            }
        }
    }

    public static int bfs(int x, int y){
        int tmp = 1;
        Queue<int []> queue = new LinkedList<>();
        queue.add(new int[]{x, y});

        while(!queue.isEmpty()){
            int[] cur = queue.poll();

            for(int dir=0; dir<4; dir++){
                int nx = cur[0] + dx[dir];
                int ny = cur[1] + dy[dir];

                if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if(board[nx][ny] == 0 || vis[nx][ny]) continue;

                queue.add(new int[]{nx, ny});
                vis[nx][ny] = true;
                tmp++;
            }
        }

        return tmp;
    }

    
}
