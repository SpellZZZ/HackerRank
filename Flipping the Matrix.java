import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {

    /*
     * Complete the 'flippingMatrix' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts 2D_INTEGER_ARRAY matrix as parameter.
     */

    public static int flippingMatrix(List<List<Integer>> matrix) {
    int n = matrix.size()/2;
    int sum = 0;
    int max = 0;
    for(int i =0 ;i<n; i++)
    {
        for(int j =0 ;j<n; j++)
        {
        max = matrix.get(i).get(j);
        if(max < matrix.get(i).get(n*2-1-j)) max = matrix.get(i).get(n*2-1-j);
        if(max < matrix.get(n*2-i-1).get(j)) max = matrix.get(n*2-i-1).get(j);
        if(max < matrix.get(n*2-i-1).get(n*2-j-1)) max = matrix.get(n*2-i-1).get(n*2-j-1);
        sum += max;
        //System.out.println(max);
       // System.out.println(i+" "+j);
       // System.out.println(i+" "+(n*2-1-j));
       // System.out.println((n*2-i-1)+" "+j);
      //  System.out.println((n*2-i-1)+" "+(n*2-j-1));
      //          System.out.println();

        }
        
        

    }
    return sum;

    }

}



public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int q = Integer.parseInt(bufferedReader.readLine().trim());

        IntStream.range(0, q).forEach(qItr -> {
            try {
                int n = Integer.parseInt(bufferedReader.readLine().trim());

                List<List<Integer>> matrix = new ArrayList<>();

                IntStream.range(0, 2 * n).forEach(i -> {
                    try {
                        matrix.add(
                            Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
                                .map(Integer::parseInt)
                                .collect(toList())
                        );
                    } catch (IOException ex) {
                        throw new RuntimeException(ex);
                    }
                });

                int result = Result.flippingMatrix(matrix);

                bufferedWriter.write(String.valueOf(result));
                bufferedWriter.newLine();
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });

        bufferedReader.close();
        bufferedWriter.close();
    }
}
