/*
 * gzll.h
 *
 *  Created on: Mar 30, 2015
 *      Author: gu45zin
 */

#ifndef __GZLL_H__
#define __GZLL_H__

#include <stdint.h>

#include "gzll-apps.h"

void gzll_init();
void init();
void communication_thread();
void communication_init();

extern uint32_t gzll_rank;

uint32_t gzll_swapping();

struct gzll_page_t {
    enum PAGE_STATUS { UNUSED = 0, KERNEL = 1, USER = 2 } status;
    enum PAGE_PLACE { LOCAL = 0, GLOBAL = 1, BOTH = 2 } place;
    uint32_t page_local;
    uint32_t page_global;
    // TODO: task
};

void gzll_paging_init();
void gzll_paging_dpage_fault(uint32_t vaddr);
void gzll_paging_ipage_fault(uint32_t vaddr);

int gzll_page_alloc();

void gzll_apps_bootstrap();

void gzll_task_start(char* identifier, struct gzll_task *task);


#endif /* SRC_GZLL_H_ */
