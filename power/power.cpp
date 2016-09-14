/*
 * Copyright (c) 2015 The CyanogenMod Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <hardware/power.h>

#define LOG_TAG "PowerHAL"
#include <utils/Log.h>

struct local_power_module {
    struct power_module base;
};

static void power_init(struct power_module *) {
}

static void power_set_interactive(struct power_module *, int on __unused) {
}

static void power_hint(struct power_module *module __unused, power_hint_t hint __unused, void *data __unused) {
}

static struct hw_module_methods_t power_module_methods = {
    .open = NULL,
};

void set_feature(struct power_module *module __unused, feature_t feature __unused, int state __unused) {
}

struct local_power_module HAL_MODULE_INFO_SYM = {
    base: {
       common: {
            tag: HARDWARE_MODULE_TAG,
            module_api_version: POWER_MODULE_API_VERSION_0_3,
            hal_api_version: HARDWARE_HAL_API_VERSION,
            id: POWER_HARDWARE_MODULE_ID,
            name: "Clovertrail Power HAL",
            author: "The CyanogenMod Project",
            methods: &power_module_methods,
            dso: 0,
            reserved: {0},
        },
        init: power_init,
        setInteractive: power_set_interactive,
        powerHint: power_hint,
        setFeature: set_feature,
        getFeature: 0,
    },
};
