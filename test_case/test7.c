int Fibonacci(int x)
{
	int val;

	if (x == 1) val = 1;
	if (x == 2) val = 1;
	if (x > 2) val = Fibonacci(x - 2) + Fibonacci(x - 1);
	return val;
}

int main(void)
{
	int x;
	int y;
	int result;

	x = 5;
	y = 2;
	result = Fibonacci(x * y);
	return result;
}