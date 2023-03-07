#ifndef TPOT_TPOTMONDRAW_H
#define TPOT_TPOTMONDRAW_H

#include "TpotDefs.h"

#include <onlmon/OnlMonDraw.h>

#include <array>
#include <memory>
#include <string>  

class OnlMonDB;
class TCanvas;
class TH1;
class TPad;

class TpotMonDraw : public OnlMonDraw
{
  public:
  
  /// constructor
  TpotMonDraw(const std::string &name);
  
  /// destructor
  ~TpotMonDraw() override = default;

  int Init() override;
  int Draw(const std::string &what = "ALL") override;
  int MakePS(const std::string &what = "ALL") override;
  int MakeHtml(const std::string &what = "ALL") override;

  private:

  TCanvas* get_canvas(const std::string& name, bool clear = true );
  TCanvas* create_canvas(const std::string &name);
  
  int draw_hv_onoff();
  int draw_fee_onoff();
  
  using histogram_array_t = std::array<TH1*, TpotDefs::n_detectors>;
  
  /// get detector dependent histogram array from base name
  histogram_array_t get_histograms( const std::string& name );  

  /// draw histogram array
  int draw_array( const std::string& name, const histogram_array_t& );
  
  /// needed to get time axis right
  int TimeOffsetTicks = -1;
  
  // draw run and time in a given pad
  void draw_time( TPad*);
  
  // canvases
  std::array<TCanvas*, 9> m_canvas = {{nullptr}};
  std::unique_ptr<OnlMonDB> dbvars;
};

#endif /* TPOT_TPOTMONDRAW_H */
