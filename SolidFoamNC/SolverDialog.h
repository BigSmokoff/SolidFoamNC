#pragma once
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

class SolverDialog : public QDialog {
public:
	SolverDialog(QWidget* parent = nullptr) : QDialog(parent) {
		setWindowTitle("Настройки решателя solidDisplacementFoam");
		resize(400, 300);

		auto layout = new QVBoxLayout(this);
		layout->addWidget(new QLabel("Введите параметры материалов и нагрузок:", this));

		auto btnRun = new QPushButton("Сгенерировать сетку и рассчитать", this);
		layout->addWidget(btnRun);

		connect(btnRun, &QPushButton::clicked, this, &QDialog::accept);
	}
};