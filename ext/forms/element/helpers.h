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

#ifndef PHALCON_FORMS_ELEMENT_HELPERS_H
#define PHALCON_FORMS_ELEMENT_HELPERS_H

#include "php_phalcon.h"
#include "kernel/main.h"
#include "kernel/fcall.h"

static inline void phalcon_forms_element_render_helper(const char *method, int use_checked, INTERNAL_FUNCTION_PARAMETERS)
{
	zval **attributes = NULL, *widget_attributes = NULL, *uc;

	phalcon_fetch_params_ex(0, 1, &attributes);

	if (!attributes) {
		attributes = &PHALCON_GLOBAL(z_null);
	}

	uc = use_checked ? PHALCON_GLOBAL(z_true) : PHALCON_GLOBAL(z_false);

	phalcon_call_method_params(
		widget_attributes, &widget_attributes,
		getThis(), SL("prepareattributes"),
		zend_inline_hash_func(SS("prepareattributes")) TSRMLS_CC,
		2, *attributes, uc
	);

	if (!EG(exception)) {
		phalcon_call_static_func_params(return_value, return_value_ptr, SL("phalcon\\tag"), method, strlen(method) TSRMLS_CC, 1, widget_attributes);
		if (EG(exception) && return_value_ptr) {
			ALLOC_INIT_ZVAL(*return_value_ptr);
		}

		zval_ptr_dtor(&widget_attributes);
	}
}

#endif /* PHALCON_FORMS_ELEMENT_HELPERS_H */
