#include <iostream>

// Define the RefCountPointer template
template<class T>
class RefCountPointer {
public:
    typedef T element_type;
    
    RefCountPointer(T* p = 0) : _p(p) {
        if (_p != 0) _p->incrementRefCount();
    }

    template<class T2>
    RefCountPointer(const RefCountPointer<T2>& o) : _p((T*)(T2*)o) {
        if (_p != 0) _p->incrementRefCount();
    }

    RefCountPointer(const RefCountPointer<T>& o) : _p(o._p) {
        if (_p != 0) _p->incrementRefCount();
    }

    RefCountPointer& operator=(const RefCountPointer<T>& o) {
        if (_p != o._p) {
            if (_p != 0) _p->decrementRefCount();
            _p = o._p;
            if (_p != 0) _p->incrementRefCount();
        }
        return *this;
    }

    ~RefCountPointer() {
        if (_p != 0) _p->decrementRefCount();
    }

    T* operator->() const {
        return _p;
    }

    operator T*() const {
        return _p;
    }

    T* get() const {
        return _p;
    }

    bool isNull() const {
        return (_p == 0);
    }

    bool notNull() const {
        return (_p != 0);
    }

protected:
    T* _p;
};

// Define the Ptr type in FastXDMDocument using RefCountPointer
class FastXDMDocument {
public:
    typedef RefCountPointer<FastXDMDocument> Ptr;

    FastXDMDocument() : refCount(0) {
        std::cout << "FastXDMDocument created." << std::endl;
    }

    void incrementRefCount() {
        ++refCount;
        std::cout << "Reference count incremented to " << refCount << std::endl;
    }

    void decrementRefCount() {
        if (--refCount == 0) {
            std::cout << "Reference count is zero, deleting document." << std::endl;
            delete this;
        } else {
            std::cout << "Reference count decremented to " << refCount << std::endl;
        }
    }

private:
    int refCount;

    // Prevent deletion through a non-RefCountPointer.
    ~FastXDMDocument() {
        std::cout << "FastXDMDocument destroyed." << std::endl;
    }
};

int main() {
    // Create a RefCountPointer to manage FastXDMDocument
    FastXDMDocument::Ptr doc1(new FastXDMDocument());

    {
        FastXDMDocument::Ptr doc2 = doc1; // Shared ownership
        std::cout << "Inside scope, doc2 created." << std::endl;
    } // doc2 goes out of scope, reference count is decremented

    std::cout << "Outside scope." << std::endl;

    return 0;
}


/*

#include <iostream>
#include <memory>

class FastXDMDocument {
public:
    FastXDMDocument() {
        std::cout << "FastXDMDocument created." << std::endl;
    }

    ~FastXDMDocument() {
        std::cout << "FastXDMDocument destroyed." << std::endl;
    }
};

int main() {
    std::shared_ptr<FastXDMDocument> doc1 = std::make_shared<FastXDMDocument>();

    {
        std::shared_ptr<FastXDMDocument> doc2 = doc1; // Shared ownership
        std::cout << "Inside scope, doc2 created." << std::endl;
    } // doc2 goes out of scope, reference count is decremented

    std::cout << "Outside scope." << std::endl;

    return 0;
}

*/