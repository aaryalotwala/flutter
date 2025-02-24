// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef FLUTTER_DISPLAY_LIST_EFFECTS_COLOR_FILTERS_DL_LINEAR_TO_SRGB_GAMMA_COLOR_FILTER_H_
#define FLUTTER_DISPLAY_LIST_EFFECTS_COLOR_FILTERS_DL_LINEAR_TO_SRGB_GAMMA_COLOR_FILTER_H_

#include "flutter/display_list/effects/dl_color_filter.h"

namespace flutter {

// The LinearToSrgb type of ColorFilter that applies the sRGB gamma curve
// to the rendered pixels.
class DlLinearToSrgbGammaColorFilter final : public DlColorFilter {
 public:
  DlLinearToSrgbGammaColorFilter() {}
  DlLinearToSrgbGammaColorFilter(const DlLinearToSrgbGammaColorFilter& filter)
      : DlLinearToSrgbGammaColorFilter() {}
  explicit DlLinearToSrgbGammaColorFilter(
      const DlLinearToSrgbGammaColorFilter* filter)
      : DlLinearToSrgbGammaColorFilter() {}

  DlColorFilterType type() const override {
    return DlColorFilterType::kLinearToSrgbGamma;
  }
  size_t size() const override { return sizeof(*this); }
  bool modifies_transparent_black() const override { return false; }
  bool can_commute_with_opacity() const override { return true; }

  std::shared_ptr<DlColorFilter> shared() const override { return kInstance; }

 protected:
  bool equals_(const DlColorFilter& other) const override {
    FML_DCHECK(other.type() == DlColorFilterType::kLinearToSrgbGamma);
    return true;
  }

 private:
  static const std::shared_ptr<DlLinearToSrgbGammaColorFilter> kInstance;

  friend class DlColorFilter;
};

}  // namespace flutter

#endif  // FLUTTER_DISPLAY_LIST_EFFECTS_COLOR_FILTERS_DL_LINEAR_TO_SRGB_GAMMA_COLOR_FILTER_H_
