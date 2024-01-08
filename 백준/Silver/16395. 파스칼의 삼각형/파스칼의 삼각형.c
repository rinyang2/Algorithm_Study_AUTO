
double facto(double a) {
	if (a == 0) {
		return 1;
	}
	return a * facto(a - 1);
}
double combination(double a, double b) {
	return facto(a) / (facto(b)*facto(a - b));
}
int main() {
	double a, b;
	scanf("%lf %lf", &a, &b);
	printf("%.0lf",combination(a-1, b-1));
	return 0;
}