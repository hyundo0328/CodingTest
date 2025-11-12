import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while(true){
            String str = br.readLine();

            if(str.equals(".")) break;
            Stack<Character> s = new Stack<>();
            boolean flag = false;
            for(int i=0; i<str.length(); i++){
                if(str.charAt(i) == '(' || str.charAt(i) == '[') s.push(str.charAt(i));
                else if(str.charAt(i) == ')'){
                    if(s.empty() || s.peek() != '('){
                        flag = true;
                        break;
                    }
                    s.pop();
                } else if(str.charAt(i) == ']'){
                    if(s.empty() || s.peek() != '['){
                        flag = true;
                        break;
                    }
                    s.pop();
                }
            }
            
            if(!s.empty()) flag = true;
            
            if(flag) System.out.println("no");
            else System.out.println("yes");
        }
    }

}
