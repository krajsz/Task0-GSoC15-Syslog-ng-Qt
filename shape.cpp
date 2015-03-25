#include "shape.h"

Shape::Shape(const std::string &_name) : m_name(_name)
{
}

Shape::~Shape()
{
}

std::string Shape::getName() const
{
    return this->m_name;
}

void Shape::SetProperty(const std::string &_key, const YAML::Node &_value)
{
    this->m_properties[_key] = _value;
}

YAML::Node Shape::GetProperty(const std::string _key)
{
    return this->m_properties[_key];
}
