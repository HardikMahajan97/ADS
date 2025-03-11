#include <iostream>
using namespace std;

class student {
    string name;
    int prn;
    int cgpa;
    
public:
    void putdata(string name, int prn, int cgpa) {
        this->name = name;
        this->prn = prn;
        this->cgpa = cgpa;
    }

    int getcgpa() const {
        return cgpa;
    }

    void setcgpa(int c) {
        cgpa = c;
    }

    void getdata(int count) const {
        cout << count <<"\t\t"<< name << "\t\t" << prn << "\t\t" << cgpa << endl;
    }

    friend void radixsort(student s[], int n, int b);
    friend int getmax(student s[], int n);
    friend void radix(student s[], int n);
};

int getmax(student s[], int n) {
    int mx = s[0].getcgpa();
    
    for (int i = 0; i < n; i++) {
        if (s[i].getcgpa() > mx) {
            mx = s[i].getcgpa();
        }
    }
    return mx;
}

void radixsort(student s[], int n, int b) {
    student output[n];
    int count[10] = {0};
    
    for (int i = 0; i < n; i++) {
        count[(s[i].getcgpa() / b) % 10]++;
    }
    
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int digit = (s[i].getcgpa() / b) % 10;
        output[count[digit] - 1] = s[i];
        count[digit]--;
    }
    
    for (int i = 0; i < n; i++) {
        s[i] = output[i];
    }
}

void radix(student s[], int n) {
    int m = getmax(s, n);
    for (int b = 1; m / b > 0; b *= 10) {
        radixsort(s, n, b);
    }
}

int main() {
    int n = 15;
    
    student s[n];
    s[0].putdata("Rohan Desai", 54853, 8.5);
    s[1].putdata("Anjali Patel", 54854, 7.9);
    s[2].putdata("Siddharth Mehta", 54855, 8.0);
    s[3].putdata("Priya Shah", 54856, 9.1);
    s[4].putdata("Vivek Singh", 54857, 7.7);
    s[5].putdata("Kavya Iyer", 54858, 8.2);
    s[6].putdata("Arjun Verma", 54859, 8.8);
    s[7].putdata("Sneha Rao", 54860, 9.0);
    s[8].putdata("Rahul Gupta", 54861, 7.8);
    s[9].putdata("Pooja Nair", 54862, 8.3);
    s[10].putdata("Amit Joshi", 54863, 8.6);
    s[11].putdata("Neha Kulkarni", 54864, 7.5);
    s[12].putdata("Karan Malhotra", 54865, 8.1);
    s[13].putdata("Meera Bhatt", 54866, 8.9);
    s[14].putdata("Nikhil Sinha", 54867, 7.6);

    radix(s, n);
    
    cout << "Top " << 10 << " Students:" << endl;
    cout << "Number\t\tName\t\t\tPRN\t\tSGPA" << endl;
    int j = 0;
    for (int i = 14; i > 4; i--) {
        s[i].getdata(++j);
    }
    
    return 0;
}

