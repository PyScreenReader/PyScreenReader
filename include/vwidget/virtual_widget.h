#pragma once

#include <memory>
#include <string>

class VirtualWidget {
 public:
//  Getters
  std::string GetTitleText() const { return title_text_; }
  std::string GetHelpText() const { return help_text_; }
  std::string GetNativeName() const { return native_name_; }
  std::string GetWidgetName() const { return widget_name_; }
  int GetX() const { return x_; }
  int GetY() const { return y_; }
  int GetWidth() const { return width_; }
  int GetHeight() const { return height_; }
  bool IsVisible() const { return is_visible_; }
  bool IsFocused() const { return is_focused_; }
  bool IsClickable() const { return is_clickable_; }
  std::shared_ptr<VirtualWidget> GetParent() const { return parent_.lock(); }

//  Setters
  void SetTitleText(const std::string& title_text) { title_text_ = title_text; }
  void SetHelpText(const std::string& help_text) { help_text_ = help_text; }
  void SetNativeName(const std::string& native_name) { native_name_ = native_name; }
  void SetX(const int x_coord) { x_ = x_coord; }
  void SetY(const int y_coord) { y_ = y_coord; }
  void SetWidth(const int width) { width_ = width; }
  void SetHeight(const int height) { height_ = height; }
  void SetVisible(const bool visible) { is_visible_ = visible; }
  void SetFocused(const bool focused) { is_focused_ = focused; }
  void SetClickable(const bool clickable) { is_clickable_ = clickable; }
  void SetParent(const std::shared_ptr<VirtualWidget>& parent) { parent_ = parent; }

  void AddChild(const std::shared_ptr<VirtualWidget>& child);
  std::shared_ptr<VirtualWidget> GetChild(int index);

  virtual const std::string& GetRepr();

 private:
  std::string title_text_;
  std::string help_text_;
  std::string native_name_;
  std::string widget_name_;
  int x_ = 0;
  int y_ = 0;
  int width_ = 0;
  int height_ = 0;
  bool is_visible_ = false;
  bool is_focused_ = false;
  bool is_clickable_ = false;
  std::weak_ptr<VirtualWidget> parent_;
  std::vector<std::shared_ptr<VirtualWidget>> children_;

 protected:
  explicit VirtualWidget(const std::string& widget_name);
  virtual ~VirtualWidget() = default;
};
