#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class Media {
protected:
    string title;
    double duration;

public:
    Media(string t, double d) : title(t), duration(d) {}

    virtual void play() = 0;
    virtual void pause() = 0;
    virtual void stop() = 0;
    virtual void showDetails() const {
        cout << "Title: " << title << " | Duration: " << duration << " mins" << endl;
    }

    virtual ~Media() = default;
};

class Audio : public Media {
public:
    Audio(string t, double d) : Media(t, d) {}

    void play() override { cout << "Playing Audio: " << title << endl; }
    void pause() override { cout << "Paused Audio: " << title << endl; }
    void stop() override { cout << "Stopped Audio: " << title << endl; }
};

class Video : public Media {
public:
    Video(string t, double d) : Media(t, d) {}

    void play() override { cout << "Rendering and Playing Video: " << title << endl; }
    void pause() override { cout << "Paused Video: " << title << endl; }
    void stop() override { cout << "Stopped Video playback: " << title << endl; }
};

int main() {
    vector<unique_ptr<Media>> playlist;
    playlist.push_back(make_unique<Audio>("Song_Track_1.mp3", 3.45));
    playlist.push_back(make_unique<Video>("Lecture_Module_1.mp4", 45.0));

    cout << "== Media Player Polymorphic Controls ==" << endl;
    for (const auto& item : playlist) {
        item->showDetails();
        item->play();
        item->pause();
        item->stop();
        cout << endl;
    }

    return 0;
}
