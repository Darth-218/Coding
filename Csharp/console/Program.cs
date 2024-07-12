
namespace ConsoleApp
{
  public class Program
  {
	static void Main(string[] args)
	{
	  Random number = new Random();
	  int newnumber = number.Next(1, 45);
	  while (newnumber != 33)
	  {
		Console.WriteLine(newnumber);
		newnumber = number.Next(1, 45);
	  }
	}
  }
}
