class MiniPS;

class Notification{
public:
}

class UpdatePictureNotifier : public Notification {
public:
    UpdatePictureNotifier(_viewmodel) : viewmodel(_viewmodel){}
    void Notify();
protected:
    std::shared_ptr<ViewModel> viewmodel;
};

class CompleteCommandNotifier : public Notification {
public:
    CompleteCommandNotifier(_viewmodel) : viewmodel(_viewmodel){}
    void Notify();
protected:
    std::shared_ptr<ViewModel> viewmodel;
};

class UpdateViewNotifier : public Notification {
public:
    UpdateViewNotifier(_view) : view(_view){}
    void Notify(const std::shared_ptr<QImage>);
protected:
    std::shared_ptr<MiniPS> view;
};