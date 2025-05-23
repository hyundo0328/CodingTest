import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int n = Integer.parseInt(br.readLine());
    StringTokenizer st = new StringTokenizer(br.readLine());
    int v = Integer.parseInt(br.readLine());

    List<Integer> arr = new ArrayList<>();
    for(int i=0;i<n;i++){
      arr.add(Integer.parseInt(st.nextToken()));
    }
    Collections.sort(arr);

    if(arr.indexOf(v) == -1){
      System.out.println(0);
    } else {
      System.out.println(arr.lastIndexOf(v) - arr.indexOf(v) + 1);
    }
  }
}
