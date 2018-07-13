class Parameters{
public:
    Parameters();
}

class PathParameters : public Parameters{
private:
    std::string path;
public:
    PathParameters(std::string_path):path(_path){
    }
    std::string get_path(){
        return path;
    }
}