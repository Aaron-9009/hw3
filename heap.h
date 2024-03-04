#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap: public std::vector<T>
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator())
      : m(m), comp(c) {};

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap() {};

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  int m;
  PComparator comp;

  void trickelUp(int loc);
  void heapify(int loc);

};

// Add implementation of member functions here

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item){
  std::vector<T>::push_back(item);
  Heap<T, PComparator>::trickelUp(Heap<T,PComparator>::size()-1);
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const{
  return std::vector<T>::empty();
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const{
  return std::vector<T>::size();
}





// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return std::vector<T>::front();


}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");
  }else{
    std::vector<T>::at(0) = std::vector<T>::back();
    std::vector<T>::pop_back();
    heapify(0);
  }
}

template<typename T, typename PComparator>
void Heap<T,PComparator>::trickelUp(int loc){
  if(loc == 0){
    return;
  }
  int parent = (loc-1)/m;
  if(comp(std::vector<T>::at(loc), std::vector<T>::at(parent))){
    std::swap(std::vector<T>::at(loc), std::vector<T>::at(parent));
    trickelUp(parent);
  }
};

template<typename T, typename PComparator>
void Heap<T,PComparator>::heapify(int loc){
  int priorityChild = m*loc +1;
  int otherChild = std::min(priorityChild+m-1, int(size()-1));

  if(priorityChild < static_cast<int>(size())){
    for(int i = priorityChild; i <= otherChild; i++){
      if(comp(std::vector<T>::at(i), std::vector<T>::at(loc))){
        std::swap(std::vector<T>::at(i), std::vector<T>::at(loc));
        heapify(i);
      }
    }
  }

}; 

#endif

