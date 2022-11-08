using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
namespace Thiscord_Interceptor
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Process.Start($"{Environment.GetFolderPath(Environment.SpecialFolder.LocalApplicationData)}\\Thiscord\\ThisCord-Master\\src\\main.py");
        }
    }
}
