#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include <vector>
#include <map>
#include "yaml-cpp/yaml.h"

/**
 * @brief The Shape class which stores datas (like name and properties) for the parsed shapes.
 */

class Shape
{
public:
    Shape(const std::string& _name);
    ~Shape();

    std::string getName() const;
    YAML::Node GetProperty(const std::string key);

    void SetProperty(const std::string& key, const YAML::Node& value);

private:

    std::map<std::string, YAML::Node> m_properties;
    std::string m_name;

};

#endif // SHAPE_H
