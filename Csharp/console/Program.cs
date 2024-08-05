
namespace ConsoleApp
{
  public class Program
  {
	static void Main(string[] args)
	{
	  try
	  {
		int i = 0;
		Console.WriteLine($"{1 / i}");
	  }
	  catch (System.DivideByZeroException)
	  {
		System.Console.WriteLine("This is an error");
	  }
	  System.Console.WriteLine("That was a test");
	}
  }
}
