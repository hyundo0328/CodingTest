import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String str = br.readLine();

    int[] alphabet = new int[26];

    for(int i=0; i<str.length(); i++){
      alphabet[str.charAt(i)-'a'] += 1;
    }

    for(int i=0; i<26; i++){
      System.out.print(alphabet[i] + " ");
    }
  }
}
