

namespace Gin.Controls
{
    public partial class PositionControl
    {
        /// <summary> 
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary> 
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором компонентов

        /// <summary> 
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.positionZ = new System.Windows.Forms.NumericUpDown();
            this.positionY = new System.Windows.Forms.NumericUpDown();
            this.positionX = new System.Windows.Forms.NumericUpDown();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.rotationX = new System.Windows.Forms.NumericUpDown();
            this.rotationZ = new System.Windows.Forms.NumericUpDown();
            this.rotationY = new System.Windows.Forms.NumericUpDown();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.scaleX = new System.Windows.Forms.NumericUpDown();
            this.scaleZ = new System.Windows.Forms.NumericUpDown();
            this.scaleY = new System.Windows.Forms.NumericUpDown();
            ((System.ComponentModel.ISupportInitialize)(this.positionZ)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.positionY)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.positionX)).BeginInit();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.rotationX)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.rotationZ)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.rotationY)).BeginInit();
            this.groupBox3.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.scaleX)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.scaleZ)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.scaleY)).BeginInit();
            this.SuspendLayout();
            // 
            // positionZ
            // 
            this.positionZ.DecimalPlaces = 3;
            this.positionZ.Increment = new decimal(new int[] {
            1,
            0,
            0,
            131072});
            this.positionZ.Location = new System.Drawing.Point(152, 28);
            this.positionZ.Maximum = new decimal(new int[] {
            10000,
            0,
            0,
            0});
            this.positionZ.Minimum = new decimal(new int[] {
            10000,
            0,
            0,
            -2147483648});
            this.positionZ.Name = "positionZ";
            this.positionZ.Size = new System.Drawing.Size(49, 20);
            this.positionZ.TabIndex = 0;
            this.positionZ.ValueChanged += new System.EventHandler(this.position_ValueChanged);
            // 
            // positionY
            // 
            this.positionY.DecimalPlaces = 3;
            this.positionY.Increment = new decimal(new int[] {
            1,
            0,
            0,
            131072});
            this.positionY.Location = new System.Drawing.Point(87, 28);
            this.positionY.Maximum = new decimal(new int[] {
            10000,
            0,
            0,
            0});
            this.positionY.Minimum = new decimal(new int[] {
            10000,
            0,
            0,
            -2147483648});
            this.positionY.Name = "positionY";
            this.positionY.Size = new System.Drawing.Size(49, 20);
            this.positionY.TabIndex = 0;
            this.positionY.ValueChanged += new System.EventHandler(this.position_ValueChanged);
            // 
            // positionX
            // 
            this.positionX.DecimalPlaces = 3;
            this.positionX.Increment = new decimal(new int[] {
            1,
            0,
            0,
            131072});
            this.positionX.Location = new System.Drawing.Point(21, 28);
            this.positionX.Maximum = new decimal(new int[] {
            10000,
            0,
            0,
            0});
            this.positionX.Minimum = new decimal(new int[] {
            10000,
            0,
            0,
            -2147483648});
            this.positionX.Name = "positionX";
            this.positionX.Size = new System.Drawing.Size(49, 20);
            this.positionX.TabIndex = 0;
            this.positionX.ValueChanged += new System.EventHandler(this.position_ValueChanged);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.label3);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Controls.Add(this.positionX);
            this.groupBox1.Controls.Add(this.positionZ);
            this.groupBox1.Controls.Add(this.positionY);
            this.groupBox1.Location = new System.Drawing.Point(3, 3);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(211, 62);
            this.groupBox1.TabIndex = 1;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Позиция";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(140, 31);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(12, 13);
            this.label3.TabIndex = 1;
            this.label3.Text = "z";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(74, 31);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(12, 13);
            this.label2.TabIndex = 1;
            this.label2.Text = "y";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(8, 31);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(12, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "x";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.label4);
            this.groupBox2.Controls.Add(this.label5);
            this.groupBox2.Controls.Add(this.label6);
            this.groupBox2.Controls.Add(this.rotationX);
            this.groupBox2.Controls.Add(this.rotationZ);
            this.groupBox2.Controls.Add(this.rotationY);
            this.groupBox2.Location = new System.Drawing.Point(3, 71);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(211, 62);
            this.groupBox2.TabIndex = 1;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Поворот";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(140, 31);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(12, 13);
            this.label4.TabIndex = 1;
            this.label4.Text = "z";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(74, 31);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(12, 13);
            this.label5.TabIndex = 1;
            this.label5.Text = "y";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(8, 31);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(12, 13);
            this.label6.TabIndex = 1;
            this.label6.Text = "x";
            // 
            // rotationX
            // 
            this.rotationX.DecimalPlaces = 3;
            this.rotationX.Increment = new decimal(new int[] {
            1,
            0,
            0,
            131072});
            this.rotationX.Location = new System.Drawing.Point(21, 28);
            this.rotationX.Maximum = new decimal(new int[] {
            10000,
            0,
            0,
            0});
            this.rotationX.Minimum = new decimal(new int[] {
            10000,
            0,
            0,
            -2147483648});
            this.rotationX.Name = "rotationX";
            this.rotationX.Size = new System.Drawing.Size(49, 20);
            this.rotationX.TabIndex = 0;
            this.rotationX.ValueChanged += new System.EventHandler(this.rotation_ValueChanged);
            // 
            // rotationZ
            // 
            this.rotationZ.DecimalPlaces = 3;
            this.rotationZ.Increment = new decimal(new int[] {
            1,
            0,
            0,
            131072});
            this.rotationZ.Location = new System.Drawing.Point(152, 28);
            this.rotationZ.Maximum = new decimal(new int[] {
            10000,
            0,
            0,
            0});
            this.rotationZ.Minimum = new decimal(new int[] {
            10000,
            0,
            0,
            -2147483648});
            this.rotationZ.Name = "rotationZ";
            this.rotationZ.Size = new System.Drawing.Size(49, 20);
            this.rotationZ.TabIndex = 0;
            this.rotationZ.ValueChanged += new System.EventHandler(this.rotation_ValueChanged);
            // 
            // rotationY
            // 
            this.rotationY.DecimalPlaces = 3;
            this.rotationY.Increment = new decimal(new int[] {
            1,
            0,
            0,
            131072});
            this.rotationY.Location = new System.Drawing.Point(87, 28);
            this.rotationY.Maximum = new decimal(new int[] {
            10000,
            0,
            0,
            0});
            this.rotationY.Minimum = new decimal(new int[] {
            10000,
            0,
            0,
            -2147483648});
            this.rotationY.Name = "rotationY";
            this.rotationY.Size = new System.Drawing.Size(49, 20);
            this.rotationY.TabIndex = 0;
            this.rotationY.ValueChanged += new System.EventHandler(this.rotation_ValueChanged);
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.label7);
            this.groupBox3.Controls.Add(this.label8);
            this.groupBox3.Controls.Add(this.label9);
            this.groupBox3.Controls.Add(this.scaleX);
            this.groupBox3.Controls.Add(this.scaleZ);
            this.groupBox3.Controls.Add(this.scaleY);
            this.groupBox3.Location = new System.Drawing.Point(3, 139);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(211, 62);
            this.groupBox3.TabIndex = 1;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Масштаб";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(140, 31);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(12, 13);
            this.label7.TabIndex = 1;
            this.label7.Text = "z";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(74, 31);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(12, 13);
            this.label8.TabIndex = 1;
            this.label8.Text = "y";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(8, 31);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(12, 13);
            this.label9.TabIndex = 1;
            this.label9.Text = "x";
            // 
            // scaleX
            // 
            this.scaleX.DecimalPlaces = 3;
            this.scaleX.Increment = new decimal(new int[] {
            1,
            0,
            0,
            131072});
            this.scaleX.Location = new System.Drawing.Point(21, 28);
            this.scaleX.Maximum = new decimal(new int[] {
            10000,
            0,
            0,
            0});
            this.scaleX.Minimum = new decimal(new int[] {
            10000,
            0,
            0,
            -2147483648});
            this.scaleX.Name = "scaleX";
            this.scaleX.Size = new System.Drawing.Size(49, 20);
            this.scaleX.TabIndex = 0;
            this.scaleX.ValueChanged += new System.EventHandler(this.scale_ValueChanged);
            // 
            // scaleZ
            // 
            this.scaleZ.DecimalPlaces = 3;
            this.scaleZ.Increment = new decimal(new int[] {
            1,
            0,
            0,
            131072});
            this.scaleZ.Location = new System.Drawing.Point(152, 28);
            this.scaleZ.Maximum = new decimal(new int[] {
            10000,
            0,
            0,
            0});
            this.scaleZ.Minimum = new decimal(new int[] {
            10000,
            0,
            0,
            -2147483648});
            this.scaleZ.Name = "scaleZ";
            this.scaleZ.Size = new System.Drawing.Size(49, 20);
            this.scaleZ.TabIndex = 0;
            this.scaleZ.ValueChanged += new System.EventHandler(this.scale_ValueChanged);
            // 
            // scaleY
            // 
            this.scaleY.DecimalPlaces = 3;
            this.scaleY.Increment = new decimal(new int[] {
            1,
            0,
            0,
            131072});
            this.scaleY.Location = new System.Drawing.Point(87, 28);
            this.scaleY.Maximum = new decimal(new int[] {
            10000,
            0,
            0,
            0});
            this.scaleY.Minimum = new decimal(new int[] {
            10000,
            0,
            0,
            -2147483648});
            this.scaleY.Name = "scaleY";
            this.scaleY.Size = new System.Drawing.Size(49, 20);
            this.scaleY.TabIndex = 0;
            this.scaleY.ValueChanged += new System.EventHandler(this.scale_ValueChanged);
            // 
            // PositionControl
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Name = "PositionControl";
            this.Size = new System.Drawing.Size(219, 205);
            ((System.ComponentModel.ISupportInitialize)(this.positionZ)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.positionY)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.positionX)).EndInit();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.rotationX)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.rotationZ)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.rotationY)).EndInit();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.scaleX)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.scaleZ)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.scaleY)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.NumericUpDown positionZ;
        private System.Windows.Forms.NumericUpDown positionY;
        private System.Windows.Forms.NumericUpDown positionX;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.NumericUpDown rotationX;
        private System.Windows.Forms.NumericUpDown rotationZ;
        private System.Windows.Forms.NumericUpDown rotationY;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.NumericUpDown scaleX;
        private System.Windows.Forms.NumericUpDown scaleZ;
        private System.Windows.Forms.NumericUpDown scaleY;
    }
}
