//
// Copyright 2016 Pixar
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
#ifndef PXRUSDMAYA_ROUND_TRIP_UTIL_H
#define PXRUSDMAYA_ROUND_TRIP_UTIL_H

#include <mayaUsd/base/api.h>

#include <pxr/pxr.h>
#include <pxr/usd/usd/attribute.h>
#include <pxr/usd/usdGeom/primvar.h>

PXR_NAMESPACE_OPEN_SCOPE

/// This holds some utility functions for dealing with data from Maya to Usd
/// and back.
struct UsdMayaRoundTripUtil
{
    /// Sometimes primvars like displayColor and displayOpacity aren't *really*
    /// authored by the user and instead are generated based on shaders, etc.
    /// This function encapsulates that logic so we can make this determination
    /// when importing a USD file. This just checks that there is an actual
    /// authored opinion and that it was not Maya generated.
    /// \sa IsAttributeMayaGenerated
    MAYAUSD_CORE_PUBLIC
    static bool IsAttributeUserAuthored(const UsdAttribute& attr);

    MAYAUSD_CORE_PUBLIC
    static bool IsAttributeMayaGenerated(const UsdAttribute& attr);

    /// Annotate that an attribute was generated by Maya.
    MAYAUSD_CORE_PUBLIC
    static void MarkAttributeAsMayaGenerated(const UsdAttribute& attr);

    /// Primvars in USD are not clamped but they may have originally have been
    /// clamped.
    MAYAUSD_CORE_PUBLIC
    static bool IsPrimvarClamped(const UsdGeomPrimvar& primvar);

    MAYAUSD_CORE_PUBLIC
    static void MarkPrimvarAsClamped(const UsdGeomPrimvar& primvar);

    /// If Maya attribute arrays are used, we may need to store this encoding.
    /// This is especially true for shading where connections are made between
    /// attributes inside the array. Returns true if this was marked as an
    /// array attribute and will set \p index. Returns false otherwise.
    MAYAUSD_CORE_PUBLIC
    static bool GetAttributeArray(const UsdAttribute& attr, unsigned int* index);

    MAYAUSD_CORE_PUBLIC
    static void MarkAttributeAsArray(const UsdAttribute& attr, const unsigned int index);
};

PXR_NAMESPACE_CLOSE_SCOPE

#endif
