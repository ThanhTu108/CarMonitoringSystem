#include "gauge_config.h"

GaugeConfig::GaugeConfig(double min_value, double max_value, double step,
                         const QString& title, const QString& unit)
    : min_value(min_value),
      max_value(max_value),
      step(step),
      m_title(title),
      m_unit(unit) {
}

// getter
double GaugeConfig::get_minvalue() const {
    return this->min_value;
}
double GaugeConfig::get_maxvalue() const {
    return this->max_value;
}
double GaugeConfig::get_step() const {
    return this->step;
}
const QString& GaugeConfig::title() const {
    return this->m_title;
}
const QString& GaugeConfig::unit() const {
    return this->m_unit;
}

// setter
void GaugeConfig::set_minvalue(double value) {
    this->min_value = value;
}
void GaugeConfig::set_maxvalue(double value) {
    this->max_value = value;
}
void GaugeConfig::set_step(double value) {
    this->step = step;
}

void GaugeConfig::set_title(const QString& title) {
    this->m_title = title;
}
void GaugeConfig::set_unit(const QString& unit) {
    this->m_unit = unit;
}
