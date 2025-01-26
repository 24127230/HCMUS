#include <iostream>
#include <conio.h>
#include <string>
using namespace std;
struct Content
{
    std::string userName;       // Name of the user who posted
    std::string dateTimePosted; // Date and time of the post (format: YYYY-MM-DD HH:MM:SS)
    int likes;                  // Number of likes the post has received
    int comments;               // Number of comments on the post
    int shares;                 // Number of times the post has been shared
};
struct Post
{
    Content *content;
    Post *next;
};
Post *createPost(const Content &content);
void addPost(Post *&head, const Content &content);
void displayCurrentPost(Post *current);
void moveToNextPost(Post *&current);
void deleteFeed(Post *&head);

int main()
{
    Post *head = NULL;
    Post *current = NULL;
    int choice = 1;
    do
    {
        if (current == NULL)
            current = head;
        system("cls");
        cout << ((choice == 1) ? "-->" : "   ") << "Move to next post\n";
        cout << ((choice == 2) ? "-->" : "   ") << "Add post\n";
        cout << ((choice == 3) ? "-->" : "   ") << "Exit\n";
        displayCurrentPost(current);
        char key = getch();
        switch (key)
        {
        case 72:
            choice = (choice == 1) ? 3 : choice - 1;
            break;
        case 80:
            choice = (choice == 3) ? 1 : choice + 1;
            break;
        case 13:
            switch (choice)
            {
            case 1:
                moveToNextPost(current);
                break;
            case 2:
            {
                Content a;
                cout << "ADD POST____________________________________________________________\n";
                cout << "User name: ";
                getline(cin, a.userName);
                cout << "Date time posted(YYYY-MM-DD HH:MM:SS): ";
                getline(cin, a.dateTimePosted);
                cout << "Number of likes: ";
                cin >> a.likes;
                cout << "Number of comment: ";
                cin >> a.comments;
                cout << "Number of share: ";
                cin >> a.shares;
                cin.ignore();
                addPost(head, a);
                break;
            }
            case 3:
                deleteFeed(head);
                cout << "Thanks";
                return 0;
                break;
            }
            break;
        }
    } while (1);

    return 0;
}

Post *createPost(const Content &content)
{
    Post *p = new Post;
    p->content = new Content;
    p->content->comments = content.comments;
    p->content->dateTimePosted = content.dateTimePosted;
    p->content->likes = content.likes;
    p->content->shares = content.shares;
    p->content->userName = content.userName;
    p->next = NULL;
    return p;
}
void addPost(Post *&head, const Content &content)
{
    if (head == NULL)
    {
        head = createPost(content);
    }
    else
    {
        Post *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        Post *pNew = createPost(content);
        p->next = pNew;
    }
}
void displayCurrentPost(Post *current)
{
    if (current == NULL)
    {
        cout << "No post!\n";
        cout << "--------------------------------------------------------------------" << endl
             << "--------------------------------------------------------------------\n";
    }
    else
    {
        cout << current->content->userName << endl;
        cout << current->content->dateTimePosted << endl
             << endl
             << endl;
        cout << "--------------------------------------------------------------------\n";
        cout << current->content->likes << " like | " << current->content->comments << " comment | " << current->content->shares << " share" << endl;
        cout << "--------------------------------------------------------------------\n";
    }
}
void moveToNextPost(Post *&current)
{
    if (current == NULL)
    {
        cout << "No post!\n";
        system("pause");
    }
    else
    {
        if (current->next == NULL)
        {
            cout << "No post next!\n";
            system("pause");
        }
        else
            current = current->next;
    }
}
void deleteFeed(Post *&head)
{
    while (head != NULL)
    {
        Post *Temp = head;
        head = head->next;
        delete Temp;
    }
}
