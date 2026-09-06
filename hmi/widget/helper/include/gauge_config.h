#pragma once

#include <QString>

class GaugeConfig {
public:
    ~GaugeConfig() = default;
    GaugeConfig() = default;

    GaugeConfig(double min_value, double max_value, double step,
                const QString& title, const QString& unit);

    // getter
    double get_minvalue() const;
    double get_maxvalue() const;
    double get_step() const;
    const QString& title() const;
    const QString& unit() const;

    // setter
    void set_minvalue(double value);
    void set_maxvalue(double value);
    void set_step(double value);

    void set_title(const QString& title);
    void set_unit(const QString& unit);

private:
    double min_value;
    double max_value;
    double step;
    QString m_title;
    QString m_unit;
};
