using System;
using System.Threading;
using System.Windows.Forms;

public class MainForm : Form
{
    private Button startButton;
    private TextBox resultBox;

    public MainForm()
    {
        this.Text = "Виведення чисел у потоці";
        this.Size = new System.Drawing.Size(400, 300);

        startButton = new Button
        {
            Text = "Запустити потік",
            Location = new System.Drawing.Point(10, 10),
            Size = new System.Drawing.Size(150, 30)
        };
        startButton.Click += StartButton_Click;

        resultBox = new TextBox
        {
            Multiline = true,
            Location = new System.Drawing.Point(10, 50),
            Size = new System.Drawing.Size(360, 200),
            ReadOnly = true,
            ScrollBars = ScrollBars.Vertical
        };

        this.Controls.Add(startButton);
        this.Controls.Add(resultBox);
    }

    private void StartButton_Click(object sender, EventArgs e)
    {
        Thread thread = new Thread(() =>
        {
            for (int i = 0; i <= 50; i++)
            {
                this.Invoke((MethodInvoker)delegate
                {
                    resultBox.AppendText(i + "\r\n");
                });
                Thread.Sleep(100);
            }
        });

        thread.Start();
    }

    [STAThread]
    public static void Main()
    {
        Application.EnableVisualStyles();
        Application.Run(new MainForm());
    }
}
