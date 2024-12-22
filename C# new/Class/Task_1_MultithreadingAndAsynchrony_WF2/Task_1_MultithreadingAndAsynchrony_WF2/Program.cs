using System;
using System.IO;
using System.Linq;
using System.Threading;
using System.Windows.Forms;

public class MainForm : Form
{
    private Button startButton;
    private TextBox resultBox;

    public MainForm()
    {
        this.Text = "����� ����� (������)";
        this.Size = new System.Drawing.Size(500, 400);

        startButton = new Button
        {
            Text = "��������� �����",
            Location = new System.Drawing.Point(10, 10),
            Size = new System.Drawing.Size(150, 30)
        };
        startButton.Click += StartButton_Click;

        resultBox = new TextBox
        {
            Multiline = true,
            Location = new System.Drawing.Point(10, 50),
            Size = new System.Drawing.Size(460, 300),
            ReadOnly = true,
            ScrollBars = ScrollBars.Vertical
        };

        this.Controls.Add(startButton);
        this.Controls.Add(resultBox);
    }

    private void StartButton_Click(object sender, EventArgs e)
    {
        int[] numbers = Enumerable.Range(1, 10000).ToArray();

        int max = int.MinValue;
        int min = int.MaxValue;
        double average = 0;

        Thread maxThread = new Thread(() => { max = numbers.Max(); });
        Thread minThread = new Thread(() => { min = numbers.Min(); });
        Thread averageThread = new Thread(() => { average = numbers.Average(); });

        maxThread.Start();
        minThread.Start();
        averageThread.Start();

        maxThread.Join();
        minThread.Join();
        averageThread.Join();

        Thread fileWriterThread = new Thread(() =>
        {
            string filePath = "results.txt";
            using (StreamWriter writer = new StreamWriter(filePath))
            {
                writer.WriteLine("���� �����:");
                writer.WriteLine(string.Join(", ", numbers));
                writer.WriteLine();
                writer.WriteLine($"��������: {max}");
                writer.WriteLine($"̳����: {min}");
                writer.WriteLine($"������ �����������: {average}");
            }
        });

        fileWriterThread.Start();
        fileWriterThread.Join();

        resultBox.Text = $"��������: {max}\r\n̳����: {min}\r\n������ �����������: {average}\r\n���������� �������� � ����: results.txt";
    }

    [STAThread]
    public static void Main()
    {
        Application.EnableVisualStyles();
        Application.Run(new MainForm());
    }
}
