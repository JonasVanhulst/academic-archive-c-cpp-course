//
// Created by Vanhuljo on 08/11/2023.
//

#include <iostream>
#include <list>

#define SUBBOT 16545

using namespace std;
using std::string;

class youTubeChannel {
private:
    string name;
    int subscribers = 0;
    list<string> ytVideos;
protected:
    string ownerName;
public:

    youTubeChannel(string youtubeChannel, string youtubeOwner) : name(youtubeChannel),
                                                                 ownerName(youtubeOwner) {}

    void getChannelInfo() {
        cout << "Name: " << name << endl;
        cout << "Owner: " << ownerName << endl;
        cout << "Subscribers: " << subscribers << endl;
        cout << "Video's: " << endl;

        for (string videoTitle: ytVideos) {
            cout << videoTitle << endl;
        }
    }

    void subscribe() {
        subscribers++;
    }

    void unsubscribe() {
        if (subscribers > 0)
            subscribers--;
    }

    void uploadNewVideo(string videoTitle) {
        ytVideos.push_front(videoTitle);
    }
};

class youTubeChannel2 : public youTubeChannel {
public:
    youTubeChannel2(string youtubeChannel, string youtubeOwner) : youTubeChannel(youtubeChannel, youtubeOwner) {}

    void praktice() {
        cout << ownerName << " is prakticing for new content" << endl;
    }
};

int main() {

    youTubeChannel channel1("FreeCodeCamp", "Bryan");
    channel1.uploadNewVideo("help me coding");
    channel1.uploadNewVideo("coding for beginners");
    channel1.uploadNewVideo("coding is so easy");
    youTubeChannel2 channel2("CodeSpace", "Bart");
    channel2.uploadNewVideo("Get your language");
    channel2.subscribe();
    channel2.praktice();


    for (int i = 0; i < SUBBOT; i++) {
        channel1.subscribe();
    }

    channel1.getChannelInfo();
    channel2.getChannelInfo();

    return 0;
}