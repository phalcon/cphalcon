
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Html\Helper\Label
 *
 * Creates a label
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Label) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Helper, Label, phalcon, html_helper_label, phalcon_html_helper_abstracthelper_ce, phalcon_html_helper_label_method_entry, 0);

	return SUCCESS;

}

/**
 * @param array $attributes Any additional attributes
 *
 * @return string
 * @throws Exception
 */
PHP_METHOD(Phalcon_Html_Helper_Label, __invoke) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attributes_param = NULL, _0;
	zval attributes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &attributes_param);

	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&attributes, attributes_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "label");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "renderelement", NULL, 0, &_0, &attributes);
	zephir_check_call_status();
	RETURN_MM();

}

