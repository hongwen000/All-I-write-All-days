#include "server.h"
MY_REGISTER_WATCHER_TYPE(SVector) {
public:
    double x;
    double y;
    SVector() :x(0), y(0){
    }
    values_type watcher_property_value() const {
        return values_type{std::to_string(x),
                           std::to_string(y)};
    }
};

struct SRadius:WatcherObject {
    double r;
    bool avil = false;
    values_type watcher_property_value() const {
        return values_type{std::to_string(r),
                           avil ? "true" : "false"};
    }
    static info_type watcher_property_info()   {
        return AbstractWatcherObject::info_type{std::make_pair("double", "r"),
                                         std::make_pair("bool", "avil")};
    }
};

int main()
{
    double var = 1;
    Watcher<double> varWatcher("Global", "double", "var");
    MYDEFINE(global, std::string, s);
    s = "万岁";
    MY_REGISTER_WATCHER_INFO(SVector) 
    {
        AbstractWatcherObject::info_type{std::make_pair("double", "x"),
                                         std::make_pair("double", "y")}
    };
    MYDEFINE(global, SVector, v);
    SVector vv;
    MYDEFINE(global, SRadius, r);
    while(true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));

        var = var - 1.5;
        varWatcher.update(var);
        
        s = s->append("!");

        vv.x = vv.x + 1;
        v = vv;

        r->avil = !r->avil;
        r->r += 1;
        r.update();
    }
}
