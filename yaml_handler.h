#ifndef YAML_HANDLER_H
#define YAML_HANDLER_H

#include "shape.h"

/**
 * @brief The Yaml_Handler class parses the input YAML file, and stores the shapes into a vector.
 */

class Yaml_Handler
{
public:
    Yaml_Handler(const std::string &base_node);
    ~Yaml_Handler();

    void Load(const std::string &shape_name);
    void LoadAll();

    YAML::Node getBaseNode() const;
    YAML::NodeType::value getBaseNodeType() const;
    std::vector<Shape> getShapes() const;

private:

    std::vector<Shape> m_shapes;
    bool m_is_loaded = false;

    YAML::Node m_base_node;
};

#endif // YAML_HANDLER_H
