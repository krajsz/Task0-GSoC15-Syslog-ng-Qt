#include "yaml_handler.h"

Yaml_Handler::Yaml_Handler(const std::string &base_node)
{
    m_base_node = YAML::LoadFile(base_node);
    if (m_base_node.size() && !m_base_node.IsNull())
    {
        m_is_loaded = true;
    }
    else m_is_loaded = false;
}

Yaml_Handler::~Yaml_Handler()
{

}

void Yaml_Handler::LoadAll()
{
    if (m_is_loaded)
    {
        for (size_t i = 0; i < m_base_node["shapes"].size(); i++)
        {
            Load(m_base_node["shapes"][i].as<std::string>());
        }
    }
    else
    {
        std::cout << "File not loaded!" << std::endl;
    }
}
void Yaml_Handler::Load(const std::string &shape_name)
{
    size_t base_node_size = m_base_node.size();

    if (!base_node_size)
    {
        std::cout << "Base node size is 0!" << std::endl;
    }
    else
    {
        YAML::Node shape_node =  m_base_node[shape_name];
        if (!shape_node.IsNull())
        {
            Shape* tmpshape = new Shape(shape_name);
            YAML::Node property_node = shape_node["properties"];
            if (!property_node.IsNull())
            {
                size_t property_node_size = property_node.size();

                for (size_t j = 0; j < property_node_size; j++)
                {
                    YAML::Node property = shape_node[property_node[j].as<std::string>()];

                    std::cout << property_node[j] << ": " <<  property.as<std::string>() << std::endl;

                    tmpshape->SetProperty(property_node[j].as<std::string>(),property );
                }
            }
            else
            {
                std::cout << "Property node is null!" << std::endl;
            }
            m_shapes.push_back(*tmpshape);
        }
        else
        {
            std::cout << "Shape node: " << shape_name << " is null!" << std::endl;
        }
    }
}

YAML::NodeType::value Yaml_Handler::getBaseNodeType() const
{
    return this->m_base_node.Type();
}

std::vector<Shape> Yaml_Handler::getShapes() const
{
    return this->m_shapes;
}

YAML::Node Yaml_Handler::getBaseNode() const
{
    return this->m_base_node;
}
