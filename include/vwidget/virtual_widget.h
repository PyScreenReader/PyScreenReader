#pragma once

#include <memory>
#include <string>
#include <vector>

class VirtualWidget {
 public:
  //  Getters
  /**
   * Get title text
   *
   * Title text is a string that represents the primary text content of the widget.
   * - It can be the content string on the button, which says "Click me"
   * - It can be the string that a text input is displaying (if any)
   *
   * @return title text string
   */
  std::string GetTitleText() const { return title_text_; }

  /**
   * Get help text
   * @see GetTitleText()
   *
   * Help text is generally the secondary text content in a widget.
   * When you hover the cursor over widgets, the if there is a tooltip pops up,
   * the tooltip content will be considered a help text.
   *
   * @return help text
   */
  std::string GetHelpText() const { return help_text_; }
  /**
   * Get name of the native widget this virtual widget being mapped from
   *
   * @return native widget name
   */
  std::string GetNativeName() const { return native_name_; }
  /**
   * Get printable current virtual widget name in upper camel case.
   *
   * For example, "VirtualButtonWidget", "VirtualTextWidget", etc.
   *
   * @return current virtual widget name
   */
  std::string GetWidgetName() const { return widget_name_; }

  /**
   * Get the X coordinate of the top left corner of widget respected to the screen,
   * with the top left corner of the screen being the origin.
   *
   * @return x coordinate
   */
  int GetX() const { return x_; }

  /**
   * Get the Y coordinate of the top left corner of widget respected to the screen,
   * with the top left corner of the screen being the origin.
   *
   * @return Y coordinate
   */
  int GetY() const { return y_; }

  /**
   * Get the width of the current widget.
   *
   * @return width of the widget
   */
  int GetWidth() const { return width_; }

  /**
   * Get the height of the current widget.
   *
   * @return height of the widget
   */
  int GetHeight() const { return height_; }

  /**
   * Get if the current widget is visible to the user.
   *
   * @return True if it is visible, otherwise false.
   */
  bool IsVisible() const { return is_visible_; }

  /**
   * Get if the current widget is focused.
   *
   * @return True if it is focused, otherwise false.
   */
  bool IsFocused() const { return is_focused_; }

  /**
   * Get the parent widget of the current widget.
   *
   * @return parent widget
   */
  std::shared_ptr<VirtualWidget> GetParent() const { return parent_.lock(); }

  //  Setters
  /**
   * Set title text.
   *
   * For detailed explanation on "Title Text", @see GetTitleText()
   * @param title_text title text string
   */
  void SetTitleText(const std::string& title_text) { title_text_ = title_text; }

  /**
   * Set help text.
   *
   * For detailed explanation on "Help Text", @see GetHelpText()
   * @param help_text help text string
   */
  void SetHelpText(const std::string& help_text) { help_text_ = help_text; }

  /**
   * Set native name.
   *
   * For detailed explanation, @see GetNativeName()
   * @param native_name name of the native widget this virtual widget being mapped from
   */
  void SetNativeName(const std::string& native_name) { native_name_ = native_name; }

  /**
   * Set the X coordinate of the top left corner of widget respected to the screen,
   * with the top left corner of the screen being the origin.
   *
   * @param x_coord x coordinate
   */
  void SetX(const int x_coord) { x_ = x_coord; }

  /**
   * Set the Y coordinate of the top left corner of widget respected to the screen,
   * with the top left corner of the screen being the origin.
   *
   * @param y_coord y coordinate
   */
  void SetY(const int y_coord) { y_ = y_coord; }

  /**
   * Set the width of the current widget.
   *
   * @return width of the widget
   */
  void SetWidth(const int width) { width_ = width; }

  /**
   * Set the height of the current widget.
   *
   * @return height of the widget
   */
  void SetHeight(const int height) { height_ = height; }

  /**
   * Set if the current widget is visible to the user.
   *
   * @param visible True if it is visible, otherwise false.
   */
  void SetVisible(const bool visible) { is_visible_ = visible; }

  /**
   * Set if the current widget is focused.
   *
   * @param focused True if it is focused, otherwise false.
   */
  void SetFocused(const bool focused) { is_focused_ = focused; }

  /**
   * Set the parent widget of the current widget.
   *
   * @param parent parent widget
   */
  void SetParent(const std::shared_ptr<VirtualWidget>& parent) { parent_ = parent; }

  /**
   * Add a child widget to this widget.
   *
   * @note this does not automatically set the child widget to point this widget as
   * its parent. In order to avoid breaking the tree structure, please also call
   * SetParent on child widget to set this widget to be the parent.
   *
   * @param child child widget
   */
  void AddChild(const std::shared_ptr<VirtualWidget>& child);

  /**
   * Get the child widget on the index (start from 0)
   *
   * @param index index of the child widget
   * @note throws an out_of_range exception if there are not that many children
   *
   * @return child widget on the index
   */
  std::shared_ptr<VirtualWidget> GetChild(int index);

  /**
   * Gets all the children of this widget in the tree
   * @return all the children of this widget
   */
  std::vector<std::shared_ptr<VirtualWidget>> &GetChildren();

  virtual ~VirtualWidget() = default;

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
  std::weak_ptr<VirtualWidget> parent_;
  std::vector<std::shared_ptr<VirtualWidget>> children_;

 protected:
  explicit VirtualWidget(std::string widget_name);
};
