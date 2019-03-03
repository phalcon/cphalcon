
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Html\TagLocator
 *
 * ServiceLocator implementation for Tag helpers
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_TagLocatorFactory) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Html, TagLocatorFactory, phalcon, html_taglocatorfactory, phalcon_html_taglocatorfactory_method_entry, 0);

	/**
	 * @var EscaperInterface
	 */
	zend_declare_property_null(phalcon_html_taglocatorfactory_ce, SL("escaper"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_class_implements(phalcon_html_taglocatorfactory_ce TSRMLS_CC, 1, phalcon_service_locatorfactoryinterface_ce);
	return SUCCESS;

}

/**
 * Returns a Locator object with all the helpers defined in anonynous
 * functions
 */
PHP_METHOD(Phalcon_Html_TagLocatorFactory, newInstance) {

	zval escaper, helpers, _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&escaper);
	ZVAL_UNDEF(&helpers);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&escaper, this_ptr, "getescaper", NULL, 211);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&helpers);
	zephir_create_array(&helpers, 25, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_0__closure_ce, SL("__invoke"));
	zephir_array_update_string(&helpers, SL("a"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_1__closure_ce, SL("__invoke"));
	zephir_array_update_string(&helpers, SL("base"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_2__closure_ce, SL("__invoke"));
	zephir_array_update_string(&helpers, SL("blockquote"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_3__closure_ce, SL("__invoke"));
	zephir_array_update_string(&helpers, SL("body"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_4__closure_ce, SL("__invoke"));
	zephir_array_update_string(&helpers, SL("button"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_5__closure_ce, SL("__invoke"));
	zephir_array_update_string(&helpers, SL("code"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_6__closure_ce, SL("__invoke"));
	zephir_array_update_string(&helpers, SL("comment"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_7__closure_ce, SL("__invoke"));
	zephir_array_update_string(&helpers, SL("data"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_8__closure_ce, SL("__invoke"));
	zephir_array_update_string(&helpers, SL("datalist"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_9__closure_ce, SL("__invoke"));
	zephir_array_update_string(&helpers, SL("doctype"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_10__closure_ce, SL("__invoke"));
	zephir_array_update_string(&helpers, SL("element"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_11__closure_ce, SL("__invoke"));
	zephir_array_update_string(&helpers, SL("form"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_12__closure_ce, SL("__invoke"));
	zephir_array_update_string(&helpers, SL("formClose"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_13__closure_ce, SL("__invoke"));
	zephir_array_update_string(&helpers, SL("head"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_14__closure_ce, SL("__invoke"));
	zephir_array_update_string(&helpers, SL("header"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_15__closure_ce, SL("__invoke"));
	zephir_array_update_string(&helpers, SL("hr"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_16__closure_ce, SL("__invoke"));
	zephir_array_update_string(&helpers, SL("img"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_17__closure_ce, SL("__invoke"));
	zephir_array_update_string(&helpers, SL("input"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_18__closure_ce, SL("__invoke"));
	zephir_array_update_string(&helpers, SL("label"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_19__closure_ce, SL("__invoke"));
	zephir_array_update_string(&helpers, SL("link"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_20__closure_ce, SL("__invoke"));
	zephir_array_update_string(&helpers, SL("script"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_21__closure_ce, SL("__invoke"));
	zephir_array_update_string(&helpers, SL("span"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_22__closure_ce, SL("__invoke"));
	zephir_array_update_string(&helpers, SL("style"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_23__closure_ce, SL("__invoke"));
	zephir_array_update_string(&helpers, SL("textarea"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_24__closure_ce, SL("__invoke"));
	zephir_array_update_string(&helpers, SL("title"), &_0, PH_COPY | PH_SEPARATE);
	object_init_ex(return_value, phalcon_service_locator_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 187, &helpers);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Get the escaper service
 *
 * I really don't like this here but it has to be here this way because there
 * is a lot mroe groundwork to be done to refactor the whole DI implementation
 */
PHP_METHOD(Phalcon_Html_TagLocatorFactory, getEscaper) {

	zval container, escaper, _1, _2, _3$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&escaper);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_CE_STATIC(&container, phalcon_di_ce, "getdefault", &_0, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "escaper");
	ZEPHIR_CALL_METHOD(&_1, &container, "has", NULL, 0, &_2);
	zephir_check_call_status();
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_1)) {
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "escaper");
		ZEPHIR_CALL_METHOD(&escaper, &container, "getservice", NULL, 0, &_3$$3);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&escaper);
		object_init_ex(&escaper, phalcon_escaper_ce);
		if (zephir_has_constructor(&escaper TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, &escaper, "__construct", NULL, 0);
			zephir_check_call_status();
		}
	}
	RETURN_CCTOR(&escaper);

}

