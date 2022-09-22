
namespace Gin.Controls
{
    partial class GridControl
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
            this.GridDensityField = new System.Windows.Forms.NumericUpDown();
            this.GridSizeField = new System.Windows.Forms.NumericUpDown();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            ((System.ComponentModel.ISupportInitialize)(this.GridDensityField)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.GridSizeField)).BeginInit();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // GridDensityField
            // 
            this.GridDensityField.Location = new System.Drawing.Point(73, 30);
            this.GridDensityField.Name = "GridDensityField";
            this.GridDensityField.Size = new System.Drawing.Size(120, 20);
            this.GridDensityField.TabIndex = 0;
            this.GridDensityField.ValueChanged += new System.EventHandler(this.GridDensityField_ValueChanged);
            // 
            // GridSizeField
            // 
            this.GridSizeField.Location = new System.Drawing.Point(73, 56);
            this.GridSizeField.Name = "GridSizeField";
            this.GridSizeField.Size = new System.Drawing.Size(120, 20);
            this.GridSizeField.TabIndex = 0;
            this.GridSizeField.ValueChanged += new System.EventHandler(this.GridSizeField_ValueChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(6, 32);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(61, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "Плотность";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(6, 58);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(46, 13);
            this.label2.TabIndex = 1;
            this.label2.Text = "Размер";
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.GridDensityField);
            this.groupBox1.Controls.Add(this.GridSizeField);
            this.groupBox1.Location = new System.Drawing.Point(3, 3);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(200, 100);
            this.groupBox1.TabIndex = 2;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Сетка";
            // 
            // GridControl
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.groupBox1);
            this.Name = "GridControl";
            this.Size = new System.Drawing.Size(208, 112);
            ((System.ComponentModel.ISupportInitialize)(this.GridDensityField)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.GridSizeField)).EndInit();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.NumericUpDown GridDensityField;
        private System.Windows.Forms.NumericUpDown GridSizeField;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.GroupBox groupBox1;
    }
}
