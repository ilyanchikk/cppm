#include <iostream>
#include <Windows.h>
#include <vector>
#include <thread>
#include <chrono>
#include <string>

void fill_vect(std::vector<int>& v);
void print_vect(std::vector<int>& v);
void sum_vect(std::vector<int>& v3, std::vector<int>& v1, std::vector<int>& v2, int begin_el, int end_el);
double parallel_sum(std::vector<int>& v3, std::vector<int>& v1, std::vector<int>& v2, int threads);
void get_info_time(std::vector<int>& v3, std::vector<int>& v1, std::vector<int>& v2, int vector_size);
void clear_vect(std::vector<int>& v3, std::vector<int>& v1, std::vector<int>& v2);
void create_res_vect(int vector_size);



int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    int vector_size1{ 1000 };
    int vector_size2{ 10000 };
    int vector_size3{ 100000 };
    int vector_size4{ 1000000 };
    unsigned int hardwareCores = std::thread::hardware_concurrency();
    std::cout << "Количество аппаратных ядер: " << hardwareCores << std::endl;
  
    create_res_vect(vector_size1);
    create_res_vect(vector_size2);
    create_res_vect(vector_size3);
    create_res_vect(vector_size4);

    return 0;
}

void fill_vect(std::vector<int>& v) {
    for (int& el : v) {
        el = rand() % 10;
    }
}
void print_vect(std::vector<int>& v) {
    for (int& el : v) {
        std::cout << el << " ";
    }
}

void sum_vect(std::vector<int>& v3, std::vector<int>& v1, std::vector<int>& v2,int begin_el, int end_el) {
        for (int i = begin_el; i < end_el; i++) {
            v3[i] = v1[i] + v2[i];
        }
    }

double parallel_sum(std::vector<int>& v3, std::vector<int>& v1, std::vector<int>& v2, int threads) {
    int size = v3.size();
    int chunk = size / threads;
    std::vector<std::thread> vec_threads;
    auto start_time = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < threads; i++) {
        int begin_el = i * chunk;
        int end_el{};
        if (threads == 1) {
            end_el = size;
        }
        else {
            end_el = begin_el + chunk-1;
        }
        vec_threads.push_back(std::thread(sum_vect, ref(v3), ref(v1), ref(v2), begin_el, end_el));
       
    }
    for (int i = 0; i < threads; i++) {
        vec_threads[i].join();
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = start_time - end_time;

    return duration.count();
}

void get_info_time(std::vector<int>& v3, std::vector<int>& v1, std::vector<int>& v2, int vector_size) {
    std::vector<double> time(5);
    int start_thread = 1;
    for (int i = 0; i < 5; i++) {
        std::cout << "поток: " << start_thread;
        time[i] = parallel_sum(v3, v1, v2, start_thread);
        start_thread = start_thread * 2;
        std::cout << time[i] << " | ";
    }
    auto min_el = std::max_element(time.begin(), time.end());
    auto mi_index = std::distance(time.begin(), min_el);
    if (mi_index == 0) {
        mi_index = 1;
    }
    else if (mi_index == 1) {
        mi_index = 2;
    }
    else if (mi_index == 2) {
        mi_index = 4;
    }
    else if (mi_index == 3) {
        mi_index = 8;
    }
    else if (mi_index == 4) {
        mi_index = 16;
    }
    std::cout <<"Массив "<< vector_size << " элеменотов минимальное время на " << mi_index << " потоке: " << *min_el;
    std::cout << std::endl;
    time.clear();
}

void clear_vect(std::vector<int>& v3, std::vector<int>& v1, std::vector<int>& v2) {
    v1.clear();
    v2.clear();
    v3.clear();
}

void create_res_vect(int vector_size) {
    std::vector<int> v1(vector_size);
    fill_vect(v1);

    std::vector<int> v2(vector_size);
    fill_vect(v2);

    std::vector<int> v3(vector_size);

    get_info_time(v3, v1, v2, vector_size);

    clear_vect(v3,v1,v2);
}