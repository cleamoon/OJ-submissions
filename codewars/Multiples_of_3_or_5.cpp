int solution(int number) 
{
  if (number <= 3) return 0;
  int m3 = (number - 1) / 3;
  int m5 = (number - 1) / 5;
  int m15 = (number - 1) / 15;
  int sum3 = (m3 + 1) * m3 / 2;
  int sum5 = (m5 + 1) * m5 / 2;
  int sum15 = (m15 + 1) * m15 / 2;
  return sum3 * 3 + sum5 * 5 - sum15 * 15;
}