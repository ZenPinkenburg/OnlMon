#ifndef MVTX_MVTXMONDRAW_H
#define MVTX_MVTXMONDRAW_H

#include <onlmon/OnlMonDraw.h>

#include <string>  // for allocator, string

class OnlMonDB;
class TCanvas;
class TGraphErrors;
class TPad;

class MvtxMonDraw : public OnlMonDraw
{
 public:
  MvtxMonDraw(const std::string &name);

  ~MvtxMonDraw() override {}

  int Init() override;
  int Draw(const std::string &what = "ALL") override;
  int MakePS(const std::string &what = "ALL") override;
  int MakeHtml(const std::string &what = "ALL") override;

     const static int NSTAVE = 4;
  const static int NCHIP = 9;

 protected:
  int MakeCanvas(const std::string &name);
  int DrawFirst(const std::string &what = "ALL");
  int DrawSecond(const std::string &what = "ALL");
  int DrawHitMap(const std::string &what = "ALL");
  int DrawHistory(const std::string &what = "ALL");
  int TimeOffsetTicks = -1;
  TCanvas *TC[4] = {nullptr};
  TPad *transparent[3] = {nullptr};
  TPad *Pad[7] = {nullptr};
  TGraphErrors *gr[2] = {nullptr};
  OnlMonDB *dbvars = nullptr;


};

#endif /* MVTX_MVTXMONDRAW_H */
