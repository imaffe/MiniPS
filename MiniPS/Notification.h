class Notification{
public:
    Notification();
    virtual void exec() = 0;
};

class UpdateDisplayDataNotification : public Notification{
private:
    std::shared_ptr<ViewModel> viewmodel;
public:
    UpdateDisplayDataNotification(std::shared_ptr<ViewModel> vm):viewmodel(vm){}
    void exec(){
        viewmodel->notified();
    }
};

class UpdateViewNotification:public Notification{
private:
    std::shared_ptr<View> view;
public:
    UpdateViewNotification(std::shared_ptr<View> v):view(v){};
    void exec(){
        view->update();
    }
}