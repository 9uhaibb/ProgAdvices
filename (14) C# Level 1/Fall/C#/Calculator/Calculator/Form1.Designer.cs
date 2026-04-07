namespace Calculator
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            textBox1 = new TextBox();
            Standard = new RadioButton();
            Scientific = new RadioButton();
            panel1 = new Panel();
            clear = new Button();
            back = new Button();
            button16 = new Button();
            button15 = new Button();
            button14 = new Button();
            button13 = new Button();
            Equal = new Button();
            Dot = new Button();
            button10 = new Button();
            button9 = new Button();
            button8 = new Button();
            button7 = new Button();
            button6 = new Button();
            button5 = new Button();
            button4 = new Button();
            button3 = new Button();
            button2 = new Button();
            button1 = new Button();
            panel2 = new Panel();
            factorial = new Button();
            XpowerN = new Button();
            SQRT = new Button();
            label1 = new Label();
            panel1.SuspendLayout();
            panel2.SuspendLayout();
            SuspendLayout();
            // 
            // textBox1
            // 
            textBox1.Location = new Point(335, 57);
            textBox1.Name = "textBox1";
            textBox1.ReadOnly = true;
            textBox1.Size = new Size(237, 27);
            textBox1.TabIndex = 0;
            // 
            // Standard
            // 
            Standard.AutoSize = true;
            Standard.Location = new Point(263, 153);
            Standard.Name = "Standard";
            Standard.Size = new Size(90, 24);
            Standard.TabIndex = 1;
            Standard.TabStop = true;
            Standard.Text = "Standard";
            Standard.UseVisualStyleBackColor = true;
            // 
            // Scientific
            // 
            Scientific.AutoSize = true;
            Scientific.Location = new Point(496, 154);
            Scientific.Name = "Scientific";
            Scientific.Size = new Size(90, 24);
            Scientific.TabIndex = 2;
            Scientific.TabStop = true;
            Scientific.Text = "Scientific";
            Scientific.UseVisualStyleBackColor = true;
            Scientific.CheckedChanged += Scientific_CheckedChanged;
            // 
            // panel1
            // 
            panel1.Controls.Add(clear);
            panel1.Controls.Add(back);
            panel1.Controls.Add(button16);
            panel1.Controls.Add(button15);
            panel1.Controls.Add(button14);
            panel1.Controls.Add(button13);
            panel1.Controls.Add(Equal);
            panel1.Controls.Add(Dot);
            panel1.Controls.Add(button10);
            panel1.Controls.Add(button9);
            panel1.Controls.Add(button8);
            panel1.Controls.Add(button7);
            panel1.Controls.Add(button6);
            panel1.Controls.Add(button5);
            panel1.Controls.Add(button4);
            panel1.Controls.Add(button3);
            panel1.Controls.Add(button2);
            panel1.Controls.Add(button1);
            panel1.Location = new Point(149, 210);
            panel1.Name = "panel1";
            panel1.Size = new Size(303, 289);
            panel1.TabIndex = 3;
            // 
            // clear
            // 
            clear.Location = new Point(27, 28);
            clear.Name = "clear";
            clear.Size = new Size(95, 45);
            clear.TabIndex = 17;
            clear.Text = "clear";
            clear.UseVisualStyleBackColor = true;
            clear.Click += clear_Click;
            // 
            // back
            // 
            back.Location = new Point(128, 28);
            back.Name = "back";
            back.Size = new Size(95, 45);
            back.TabIndex = 16;
            back.Text = "<--";
            back.UseVisualStyleBackColor = true;
            back.Click += back_Click;
            // 
            // button16
            // 
            button16.Location = new Point(227, 28);
            button16.Name = "button16";
            button16.Size = new Size(59, 45);
            button16.TabIndex = 15;
            button16.Text = "/";
            button16.UseVisualStyleBackColor = true;
            button16.Click += OperationClick;
            // 
            // button15
            // 
            button15.Location = new Point(226, 79);
            button15.Name = "button15";
            button15.Size = new Size(59, 45);
            button15.TabIndex = 14;
            button15.Text = "*";
            button15.UseVisualStyleBackColor = true;
            button15.Click += OperationClick;
            // 
            // button14
            // 
            button14.Location = new Point(227, 130);
            button14.Name = "button14";
            button14.Size = new Size(59, 45);
            button14.TabIndex = 13;
            button14.Text = "-";
            button14.UseVisualStyleBackColor = true;
            button14.Click += OperationClick;
            // 
            // button13
            // 
            button13.Location = new Point(226, 181);
            button13.Name = "button13";
            button13.Size = new Size(59, 45);
            button13.TabIndex = 12;
            button13.Text = "+";
            button13.UseVisualStyleBackColor = true;
            button13.Click += OperationClick;
            // 
            // Equal
            // 
            Equal.Location = new Point(226, 230);
            Equal.Name = "Equal";
            Equal.Size = new Size(59, 45);
            Equal.TabIndex = 11;
            Equal.Text = "=";
            Equal.UseVisualStyleBackColor = true;
            Equal.Click += Equal_Click;
            // 
            // Dot
            // 
            Dot.Location = new Point(164, 230);
            Dot.Name = "Dot";
            Dot.Size = new Size(59, 45);
            Dot.TabIndex = 10;
            Dot.Text = ".";
            Dot.UseVisualStyleBackColor = true;
            Dot.Click += DotClick;
            // 
            // button10
            // 
            button10.Location = new Point(25, 230);
            button10.Name = "button10";
            button10.Size = new Size(131, 45);
            button10.TabIndex = 9;
            button10.Text = "0";
            button10.UseVisualStyleBackColor = true;
            button10.Click += NumberClick;
            // 
            // button9
            // 
            button9.Location = new Point(162, 79);
            button9.Name = "button9";
            button9.Size = new Size(59, 45);
            button9.TabIndex = 8;
            button9.Text = "9";
            button9.UseVisualStyleBackColor = true;
            button9.Click += NumberClick;
            // 
            // button8
            // 
            button8.Location = new Point(97, 79);
            button8.Name = "button8";
            button8.Size = new Size(59, 45);
            button8.TabIndex = 7;
            button8.Text = "8";
            button8.UseVisualStyleBackColor = true;
            button8.Click += NumberClick;
            // 
            // button7
            // 
            button7.Location = new Point(25, 79);
            button7.Name = "button7";
            button7.Size = new Size(59, 45);
            button7.TabIndex = 6;
            button7.Text = "7";
            button7.UseVisualStyleBackColor = true;
            button7.Click += NumberClick;
            // 
            // button6
            // 
            button6.Location = new Point(162, 130);
            button6.Name = "button6";
            button6.Size = new Size(59, 45);
            button6.TabIndex = 5;
            button6.Text = "6";
            button6.UseVisualStyleBackColor = true;
            button6.Click += NumberClick;
            // 
            // button5
            // 
            button5.Location = new Point(97, 130);
            button5.Name = "button5";
            button5.Size = new Size(59, 45);
            button5.TabIndex = 4;
            button5.Text = "5";
            button5.UseVisualStyleBackColor = true;
            button5.Click += NumberClick;
            // 
            // button4
            // 
            button4.Location = new Point(25, 130);
            button4.Name = "button4";
            button4.Size = new Size(59, 45);
            button4.TabIndex = 3;
            button4.Text = "4";
            button4.UseVisualStyleBackColor = true;
            button4.Click += NumberClick;
            // 
            // button3
            // 
            button3.Location = new Point(162, 181);
            button3.Name = "button3";
            button3.Size = new Size(59, 45);
            button3.TabIndex = 2;
            button3.Text = "3";
            button3.UseVisualStyleBackColor = true;
            button3.Click += NumberClick;
            // 
            // button2
            // 
            button2.Location = new Point(97, 181);
            button2.Name = "button2";
            button2.Size = new Size(59, 45);
            button2.TabIndex = 1;
            button2.Text = "2";
            button2.UseVisualStyleBackColor = true;
            button2.Click += NumberClick;
            // 
            // button1
            // 
            button1.Location = new Point(25, 181);
            button1.Name = "button1";
            button1.Size = new Size(59, 45);
            button1.TabIndex = 0;
            button1.Text = "1";
            button1.UseVisualStyleBackColor = true;
            button1.Click += NumberClick;
            // 
            // panel2
            // 
            panel2.Controls.Add(factorial);
            panel2.Controls.Add(XpowerN);
            panel2.Controls.Add(SQRT);
            panel2.Location = new Point(526, 210);
            panel2.Name = "panel2";
            panel2.Size = new Size(129, 278);
            panel2.TabIndex = 4;
            panel2.Visible = false;
            // 
            // factorial
            // 
            factorial.Location = new Point(16, 214);
            factorial.Name = "factorial";
            factorial.Size = new Size(95, 45);
            factorial.TabIndex = 20;
            factorial.Text = "x!";
            factorial.UseVisualStyleBackColor = true;
            factorial.Click += factorial_Click;
            // 
            // XpowerN
            // 
            XpowerN.Location = new Point(16, 121);
            XpowerN.Name = "XpowerN";
            XpowerN.Size = new Size(95, 45);
            XpowerN.TabIndex = 19;
            XpowerN.Text = "x ^ n";
            XpowerN.UseVisualStyleBackColor = true;
            XpowerN.Click += XpowerN_Click;
            // 
            // SQRT
            // 
            SQRT.Location = new Point(16, 28);
            SQRT.Name = "SQRT";
            SQRT.Size = new Size(95, 45);
            SQRT.TabIndex = 18;
            SQRT.Text = "SQRT";
            SQRT.UseVisualStyleBackColor = true;
            SQRT.Click += SQRT_Click;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(256, 62);
            label1.Name = "label1";
            label1.Size = new Size(49, 20);
            label1.TabIndex = 5;
            label1.Text = "Result";
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(934, 572);
            Controls.Add(label1);
            Controls.Add(panel2);
            Controls.Add(panel1);
            Controls.Add(Scientific);
            Controls.Add(Standard);
            Controls.Add(textBox1);
            Name = "Form1";
            Text = "Calculator";
            Load += Form1_Load;
            Click += OperationClick;
            panel1.ResumeLayout(false);
            panel2.ResumeLayout(false);
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private TextBox textBox1;
        private RadioButton Standard;
        private RadioButton Scientific;
        private Panel panel1;
        private Panel panel2;
        private Label label1;
        private Button button1;
        private Button back;
        private Button button16;
        private Button button15;
        private Button button14;
        private Button button13;
        private Button Equal;
        private Button Dot;
        private Button button10;
        private Button button9;
        private Button button8;
        private Button button7;
        private Button button6;
        private Button button5;
        private Button button4;
        private Button button3;
        private Button button2;
        private Button clear;
        private Button factorial;
        private Button XpowerN;
        private Button SQRT;
    }
}
