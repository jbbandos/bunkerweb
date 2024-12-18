/*
 * ModSecurity, http://www.modsecurity.org/
 * Copyright (c) 2015 - 2021 Trustwave Holdings, Inc. (http://www.trustwave.com/)
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

#include "src/actions/accuracy.h"

#include "modsecurity/rule_with_actions.h"


namespace modsecurity::actions {


bool Accuracy::init(std::string *error) {
    try {
        m_accuracy = std::stoi(m_parser_payload);
    }  catch (...) {
        error->assign("Accuracy: The input \"" + m_parser_payload + "\" is " \
            "not a number.");
        return false;
    }
    return true;
}


bool Accuracy::evaluate(RuleWithActions *rule, Transaction *transaction) {
    rule->m_accuracy = m_accuracy;
    return true;
}


}  // namespace modsecurity::actions
