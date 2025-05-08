#pragma once

#include <string>
#include <memory>

class VirtualWidget {
protected:
    std::string title_text_;
    std::string help_text_;
    int x_;
    int y_;
    int width_;
    int height_;
    bool visible_;
    std::weak_ptr<VirtualWidget> parent_;

public:
    [[nodiscard]] std::string GetTitleText() const;
    [[nodiscard]] std::string GetHelpText() const;
    [[nodiscard]] int GetX() const;
    [[nodiscard]] int GetY() const;
    [[nodiscard]] int GetWidth() const;
    [[nodiscard]] int GetHeight() const;
    [[nodiscard]] bool IsVisible() const;
    [[nodiscard]] std::shared_ptr<VirtualWidget> GetParent() const;

    void SetTitleText(const std::string& title_text);
    void SetHelpText(const std::string& help_text);
    void SetX(int x);
    void SetY(int y);
    void SetWidth(int width);
    void SetHeight(int height);
    void SetVisible(bool visible);
    void SetParent(const std::shared_ptr<VirtualWidget>& parent);

    virtual void AddChild(const std::shared_ptr<VirtualWidget>& child) {}
    [[nodiscard]] virtual std::string GetRepr();
    [[nodiscard]] virtual bool IsClickable() = 0;
    [[nodiscard]] virtual std::string GetWidgetName() = 0;

    virtual ~VirtualWidget() = default;
};
