#ifndef GRAPH_EVEN_ODD_CELL_H
#define GRAPH_EVEN_ODD_CELL_H

#include <escher.h>

namespace Graph {

class EvenOddCell : public TableViewCell {
public:
  EvenOddCell();
  void setEven(bool even);
  KDColor backgroundColor() const;
  void drawRect(KDContext * ctx, KDRect rect) const override;

  static constexpr KDColor k_evenLineBackgroundColor = KDColor(0xF7F9FA);
  static constexpr KDColor k_oddLineBackgroundColor = KDColorWhite;
  static constexpr KDColor k_selectedLineBackgroundColor = KDColor(0xC0D3EA);

private:
  bool m_even;
};

}

#endif
