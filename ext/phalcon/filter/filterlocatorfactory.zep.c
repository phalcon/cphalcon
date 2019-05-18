
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
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/fcall.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_FilterLocatorFactory) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Filter, FilterLocatorFactory, phalcon, filter_filterlocatorfactory, phalcon_filter_filterlocatorfactory_method_entry, 0);

	zend_class_implements(phalcon_filter_filterlocatorfactory_ce TSRMLS_CC, 1, phalcon_service_locatorfactoryinterface_ce);
	return SUCCESS;

}

/**
 * Returns a Locator object with all the helpers defined in anonynous
 * functions
 */
PHP_METHOD(Phalcon_Filter_FilterLocatorFactory, newInstance) {

	zval locator, helpers, _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&locator);
	ZVAL_UNDEF(&helpers);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&helpers);
	zephir_create_array(&helpers, 21, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_1__closure_ce, SL("__invoke"));
	zephir_array_update_string(&helpers, SL("absint"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_2__closure_ce, SL("__invoke"));
	zephir_array_update_string(&helpers, SL("alnum"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_3__closure_ce, SL("__invoke"));
	zephir_array_update_string(&helpers, SL("alpha"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_4__closure_ce, SL("__invoke"));
	zephir_array_update_string(&helpers, SL("bool"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_5__closure_ce, SL("__invoke"));
	zephir_array_update_string(&helpers, SL("email"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_6__closure_ce, SL("__invoke"));
	zephir_array_update_string(&helpers, SL("float"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_7__closure_ce, SL("__invoke"));
	zephir_array_update_string(&helpers, SL("int"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_8__closure_ce, SL("__invoke"));
	zephir_array_update_string(&helpers, SL("lower"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_9__closure_ce, SL("__invoke"));
	zephir_array_update_string(&helpers, SL("lowerFirst"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_10__closure_ce, SL("__invoke"));
	zephir_array_update_string(&helpers, SL("regex"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_11__closure_ce, SL("__invoke"));
	zephir_array_update_string(&helpers, SL("remove"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_12__closure_ce, SL("__invoke"));
	zephir_array_update_string(&helpers, SL("replace"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_13__closure_ce, SL("__invoke"));
	zephir_array_update_string(&helpers, SL("special"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_14__closure_ce, SL("__invoke"));
	zephir_array_update_string(&helpers, SL("specialFull"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_15__closure_ce, SL("__invoke"));
	zephir_array_update_string(&helpers, SL("string"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_16__closure_ce, SL("__invoke"));
	zephir_array_update_string(&helpers, SL("striptags"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_17__closure_ce, SL("__invoke"));
	zephir_array_update_string(&helpers, SL("trim"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_18__closure_ce, SL("__invoke"));
	zephir_array_update_string(&helpers, SL("upper"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_19__closure_ce, SL("__invoke"));
	zephir_array_update_string(&helpers, SL("upperFirst"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_20__closure_ce, SL("__invoke"));
	zephir_array_update_string(&helpers, SL("upperWords"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_21__closure_ce, SL("__invoke"));
	zephir_array_update_string(&helpers, SL("url"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&locator);
	object_init_ex(&locator, phalcon_filter_filterlocator_ce);
	ZEPHIR_CALL_METHOD(NULL, &locator, "__construct", NULL, 207, &helpers);
	zephir_check_call_status();
	RETURN_CCTOR(&locator);

}

