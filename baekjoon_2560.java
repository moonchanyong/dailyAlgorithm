import java.util.Scanner;


public class Main {
	public static void main(String[] args) {


		int[] productableWeight = new int[1000001];
		int[] death = new int[1000001];

		Scanner scan = new Scanner(System.in);

		int a = scan.nextInt(),
			b = scan.nextInt(),
			d = scan.nextInt(),
			N = scan.nextInt(),
			bugs, idx = 0, productable, gab ;


		bugs= 1;
		productable = 0;
		productableWeight[idx + a] += 1;
		productableWeight[idx + b] -= 1;
		death[idx + d] = 1;

		while(++idx <= N) {
			productable += productableWeight[idx];
			if (productable  >= 1000) productable %= 1000;
			gab = productable - death[idx];
			bugs +=  gab <0 ? 1000 + gab : gab;
			if (bugs >= 1000) bugs %= 1000;

			if (idx + a <= 1000000) {
				productableWeight[idx + a] += productable;
				if (idx + b <= 1000000) {
					productableWeight[idx + b] = productableWeight[idx + b] - productable < 0 ? 1000 +  productableWeight[idx + b] - productable : productableWeight[idx + b] - productable;
					if (idx + d <= 1000000) death[idx + d] += productable;
				}
			}
		}
		System.out.println(bugs);
	}
}
