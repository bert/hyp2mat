/*
 * hyp2mat - convert hyperlynx files to matlab scripts
 * Copyright 2012 Koen De Vleeschauwer.
 *
 * This file is part of hyp2mat.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef PDF_H
#define PDF_H

#include <cmath>
 
#include <cairo.h>
#include <cairo-pdf.h>

#include "palette.h"
#include "hyp2mat.h"

class PDF: public Palette {
public:
  PDF();
  void Write(const std::string& filename, Hyp2Mat::PCB& pcb);

private:
  Palette palette;
  double x_max; /* board dimensions */
  double y_max;
  double x_min;
  double y_min;
  double text_height; /* in points */
  double margin; /* in points */
  double m_to_points; /* convert meter to points */
  void set_color(cairo_t* cr, int color_idx);
  void set_color_black(cairo_t* cr);
  void draw_composite_view(cairo_t* cr, Hyp2Mat::PCB& pcb);
  void draw_layer_view(cairo_t* cr, Hyp2Mat::PCB& pcb);
  void draw_caption(cairo_t* cr, std::string txt);
  void draw(cairo_t* cr, Hyp2Mat::FloatPolygons& polygons); /* output a polygon */
  void draw(cairo_t* cr, Hyp2Mat::FloatPolygon& polygon); /* output a polygon edge */
  void draw(cairo_t* cr, Hyp2Mat::Via& via); /* output a via */
  void page_fill(cairo_t* cr); /* fill */
  void page_stroke(cairo_t* cr); /* draw lines */
  };

#endif

/* not truncated */
