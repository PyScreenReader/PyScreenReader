#pragma once

#include <memory>
#include <string>

class VirtualWidget {
 public:
  std::string GetTitleText() const { return title_text_; }
  std::string GetHelpText() const { return help_text_; }
  int GetX() const { return x_; }
  int GetY() const { return y_; }
  int GetWidth() const { return width_; }
  int GetHeight() const { return height_; }
  bool IsVisible() const { return visible_; }
  std::shared_ptr<VirtualWidget> GetParent() const { return parent_.lock(); }

  void SetTitleText(const std::string& title_text) { title_text_ = title_text; }
  void SetHelpText(const std::string& help_text) { help_text_ = help_text; }
  void SetX(const int x_coord) { x_ = x_coord; }
  void SetY(const int y_coord) { y_ = y_coord; }
  void SetWidth(const int width) { width_ = width; }
  void SetHeight(const int height) { height_ = height; }
  void SetVisible(const bool visible) { visible_ = visible; }
  void SetParent(const std::shared_ptr<VirtualWidget>& parent) { parent_ = parent; }

  virtual void AddChild(const std::shared_ptr<VirtualWidget>& child) {}

  [[nodiscard]] virtual std::string GetRepr();
  [[nodiscard]] virtual bool IsClickable() = 0;
  [[nodiscard]] virtual std::string GetWidgetName() = 0;

  virtual ~VirtualWidget() = default;

 protected:
  std::string title_text_;
  std::string help_text_;
  int x_ = 0;
  int y_ = 0;
  int width_ = 0;
  int height_ = 0;
  bool visible_ = false;
  std::weak_ptr<VirtualWidget> parent_;
};
