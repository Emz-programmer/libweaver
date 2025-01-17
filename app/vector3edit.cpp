#include "vector3edit.h"

#include <float.h>
#include <QHBoxLayout>
#include <QLabel>

Vector3Edit::Vector3Edit(QWidget *parent) :
  QWidget{parent}
{
  auto layout = new QHBoxLayout(this);

  layout->addWidget(new QLabel(tr("X")));

  x_edit_ = new QDoubleSpinBox();
  x_edit_->setMinimum(DBL_MIN);
  x_edit_->setMaximum(DBL_MAX);
  layout->addWidget(x_edit_);
  connect(x_edit_, static_cast<void(QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), this, &Vector3Edit::internalChanged);

  layout->addStretch();

  layout->addWidget(new QLabel(tr("Y")));

  y_edit_ = new QDoubleSpinBox();
  y_edit_->setMinimum(DBL_MIN);
  y_edit_->setMaximum(DBL_MAX);
  layout->addWidget(y_edit_);
  connect(y_edit_, static_cast<void(QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), this, &Vector3Edit::internalChanged);

  layout->addStretch();

  layout->addWidget(new QLabel(tr("Z")));

  z_edit_ = new QDoubleSpinBox();
  z_edit_->setMinimum(DBL_MIN);
  z_edit_->setMaximum(DBL_MAX);
  layout->addWidget(z_edit_);
  connect(z_edit_, static_cast<void(QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), this, &Vector3Edit::internalChanged);
}

si::Vector3 Vector3Edit::GetValue() const
{
  return si::Vector3(x_edit_->value(), y_edit_->value(), z_edit_->value());
}

void Vector3Edit::SetValue(const si::Vector3 &xyz)
{
  x_edit_->blockSignals(true);
  y_edit_->blockSignals(true);
  z_edit_->blockSignals(true);

  x_edit_->setValue(xyz.x);
  y_edit_->setValue(xyz.y);
  z_edit_->setValue(xyz.z);

  x_edit_->blockSignals(false);
  y_edit_->blockSignals(false);
  z_edit_->blockSignals(false);
}

void Vector3Edit::internalChanged()
{
  emit changed(si::Vector3(x_edit_->value(), y_edit_->value(), z_edit_->value()));
}
