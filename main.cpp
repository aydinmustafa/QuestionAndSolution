#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;
int global_size;
bool isPrime( int number){
if ((number & 1) == 0){
    if (number == 2){
        return true;
        }
    return false;
}
for (int i = 3; (i * i) <= number; i += 2){
    if (number % i == 0){
        return false;}}
return number != 1;
}

int max_sum_of_triangle(int** tri, int m){
    for (int i=m-1; i>=0; i--){
        for (int j=0; j<=i; j++){
            if (tri[i+1][j] > tri[i+1][j+1])
                tri[i][j] += tri[i+1][j];
            else
                tri[i][j] += tri[i+1][j+1];
        }
    }
    return tri[0][0];
}
int how_many_delimiter(string ss, string delimiter){
    size_t pos = 0;
    int counter = 0;
    while((pos = ss.find(delimiter)) != string::npos) {
        counter++;
        ss.erase(0, pos + 1);
    }
    return (counter+1);
}




int main()
{

//    string s= {"1\n"
//                "8 4\n"
//                "2 6 9\n"
//                "8 5 9 3"};
    string s = {
                 "215\n"
                 "193 124\n"
                 "117 237 442\n"
                 "218 935 347 235\n"
                 "320 804 522 417 345\n"
                 "229 601 723 835 133 124\n"
                 "248 202 277 433 207 263 257\n"
                 "359 464 504 528 516 716 871 182\n"
                 "461 441 426 656 863 560 380 171 923\n"
                 "381 348 573 533 447 632 387 176 975 449\n"
                 "223 711 445 645 245 543 931 532 937 541 444\n"
                 "330 131 333 928 377 733 017 778 839 168 197 197\n"
                 "131 171 522 137 217 224 291 413 528 520 227 229 928\n"
                 "223 626 034 683 839 053 627 310 713 999 629 817 410 121\n"
                 "924 622 911 233 325 139 721 218 253 223 107 233 230 124 233"};


   int size = how_many_delimiter(s, "\n");
   global_size =size;

    int** array2D = 0;
    array2D = new int*[global_size];
    for (int h = 0; h < global_size; h++){
        array2D[h] = new int[global_size];
        for (int w = 0; w < global_size; w++){
            array2D[h][w] = 0;}
    }
    vector<string> vecString;
    size_t pos = 0;
    string token;
    int counter = 0;
    while((pos = s.find("\n")) != string::npos) {
        token = s.substr(0, pos);
        //cout << token << endl;
        counter++;
        vecString.push_back(token);
        s.erase(0, pos + 1);
    }
    vecString.push_back(s);
    //cout <<s <<"\n";

    vector<int> integers_of_triangle;

    for(int i=0;i<vecString.size();i++){
        size_t pos1 = 0;
        string token1;

        while((pos1 = vecString[i].find(" ")) != string::npos) {
            token1 = vecString[i].substr(0, pos1);

            int numb = stoi(token1);
            if(isPrime(numb)){
                numb= INT_MIN;
            }
            integers_of_triangle.push_back(numb);
            vecString[i].erase(0, pos1 + 1);
        }

        int numb2 = stoi(vecString[i]);
        if(isPrime(numb2)){
            numb2 = INT_MIN;
        }
        integers_of_triangle.push_back(numb2);
    }

    array2D[1][0] = 2;
    int writing_cntr=1;
    int cnt=0;
    for(int i=0; i< global_size;i++){
        for(int j=0;j<global_size;j++){
            if(j<writing_cntr){
                array2D[i][j] = integers_of_triangle[cnt++];
            }
            //cout << array2D[i][j]<< "  ";
        }
        writing_cntr++;
        //cout << "\n";
    }



    cout << max_sum_of_triangle(array2D, global_size - 1);

    for (int h = 0; h < global_size; h++){
        delete [] array2D[h];}
    delete [] array2D;
    array2D = 0;


    return 0;
}
