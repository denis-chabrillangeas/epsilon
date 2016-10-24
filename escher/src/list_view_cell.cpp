#include <escher/list_view_cell.h>
#include <assert.h>

constexpr KDCoordinate ListViewCell::k_separatorThickness;

ListViewCell::ListViewCell(char * label) :
  TableViewCell(),
  m_pointerTextView(PointerTextView(label, 0, 0.5, KDColorBlack, Palette::CellBackgroundColor))
{
}

int ListViewCell::numberOfSubviews() const {
  if (contentView() == nullptr) {
    return 1;
  }
  return 2;
}

View * ListViewCell::subviewAtIndex(int index) {
  if (index == 0) {
    return &m_pointerTextView;
  }
  assert(numberOfSubviews() == 2 && index == 1);
  return contentView();
}

void ListViewCell::layoutSubviews() {
  KDCoordinate width = bounds().width();
  KDCoordinate height = bounds().height();
  KDSize labelSize = m_pointerTextView.minimalSizeForOptimalDisplay();
  m_pointerTextView.setFrame(KDRect(k_separatorThickness, k_separatorThickness, labelSize.width(), height - 2*k_separatorThickness));
  View * content = contentView();
  if (content) {
    content->setFrame(KDRect(k_separatorThickness + labelSize.width(), k_separatorThickness, width - labelSize.width()-2*k_separatorThickness, height-2*k_separatorThickness));
  }
}

void ListViewCell::reloadCell() {
  TableViewCell::reloadCell();
  KDColor backgroundColor = isHighlighted()? Palette::FocusCellBackgroundColor : Palette::CellBackgroundColor;
  m_pointerTextView.setBackgroundColor(backgroundColor);
}

PointerTextView * ListViewCell::textView() {
  return &m_pointerTextView;
}

View * ListViewCell::contentView() const {
  return nullptr;
}

void ListViewCell::drawRect(KDContext * ctx, KDRect rect) const {
  KDCoordinate width = bounds().width();
  KDCoordinate height = bounds().height();
  KDColor backgroundColor = isHighlighted() ? Palette::FocusCellBackgroundColor : Palette::CellBackgroundColor;

  ctx->fillRect(KDRect(k_separatorThickness, k_separatorThickness, width-2*k_separatorThickness, height-k_separatorThickness), backgroundColor);
  ctx->fillRect(KDRect(0, 0, width, k_separatorThickness), Palette::LineColor);
  ctx->fillRect(KDRect(0, k_separatorThickness, k_separatorThickness, height-k_separatorThickness), Palette::LineColor);
  ctx->fillRect(KDRect(width-k_separatorThickness, k_separatorThickness, k_separatorThickness, height-k_separatorThickness), Palette::LineColor);
 }
