#include "pch.h"
#include "RoundThickLine.h"

#include "ShaderProgram.h"

RoundThickLine::RoundThickLine(const glm::vec2& pos1, const glm::vec2& pos2, float width, const glm::vec4& color, float resolution0, float resolution1) :
    ThickLine(pos1, pos2, width, color),
    cap0(pos1, width / 2.0f, color, std::numbers::pi, 32, getRotation() + 0.5f * std::numbers::pi),
    cap1(pos2, width / 2.0f, color, std::numbers::pi, 32, getRotation() + 1.5f * std::numbers::pi) {}

float RoundThickLine::getResolution0() const {
    return cap0.getResolution();
}

float RoundThickLine::getResolution1() const {
    return cap1.getResolution();
}

void RoundThickLine::setResolution0(float resolution0) {
    cap0.setResolution(resolution0);
}

void RoundThickLine::setResolution1(float resolution1) {
    cap1.setResolution(resolution1);
}

void RoundThickLine::draw(const ShaderProgram& shaderProgram) {
    ThickLine::draw(shaderProgram);
    cap0.draw(shaderProgram);
    cap1.draw(shaderProgram);
}