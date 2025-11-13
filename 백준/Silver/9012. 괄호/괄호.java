import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        while(n-- > 0){
            String str = br.readLine();

            Stack<Character> s = new Stack<>();
            boolean flag = false;
            for(int i=0; i<str.length(); i++){
                if(str.charAt(i) == '(') s.push(str.charAt(i));
                else {
                    if(!s.empty()) s.pop();
                    else{
                        flag = true;
                        break;
                    }   
                }
            }

            if(!s.empty()) flag = true;

            if(flag) System.out.println("NO");
            else System.out.println("YES");
        }
    }

}
