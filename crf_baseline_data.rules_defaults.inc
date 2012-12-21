<?php
/**
 * @file
 * crf_baseline_data.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function crf_baseline_data_default_rules_configuration() {
  $items = array();
  $items['rules_email_ocha_focal_point_on_baseline_data_submission'] = entity_import('rules_config', '{ "rules_email_ocha_focal_point_on_baseline_data_submission" : {
      "LABEL" : "Email OCHA focal point on Baseline Data submission",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules" ],
      "ON" : [ "node_insert", "node_update" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "baseline_data" : "baseline_data" } }
          }
        },
        { "entity_has_field" : {
            "entity" : [ "node:field-nc-request" ],
            "field" : "field_crf_req_contact"
          }
        }
      ],
      "DO" : [
        { "LOOP" : {
            "USING" : { "list" : [ "node:field-nc-request:field-crf-req-contact" ] },
            "ITEM" : { "current_contact" : "Current contact" },
            "DO" : [
              { "mail" : {
                  "to" : [ "current-contact:mail" ],
                  "subject" : "Baseline Data provided by [node:author:field-first-name] [node:author:field-last-name] in [node:field-nc-request:title] is now finalised",
                  "message" : "Dear [current-contact:field-first-name] [current-contact:field-last-name],\\r\\n\\r\\nKindly note that the Baseline Data by [node:author:field-first-name] [node:author:field-last-name] in the Information Request [node:field-nc-request:title] has been finalised.  The information can be viewed online: [node:url]\\r\\n\\r\\nNo action is required on your part at this time.\\r\\n\\r\\nKind regards,\\r\\nOCHA\\r\\n",
                  "from" : [ "node:author:mail" ],
                  "language" : [ "" ]
                }
              }
            ]
          }
        },
        { "redirect" : { "url" : "\\u003Cfront\\u003E" } }
      ]
    }
  }');
  return $items;
}
