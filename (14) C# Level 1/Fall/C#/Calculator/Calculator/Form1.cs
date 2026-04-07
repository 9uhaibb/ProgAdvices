namespace Calculator
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void Scientific_CheckedChanged(object sender, EventArgs e)
        {
            if (Scientific.Checked)
            {
                panel2.Visible = true;
            }
            else
            {
                panel2.Visible = false;
            }
        }


        private void NumberClick(object sender, EventArgs e)
        {
            Button Number = (Button)sender;
            textBox1.Text += Number.Text;
        }

        double total1 = 0, total2 = 0, result = 0;
        string operation = "";
        private void OperationClick(object sender, EventArgs e)
        {
            Button Op = (Button)sender;
            operation = Op.Text.ToString();
            total1 = double.Parse(textBox1.Text);
            textBox1.Clear();

        }

        private void Equal_Click(object sender, EventArgs e)
        {
            if (operation != "SQRT" && operation != "Factorial" && operation != "pow")
            {
                total2 = double.Parse(textBox1.Text);
            }

            if (operation == "+")
            {
                result = (total1 + total2);
            }
            else if (operation == "-")
            {
                result = (total1 - total2);
            }
            else if (operation == "*")
            {
                result = (total1 * total2);
            }
            else if (operation == "/")
            {
                result = (total1 / total2);
            }
            else if (operation == "SQRT")
            {
                result = Math.Sqrt(total1);
            }
            else if (operation == "pow")
            {
                string[] parts = textBox1.Text.Split('^'); // [0] : X, [1] : n
                total1 = double.Parse(parts[0]);   // ÇáÃÓÇÓ
                total2 = double.Parse(parts[1]);

                result = Math.Pow(total1, total2);
            }
            else if (operation == "Factorial")
            {
                result = 1;
                for (int i = (int) total1; i > 0; i--)
                {
                    result *= i;
                }
            }
                textBox1.Text = result.ToString();

        }

        private void back_Click(object sender, EventArgs e)
        {
            if (textBox1.Text.Length > 0)
            {
                if (textBox1.Text.EndsWith(Dot.Text))
                {
                    dotFlag = false;
                }
                textBox1.Text = (textBox1.Text.Substring(0, textBox1.Text.Length - 1));
            }
        }

        private void clear_Click(object sender, EventArgs e)
        {
            textBox1.Clear();
        }

        bool dotFlag = false;
        private void DotClick(object sender, EventArgs e)
        {
            if (dotFlag == false)
            {
                textBox1.Text += Dot.Text;
                dotFlag = true;
            }
        }

        private void SQRT_Click(object sender, EventArgs e)
        {
            if (textBox1.Text != "")
            {
                double number = double.Parse(textBox1.Text);
                total1 = number;
                operation = "SQRT";
                textBox1.Clear();

                result = Math.Sqrt(number);
                textBox1.Text = result.ToString();
            }
        }

        private void XpowerN_Click(object sender, EventArgs e)
        {
            double number = double.Parse(textBox1.Text);

            total1 = number;
            operation = "pow";
            textBox1.Text += "^";
        }

        private void factorial_Click(object sender, EventArgs e)
        {
            double number = double.Parse(textBox1.Text);

            total1 = number;
            operation = "Factorial";
            textBox1.Text += "!";
        }
    }
}
