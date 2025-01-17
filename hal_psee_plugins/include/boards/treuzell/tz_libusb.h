/**********************************************************************************************************************
 * Copyright (c) Prophesee S.A.                                                                                       *
 *                                                                                                                    *
 * Licensed under the Apache License, Version 2.0 (the "License");                                                    *
 * you may not use this file except in compliance with the License.                                                   *
 * You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0                                 *
 * Unless required by applicable law or agreed to in writing, software distributed under the License is distributed   *
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.                      *
 * See the License for the specific language governing permissions and limitations under the License.                 *
 **********************************************************************************************************************/

#ifndef METAVISION_HAL_TZ_LIBUSB_H
#define METAVISION_HAL_TZ_LIBUSB_H

#ifdef _MSC_VER
#define NOMINMAX // libusb.h includes windows.h which defines min max macros that we don't want
#endif

#include <system_error>
#include <libusb-1.0/libusb.h>

namespace Metavision {

/// LibUSB error category
class LibUsbError : public std::error_category {
public:
    virtual const char *name() const noexcept {
        return "LibUSB";
    }
    virtual std::string message(int err) const {
        return libusb_error_name(err);
    }
};

class LibUSBContext {
public:
    LibUSBContext();
    ~LibUSBContext();
    libusb_context *ctx();

private:
    libusb_context *ctx_;
};

} // namespace Metavision

#endif // METAVISION_HAL_TZ_LIBUSB_H
