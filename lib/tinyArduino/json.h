#pragma once

// Pull in the Particle/Wiring JSON API
#include "wiring_json.h"

// Flatten the names so your code doesn't care about spark:: namespaces
using JSONValue         = spark::JSONValue;
using JSONString        = spark::JSONString;
using JSONObjectIterator= spark::JSONObjectIterator;

// If your code uses these symbols, alias them too.
// (Adjust if your wiring_json uses a different enum/type name.)
static constexpr auto JSON_TYPE_OBJECT = spark::JSON_TYPE_OBJECT;
static constexpr auto JSON_TYPE_ARRAY  = spark::JSON_TYPE_ARRAY;
static constexpr auto JSON_TYPE_STRING = spark::JSON_TYPE_STRING;
static constexpr auto JSON_TYPE_NUMBER = spark::JSON_TYPE_NUMBER;
static constexpr auto JSON_TYPE_BOOL   = spark::JSON_TYPE_BOOL;
static constexpr auto JSON_TYPE_NULL   = spark::JSON_TYPE_NULL;
