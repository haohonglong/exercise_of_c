int is_leap(int year)
{
  if(0 == year%4 && year%100 != 0 || 0 == year%400){
    return 1;
  }
  return 0;
}