/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php_phalcon.h"
#include "kernel/main.h"
#include "kernel/string.h"

#include "interned-strings.h"

const char *phalcon_interned_DELETE         = NULL;
const char *phalcon_interned_GET            = NULL;
const char *phalcon_interned_HEAD           = NULL;
const char *phalcon_interned_OPTIONS        = NULL;
const char *phalcon_interned_PATCH          = NULL;
const char *phalcon_interned_POST           = NULL;
const char *phalcon_interned_PUT            = NULL;
const char *phalcon_interned_alias          = NULL;
const char *phalcon_interned_all            = NULL;
const char *phalcon_interned_arguments      = NULL;
const char *phalcon_interned_balias         = NULL;
const char *phalcon_interned_binary_op      = NULL;
const char *phalcon_interned_column         = NULL;
const char *phalcon_interned_columns        = NULL;
const char *phalcon_interned_conditions     = NULL;
const char *phalcon_interned_controller     = NULL;
const char *phalcon_interned_delete         = NULL;
const char *phalcon_interned_distinct       = NULL;
const char *phalcon_interned_domain         = NULL;
const char *phalcon_interned_expr           = NULL;
const char *phalcon_interned_fields         = NULL;
const char *phalcon_interned_file           = NULL;
const char *phalcon_interned_functionCall   = NULL;
const char *phalcon_interned_group          = NULL;
const char *phalcon_interned_groupBy        = NULL;
const char *phalcon_interned_having         = NULL;
const char *phalcon_interned_items          = NULL;
const char *phalcon_interned_joins          = NULL;
const char *phalcon_interned_left           = NULL;
const char *phalcon_interned_limit          = NULL;
const char *phalcon_interned_line           = NULL;
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
const char *phalcon_interned_paths          = NULL;
const char *phalcon_interned_qualified      = NULL;
const char *phalcon_interned_qualifiedName  = NULL;
const char *phalcon_interned_right          = NULL;
const char *phalcon_interned_select         = NULL;
const char *phalcon_interned_sort           = NULL;
const char *phalcon_interned_source         = NULL;
const char *phalcon_interned_sqlAlias       = NULL;
const char *phalcon_interned_table          = NULL;
const char *phalcon_interned_tables         = NULL;
const char *phalcon_interned_type           = NULL;
const char *phalcon_interned_update         = NULL;
const char *phalcon_interned_value          = NULL;
const char *phalcon_interned_values         = NULL;
const char *phalcon_interned_where          = NULL;

PHALCON_STATIC void phalcon_init_interned_strings(TSRMLS_D)
{
	phalcon_interned_DELETE         = zend_new_interned_string(SS("DELETE"), 0 TSRMLS_CC);
	phalcon_interned_GET            = zend_new_interned_string(SS("GET"), 0 TSRMLS_CC);
	phalcon_interned_HEAD           = zend_new_interned_string(SS("HEAD"), 0 TSRMLS_CC);
	phalcon_interned_OPTIONS        = zend_new_interned_string(SS("OPTIONS"), 0 TSRMLS_CC);
	phalcon_interned_PATCH          = zend_new_interned_string(SS("PATCH"), 0 TSRMLS_CC);
	phalcon_interned_POST           = zend_new_interned_string(SS("POST"), 0 TSRMLS_CC);
	phalcon_interned_PUT            = zend_new_interned_string(SS("PUT"), 0 TSRMLS_CC);
	phalcon_interned_alias          = zend_new_interned_string(SS("alias"), 0 TSRMLS_CC);
	phalcon_interned_all            = zend_new_interned_string(SS("all"), 0 TSRMLS_CC);
	phalcon_interned_arguments      = zend_new_interned_string(SS("arguments"), 0 TSRMLS_CC);
	phalcon_interned_balias         = zend_new_interned_string(SS("balias"), 0 TSRMLS_CC);
	phalcon_interned_binary_op      = zend_new_interned_string(SS("binary-op"), 0 TSRMLS_CC);
	phalcon_interned_column         = zend_new_interned_string(SS("column"), 0 TSRMLS_CC);
	phalcon_interned_columns        = zend_new_interned_string(SS("columns"), 0 TSRMLS_CC);
	phalcon_interned_conditions     = zend_new_interned_string(SS("conditions"), 0 TSRMLS_CC);
	phalcon_interned_controller     = zend_new_interned_string(SS("controller"), 0 TSRMLS_CC);
	phalcon_interned_delete         = zend_new_interned_string(SS("delete"), 0 TSRMLS_CC);
	phalcon_interned_distinct       = zend_new_interned_string(SS("distinct"), 0 TSRMLS_CC);
	phalcon_interned_domain         = zend_new_interned_string(SS("domain"), 0 TSRMLS_CC);
	phalcon_interned_expr           = zend_new_interned_string(SS("expr"), 0 TSRMLS_CC);
	phalcon_interned_fields         = zend_new_interned_string(SS("fields"), 0 TSRMLS_CC);
	phalcon_interned_file           = zend_new_interned_string(SS("file"), 0 TSRMLS_CC);
	phalcon_interned_functionCall   = zend_new_interned_string(SS("functionCall"), 0 TSRMLS_CC);
	phalcon_interned_group          = zend_new_interned_string(SS("group"), 0 TSRMLS_CC);
	phalcon_interned_groupBy        = zend_new_interned_string(SS("groupBy"), 0 TSRMLS_CC);
	phalcon_interned_having         = zend_new_interned_string(SS("having"), 0 TSRMLS_CC);
	phalcon_interned_items          = zend_new_interned_string(SS("items"), 0 TSRMLS_CC);
	phalcon_interned_joins          = zend_new_interned_string(SS("joins"), 0 TSRMLS_CC);
	phalcon_interned_left           = zend_new_interned_string(SS("left"), 0 TSRMLS_CC);
	phalcon_interned_limit          = zend_new_interned_string(SS("limit"), 0 TSRMLS_CC);
	phalcon_interned_line           = zend_new_interned_string(SS("line"), 0 TSRMLS_CC);
	phalcon_interned_model          = zend_new_interned_string(SS("model"), 0 TSRMLS_CC);
	phalcon_interned_models         = zend_new_interned_string(SS("models"), 0 TSRMLS_CC);
	phalcon_interned_modelsCache    = zend_new_interned_string(SS("modelsCache"), 0 TSRMLS_CC);
	phalcon_interned_modelsManager  = zend_new_interned_string(SS("modelsManager"), 0 TSRMLS_CC);
	phalcon_interned_modelsMetadata = zend_new_interned_string(SS("modelsMetadata"), 0 TSRMLS_CC);
	phalcon_interned_module         = zend_new_interned_string(SS("module"), 0 TSRMLS_CC);
	phalcon_interned_name           = zend_new_interned_string(SS("name"), 0 TSRMLS_CC);
	phalcon_interned_namespace      = zend_new_interned_string(SS("namespace"), 0 TSRMLS_CC);
	phalcon_interned_ns_alias       = zend_new_interned_string(SS("ns-alias"), 0 TSRMLS_CC);
	phalcon_interned_number         = zend_new_interned_string(SS("number"), 0 TSRMLS_CC);
	phalcon_interned_offset         = zend_new_interned_string(SS("offset"), 0 TSRMLS_CC);
	phalcon_interned_op             = zend_new_interned_string(SS("op"), 0 TSRMLS_CC);
	phalcon_interned_order          = zend_new_interned_string(SS("order"), 0 TSRMLS_CC);
	phalcon_interned_orderBy        = zend_new_interned_string(SS("orderBy"), 0 TSRMLS_CC);
	phalcon_interned_params         = zend_new_interned_string(SS("params"), 0 TSRMLS_CC);
	phalcon_interned_paths          = zend_new_interned_string(SS("paths"), 0 TSRMLS_CC);
	phalcon_interned_qualified      = zend_new_interned_string(SS("qualified"), 0 TSRMLS_CC);
	phalcon_interned_qualifiedName  = zend_new_interned_string(SS("qualifiedName"), 0 TSRMLS_CC);
	phalcon_interned_right          = zend_new_interned_string(SS("right"), 0 TSRMLS_CC);
	phalcon_interned_select         = zend_new_interned_string(SS("select"), 0 TSRMLS_CC);
	phalcon_interned_sort           = zend_new_interned_string(SS("sort"), 0 TSRMLS_CC);
	phalcon_interned_source         = zend_new_interned_string(SS("source"), 0 TSRMLS_CC);
	phalcon_interned_sqlAlias       = zend_new_interned_string(SS("sqlAlias"), 0 TSRMLS_CC);
	phalcon_interned_table          = zend_new_interned_string(SS("table"), 0 TSRMLS_CC);
	phalcon_interned_tables         = zend_new_interned_string(SS("tables"), 0 TSRMLS_CC);
	phalcon_interned_type           = zend_new_interned_string(SS("type"), 0 TSRMLS_CC);
	phalcon_interned_update         = zend_new_interned_string(SS("update"), 0 TSRMLS_CC);
	phalcon_interned_value          = zend_new_interned_string(SS("value"), 0 TSRMLS_CC);
	phalcon_interned_values         = zend_new_interned_string(SS("values"), 0 TSRMLS_CC);
	phalcon_interned_where          = zend_new_interned_string(SS("where"), 0 TSRMLS_CC);
}
