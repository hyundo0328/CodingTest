import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        int count = 0;
        while(n-- > 0){
            String str = br.readLine();
            
            Stack<Character> s = new Stack<>();
            for(int i=0; i<str.length(); i++){
                if(!s.empty() && s.peek() == str.charAt(i)) s.pop();
                else s.push(str.charAt(i));
            }
            
            if(s.empty()) count++;
        }
        
        System.out.println(count);
    }

}
