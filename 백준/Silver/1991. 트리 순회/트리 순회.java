import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

  public static int n;
  public static List<Integer>[] adj = new ArrayList[28];
  public static int[] p = new int[28];
  public static int[] lc = new int[28];
  public static int[] rc = new int[28];

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = null;

    n = Integer.parseInt(br.readLine());
    for(int i=0; i<n; i++){
      st = new StringTokenizer(br.readLine());
      char root = st.nextToken().charAt(0);
      char left = st.nextToken().charAt(0);
      char right = st.nextToken().charAt(0);

      if(left != '.'){
        lc[root-'A'] = left - 'A';
      }
      if(right != '.'){
        rc[root-'A'] = right - 'A';
      }
    }

    preOrder(0);
    System.out.println();
    inOrder(0);
    System.out.println();
    postOrder(0);
  }

  public static void preOrder(int cur){
    System.out.print((char) ('A' + cur));
    if(lc[cur] != 0) preOrder(lc[cur]);
    if(rc[cur] != 0) preOrder(rc[cur]);
  }

  public static void inOrder(int cur){
    if(lc[cur] != 0) inOrder(lc[cur]);
    System.out.print((char) ('A' + cur));
    if(rc[cur] != 0) inOrder(rc[cur]);
  }

  public static void postOrder(int cur){
    if(lc[cur] != 0) postOrder(lc[cur]);
    if(rc[cur] != 0) postOrder(rc[cur]);
    System.out.print((char) ('A' + cur));
  }
}
