#ifndef EX13_34_HPP_
#define EX13_34_HPP_

#include <string>
#include <set>

class Folder;

class Message {
    friend void swap(Message &, Message &);
    friend class Folder;

public:
    explicit Message(const std::string &str = "") : contents_(str) { }
    Message(const Message &);
    Message& operator=(const Message &);
    ~Message();

    void Save(Folder &);
    void Remove(Folder &);
    void PrintDebug();

private:
    void AddToFolders(const Message &);
    void RemoveFromFolders();

    void AddFolder(Folder *f) { folders_.insert(f); }
    void RemoveFolder(Folder *f) { folders_.erase(f); }

private:
    std::string contents_;
    std::set<Folder *> folders_;
};

void swap(Message &, Message &);

class Folder {
    friend void swap(Folder &, Folder &);
    friend class Message;

public:
    Folder() = default;
    Folder(const Folder &);
    Folder& operator=(const Folder &);
    ~Folder();

    void PrintDebug();

private:
    void AddToMessage(const Folder &);
    void RemoveFromMessage();

    void AddMessage(Message *msg) { msgs_.insert(msg); }
    void RemoveMessage(Message *msg) { msgs_.erase(msg); }

    std::set<Message *> msgs_;
};

void swap(Folder &, Folder &);

#endif  // EX13_34_HPP_
