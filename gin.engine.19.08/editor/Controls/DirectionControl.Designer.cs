
namespace Gin.Controls
{
    partial class DirectionControl
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
            this.DirGroup = new System.Windows.Forms.GroupBox();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.directionX = new System.Windows.Forms.NumericUpDown();
            this.directionZ = new System.Windows.Forms.NumericUpDown();
            this.directionY = new System.Windows.Forms.NumericUpDown();
            this.DirGroup.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.directionX)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.directionZ)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.directionY)).BeginInit();
            this.SuspendLayout();
            // 
            // DirGroup
            // 
            this.DirGroup.Controls.Add(this.label4);
            this.DirGroup.Controls.Add(this.label5);
            this.DirGroup.Controls.Add(this.label6);
            this.DirGroup.Controls.Add(this.directionX);
            this.DirGroup.Controls.Add(this.directionZ);
            this.DirGroup.Controls.Add(this.directionY);
            this.DirGroup.Location = new System.Drawing.Point(3, 3);
            this.DirGroup.Name = "DirGroup";
            this.DirGroup.Size = new System.Drawing.Size(211, 62);
            this.DirGroup.TabIndex = 2;
            this.DirGroup.TabStop = false;
            this.DirGroup.Text = "Направление";
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
            // directionX
            // 
            this.directionX.Location = new System.Drawing.Point(21, 28);
            this.directionX.Minimum = new decimal(new int[] {
            100,
            0,
            0,
            -2147483648});
            this.directionX.Name = "directionX";
            this.directionX.Size = new System.Drawing.Size(49, 20);
            this.directionX.TabIndex = 0;
            this.directionX.ValueChanged += new System.EventHandler(this.direction_ValueChanged);
            // 
            // directionZ
            // 
            this.directionZ.Location = new System.Drawing.Point(152, 28);
            this.directionZ.Minimum = new decimal(new int[] {
            100,
            0,
            0,
            -2147483648});
            this.directionZ.Name = "directionZ";
            this.directionZ.Size = new System.Drawing.Size(49, 20);
            this.directionZ.TabIndex = 0;
            this.directionZ.ValueChanged += new System.EventHandler(this.direction_ValueChanged);
            // 
            // directionY
            // 
            this.directionY.Location = new System.Drawing.Point(87, 28);
            this.directionY.Minimum = new decimal(new int[] {
            100,
            0,
            0,
            -2147483648});
            this.directionY.Name = "directionY";
            this.directionY.Size = new System.Drawing.Size(49, 20);
            this.directionY.TabIndex = 0;
            this.directionY.ValueChanged += new System.EventHandler(this.direction_ValueChanged);
            // 
            // DirectionControl
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.DirGroup);
            this.Name = "DirectionControl";
            this.Size = new System.Drawing.Size(219, 68);
            this.DirGroup.ResumeLayout(false);
            this.DirGroup.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.directionX)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.directionZ)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.directionY)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox DirGroup;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.NumericUpDown directionX;
        private System.Windows.Forms.NumericUpDown directionZ;
        private System.Windows.Forms.NumericUpDown directionY;
    }
}
