#include "./httplib/httplib.h"
#include "./json/json.hpp"
#include <iostream>
#include <string>

using json = nlohmann::json;

struct Point
{
    std::array<float, 2> data;
    std::string HANDLE;
    // explicit Point(Point P, std::string Handle) : data(P.data), HANDLE(Handle) {};
};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Point, data, HANDLE)
int main()
{
    Point point{
        {10.5f, 55.2f}, // {data[0], data[1]}
        "Base_Station_A"};
    static json p_out = point;
    std::cout << p_out.dump(4) << std::endl;

    httplib::Server server;

    server.Get("/", [&](const httplib::Request &, httplib::Response &res)
               {
                   // Set the Content-Type header correctly
                   res.set_content(p_out.dump(4), "application/json"); });

    std::cout << "Server listening on http://localhost:8080" << std::endl;
    

    server.Post("/", [&](const httplib::Request &req, httplib::Response &res){
        std::cout << req.body << std::endl;
    });


    
    server.listen("localhost", 8080);



    return 0;
}