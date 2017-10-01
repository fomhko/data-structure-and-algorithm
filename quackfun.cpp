

/**
 * @return true if the parameter stack and queue contain only elements of
 *  exactly the same values in exactly the same order; false, otherwise.
 *
 * @note You may assume the stack and queue contain the same number of items!
 * @note There are restrictions for writing this function.
 * - Your function may not use any loops
 * - In your function you may only declare ONE local boolean variable to use in
 *   your return statement, and you may only declare TWO local variables of
 *   parametrized type T to use however you wish.
 * - No other local variables can be used.
 * - After execution of verifySame, the stack and queue must be unchanged. Be
 *   sure to comment your code VERY well.
 */
  template <typename T>
  bool verifySame(stack<T>& s, queue<T>& q){
    bool retval = true;
    T temp;
    if (s.size() == 1){
      if (s.top() != q.front()){
        retval = false;
      }
      temp = q.front();
      q.pop();
      q.push(temp);
      return retval;
    }
    temp = s.top();
    s.pop();
    retval = retval && verifySame(s,q);
    s.push(temp);
    if (s.top() != q.front()){
      retval = false;
    }
    temp = q.front();
    q.pop();
    q.push(temp);
    return retval;
  }
}
