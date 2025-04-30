import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;

    int n = Integer.parseInt(br.readLine());

    for(int i=0; i<n; i++){
      int[] first = new int[26];
      int[] second = new int[26];
      int[] check = new int[26];

      st = new StringTokenizer(br.readLine());
      String a = st.nextToken();
      String b = st.nextToken();

      if(a.length() != b.length()) {
        System.out.println("Impossible");
        continue;
      }

      for(int j=0; j<a.length(); j++){
        check[a.charAt(j)-'a']++;
        check[b.charAt(j)-'a']--;
      }

      boolean flag = false;
      for(int j=0; j<26; j++){
        if(check[j] != 0){
          flag = true;
          break;
        }
      }

      if (flag) System.out.println("Impossible");
      else System.out.println("Possible");
    }
  }
}
