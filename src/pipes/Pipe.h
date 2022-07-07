#pragma once
#include "AbstractPipe.h"

/**
  * Pipe interface
  * @tparam T type of elements to be passed though this pipe.
  */
template<typename T>
class Pipe : public AbstractPipe
{
public:
  virtual ~Pipe() = default;

  /**
    * remove last element from pipe.
    * @return optional that contains either the last value, or is empty if pipe was also empty.
    */
  virtual T removeLast() = 0;

  /**
    * Add an element to the queue. If queue is full, this blocks until the element was added
    * @param t element to add
    */
  virtual void add(T&& t) = 0;

  /**
    * Try to add an element to the queue. If queue is full, returns false. Does not block.
    * @param t element to add
    * @return true if element was added, false otherwise.
    */
  virtual bool tryAdd(T&& t) = 0;


  virtual bool isEmpty() const = 0;
};
