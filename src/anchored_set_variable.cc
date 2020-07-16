/*
 * ModSecurity, http://www.modsecurity.org/
 * Copyright (c) 2015 - 2020 Trustwave Holdings, Inc. (http://www.trustwave.com/)
 *
 * You may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * If any of the files related to licensing are missing or if you have any
 * other questions related to licensing please contact Trustwave Holdings, Inc.
 * directly using the email address security@modsecurity.org.
 *
 */

#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "modsecurity/anchored_set_variable.h"
#include "modsecurity/modsecurity.h"
#include "modsecurity/transaction.h"
#include "src/utils/regex.h"
#include "src/variables/variable.h"

namespace modsecurity {

static void addReverse(VariableValueList* to, VariableValueList& from){
    for (auto reverse_iter = from.rbegin(); reverse_iter != from.rend(); ++reverse_iter){
        to->emplace_back(std::move(*reverse_iter));
    }
}

AnchoredSetVariable::AnchoredSetVariable(Transaction *t,
    const std::string &name)
    : m_transaction(t),
    m_name(name) {
        reserve(10);
    }


AnchoredSetVariable::~AnchoredSetVariable() {
    unset();
}


void AnchoredSetVariable::unset() {
    clear();
}

void AnchoredSetVariable::set(const std::string &key,
    const std::string &value, size_t offset, size_t size) {
    auto result = emplace(key, VariableValue(&m_name, &key, &value));

    result->second.addOrigin(VariableOrigin{size, offset});
}

void AnchoredSetVariable::set(const std::string &key,
    const std::string &value, size_t offset) {
  set(key, value, offset, value.size());
}

void AnchoredSetVariable::resolve(VariableValueList *l) {
    VariableValueList list;

    for (const auto& x : *this) {
        list.emplace_back(&x.second);
    }

    addReverse(l, list);
}


void AnchoredSetVariable::resolve(
    VariableValueList *l,
    variables::KeyExclusions &ke) {
    VariableValueList list;
    for (const auto& x : *this) {
        if (!ke.toOmit(x.first)) {
            list.emplace_back(&x.second);
        } else {
            ms_dbg_a(m_transaction, 7, "Excluding key: " + x.first
                + " from target value.");
        }
    }
    addReverse(l, list);
}


void AnchoredSetVariable::resolve(const std::string &key,
    VariableValueList *l) {
    auto range = this->equal_range(key);
    for (auto it = range.first; it != range.second; ++it) {
        l->emplace_back(&it->second);
    }
}


std::unique_ptr<std::string> AnchoredSetVariable::resolveFirst(
    const std::string &key) {
    auto range = equal_range(key);
    for (auto it = range.first; it != range.second; ++it) {
        std::unique_ptr<std::string> b(new std::string());
        b->assign(it->second.getValue());
        return b;
    }
    return nullptr;
}


void AnchoredSetVariable::resolveRegularExpression(Utils::Regex *r,
    VariableValueList *l) {
    VariableValueList list;
    for (const auto& x : *this) {
        int ret = Utils::regex_search(x.first, *r);
        if (ret <= 0) {
            continue;
        }
        list.emplace_back(&x.second);
    }
    addReverse(l, list);
}


void AnchoredSetVariable::resolveRegularExpression(Utils::Regex *r,
    VariableValueList *l,
    variables::KeyExclusions &ke) {
    VariableValueList list;
    for (const auto& x : *this) {
        int ret = Utils::regex_search(x.first, *r);
        if (ret <= 0) {
            continue;
        }
        if (!ke.toOmit(x.first)) {
            list.emplace_back(&x.second);
        } else {
            ms_dbg_a(m_transaction, 7, "Excluding key: " + x.first
                + " from target value.");
        }
    }
    addReverse(l, list);
}


}  // namespace modsecurity
