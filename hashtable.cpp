#include <iostream>
#define MAX 512

using namespace std;

template <class T>
class hashT{
private:
  T *arr;
  int size;
public:
  hashT();
  ~hashT();
  int insert(T);
  int search(T);
};

template <class T>
hashT<T>::hashT(){
  size = 0;
  arr = new T[MAX];
  for(int i = 0; i < MAX; arr[i] = NULL, i++);
}

template <class T>
hashT<T>::~hashT(){
    delete[] arr;
}

template <class T>
int hashT<T>::insert(T x){
  if(size == MAX)
    throw 404;
  int col = 0, i = ((60147*x)%65536)/128;
  while(arr[i%512]!=NULL){
    i++;
    col++;
  }
  arr[i%512] = x;
  size++;
  return col;
}

template <class T>
int hashT<T>::search(T x){
  int col = 0, i = ((60147*x)%65536)/128;
  while(arr[i%512]!=NULL && col<512){
    if(arr[i%512]==x)
        break;
    i++;
    col++;

  }
  return col;
}

int main(){
  int n,m,x,y;
  cin >> n;
  for(int i = 0; i < n; i++){
    hashT<int> a;
    cin >> m;
    for(int j = 0; j < m; j++){
      cin >> x;
      cout << a.insert(x) << " ";
    }
    cin >> y;
    cout << endl << a.search(y) << endl;
  }
  return 0;
}
