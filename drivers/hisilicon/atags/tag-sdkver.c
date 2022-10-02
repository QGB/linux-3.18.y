/******************************************************************************
 *  Copyright (C) 2015 Hisilicon Technologies CO.,LTD.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Create By Cai Zhiyong 2015.6.10
 *
******************************************************************************/

#include <linux/kernel.h>
#include <linux/string.h>
#include "setup.h"

static char sdkver_boot[64] = "0.0.0.0";

static int __init parse_sdkver(const struct tag *tag, void *fdt)
{
	memcpy(sdkver_boot, &tag->u, sizeof(sdkver_boot));

	sdkver_boot[sizeof(sdkver_boot)-1] = '\0';

	return 0;
}
struct tagtable tag_sdkver __initdata = {0x726d6d75, parse_sdkver};
/*****************************************************************************/

const char *get_sdkversion(void)
{
	return sdkver_boot;
}
EXPORT_SYMBOL(get_sdkversion);
