#include "Notification.h"
#include "MiniPS.h"
#include <string>
void UpdatePictureNotifier::Notify() {
    viewmodel->UpdatePicture();
}
void UpdateViewNotifier::Notify(const std::shared_ptr<QImage> qimg) {
    view->ShowPicture(qimg);
}