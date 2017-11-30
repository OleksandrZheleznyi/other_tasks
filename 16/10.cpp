#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
using namespace std;

struct Review
{
    string title;
    int rating;
    double price;
};

bool worseThan(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2);
bool worseThan2(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2);
bool operator<(const shared_ptr<Review> & a, const shared_ptr<Review> & b);
bool FillReview(Review & rr);
void ShowReview(const shared_ptr<Review> & rr);

int main()
{
    vector< shared_ptr<Review> > books;
    Review temp;
    for (;FillReview(temp);)
    {
        books.push_back(shared_ptr<Review>(new Review(temp)));
    }    
    
    if (books.size() > 0)
    {
        cout<<"Thank you. You entered the following "
            <<books.size()<<" ratings:\n"
            <<"Rating\tPrice\tBook\n";
        for(auto x : books) ShowReview(x);   

        vector<shared_ptr<Review> > booksTitle = books;
        vector<shared_ptr<Review> > booksRating = books;
        vector<shared_ptr<Review> > booksPrice = books;
        
        sort(booksTitle.begin(), booksTitle.end());
        cout << "Sorted by title:\nRating\tPrice\tBook\n";
        for(auto x : booksTitle) ShowReview(x);
        
        sort(booksRating.begin(), booksRating.end(), worseThan);
        cout << "Sorted by rating:\nRating\tPrice\tBook\n";
        for(auto x : booksRating) ShowReview(x);
         
        sort(booksPrice.begin(), booksPrice.end(), worseThan2);
        cout << "Sorted by price:\nRating\tPrice\tBook\n";
        for(auto x : booksPrice) ShowReview(x);
    }
    else
        cout << "No entries. ";
    cout << "Bye.\n";
}

bool operator<(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2)
{
    if ( r1->title < r2->title )
        return true ;
    else
        return false;
}
bool worseThan(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2)
{
    if (r1->rating < r2->rating)
        return true;
    else
        return false;
}
bool worseThan2(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2)
{
    if (r1->price < r2->price)
        return true;
    else
        return false;
}
bool FillReview(Review & rr)
{
    cout<<"Enter book title (quit to quit): ";
    getline(cin, rr.title);
    if(rr.title == "quit")
        return false;
    cout<<"Enter book rating: ";
    cin>>rr.rating;
    if(!cin)
        return false;
    cout<<"Enter book price: ";
    cin>>rr.price;
    if(!cin)
        return false;
    while(cin.get() != '\n')
        continue;
    return true;
}
void ShowReview(const shared_ptr<Review> & rr)
{
    cout<<rr->rating<<"\t"<<rr->price<<"\t"<<rr->title<<endl;
}

