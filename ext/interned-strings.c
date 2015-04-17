/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  |          Vladimir Kolesnikov <vladimir@extrememember.com>              |
  +------------------------------------------------------------------------+
*/

#include "php_phalcon.h"
#include "interned-strings.h"
#include "kernel/main.h"
#include "kernel/string.h"

const char *phalcon_interned_DELETE         = NULL;
const char *phalcon_interned_GET            = NULL;
const char *phalcon_interned_HEAD           = NULL;
const char *phalcon_interned_OPTIONS        = NULL;
const char *phalcon_interned_PATCH          = NULL;
const char *phalcon_interned_POST           = NULL;
const char *phalcon_interned_PUT            = NULL;
const char *phalcon_interned_action         = NULL;
const char *phalcon_interned_alias          = NULL;
const char *phalcon_interned_all            = NULL;
const char *phalcon_interned_allowEmpty     = NULL;
const char *phalcon_interned_arguments      = NULL;
const char *phalcon_interned_balias         = NULL;
const char *phalcon_interned_binary_op      = NULL;
const char *phalcon_interned_code           = NULL;
const char *phalcon_interned_column         = NULL;
const char *phalcon_interned_columns        = NULL;
const char *phalcon_interned_conditions     = NULL;
const char *phalcon_interned_controller     = NULL;
const char *phalcon_interned_delete         = NULL;
const char *phalcon_interned_dispatcher     = NULL;
const char *phalcon_interned_distinct       = NULL;
const char *phalcon_interned_domain         = NULL;
const char *phalcon_interned_escaper        = NULL;
const char *phalcon_interned_expr           = NULL;
const char *phalcon_interned_fields         = NULL;
const char *phalcon_interned_file           = NULL;
const char *phalcon_interned_filter         = NULL;
const char *phalcon_interned_functionCall   = NULL;
const char *phalcon_interned_group          = NULL;
const char *phalcon_interned_groupBy        = NULL;
const char *phalcon_interned_having         = NULL;
const char *phalcon_interned_items          = NULL;
const char *phalcon_interned_joins          = NULL;
const char *phalcon_interned_label          = NULL;
const char *phalcon_interned_left           = NULL;
const char *phalcon_interned_limit          = NULL;
const char *phalcon_interned_line           = NULL;
const char *phalcon_interned_message        = NULL;
const char *phalcon_interned_model          = NULL;
const char *phalcon_interned_models         = NULL;
const char *phalcon_interned_modelsCache    = NULL;
const char *phalcon_interned_modelsManager  = NULL;
const char *phalcon_interned_modelsMetadata = NULL;
const char *phalcon_interned_module         = NULL;
const char *phalcon_interned_name           = NULL;
const char *phalcon_interned_namespace      = NULL;
const char *phalcon_interned_ns_alias       = NULL;
const char *phalcon_interned_number         = NULL;
const char *phalcon_interned_offset         = NULL;
const char *phalcon_interned_op             = NULL;
const char *phalcon_interned_order          = NULL;
const char *phalcon_interned_orderBy        = NULL;
const char *phalcon_interned_params         = NULL;
const char *phalcon_interned_parent         = NULL;
const char *phalcon_interned_paths          = NULL;
const char *phalcon_interned_qualified      = NULL;
const char *phalcon_interned_qualifiedName  = NULL;
const char *phalcon_interned_request        = NULL;
const char *phalcon_interned_response       = NULL;
const char *phalcon_interned_right          = NULL;
const char *phalcon_interned_router         = NULL;
const char *phalcon_interned_select         = NULL;
const char *phalcon_interned_self           = NULL;
const char *phalcon_interned_session        = NULL;
const char *phalcon_interned_sort           = NULL;
const char *phalcon_interned_source         = NULL;
const char *phalcon_interned_static         = NULL;
const char *phalcon_interned_sqlAlias       = NULL;
const char *phalcon_interned_table          = NULL;
const char *phalcon_interned_tables         = NULL;
const char *phalcon_interned_type           = NULL;
const char *phalcon_interned_update         = NULL;
const char *phalcon_interned_url            = NULL;
const char *phalcon_interned_value          = NULL;
const char *phalcon_interned_values         = NULL;
const char *phalcon_interned_where          = NULL;

PHALCON_STATIC void phalcon_init_interned_strings(TSRMLS_D)
{
	phalcon_interned_DELETE         = zend_new_interned_string(ZEND_STRS("DELETE"), 0 TSRMLS_CC);
	phalcon_interned_GET            = zend_new_interned_string(ZEND_STRS("GET"), 0 TSRMLS_CC);
	phalcon_interned_HEAD           = zend_new_interned_string(ZEND_STRS("HEAD"), 0 TSRMLS_CC);
	phalcon_interned_OPTIONS        = zend_new_interned_string(ZEND_STRS("OPTIONS"), 0 TSRMLS_CC);
	phalcon_interned_PATCH          = zend_new_interned_string(ZEND_STRS("PATCH"), 0 TSRMLS_CC);
	phalcon_interned_POST           = zend_new_interned_string(ZEND_STRS("POST"), 0 TSRMLS_CC);
	phalcon_interned_PUT            = zend_new_interned_string(ZEND_STRS("PUT"), 0 TSRMLS_CC);
	phalcon_interned_action         = zend_new_interned_string(ZEND_STRS("action"), 0 TSRMLS_CC);
	phalcon_interned_alias          = zend_new_interned_string(ZEND_STRS("alias"), 0 TSRMLS_CC);
	phalcon_interned_all            = zend_new_interned_string(ZEND_STRS("all"), 0 TSRMLS_CC);
	phalcon_interned_allowEmpty     = zend_new_interned_string(ZEND_STRS("allowEmpty"), 0 TSRMLS_CC);
	phalcon_interned_arguments      = zend_new_interned_string(ZEND_STRS("arguments"), 0 TSRMLS_CC);
	phalcon_interned_balias         = zend_new_interned_string(ZEND_STRS("balias"), 0 TSRMLS_CC);
	phalcon_interned_binary_op      = zend_new_interned_string(ZEND_STRS("binary-op"), 0 TSRMLS_CC);
	phalcon_interned_code           = zend_new_interned_string(ZEND_STRS("code"), 0 TSRMLS_CC);
	phalcon_interned_column         = zend_new_interned_string(ZEND_STRS("column"), 0 TSRMLS_CC);
	phalcon_interned_columns        = zend_new_interned_string(ZEND_STRS("columns"), 0 TSRMLS_CC);
	phalcon_interned_conditions     = zend_new_interned_string(ZEND_STRS("conditions"), 0 TSRMLS_CC);
	phalcon_interned_controller     = zend_new_interned_string(ZEND_STRS("controller"), 0 TSRMLS_CC);
	phalcon_interned_delete         = zend_new_interned_string(ZEND_STRS("delete"), 0 TSRMLS_CC);
	phalcon_interned_dispatcher     = zend_new_interned_string(ZEND_STRS("dispatcher"), 0 TSRMLS_CC);
	phalcon_interned_distinct       = zend_new_interned_string(ZEND_STRS("distinct"), 0 TSRMLS_CC);
	phalcon_interned_domain         = zend_new_interned_string(ZEND_STRS("domain"), 0 TSRMLS_CC);
	phalcon_interned_escaper        = zend_new_interned_string(ZEND_STRS("escaper"), 0 TSRMLS_CC);
	phalcon_interned_expr           = zend_new_interned_string(ZEND_STRS("expr"), 0 TSRMLS_CC);
	phalcon_interned_fields         = zend_new_interned_string(ZEND_STRS("fields"), 0 TSRMLS_CC);
	phalcon_interned_file           = zend_new_interned_string(ZEND_STRS("file"), 0 TSRMLS_CC);
	phalcon_interned_filter         = zend_new_interned_string(ZEND_STRS("filter"), 0 TSRMLS_CC);
	phalcon_interned_functionCall   = zend_new_interned_string(ZEND_STRS("functionCall"), 0 TSRMLS_CC);
	phalcon_interned_group          = zend_new_interned_string(ZEND_STRS("group"), 0 TSRMLS_CC);
	phalcon_interned_groupBy        = zend_new_interned_string(ZEND_STRS("groupBy"), 0 TSRMLS_CC);
	phalcon_interned_having         = zend_new_interned_string(ZEND_STRS("having"), 0 TSRMLS_CC);
	phalcon_interned_items          = zend_new_interned_string(ZEND_STRS("items"), 0 TSRMLS_CC);
	phalcon_interned_joins          = zend_new_interned_string(ZEND_STRS("joins"), 0 TSRMLS_CC);
	phalcon_interned_label          = zend_new_interned_string(ZEND_STRS("label"), 0 TSRMLS_CC);
	phalcon_interned_left           = zend_new_interned_string(ZEND_STRS("left"), 0 TSRMLS_CC);
	phalcon_interned_limit          = zend_new_interned_string(ZEND_STRS("limit"), 0 TSRMLS_CC);
	phalcon_interned_line           = zend_new_interned_string(ZEND_STRS("line"), 0 TSRMLS_CC);
	phalcon_interned_message        = zend_new_interned_string(ZEND_STRS("message"), 0 TSRMLS_CC);
	phalcon_interned_model          = zend_new_interned_string(ZEND_STRS("model"), 0 TSRMLS_CC);
	phalcon_interned_models         = zend_new_interned_string(ZEND_STRS("models"), 0 TSRMLS_CC);
	phalcon_interned_modelsCache    = zend_new_interned_string(ZEND_STRS("modelsCache"), 0 TSRMLS_CC);
	phalcon_interned_modelsManager  = zend_new_interned_string(ZEND_STRS("modelsManager"), 0 TSRMLS_CC);
	phalcon_interned_modelsMetadata = zend_new_interned_string(ZEND_STRS("modelsMetadata"), 0 TSRMLS_CC);
	phalcon_interned_module         = zend_new_interned_string(ZEND_STRS("module"), 0 TSRMLS_CC);
	phalcon_interned_name           = zend_new_interned_string(ZEND_STRS("name"), 0 TSRMLS_CC);
	phalcon_interned_namespace      = zend_new_interned_string(ZEND_STRS("namespace"), 0 TSRMLS_CC);
	phalcon_interned_ns_alias       = zend_new_interned_string(ZEND_STRS("ns-alias"), 0 TSRMLS_CC);
	phalcon_interned_number         = zend_new_interned_string(ZEND_STRS("number"), 0 TSRMLS_CC);
	phalcon_interned_offset         = zend_new_interned_string(ZEND_STRS("offset"), 0 TSRMLS_CC);
	phalcon_interned_op             = zend_new_interned_string(ZEND_STRS("op"), 0 TSRMLS_CC);
	phalcon_interned_order          = zend_new_interned_string(ZEND_STRS("order"), 0 TSRMLS_CC);
	phalcon_interned_orderBy        = zend_new_interned_string(ZEND_STRS("orderBy"), 0 TSRMLS_CC);
	phalcon_interned_params         = zend_new_interned_string(ZEND_STRS("params"), 0 TSRMLS_CC);
	phalcon_interned_parent         = zend_new_interned_string(ZEND_STRS("parent"), 0 TSRMLS_CC);
	phalcon_interned_paths          = zend_new_interned_string(ZEND_STRS("paths"), 0 TSRMLS_CC);
	phalcon_interned_qualified      = zend_new_interned_string(ZEND_STRS("qualified"), 0 TSRMLS_CC);
	phalcon_interned_qualifiedName  = zend_new_interned_string(ZEND_STRS("qualifiedName"), 0 TSRMLS_CC);
	phalcon_interned_request        = zend_new_interned_string(ZEND_STRS("request"), 0 TSRMLS_CC);
	phalcon_interned_response       = zend_new_interned_string(ZEND_STRS("response"), 0 TSRMLS_CC);
	phalcon_interned_right          = zend_new_interned_string(ZEND_STRS("right"), 0 TSRMLS_CC);
	phalcon_interned_router         = zend_new_interned_string(ZEND_STRS("router"), 0 TSRMLS_CC);
	phalcon_interned_select         = zend_new_interned_string(ZEND_STRS("select"), 0 TSRMLS_CC);
	phalcon_interned_self           = zend_new_interned_string(ZEND_STRS("self"), 0 TSRMLS_CC);
	phalcon_interned_session        = zend_new_interned_string(ZEND_STRS("session"), 0 TSRMLS_CC);
	phalcon_interned_sort           = zend_new_interned_string(ZEND_STRS("sort"), 0 TSRMLS_CC);
	phalcon_interned_source         = zend_new_interned_string(ZEND_STRS("source"), 0 TSRMLS_CC);
	phalcon_interned_static         = zend_new_interned_string(ZEND_STRS("static"), 0 TSRMLS_CC);
	phalcon_interned_sqlAlias       = zend_new_interned_string(ZEND_STRS("sqlAlias"), 0 TSRMLS_CC);
	phalcon_interned_table          = zend_new_interned_string(ZEND_STRS("table"), 0 TSRMLS_CC);
	phalcon_interned_tables         = zend_new_interned_string(ZEND_STRS("tables"), 0 TSRMLS_CC);
	phalcon_interned_type           = zend_new_interned_string(ZEND_STRS("type"), 0 TSRMLS_CC);
	phalcon_interned_update         = zend_new_interned_string(ZEND_STRS("update"), 0 TSRMLS_CC);
	phalcon_interned_url            = zend_new_interned_string(ZEND_STRS("url"), 0 TSRMLS_CC);
	phalcon_interned_value          = zend_new_interned_string(ZEND_STRS("value"), 0 TSRMLS_CC);
	phalcon_interned_values         = zend_new_interned_string(ZEND_STRS("values"), 0 TSRMLS_CC);
	phalcon_interned_where          = zend_new_interned_string(ZEND_STRS("where"), 0 TSRMLS_CC);
}
