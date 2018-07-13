class Command{
protected:
    std::shared_ptr<Parameters> parms;
public:
    Command();
    void set_parameters(std::shared_ptr<Parameters> parameters){
        params = parameters;
    }
    virtual void exec() = 0;
}