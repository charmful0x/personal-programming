#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<array>
#include<algorithm>
#include<cassert>
#include<array>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<regex>
#include "utils.h"


void print_date(int d, int m, int y) {
    std::cout << std::setw(2) << std::setfill('0') << d << "/" 
    << std::setw(2) << std::setfill('0') << m << "/"
    << std::setw(4) << std::setfill('0') << y
    << std::endl;
}


void print_hour(int h, int m, int s) {
    std::cout << std::setw(2) << std::setfill('0') << h << ":" 
    << std::setw(2) << std::setfill('0') << m << ":"
    << std::setw(2) << std::setfill('0') << s
    << std::endl;
}
void print_delimiter(int r, int c, char symbol) {
    std::string row = "";

    for (int i = 0; i < c; i++) {
        row += symbol;
    }

    for (int i = 0; i < r; i++) {
        std::cout << row << std::endl;
    }
    
}

void print_diff_between_extremes(double a, double b, double c) {
    std::vector<double> data_set;
    double diff;

    data_set.push_back(a);
    data_set.push_back(b);
    data_set.push_back(c);

    std::sort(data_set.begin(), data_set.end());

    diff = data_set.back() - data_set.front();

    std::cout << "difference between min and max = " << diff << std::endl; 

}

void print_reversed_number(int input) {
    assert(input > 0);
    std::string stringified_input = std::to_string(input);
    std::reverse(stringified_input.begin(), stringified_input.end());
    int result = std::stoi(stringified_input);

    std::cout << "reversed " << input << " is " << result << std::endl; 
}

int is_prime_number(int n) {
    // return 0 if not prime
    // return 1 if prime

    assert(n > 1);

    if (n == 2) {
        return 1;
    }

    if (n % 2 == 0) {
        return 0;
    }

    for (int i = 1; i <=n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

bool is_int(double n) {
    return std::floor(n) == n;
}

int find_min_power(int n, int b) {
    int smallest_pow = 0;
    int result = 0;
    assert(b > 1 && n >= 0);
    int i = 0;

    for (int i = 0; result < n; i++) {
        result = pow(b, i);
        smallest_pow = i;
    }

    std::cout << "smallest power of " << b << " whose value is greater than " 
    << n << " is " << b << "^" << smallest_pow << " = " << result << std::endl; 
    return smallest_pow;

}

void generate_rand_ints_arr() {
    int arr[30] = {0};
    srand(time(NULL));
    std::cout << "result: [";
    for (int i = 0; i < 30; i++) {
        int rand_int = rand() % 100; // 0-99 rand nums only
        arr[i] = rand_int;
        std::cout << std::setfill('0') << std::setw(2) << rand_int << ", ";
    }

    std::cout << "]" << std::endl;

}

int nullify_out_range_arr_vals(double a[], int n, double x, double y) {
    int assingements = 0;
    if ( x > y ) {
        return -1;
    }


    for (int i = 0; i < n; i++) {
        if (a[i] < x || a[i] > y) {
            a[i] = 0;
            assingements++;
        }
    }
    std::cout << "hello" << std::endl;
    std::cout << assingements << std::endl;

    return assingements;

};

void reverse_str(std::string input) {
    std::string input_copy = input;
    std::reverse(input_copy.begin(), input_copy.end());

    std::cout << input << " reversed is: " << input_copy << std::endl;
}

int count_occurences(int a[], int b[10], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] >= 0 || a[i] <= 0) {
            int temp_count = 0;
            for (int j = 0; j < n; j++) {
                if (a[j] == a[i]) {
                    temp_count++;
                }
            }
            b[i] = temp_count;
        }
    }

    return 0;
}

void manip_arrays(int a[12], int b[12]) {
    b[0] = 1; b[11] = 1;

    for (int i = 10; i > 0; i--) {
        int temp_res = temp_res = a[i + 1] * a[i -1];
        b[i] = temp_res;
    }

    std::cout << "result =  [";
    for (int i = 0; i < 12; i++) {
        std::cout << b[i] << ", ";
    }

    std::cout << "]" << std::endl;

}

void remove_dupli_occurences(std::string a, char t) {
    std::string str_t(1, t);

    for (int i = 0; i < a.length(); i++) {
        int temp_count = 0;
        for (int j = 0; j < a.length(); j++) {
            if (a[j] == t) {
                temp_count++;
            }
        }

        std::cout << temp_count << std::endl;

        if (temp_count > 1) {
            a = std::regex_replace(a, std::regex(str_t), "");
        }
    }

    std::cout << a << std::endl;
}

int strToIp(char ip_char[], int ip[4]) {
    std::string ip_str(ip_char);
    // add "." at the end of the ip_str so the
    // for loop work properly
    ip_str += ".";
    std::string temp_str = "";
    int i = 0;

    // initialize ip to 0s
    for (int i = 0; i <= 4; i++) {
        ip[i] = 0;
    }

    for (char c: ip_str) {

        if (c != '.') {
            temp_str+= c;
            std::cout << temp_str << std::endl;
        }

        if (c == '.') {
        int int_ip = std::stoi(temp_str); 

        if (int_ip < 0 || int_ip > 255) {
            return -1;
        }
        ip[i] = int_ip;
        temp_str = "";
        i++;
        }
}

    std::cout << "converted ip: {";

    for (int i = 0; i < 4; i++) {
        std::cout << ip[i] << ", ";
    }

    std::cout << "}" << std::endl;
    return 1;
}

void m3xm3(int A[3][3], int B[3][3]) {
    int C[3][3] = {0};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; j++) {
                C[i][j] += A[i][k] * B [k][j];
            }

        }
    }
}

double main_matrix_diagonal(double (&M) [2][2]) {
    double trace = 0.0;
    // rows number = total M size / one row size
    int r_number = sizeof(M) / sizeof(M[0]);
    // colomns number = total row size / row's element size
    int c_number = sizeof(M[0]) / sizeof(M[0][0]);
    // validate M dymensions

    assert(c_number == 2 && r_number == 2);

    for (int i = 0; i < 2; i++) {
        trace += M[i][i];
    }

    return trace;
}

const int n = 5;
const int m = 5;

int get_winning_team_of_day(int M[n][m], int k) {
    // n: teams
    // m: match days (standings)
    // k: chosen match day

    int winner_score = 0;
    int team_index = 0;

    if (k > m || k < 0) {
        return -1;
    };

    for (int i = 0; i < n; i++) {
        int team_score = 0;
        for (int j = 0; j <= k; j++) {
            team_score += M[i][j];
        }

        if (team_score > winner_score) {
            winner_score = team_score;
            team_index = i;
        }
    };

    return team_index;
}

const int a = 4;
const int b = 5;

void interval_of(double M[a][b], double x, double y, int P[2][b]) {

    for (int j = 0; j < b; j++) {
        double col_count = 0;
        for (int i = 0; i < a; i++) {
            if (M[i][j] >= x && M[i][j] <= y) {
                col_count++;
            }
        }

        P[0][j] = col_count;
        P[1][j] = a - col_count;
    }
}

double diff_between_matrix_triangles(int M[n][n]) {

    int upper_triangle = 0;
    int up_tr_count = 0;
    int lower_triangle = 0;
    int lw_tr_count = 0;

    // upper triangle
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            upper_triangle += M[i][j];
            up_tr_count++;
        }
    }

    // lower triangle
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            lower_triangle += M[i][j];
            lw_tr_count++;
        }
    }

    // avg values of each triangle
    double up_tr_avg = upper_triangle / up_tr_count;
    double lw_tr_avg = lower_triangle / lw_tr_count;
    // |delata|
    double diff = std::abs(up_tr_avg - lw_tr_avg);
    return diff;
}