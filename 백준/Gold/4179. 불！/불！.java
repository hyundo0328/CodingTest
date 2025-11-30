import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static int n, m;
    public static int[] dx = {1, 0, -1, 0};
    public static int[] dy = {0, 1, 0, -1};
    public static char[][] board = new char[1002][1002];
    public static int[][] disJ = new int[1002][1002];
    public static int[][] disF = new int[1002][1002];
    public static Queue<int []> qj = new LinkedList<>();
    public static Queue<int []> qf = new LinkedList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        for(int i=0; i<n; i++){
            String s = br.readLine();
            Arrays.fill(disJ[i], -1);
            Arrays.fill(disF[i], -1);
            for(int j=0; j<m; j++){
                board[i][j] = s.charAt(j);
                if(board[i][j] == 'J') {
                    disJ[i][j] = 0;
                    qj.add(new int[]{i, j});
                }
                if(board[i][j] == 'F') {
                    disF[i][j] = 0;
                    qf.add(new int[]{i, j});
                }
            }
        }

        while(!qf.isEmpty()){
            int[] cur = qf.remove();

            for(int dir=0; dir<4; dir++){
                int nx = cur[0] + dx[dir];
                int ny = cur[1] + dy[dir];

                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(board[nx][ny] == '#' || disF[nx][ny] != -1) continue;

                disF[nx][ny] = disF[cur[0]][cur[1]] + 1;
                qf.add(new int[]{nx, ny});
            }
        }

        while(!qj.isEmpty()){
            int[] cur = qj.remove();

            for(int dir=0; dir<4; dir++){
                int nx = cur[0] + dx[dir];
                int ny = cur[1] + dy[dir];

                if(nx < 0 || nx >= n || ny < 0 || ny >= m){
                    System.out.println(disJ[cur[0]][cur[1]]+1);
                    return;
                }

                if(board[nx][ny] == '#' || disJ[nx][ny] >= 0) continue;
                if(disF[nx][ny] != -1 && disF[nx][ny] <= disJ[cur[0]][cur[1]] + 1) continue;

                disJ[nx][ny] = disJ[cur[0]][cur[1]] + 1;
                qj.add(new int[]{nx, ny});
            }
        }

        System.out.println("IMPOSSIBLE");
    }
}
