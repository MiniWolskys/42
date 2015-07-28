using System;
using System.Collections.Generic;

public struct			s_loot
{
	public string[]		mobs;
	public string		name;
	public int			prob;
}

public class Loot_system
{

	static List<string>			get_loot(List<s_loot> tab, string name)
	{
		List<string>			ret = new List<string>();
		Random					rnd = new Random();
		int						rand;
		bool					ok;

		foreach (s_loot line in tab) {
			ok = false;
			foreach (string dropper in line.mobs) {
				if (dropper.Equals(name)) {
					ok = true;
				}
			}
			if (ok) {
				rand = rnd.Next(0, 10000);
				if (rand < line.prob) {
					ret.Add(line.name);
				}
			}
		}
		return (ret);
	}

	static List<s_loot>			get_file()
	{
		System.IO.StreamReader	fd;
		List<s_loot>			tab = new List<s_loot>();
		s_loot					mem;
		string[]				tmp;

		fd = new System.IO.StreamReader("./loot_file.txt");
		string readed_File = fd.ReadToEnd();
		fd.Close();
		string[] file = readed_File.Split('\n');
		foreach (string part in file) {
			if (!part.Equals("")) {
				tmp = part.Split(':');
				mem.mobs = tmp[0].Split(',');
				mem.name = tmp[1];
				mem.prob = (int)(Convert.ToDouble(tmp[2]) * 100.0);
				tab.Add(mem);
			}
		}
		return (tab);
	}

	static void			Main(string[] args)
	{
		List<s_loot>	tab = get_file();
		List<string>	file = new List<string>();
		List<string>	tmp;

		foreach (string str in args) {
			tmp = get_loot(tab, str);
			foreach (string loot in tmp) {
				file.Add(loot);
			}
		}
		for (int i = 0; i < file.Count; i++) {
			Console.WriteLine(file[i]);
		}
	}
}
