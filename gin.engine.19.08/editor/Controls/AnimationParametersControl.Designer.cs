
namespace Gin.Controls
{
    partial class AnimationParametersControl
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
            this.AddAnimationButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // AddAnimationButton
            // 
            this.AddAnimationButton.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.AddAnimationButton.Location = new System.Drawing.Point(0, 107);
            this.AddAnimationButton.Name = "AddAnimationButton";
            this.AddAnimationButton.Size = new System.Drawing.Size(203, 55);
            this.AddAnimationButton.TabIndex = 0;
            this.AddAnimationButton.Text = "Добавить анимацию";
            this.AddAnimationButton.UseVisualStyleBackColor = true;
            this.AddAnimationButton.Click += new System.EventHandler(this.AddAnimationButton_Click);
            // 
            // AnimationParametersControl
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSize = true;
            this.Controls.Add(this.AddAnimationButton);
            this.Name = "AnimationParametersControl";
            this.Size = new System.Drawing.Size(203, 162);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button AddAnimationButton;
    }
}
