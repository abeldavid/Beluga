#ifndef BELUGA_VIDEOSETUPDIALOG_H
#define BELUGA_VIDEOSETUPDIALOG_H

#include "MT_Tracking.h"

class wxFilePickerCtrl;

class Beluga_VideoSetupCanvas : public MT_GLCanvasBase
{
protected:
public:
    Beluga_VideoSetupCanvas(wxWindow* parent,
             wxWindowID id = wxID_ANY,
             const wxPoint& pos = wxDefaultPosition,
             const wxSize& size = wxDefaultSize);

    bool doMouseCallback(wxMouseEvent& event, double viewport_x, double viewport_y);
    
    void doGLDrawing();

};

class Beluga_VideoSetupDialog : public wxDialog
{
protected:
    Beluga_VideoSetupCanvas* m_pCanvases[4];
    std::vector<std::string> m_vsNames;
    MT_Capture* m_pCapture;

    bool m_bCamerasStarted;

    unsigned int* m_pIndexMap;

    wxChoice* m_pChoices[4];
    wxFilePickerCtrl* m_pFilePickerCtrls[4];

    void onDoneClicked(wxCommandEvent& event);

    void onCameraSelected(wxCommandEvent& event);
    void SwapCameras(int quad1, int quad2);

public:
    Beluga_VideoSetupDialog(MT_Capture* capture,
                            std::vector<std::string> names,
                            unsigned int* indexMap,
                            wxWindow* parent,
                            wxWindowID id = wxID_ANY);

    void StartCameras();
    void UpdateView();
    
};

#endif // BELUGA_VIDEOSETUPDIALOG_H
