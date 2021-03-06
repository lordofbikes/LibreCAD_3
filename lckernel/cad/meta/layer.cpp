#include "layer.h"
#include "cad/functions/string_helper.h"
#include <cassert>

using namespace lc;

Layer::Layer() {
}

Layer::Layer(const std::string name, const MetaLineWidthByValue lineWidth, const Color color) : EntityMetaType(), DocumentMetaType(), _name(name), _lineWidth(lineWidth), _color(color) {
    assert(!StringHelper::isBlank(name) && "Name cannot be blank");
}

Layer::Layer(const std::string name, const MetaLineWidthByValue lineWidth) : EntityMetaType(), DocumentMetaType(), _name(name), _lineWidth(lineWidth) {
    assert(!StringHelper::isBlank(name) && "Name cannot be blank");
}

Layer::Layer(const std::string name, const Color color) : EntityMetaType(), DocumentMetaType(), _name(name), _color(color) {
    assert(!StringHelper::isBlank(name) && "Name cannot be blank"); // Name must be set
}

Color Layer::color() const {
    return _color;
}
MetaLineWidthByValue Layer::lineWidth() const {
    return _lineWidth;
}

const std::string Layer::name() const {
    return _name;
}

