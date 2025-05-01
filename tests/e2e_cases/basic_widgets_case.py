import sys
from PySide6.QtWidgets import (
    QApplication, QWidget, QPushButton, QLabel, QLineEdit, QTextEdit,
    QCheckBox, QRadioButton, QComboBox, QSlider, QProgressBar,
    QDateEdit, QTableWidget, QTableWidgetItem, QTreeWidget, QTreeWidgetItem,
    QVBoxLayout, QSpinBox
)
from PySide6.QtCore import Qt, QDate

class BasicWidgetsCase(QWidget):
    """
    This is a test case contains basic UI widgets:
        - Button
        - Text Inputs
        - Check Boxes
        - Radio Buttons
        - Combo Boxes
        - Slider
        - Progress Bar
        - Date Selector
        - Spin Box
        - Table
        - Tree View
    """
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Demo Title")
        self.setMinimumSize(600, 600)

        layout = QVBoxLayout()

        # Buttons
        layout.addWidget(QLabel("Buttons:"))
        btn = QPushButton("Click Me")
        layout.addWidget(btn)

        # Text inputs
        layout.addWidget(QLabel("Single-line Text:"))
        line_edit = QLineEdit()
        layout.addWidget(line_edit)

        layout.addWidget(QLabel("Multi-line Text:"))
        text_edit = QTextEdit()
        layout.addWidget(text_edit)

        # Checkboxes and Radio buttons
        check_box = QCheckBox("Check me")
        radio_btn1 = QRadioButton("Option A")
        radio_btn2 = QRadioButton("Option B")
        layout.addWidget(check_box)
        layout.addWidget(radio_btn1)
        layout.addWidget(radio_btn2)

        # Combo box (dropdown)
        combo = QComboBox()
        combo.addItems(["Item 1", "Item 2", "Item 3"])
        layout.addWidget(QLabel("Dropdown (ComboBox):"))
        layout.addWidget(combo)

        # Slider
        slider = QSlider(Qt.Horizontal)
        slider.setRange(0, 100)
        layout.addWidget(QLabel("Slider:"))
        layout.addWidget(slider)

        # Progress bar
        progress = QProgressBar()
        progress.setValue(50)
        layout.addWidget(QLabel("Progress Bar:"))
        layout.addWidget(progress)

        # Date selector
        date_edit = QDateEdit()
        date_edit.setDate(QDate.currentDate())
        layout.addWidget(QLabel("Date Picker:"))
        layout.addWidget(date_edit)

        # Spin box
        spin_box = QSpinBox()
        spin_box.setRange(0, 10)
        layout.addWidget(QLabel("Spin Box:"))
        layout.addWidget(spin_box)

        # Table
        table = QTableWidget(2, 2)
        table.setHorizontalHeaderLabels(["Column 1", "Column 2"])
        table.setItem(0, 0, QTableWidgetItem("A"))
        table.setItem(0, 1, QTableWidgetItem("B"))
        layout.addWidget(QLabel("Table:"))
        layout.addWidget(table)

        # Tree view
        tree = QTreeWidget()
        tree.setHeaderLabels(["Tree"])
        parent = QTreeWidgetItem(tree, ["Parent"])
        QTreeWidgetItem(parent, ["Child 1"])
        QTreeWidgetItem(parent, ["Child 2"])
        layout.addWidget(QLabel("Tree View:"))
        layout.addWidget(tree)

        self.setLayout(layout)

if __name__ == "__main__":
    app = QApplication(sys.argv)
    demo = BasicWidgetsCase()
    demo.show()
    sys.exit(app.exec_())
