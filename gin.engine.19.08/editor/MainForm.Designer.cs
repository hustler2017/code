
namespace Gin
{
    partial class MainForm
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

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainForm));
            this.Canvas = new System.Windows.Forms.Panel();
            this.statusStrip1 = new System.Windows.Forms.StatusStrip();
            this.ResourcesPanel = new System.Windows.Forms.Panel();
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.TexturesWindow = new System.Windows.Forms.TabPage();
            this.ModelsWindow = new System.Windows.Forms.TabPage();
            this.NavigationPanel = new System.Windows.Forms.Panel();
            this.NavigationTabs = new System.Windows.Forms.TabControl();
            this.SceneObjectsPage = new System.Windows.Forms.TabPage();
            this.ObjectsExplorer = new System.Windows.Forms.TreeView();
            this.tabPage4 = new System.Windows.Forms.TabPage();
            this.SettingsPanel = new System.Windows.Forms.Panel();
            this.ObjectsPropertiesTabs = new System.Windows.Forms.TabControl();
            this.ObjectParameters = new System.Windows.Forms.TabPage();
            this.vScrollBar1 = new System.Windows.Forms.VScrollBar();
            this.tabPage6 = new System.Windows.Forms.TabPage();
            this.mainMenu = new System.Windows.Forms.MenuStrip();
            this.menuItemFile = new System.Windows.Forms.ToolStripMenuItem();
            this.menuItemFileCreate = new System.Windows.Forms.ToolStripMenuItem();
            this.menuItemFileOpen = new System.Windows.Forms.ToolStripMenuItem();
            this.menuItemFileSave = new System.Windows.Forms.ToolStripMenuItem();
            this.menuItemTools = new System.Windows.Forms.ToolStripMenuItem();
            this.dPainterToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuItemWindows = new System.Windows.Forms.ToolStripMenuItem();
            this.EmptyToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.пустоToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuItemSettings = new System.Windows.Forms.ToolStripMenuItem();
            this.пустоToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.menuItemModel = new System.Windows.Forms.ToolStripMenuItem();
            this.menuItemModel_Load = new System.Windows.Forms.ToolStripMenuItem();
            this.menuItemTexture = new System.Windows.Forms.ToolStripMenuItem();
            this.menuItemTexture_Load = new System.Windows.Forms.ToolStripMenuItem();
            this.panel2 = new System.Windows.Forms.Panel();
            this.toolStrip1 = new System.Windows.Forms.ToolStrip();
            this.toolStripSplitButton1 = new System.Windows.Forms.ToolStripSplitButton();
            this.пустоToolStripMenuItem2 = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripDropDownButton1 = new System.Windows.Forms.ToolStripDropDownButton();
            this.пустоToolStripMenuItem3 = new System.Windows.Forms.ToolStripMenuItem();
            this.пустоToolStripMenuItem4 = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.toolStripComboBox1 = new System.Windows.Forms.ToolStripComboBox();
            this.toolStripTextBox1 = new System.Windows.Forms.ToolStripTextBox();
            this.toolStripProgressBar2 = new System.Windows.Forms.ToolStripProgressBar();
            this.PlayModeButton = new System.Windows.Forms.ToolStripButton();
            this.toolStripButton2 = new System.Windows.Forms.ToolStripButton();
            this.toolStripButton3 = new System.Windows.Forms.ToolStripButton();
            this.toolStripButton4 = new System.Windows.Forms.ToolStripButton();
            this.toolStripSplitButton2 = new System.Windows.Forms.ToolStripSplitButton();
            this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.toolStripButton5 = new System.Windows.Forms.ToolStripButton();
            this.panel6 = new System.Windows.Forms.Panel();
            this.modelOpenDialog = new System.Windows.Forms.OpenFileDialog();
            this.saveFileDialog = new System.Windows.Forms.SaveFileDialog();
            this.icons = new System.Windows.Forms.ImageList(this.components);
            this.openTextureFileDialog = new System.Windows.Forms.OpenFileDialog();
            this.ResourcesPanel.SuspendLayout();
            this.tabControl1.SuspendLayout();
            this.NavigationPanel.SuspendLayout();
            this.NavigationTabs.SuspendLayout();
            this.SceneObjectsPage.SuspendLayout();
            this.SettingsPanel.SuspendLayout();
            this.ObjectsPropertiesTabs.SuspendLayout();
            this.ObjectParameters.SuspendLayout();
            this.mainMenu.SuspendLayout();
            this.panel2.SuspendLayout();
            this.toolStrip1.SuspendLayout();
            this.panel6.SuspendLayout();
            this.SuspendLayout();
            // 
            // Canvas
            // 
            this.Canvas.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.Canvas.Location = new System.Drawing.Point(0, 0);
            this.Canvas.Name = "Canvas";
            this.Canvas.Padding = new System.Windows.Forms.Padding(10);
            this.Canvas.Size = new System.Drawing.Size(1442, 745);
            this.Canvas.TabIndex = 0;
            this.Canvas.Enter += new System.EventHandler(this.Canvas_OnFocusEnter);
            this.Canvas.Leave += new System.EventHandler(this.Canvas_OnFocusLeave);
            this.Canvas.MouseDown += new System.Windows.Forms.MouseEventHandler(this.Canvas_MouseDown);
            this.Canvas.MouseEnter += new System.EventHandler(this.Canvas_MouseEnter);
            this.Canvas.MouseLeave += new System.EventHandler(this.Canvas_MouseLeave);
            this.Canvas.MouseHover += new System.EventHandler(this.Canvas_MouseHover);
            this.Canvas.MouseMove += new System.Windows.Forms.MouseEventHandler(this.Canvas_MouseMove);
            this.Canvas.MouseUp += new System.Windows.Forms.MouseEventHandler(this.Canvas_MouseUp);
            // 
            // statusStrip1
            // 
            this.statusStrip1.Location = new System.Drawing.Point(0, 977);
            this.statusStrip1.Name = "statusStrip1";
            this.statusStrip1.Size = new System.Drawing.Size(1902, 22);
            this.statusStrip1.TabIndex = 1;
            this.statusStrip1.Text = "statusStrip1";
            // 
            // ResourcesPanel
            // 
            this.ResourcesPanel.Controls.Add(this.tabControl1);
            this.ResourcesPanel.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.ResourcesPanel.Location = new System.Drawing.Point(0, 794);
            this.ResourcesPanel.Name = "ResourcesPanel";
            this.ResourcesPanel.Size = new System.Drawing.Size(1902, 183);
            this.ResourcesPanel.TabIndex = 4;
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.TexturesWindow);
            this.tabControl1.Controls.Add(this.ModelsWindow);
            this.tabControl1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tabControl1.Location = new System.Drawing.Point(0, 0);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(1902, 183);
            this.tabControl1.TabIndex = 0;
            // 
            // TexturesWindow
            // 
            this.TexturesWindow.Location = new System.Drawing.Point(4, 22);
            this.TexturesWindow.Name = "TexturesWindow";
            this.TexturesWindow.Padding = new System.Windows.Forms.Padding(3);
            this.TexturesWindow.Size = new System.Drawing.Size(1894, 157);
            this.TexturesWindow.TabIndex = 0;
            this.TexturesWindow.Text = "Текстуры";
            this.TexturesWindow.UseVisualStyleBackColor = true;
            // 
            // ModelsWindow
            // 
            this.ModelsWindow.Location = new System.Drawing.Point(4, 22);
            this.ModelsWindow.Name = "ModelsWindow";
            this.ModelsWindow.Padding = new System.Windows.Forms.Padding(3);
            this.ModelsWindow.Size = new System.Drawing.Size(1894, 157);
            this.ModelsWindow.TabIndex = 1;
            this.ModelsWindow.Text = "Модели";
            this.ModelsWindow.UseVisualStyleBackColor = true;
            // 
            // NavigationPanel
            // 
            this.NavigationPanel.Controls.Add(this.NavigationTabs);
            this.NavigationPanel.Dock = System.Windows.Forms.DockStyle.Left;
            this.NavigationPanel.Location = new System.Drawing.Point(0, 49);
            this.NavigationPanel.Name = "NavigationPanel";
            this.NavigationPanel.Size = new System.Drawing.Size(216, 745);
            this.NavigationPanel.TabIndex = 5;
            // 
            // NavigationTabs
            // 
            this.NavigationTabs.Controls.Add(this.SceneObjectsPage);
            this.NavigationTabs.Controls.Add(this.tabPage4);
            this.NavigationTabs.Dock = System.Windows.Forms.DockStyle.Fill;
            this.NavigationTabs.Location = new System.Drawing.Point(0, 0);
            this.NavigationTabs.Name = "NavigationTabs";
            this.NavigationTabs.SelectedIndex = 0;
            this.NavigationTabs.Size = new System.Drawing.Size(216, 745);
            this.NavigationTabs.TabIndex = 0;
            // 
            // SceneObjectsPage
            // 
            this.SceneObjectsPage.Controls.Add(this.ObjectsExplorer);
            this.SceneObjectsPage.Location = new System.Drawing.Point(4, 22);
            this.SceneObjectsPage.Name = "SceneObjectsPage";
            this.SceneObjectsPage.Padding = new System.Windows.Forms.Padding(3);
            this.SceneObjectsPage.Size = new System.Drawing.Size(208, 719);
            this.SceneObjectsPage.TabIndex = 0;
            this.SceneObjectsPage.Text = "Объекты сцены";
            this.SceneObjectsPage.UseVisualStyleBackColor = true;
            // 
            // ObjectsExplorer
            // 
            this.ObjectsExplorer.Dock = System.Windows.Forms.DockStyle.Fill;
            this.ObjectsExplorer.Location = new System.Drawing.Point(3, 3);
            this.ObjectsExplorer.Name = "ObjectsExplorer";
            this.ObjectsExplorer.Size = new System.Drawing.Size(202, 713);
            this.ObjectsExplorer.TabIndex = 0;
            this.ObjectsExplorer.AfterSelect += new System.Windows.Forms.TreeViewEventHandler(this.ObjectsExplorer_AfterSelect);
            // 
            // tabPage4
            // 
            this.tabPage4.Location = new System.Drawing.Point(4, 22);
            this.tabPage4.Name = "tabPage4";
            this.tabPage4.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage4.Size = new System.Drawing.Size(208, 719);
            this.tabPage4.TabIndex = 1;
            this.tabPage4.Text = "tabPage4";
            this.tabPage4.UseVisualStyleBackColor = true;
            // 
            // SettingsPanel
            // 
            this.SettingsPanel.Controls.Add(this.ObjectsPropertiesTabs);
            this.SettingsPanel.Dock = System.Windows.Forms.DockStyle.Right;
            this.SettingsPanel.Location = new System.Drawing.Point(1664, 49);
            this.SettingsPanel.Name = "SettingsPanel";
            this.SettingsPanel.Size = new System.Drawing.Size(238, 745);
            this.SettingsPanel.TabIndex = 6;
            // 
            // ObjectsPropertiesTabs
            // 
            this.ObjectsPropertiesTabs.Controls.Add(this.ObjectParameters);
            this.ObjectsPropertiesTabs.Controls.Add(this.tabPage6);
            this.ObjectsPropertiesTabs.Dock = System.Windows.Forms.DockStyle.Fill;
            this.ObjectsPropertiesTabs.Location = new System.Drawing.Point(0, 0);
            this.ObjectsPropertiesTabs.Name = "ObjectsPropertiesTabs";
            this.ObjectsPropertiesTabs.SelectedIndex = 0;
            this.ObjectsPropertiesTabs.Size = new System.Drawing.Size(238, 745);
            this.ObjectsPropertiesTabs.TabIndex = 0;
            // 
            // ObjectParameters
            // 
            this.ObjectParameters.Controls.Add(this.vScrollBar1);
            this.ObjectParameters.Location = new System.Drawing.Point(4, 22);
            this.ObjectParameters.Name = "ObjectParameters";
            this.ObjectParameters.Padding = new System.Windows.Forms.Padding(3);
            this.ObjectParameters.Size = new System.Drawing.Size(230, 719);
            this.ObjectParameters.TabIndex = 0;
            this.ObjectParameters.Text = "Параметры объекта";
            this.ObjectParameters.UseVisualStyleBackColor = true;
            // 
            // vScrollBar1
            // 
            this.vScrollBar1.Dock = System.Windows.Forms.DockStyle.Right;
            this.vScrollBar1.Location = new System.Drawing.Point(210, 3);
            this.vScrollBar1.Name = "vScrollBar1";
            this.vScrollBar1.Size = new System.Drawing.Size(17, 713);
            this.vScrollBar1.TabIndex = 3;
            // 
            // tabPage6
            // 
            this.tabPage6.Location = new System.Drawing.Point(4, 22);
            this.tabPage6.Name = "tabPage6";
            this.tabPage6.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage6.Size = new System.Drawing.Size(230, 719);
            this.tabPage6.TabIndex = 1;
            this.tabPage6.Text = "tabPage6";
            this.tabPage6.UseVisualStyleBackColor = true;
            // 
            // mainMenu
            // 
            this.mainMenu.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.menuItemFile,
            this.menuItemTools,
            this.menuItemWindows,
            this.menuItemSettings,
            this.menuItemModel,
            this.menuItemTexture});
            this.mainMenu.Location = new System.Drawing.Point(0, 0);
            this.mainMenu.Name = "mainMenu";
            this.mainMenu.Size = new System.Drawing.Size(1902, 24);
            this.mainMenu.TabIndex = 7;
            this.mainMenu.Text = "menuStrip1";
            // 
            // menuItemFile
            // 
            this.menuItemFile.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.menuItemFileCreate,
            this.menuItemFileOpen,
            this.menuItemFileSave});
            this.menuItemFile.Name = "menuItemFile";
            this.menuItemFile.Size = new System.Drawing.Size(48, 20);
            this.menuItemFile.Text = "Файл";
            // 
            // menuItemFileCreate
            // 
            this.menuItemFileCreate.Name = "menuItemFileCreate";
            this.menuItemFileCreate.Size = new System.Drawing.Size(133, 22);
            this.menuItemFileCreate.Text = "Создать";
            // 
            // menuItemFileOpen
            // 
            this.menuItemFileOpen.Name = "menuItemFileOpen";
            this.menuItemFileOpen.Size = new System.Drawing.Size(133, 22);
            this.menuItemFileOpen.Text = "Открыть";
            // 
            // menuItemFileSave
            // 
            this.menuItemFileSave.Name = "menuItemFileSave";
            this.menuItemFileSave.Size = new System.Drawing.Size(133, 22);
            this.menuItemFileSave.Text = "Сохранить";
            // 
            // menuItemTools
            // 
            this.menuItemTools.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.dPainterToolStripMenuItem});
            this.menuItemTools.Name = "menuItemTools";
            this.menuItemTools.Size = new System.Drawing.Size(95, 20);
            this.menuItemTools.Text = "Инструменты";
            // 
            // dPainterToolStripMenuItem
            // 
            this.dPainterToolStripMenuItem.Name = "dPainterToolStripMenuItem";
            this.dPainterToolStripMenuItem.Size = new System.Drawing.Size(125, 22);
            this.dPainterToolStripMenuItem.Text = "3DPainter";
            // 
            // menuItemWindows
            // 
            this.menuItemWindows.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.EmptyToolStripMenuItem,
            this.пустоToolStripMenuItem});
            this.menuItemWindows.Name = "menuItemWindows";
            this.menuItemWindows.Size = new System.Drawing.Size(47, 20);
            this.menuItemWindows.Text = "Окна";
            // 
            // EmptyToolStripMenuItem
            // 
            this.EmptyToolStripMenuItem.Name = "EmptyToolStripMenuItem";
            this.EmptyToolStripMenuItem.Size = new System.Drawing.Size(107, 22);
            this.EmptyToolStripMenuItem.Text = "Пусто";
            this.EmptyToolStripMenuItem.Click += new System.EventHandler(this.пустоъToolStripMenuItem_Click);
            // 
            // пустоToolStripMenuItem
            // 
            this.пустоToolStripMenuItem.Name = "пустоToolStripMenuItem";
            this.пустоToolStripMenuItem.Size = new System.Drawing.Size(107, 22);
            this.пустоToolStripMenuItem.Text = "Пусто";
            // 
            // menuItemSettings
            // 
            this.menuItemSettings.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.пустоToolStripMenuItem1});
            this.menuItemSettings.Name = "menuItemSettings";
            this.menuItemSettings.Size = new System.Drawing.Size(79, 20);
            this.menuItemSettings.Text = "Настройки";
            // 
            // пустоToolStripMenuItem1
            // 
            this.пустоToolStripMenuItem1.Name = "пустоToolStripMenuItem1";
            this.пустоToolStripMenuItem1.Size = new System.Drawing.Size(107, 22);
            this.пустоToolStripMenuItem1.Text = "Пусто";
            // 
            // menuItemModel
            // 
            this.menuItemModel.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.menuItemModel_Load});
            this.menuItemModel.Name = "menuItemModel";
            this.menuItemModel.Size = new System.Drawing.Size(62, 20);
            this.menuItemModel.Text = "Модель";
            // 
            // menuItemModel_Load
            // 
            this.menuItemModel_Load.Name = "menuItemModel_Load";
            this.menuItemModel_Load.Size = new System.Drawing.Size(128, 22);
            this.menuItemModel_Load.Text = "Загрузить";
            this.menuItemModel_Load.Click += new System.EventHandler(this.menuItemModel_Load_Click);
            // 
            // menuItemTexture
            // 
            this.menuItemTexture.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.menuItemTexture_Load});
            this.menuItemTexture.Name = "menuItemTexture";
            this.menuItemTexture.Size = new System.Drawing.Size(67, 20);
            this.menuItemTexture.Text = "Текстура";
            // 
            // menuItemTexture_Load
            // 
            this.menuItemTexture_Load.Name = "menuItemTexture_Load";
            this.menuItemTexture_Load.Size = new System.Drawing.Size(128, 22);
            this.menuItemTexture_Load.Text = "Загрузить";
            // 
            // panel2
            // 
            this.panel2.AutoSize = true;
            this.panel2.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panel2.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.panel2.Controls.Add(this.toolStrip1);
            this.panel2.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel2.Location = new System.Drawing.Point(0, 24);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(1902, 25);
            this.panel2.TabIndex = 2;
            // 
            // toolStrip1
            // 
            this.toolStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripSplitButton1,
            this.toolStripDropDownButton1,
            this.toolStripSeparator1,
            this.toolStripComboBox1,
            this.toolStripTextBox1,
            this.toolStripProgressBar2,
            this.PlayModeButton,
            this.toolStripButton2,
            this.toolStripButton3,
            this.toolStripButton4,
            this.toolStripSplitButton2,
            this.toolStripSeparator2,
            this.toolStripButton5});
            this.toolStrip1.Location = new System.Drawing.Point(0, 0);
            this.toolStrip1.Name = "toolStrip1";
            this.toolStrip1.Size = new System.Drawing.Size(1902, 25);
            this.toolStrip1.TabIndex = 0;
            this.toolStrip1.Text = "toolStrip1";
            // 
            // toolStripSplitButton1
            // 
            this.toolStripSplitButton1.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripSplitButton1.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.пустоToolStripMenuItem2});
            this.toolStripSplitButton1.Image = ((System.Drawing.Image)(resources.GetObject("toolStripSplitButton1.Image")));
            this.toolStripSplitButton1.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripSplitButton1.Name = "toolStripSplitButton1";
            this.toolStripSplitButton1.Size = new System.Drawing.Size(32, 22);
            this.toolStripSplitButton1.Text = "toolStripSplitButton1";
            // 
            // пустоToolStripMenuItem2
            // 
            this.пустоToolStripMenuItem2.Name = "пустоToolStripMenuItem2";
            this.пустоToolStripMenuItem2.Size = new System.Drawing.Size(107, 22);
            this.пустоToolStripMenuItem2.Text = "Пусто";
            // 
            // toolStripDropDownButton1
            // 
            this.toolStripDropDownButton1.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripDropDownButton1.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.пустоToolStripMenuItem3,
            this.пустоToolStripMenuItem4});
            this.toolStripDropDownButton1.Image = ((System.Drawing.Image)(resources.GetObject("toolStripDropDownButton1.Image")));
            this.toolStripDropDownButton1.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripDropDownButton1.Name = "toolStripDropDownButton1";
            this.toolStripDropDownButton1.Size = new System.Drawing.Size(29, 22);
            this.toolStripDropDownButton1.Text = "toolStripDropDownButton1";
            // 
            // пустоToolStripMenuItem3
            // 
            this.пустоToolStripMenuItem3.Name = "пустоToolStripMenuItem3";
            this.пустоToolStripMenuItem3.Size = new System.Drawing.Size(107, 22);
            this.пустоToolStripMenuItem3.Text = "Пусто";
            // 
            // пустоToolStripMenuItem4
            // 
            this.пустоToolStripMenuItem4.Name = "пустоToolStripMenuItem4";
            this.пустоToolStripMenuItem4.Size = new System.Drawing.Size(107, 22);
            this.пустоToolStripMenuItem4.Text = "Пусто";
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(6, 25);
            // 
            // toolStripComboBox1
            // 
            this.toolStripComboBox1.Name = "toolStripComboBox1";
            this.toolStripComboBox1.Size = new System.Drawing.Size(121, 25);
            this.toolStripComboBox1.Click += new System.EventHandler(this.toolStripComboBox1_Click);
            // 
            // toolStripTextBox1
            // 
            this.toolStripTextBox1.Font = new System.Drawing.Font("Segoe UI", 9F);
            this.toolStripTextBox1.Name = "toolStripTextBox1";
            this.toolStripTextBox1.Size = new System.Drawing.Size(100, 25);
            // 
            // toolStripProgressBar2
            // 
            this.toolStripProgressBar2.Name = "toolStripProgressBar2";
            this.toolStripProgressBar2.Size = new System.Drawing.Size(100, 22);
            // 
            // PlayModeButton
            // 
            this.PlayModeButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.PlayModeButton.Image = global::Gin.Properties.Resources.play;
            this.PlayModeButton.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.PlayModeButton.Name = "PlayModeButton";
            this.PlayModeButton.Size = new System.Drawing.Size(23, 22);
            this.PlayModeButton.Text = "toolStripButton1";
            this.PlayModeButton.Click += new System.EventHandler(this.playModeButton_Click);
            // 
            // toolStripButton2
            // 
            this.toolStripButton2.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButton2.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButton2.Image")));
            this.toolStripButton2.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton2.Name = "toolStripButton2";
            this.toolStripButton2.Size = new System.Drawing.Size(23, 22);
            this.toolStripButton2.Text = "toolStripButton2";
            // 
            // toolStripButton3
            // 
            this.toolStripButton3.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButton3.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButton3.Image")));
            this.toolStripButton3.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton3.Name = "toolStripButton3";
            this.toolStripButton3.Size = new System.Drawing.Size(23, 22);
            this.toolStripButton3.Text = "toolStripButton3";
            // 
            // toolStripButton4
            // 
            this.toolStripButton4.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButton4.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButton4.Image")));
            this.toolStripButton4.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton4.Name = "toolStripButton4";
            this.toolStripButton4.Size = new System.Drawing.Size(23, 22);
            this.toolStripButton4.Text = "toolStripButton4";
            // 
            // toolStripSplitButton2
            // 
            this.toolStripSplitButton2.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripSplitButton2.Image = ((System.Drawing.Image)(resources.GetObject("toolStripSplitButton2.Image")));
            this.toolStripSplitButton2.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripSplitButton2.Name = "toolStripSplitButton2";
            this.toolStripSplitButton2.Size = new System.Drawing.Size(32, 22);
            this.toolStripSplitButton2.Text = "toolStripSplitButton2";
            // 
            // toolStripSeparator2
            // 
            this.toolStripSeparator2.Name = "toolStripSeparator2";
            this.toolStripSeparator2.Size = new System.Drawing.Size(6, 25);
            // 
            // toolStripButton5
            // 
            this.toolStripButton5.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButton5.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButton5.Image")));
            this.toolStripButton5.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton5.Name = "toolStripButton5";
            this.toolStripButton5.Size = new System.Drawing.Size(23, 22);
            this.toolStripButton5.Text = "toolStripButton5";
            // 
            // panel6
            // 
            this.panel6.Controls.Add(this.Canvas);
            this.panel6.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panel6.Location = new System.Drawing.Point(216, 49);
            this.panel6.Name = "panel6";
            this.panel6.Size = new System.Drawing.Size(1448, 745);
            this.panel6.TabIndex = 8;
            // 
            // modelOpenDialog
            // 
            this.modelOpenDialog.Filter = "Fbx files | *.fbx";
            this.modelOpenDialog.InitialDirectory = "d:\\work\\projects\\warzone\\source\\Warzone\\data\\models\\";
            // 
            // icons
            // 
            this.icons.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("icons.ImageStream")));
            this.icons.TransparentColor = System.Drawing.Color.Transparent;
            this.icons.Images.SetKeyName(0, "icon_box.png");
            this.icons.Images.SetKeyName(1, "icon_camera.png");
            this.icons.Images.SetKeyName(2, "icon_folder.png");
            this.icons.Images.SetKeyName(3, "icon_gear.png");
            this.icons.Images.SetKeyName(4, "icon_grid.png");
            this.icons.Images.SetKeyName(5, "icon_lamp.png");
            this.icons.Images.SetKeyName(6, "icon_layers.png");
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1902, 999);
            this.Controls.Add(this.panel6);
            this.Controls.Add(this.SettingsPanel);
            this.Controls.Add(this.NavigationPanel);
            this.Controls.Add(this.ResourcesPanel);
            this.Controls.Add(this.panel2);
            this.Controls.Add(this.statusStrip1);
            this.Controls.Add(this.mainMenu);
            this.MainMenuStrip = this.mainMenu;
            this.MaximumSize = new System.Drawing.Size(1920, 1080);
            this.MinimumSize = new System.Drawing.Size(1918, 1038);
            this.Name = "MainForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "MainForm";
            this.WindowState = System.Windows.Forms.FormWindowState.Maximized;
            this.Load += new System.EventHandler(this.Form1_Load);
            this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.Form1_KeyDown);
            this.MouseMove += new System.Windows.Forms.MouseEventHandler(this.Form1_MouseMove);
            this.ResourcesPanel.ResumeLayout(false);
            this.tabControl1.ResumeLayout(false);
            this.NavigationPanel.ResumeLayout(false);
            this.NavigationTabs.ResumeLayout(false);
            this.SceneObjectsPage.ResumeLayout(false);
            this.SettingsPanel.ResumeLayout(false);
            this.ObjectsPropertiesTabs.ResumeLayout(false);
            this.ObjectParameters.ResumeLayout(false);
            this.mainMenu.ResumeLayout(false);
            this.mainMenu.PerformLayout();
            this.panel2.ResumeLayout(false);
            this.panel2.PerformLayout();
            this.toolStrip1.ResumeLayout(false);
            this.toolStrip1.PerformLayout();
            this.panel6.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        public System.Windows.Forms.Panel Canvas;
        private System.Windows.Forms.StatusStrip statusStrip1;
        private System.Windows.Forms.Panel ResourcesPanel;
        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage TexturesWindow;
        private System.Windows.Forms.TabPage ModelsWindow;
        private System.Windows.Forms.Panel NavigationPanel;
        private System.Windows.Forms.TabControl NavigationTabs;
        private System.Windows.Forms.TabPage SceneObjectsPage;
        private System.Windows.Forms.TabPage tabPage4;
        private System.Windows.Forms.Panel SettingsPanel;
        private System.Windows.Forms.TabControl ObjectsPropertiesTabs;
        private System.Windows.Forms.TabPage ObjectParameters;
        private System.Windows.Forms.TabPage tabPage6;
        private System.Windows.Forms.MenuStrip mainMenu;
        private System.Windows.Forms.ToolStripMenuItem menuItemFile;
        private System.Windows.Forms.ToolStripMenuItem menuItemFileCreate;
        private System.Windows.Forms.ToolStripMenuItem menuItemFileOpen;
        private System.Windows.Forms.ToolStripMenuItem menuItemFileSave;
        private System.Windows.Forms.ToolStripMenuItem menuItemWindows;
        private System.Windows.Forms.ToolStripMenuItem EmptyToolStripMenuItem;
        private System.Windows.Forms.TreeView ObjectsExplorer;
        private System.Windows.Forms.ToolStripMenuItem menuItemTools;
        private System.Windows.Forms.ToolStripMenuItem dPainterToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem пустоToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem menuItemSettings;
        private System.Windows.Forms.ToolStripMenuItem пустоToolStripMenuItem1;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.ToolStrip toolStrip1;
        private System.Windows.Forms.ToolStripSplitButton toolStripSplitButton1;
        private System.Windows.Forms.ToolStripMenuItem пустоToolStripMenuItem2;
        private System.Windows.Forms.ToolStripDropDownButton toolStripDropDownButton1;
        private System.Windows.Forms.ToolStripMenuItem пустоToolStripMenuItem3;
        private System.Windows.Forms.ToolStripMenuItem пустоToolStripMenuItem4;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.Windows.Forms.ToolStripComboBox toolStripComboBox1;
        private System.Windows.Forms.ToolStripTextBox toolStripTextBox1;
        private System.Windows.Forms.ToolStripProgressBar toolStripProgressBar2;
        private System.Windows.Forms.ToolStripButton PlayModeButton;
        private System.Windows.Forms.ToolStripButton toolStripButton2;
        private System.Windows.Forms.ToolStripButton toolStripButton3;
        private System.Windows.Forms.Panel panel6;
        private System.Windows.Forms.VScrollBar vScrollBar1;
        private System.Windows.Forms.OpenFileDialog modelOpenDialog;
        private System.Windows.Forms.SaveFileDialog saveFileDialog;
        private System.Windows.Forms.ImageList icons;
        private System.Windows.Forms.ToolStripMenuItem menuItemModel;
        private System.Windows.Forms.ToolStripMenuItem menuItemModel_Load;
        private System.Windows.Forms.ToolStripMenuItem menuItemTexture;
        private System.Windows.Forms.ToolStripMenuItem menuItemTexture_Load;
        private System.Windows.Forms.OpenFileDialog openTextureFileDialog;
        private System.Windows.Forms.ToolStripButton toolStripButton4;
        private System.Windows.Forms.ToolStripSplitButton toolStripSplitButton2;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator2;
        private System.Windows.Forms.ToolStripButton toolStripButton5;
    }
}

