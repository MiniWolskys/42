using System;
using System.IO;
using System.Linq;

public class add_system
{

	private static void		delete_last(string drop) {

		string[]			splitted = drop.Split("\n");
		splitted.Last() = "";

	}

	private static void		list(string name, string drop) {

		Console.WriteLine(name);
		Console.Write(drop);

	}

	private static void		file_add() {

		string			itemName = "";
		string			itemDrop = "";
		string			confirm = "n";
		string			cmd = "";

		while (!confirm.Equals("y"))
		{
			Console.WriteLine("Enter the name of the item you want to add or edit :");
			itemName = Console.ReadLine();
			Console.WriteLine("Are you sure you want to add the item " + itemName + " to the list of loot? [y/n]");
			confirm = Console.ReadLine();
		}

		confirm = "n";

		while (!confirm.Equals("y"))
		{
			Console.WriteLine("Enter the name of mob on wich you can drop it, and then the value of drop (%).");
			Console.WriteLine("Exemple : \"bouftou : 5.\"");
			Console.WriteLine("Then enter \"end\" to exit.");
			Console.WriteLine("Don't forget that you can remove last line by typing \"delete\".");
			Console.WriteLine("You can also delete all data entered by typing \"delete all\"");
			Console.WriteLine("You can see what you've already entered by typing \"list\"");
			cmd = Console.ReadLine();

			if (cmd.Equals("end"))
			{
				Console.WriteLine("Are you sure you want to quit? [y/n]");
				Console.WriteLine("List below : ");
				list(itemName, itemDrop);
				confirm = Console.ReadLine();
			}

			else if (cmd.Equals("list"))
				list(itemName, itemDrop);

			else if (cmd.Equals("delete"))
			{
				Console.WriteLine("Are you sure you want to delete the last item drop? [y/n]");
				Console.WriteLine("List below : ");
				list(itemName, itemDrop);
				confirm = Console.ReadLine();

				if (confirm.Equals("y"))
				{
					confirm = "n";
					delete_last(itemDrop);
				}

			}

			else if (cmd.Equals("delete all"))
			{
				Console.WriteLine("Are you sure you want to delete all items in list? [y/n]");
				Console.WriteLine("List below : ");
				list(itemName, itemDrop);
				confirm = Console.ReadLine();

				if (confirm.Equals("y"))
				{
					confirm = "n";
					itemDrop = "";

				}
			}
		}
	}

	static void			Main() {

		string			action;
		bool			out_pro = false;

		while (!out_pro)
		{
			Console.WriteLine("Enter \"delete\" to delete an element or \"add\" to add an element.");
			action = Console.ReadLine();
			if (action.Equals("delete") || action.Equals("del"))
			{
				out_pro = true;
//				delete();
			}
			else if (action.Equals("add"))
			{
				out_pro = true;
				file_add();
			}
		}
	}
}
