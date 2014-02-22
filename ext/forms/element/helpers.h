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
#include "tag.h"

static inline void phalcon_forms_element_render_helper(const char *method, int use_checked, INTERNAL_FUNCTION_PARAMETERS)
{
	zval **attributes = NULL, *widget_attributes = NULL, *uc;
	zval *params[1];

	phalcon_fetch_params_ex(0, 1, &attributes);

	if (!attributes) {
		attributes = &PHALCON_GLOBAL(z_null);
	}

	uc = use_checked ? PHALCON_GLOBAL(z_true) : PHALCON_GLOBAL(z_false);

	PHALCON_CALL_METHODW(&widget_attributes, getThis(), "prepareattributes", *attributes, uc);

	params[0] = widget_attributes;
	if (FAILURE == phalcon_return_call_class_method(return_value, return_value_ptr, phalcon_tag_ce, phalcon_fcall_ce, NULL, method, strlen(method), 1, params TSRMLS_CC)) {
		;
	}

	zval_ptr_dtor(&widget_attributes);
}

#endif /* PHALCON_FORMS_ELEMENT_HELPERS_H */
