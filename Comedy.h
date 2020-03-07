//
//  Comedy.h
//  Assignment4
//
//  Created by Diana Gutierrez on 3/6/20.
//  Copyright © 2020 Diana Gutierrez. All rights reserved.
//

#ifndef Comedy_h
#define Comedy_h

class Comedy: public Movie {
    
public:
    Comedy(const string&); // constructor
    Comedy(const string&, const int&); // constructor
    
    virtual ~Comedy(); // destructor
    
    // returns movie information
    virtual string createMovie() const;
       
    // info for customer transactions
    virtual string creatCustomerHistory() const;
    
    static const char TYPE = 'F'; // movieType
    
protected:
    bool operator==(const Movie*) const;
    bool operator!=(const Movie*) const;
    bool operator>(const Movie*) const;
    bool operator<(const Movie*)const;
};
#endif /* Comedy_h */
