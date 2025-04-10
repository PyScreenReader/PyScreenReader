#pragma once

#include <string>
#include <memory>

class VirtualWidget {
protected:
    std::string titleText_;
    std::string helpText_;
    int x_;
    int y_;
    int width_;
    int height_;
    bool visible_;
    std::weak_ptr<VirtualWidget> parent_;

public:
    [[nodiscard]] std::string getTitleText() const;
    [[nodiscard]] std::string getHelpText() const;
    [[nodiscard]] int getX() const;
    [[nodiscard]] int getY() const;
    [[nodiscard]] int getWidth() const;
    [[nodiscard]] int getHeight() const;
    [[nodiscard]] bool isVisible() const;
    [[nodiscard]] std::shared_ptr<VirtualWidget> getParent() const;

    void setTitleText(const std::string& titleText);
    void setHelpText(const std::string& helpText);
    void setX(int x);
    void setY(int y);
    void setWidth(int width);
    void setHeight(int height);
    void setVisible(bool visible);
    void setParent(const std::shared_ptr<VirtualWidget>& parent);

    virtual void addChild(const std::shared_ptr<VirtualWidget>& child) {}
    [[nodiscard]] virtual std::string getRepr();
    [[nodiscard]] virtual bool isClickable() = 0;
    [[nodiscard]] virtual std::string getWidgetName() = 0;

    virtual ~VirtualWidget() = default;
};
