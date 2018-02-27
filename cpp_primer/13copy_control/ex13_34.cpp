#include <iostream>
#include "ex13_34.hpp"

void swap(Message &lhs, Message &rhs) {
    using std::swap;
    lhs.RemoveFromFolders();
    rhs.RemoveFromFolders();

    swap(lhs.folders_, rhs.folders_);
    swap(lhs.contents_, rhs.contents_);

    lhs.AddToFolders(lhs);
    rhs.AddToFolders(rhs);
}

void Message::Save(Folder &f) {
    AddFolder(&f);
    f.AddMessage(this);
}

void Message::Remove(Folder &f) {
    RemoveFolder(&f);
    f.RemoveMessage(this);
}

void Message::AddToFolders(const Message &msg) {
    for (auto f : msg.folders_) {
        f->AddMessage(this);
    }
}

Message::Message(const Message &msg)
    : contents_(msg.contents_), folders_(msg.folders_) {
    AddToFolders(msg);
}

void Message::RemoveFromFolders() {
    for (auto f : folders_) {
        f->RemoveMessage(this);
    }
}

Message::~Message() {
    RemoveFromFolders();
}

Message& Message::operator=(const Message &rhs) {
    RemoveFromFolders();
    contents_ = rhs.contents_;
    folders_ = rhs.folders_;
    AddToFolders(rhs);

    return *this;
}

void Message::PrintDebug() {
    std::cout << contents_ << '\n';
}

void swap(Folder &lhs, Folder &rhs) {
    using std::swap;
    lhs.RemoveFromMessage();
    rhs.RemoveFromMessage();

    swap(lhs.msgs_, rhs.msgs_);

    lhs.AddToMessage(lhs);
    rhs.AddToMessage(rhs);
}

void Folder::AddToMessage(const Folder &f) {
    for (auto m : f.msgs_) {
        m->AddFolder(this);
    }
}

Folder::Folder(const Folder &f) : msgs_(f.msgs_) {
    AddToMessage(f);
}

void Folder::RemoveFromMessage() {
    for (auto m : msgs_) {
        m->RemoveFolder(this);
    }
}

Folder::~Folder() {
    RemoveFromMessage();
}

Folder& Folder::operator=(const Folder &rhs) {
    RemoveFromMessage();
    msgs_ = rhs.msgs_;
    AddToMessage(rhs);

    return *this;
}

void Folder::PrintDebug() {
    for (const auto &m : msgs_) {
        std::cout << m->contents_ << " ";
    }
    std::cout << '\n';
}


int main() {



    return 0;
}
