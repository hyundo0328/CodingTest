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
    public static char[][] board;
    public static int[][] disS;
    public static int[][] disF;
    public static int n, m, t;
    public static boolean flag;
    public static Queue<int[]> qf;
    public static Queue<int[]> qs;
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        t = Integer.parseInt(br.readLine());

        while(t-- > 0){
            StringTokenizer st = new StringTokenizer(br.readLine());
            m = Integer.parseInt(st.nextToken());
            n = Integer.parseInt(st.nextToken());

            init();
            input();

            // 불의 이동거리
            while(!qf.isEmpty()){
                int[] cur = qf.poll();

                for(int dir=0; dir<4; dir++){
                    int nx = cur[0] + dx[dir];
                    int ny = cur[1] + dy[dir];

                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(board[nx][ny] == '#' || disF[nx][ny] != 0) continue;

                    disF[nx][ny] = disF[cur[0]][cur[1]] + 1;
                    qf.add(new int[]{nx,ny});
                }
            }

            // 상근 이동거리
            while(!qs.isEmpty() && !flag){
                int[] cur = qs.poll();

                for(int dir=0; dir<4; dir++){
                    int nx = cur[0] + dx[dir];
                    int ny = cur[1] + dy[dir];

                    if(nx < 0 || nx >= n || ny < 0 || ny >= m){
                        flag = true;
                        System.out.println(disS[cur[0]][cur[1]]);
                        break;
                    }
                    if(board[nx][ny] == '#' || board[nx][ny] == '*' || disS[nx][ny] != 0) continue;
                    if(disF[nx][ny] != 0 && disF[nx][ny] <= disS[cur[0]][cur[1]] + 1) continue;

                    disS[nx][ny] = disS[cur[0]][cur[1]] + 1;
                    qs.add(new int[]{nx,ny});
                }
            }

            if(!flag) System.out.println("IMPOSSIBLE");
        }
    }

    public static void init(){
        board = new char[1002][1002];
        disS = new int[1002][1002];
        disF = new int[1002][1002];

        flag = false;
        qf = new LinkedList<>();
        qs = new LinkedList<>();
    }

    public static void input() throws IOException {
        for(int i=0; i<n; i++){
            String tmp = br.readLine();
            for(int j=0; j<m; j++){
                board[i][j] = tmp.charAt(j);
                if(board[i][j] == '@'){
                    disS[i][j] = 1;
                    qs.add(new int[]{i,j});
                }

                if(board[i][j] == '*'){
                    disF[i][j] = 1;
                    qf.add(new int[]{i,j});
                }
            }
        }
    }

}
