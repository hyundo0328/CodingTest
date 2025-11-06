import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        int[] cnt = new int[10];

        while(n > 0){
            int num = n%10;

            if(num == 6 || num == 9){
                if(cnt[6] >= cnt[9]) cnt[9]++;
                else cnt[6]++;
            } else {
                cnt[num]++;
            }

            n /= 10;
        }

        int max = -1;
        for(int count:cnt){
            if(max <= count) max = count;
        }
        
        System.out.println(max);
    }

}