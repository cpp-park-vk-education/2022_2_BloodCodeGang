//
// Created by Алексей on 19.12.2022.
//

#ifndef MYPROJECT_SWIPERESOURCE_H
#define MYPROJECT_SWIPERESOURCE_H

#include <Wt/Http/Request.h>
#include <Wt/WResource.h>
#include <Wt/Http/Response.h>
#include <Wt/Json/Object.h>
#include <Wt/Json/Parser.h>
#include <Wt/Json/Serializer.h>


class SwipeResource : public Wt::WResource {

public:
//    SwipeResource() {
//    }

    ~SwipeResource() {
        beingDeleted();
    }

    void handleRequest(const Wt::Http::Request& request, Wt::Http::Response& response) {
        Wt::Json::Object result;
        Wt::Json::parse("{ "
                    "  \"a\": \"That's great\", "
                    "  \"b\": true "
                    "}",
                    result);
        response.out() << Wt::Json::serialize(result) << std::endl;
    }
};


#endif //MYPROJECT_SWIPERESOURCE_H
