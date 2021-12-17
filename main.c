#include <polyglot.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 4096


size_t min(size_t a, size_t b){
    if (a < b)
        return a;
    return b;
}

void* getCpuInfo(){
    FILE *fin = fopen("/proc/cpuinfo", "r");    
    size_t curr_size = MAX_SIZE;
	char* cpu_info = (char*)malloc(sizeof(char) * curr_size);
	size_t read_total = 0;
	while (!feof(fin)){
		size_t read_cnt = fread(cpu_info + read_total, 1, min(MAX_SIZE, curr_size - read_total), fin);
		if (read_total + read_cnt >= curr_size){
			curr_size += MAX_SIZE;
			cpu_info = realloc(cpu_info, curr_size);
		}

		read_total += read_cnt;
    }

	if (read_total < curr_size)
		cpu_info[read_total] = '\0';
	else{
		cpu_info = realloc(cpu_info, curr_size + 1);
		cpu_info[curr_size] = '\0';
	}

    fclose(fin);
    void* polyglot_str = polyglot_from_string(cpu_info, "UTF-8");
	free(cpu_info);
    return polyglot_str;
}
