#import <Foundation/Foundation.h>
#import "Server.hpp"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        Server server;
        server.start();
    }
    return 0;
}
