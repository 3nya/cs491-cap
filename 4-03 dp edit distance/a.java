public class sol {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int n = scan.nextInt();
        int m = scan.nextInt();
        int[][] mountain = new int[n][m];
        int[][] memo = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mountain[i][j] = scan.nextInt();
            }
        }
        
        int result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result = Math.max(result, maxPathEndAtIJ(mountain, i, j, memo));
            }
        }
        System.out.println(result);
    }
    //4 directions
    static int[][] directions = new int[][]{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    private static int maxPathEndAtIJ(int[][] mountain, int i, int j, int[][] memo) {
        if (i < 0 || i >= mountain.length) {
            return 0;
        }
        if (j < 0 || j >= mountain[0].length) {
            return 0;
        }

        int result = 1;
        for (int d = 0; d < directions.length; d++) {
            int nextI = i + directions[d][0];
            int nextJ = j + directions[d][1];

            if (nextI >= 0 && nextI < mountain.length && nextJ >= 0 && nextJ < mountain[0].length
                && mountain[i][j] > mountain[nextI][nextJ]) {

                result = Math.max(result, maxPathEndAtIJ(mountain, nextI, nextJ, memo) + 1);
            }
        }
        memo[i][j] = result;
        return result;
    }
}
