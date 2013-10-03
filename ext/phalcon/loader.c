
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"


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
 +------------------------------------------------------------------------+
 */
/**
 * Phalcon\Loader
 *
 * This component helps to load your project classes automatically based on some conventions
 *
 *<code>
 * //Creates the autoloader
 * $loader = new Phalcon\Loader();
 *
 * //Register some namespaces
 * $loader->registerNamespaces(array(
 *   'Example\Base' => 'vendor/example/base/',
 *   'Example\Adapter' => 'vendor/example/adapter/',
 *   'Example' => 'vendor/example/'
 * ));
 *
 * //register autoloader
 * $loader->register();
 *
 * //Requiring this class will automatically include file vendor/example/adapter/Some.php
 * $adapter = Example\Adapter\Some();
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Loader) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Loader, phalcon, loader, phalcon_loader_method_entry, 0);

	zend_declare_property_null(phalcon_loader_ce, SL("_eventsManager"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_loader_ce, SL("_foundPath"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_loader_ce, SL("_checkedPath"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_loader_ce, SL("_prefixes"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_loader_ce, SL("_classes"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_loader_ce, SL("_extensions"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_loader_ce, SL("_namespaces"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_loader_ce, SL("_directories"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_loader_ce, SL("_registered"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_loader_ce TSRMLS_CC, 1, phalcon_events_eventsawareinterface_ce);

	return SUCCESS;

}

/**
 * Phalcon\Loader constructor
 */
PHP_METHOD(Phalcon_Loader, __construct) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "php", 1);
	zephir_array_fast_append(_0, _1);
	zephir_update_property_this(this_ptr, SL("_extensions"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the events manager
 *
 * @param Phalcon\Events\ManagerInterface eventsManager
 */
PHP_METHOD(Phalcon_Loader, setEventsManager) {

	zval *eventsManager;

	zephir_fetch_params(0, 1, 0, &eventsManager);



	zephir_update_property_this(this_ptr, SL("_eventsManager"), eventsManager TSRMLS_CC);

}

/**
 * Returns the internal event manager
 *
 * @return Phalcon\Events\ManagerInterface
 */
PHP_METHOD(Phalcon_Loader, getEventsManager) {


	RETURN_MEMBER(this_ptr, "_eventsManager");

}

/**
 * Sets an array of extensions that the loader must try in each attempt to locate the file
 *
 * @param array extensions
 * @param boolean merge
 * @return Phalcon\Loader
 */
PHP_METHOD(Phalcon_Loader, setExtensions) {

	zval *extensions;

	zephir_fetch_params(0, 1, 0, &extensions);



	if ((Z_TYPE_P(extensions) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STRW(phalcon_loader_exception_ce, "Parameter extensions must be an array");
		return;
	}
	zephir_update_property_this(this_ptr, SL("_extensions"), extensions TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Return file extensions registered in the loader
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Loader, getExtensions) {


	RETURN_MEMBER(this_ptr, "_extensions");

}

/**
 * Register namespaces and their related directories
 *
 * @param array namespaces
 * @param boolean merge
 * @return Phalcon\Loader
 */
PHP_METHOD(Phalcon_Loader, registerNamespaces) {

	zend_bool merge;
	zval *namespaces, *merge_param = NULL, *currentNamespaces, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &namespaces, &merge_param);

	if (!merge_param) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	if ((Z_TYPE_P(namespaces) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_loader_exception_ce, "Parameter namespaces must be an array");
		return;
	}
	if (merge) {
		currentNamespaces = zephir_fetch_nproperty_this(this_ptr, SL("_namespaces"), PH_NOISY_CC);
		if ((Z_TYPE_P(currentNamespaces) == IS_ARRAY)) {
			ZEPHIR_INIT_VAR(_0);
			zephir_fast_array_merge(_0, &(currentNamespaces), &(namespaces) TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("_namespaces"), _0 TSRMLS_CC);
		} else {
			zephir_update_property_this(this_ptr, SL("_namespaces"), namespaces TSRMLS_CC);
		}
	} else {
		zephir_update_property_this(this_ptr, SL("_namespaces"), namespaces TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Return current namespaces registered in the autoloader
 *
 * @param array
 */
PHP_METHOD(Phalcon_Loader, getNamespaces) {


	RETURN_MEMBER(this_ptr, "_namespaces");

}

/**
 * Register directories on which "not found" classes could be found
 *
 * @param array prefixes
 * @param boolean merge
 * @return Phalcon\Loader
 */
PHP_METHOD(Phalcon_Loader, registerPrefixes) {

	zend_bool merge;
	zval *prefixes, *merge_param = NULL, *currentPrefixes, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &prefixes, &merge_param);

	if (!merge_param) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	if ((Z_TYPE_P(prefixes) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_loader_exception_ce, "Parameter prefixes must be an array");
		return;
	}
	if (merge) {
		currentPrefixes = zephir_fetch_nproperty_this(this_ptr, SL("_prefixes"), PH_NOISY_CC);
		if ((Z_TYPE_P(currentPrefixes) == IS_ARRAY)) {
			ZEPHIR_INIT_VAR(_0);
			zephir_fast_array_merge(_0, &(currentPrefixes), &(prefixes) TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("_prefixes"), _0 TSRMLS_CC);
		} else {
			zephir_update_property_this(this_ptr, SL("_prefixes"), prefixes TSRMLS_CC);
		}
	} else {
		zephir_update_property_this(this_ptr, SL("_prefixes"), prefixes TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Return current prefixes registered in the autoloader
 *
 * @param array
 */
PHP_METHOD(Phalcon_Loader, getPrefixes) {


	RETURN_MEMBER(this_ptr, "_prefixes");

}

/**
 * Register directories on which "not found" classes could be found
 *
 * @param array directories
 * @param boolean merge
 * @return Phalcon\Loader
 */
PHP_METHOD(Phalcon_Loader, registerDirs) {

	zend_bool merge;
	zval *directories, *merge_param = NULL, *currentDirectories, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &directories, &merge_param);

	if (!merge_param) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	if ((Z_TYPE_P(directories) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_loader_exception_ce, "Parameter directories must be an array");
		return;
	}
	if (merge) {
		currentDirectories = zephir_fetch_nproperty_this(this_ptr, SL("_directories"), PH_NOISY_CC);
		if ((Z_TYPE_P(currentDirectories) == IS_ARRAY)) {
			ZEPHIR_INIT_VAR(_0);
			zephir_fast_array_merge(_0, &(currentDirectories), &(directories) TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("_directories"), _0 TSRMLS_CC);
		} else {
			zephir_update_property_this(this_ptr, SL("_directories"), directories TSRMLS_CC);
		}
	} else {
		zephir_update_property_this(this_ptr, SL("_directories"), directories TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Return current directories registered in the autoloader
 *
 * @param array
 */
PHP_METHOD(Phalcon_Loader, getDirs) {


	RETURN_MEMBER(this_ptr, "_directories");

}

/**
 * Register classes and their locations
 *
 * @param array classes
 * @param boolean merge
 * @return Phalcon\Loader
 */
PHP_METHOD(Phalcon_Loader, registerClasses) {

	zend_bool merge;
	zval *classes, *merge_param = NULL, *currentClasses, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &classes, &merge_param);

	if (!merge_param) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	if ((Z_TYPE_P(classes) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_loader_exception_ce, "Parameter directories must be an array");
		return;
	}
	if (merge) {
		currentClasses = zephir_fetch_nproperty_this(this_ptr, SL("_classes"), PH_NOISY_CC);
		if ((Z_TYPE_P(currentClasses) == IS_ARRAY)) {
			ZEPHIR_INIT_VAR(_0);
			zephir_fast_array_merge(_0, &(currentClasses), &(classes) TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("_classes"), _0 TSRMLS_CC);
		} else {
			zephir_update_property_this(this_ptr, SL("_classes"), classes TSRMLS_CC);
		}
	} else {
		zephir_update_property_this(this_ptr, SL("_classes"), classes TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Return the current class-map registered in the autoloader
 *
 * @param array
 */
PHP_METHOD(Phalcon_Loader, getClasses) {


	RETURN_MEMBER(this_ptr, "_classes");

}

/**
 * Register the autoload method
 *
 * @return Phalcon\Loader
 */
PHP_METHOD(Phalcon_Loader, register) {

	zval *registered, *_0, *_1;

	ZEPHIR_MM_GROW();

	registered = zephir_fetch_nproperty_this(this_ptr, SL("_registered"), PH_NOISY_CC);
	if (ZEPHIR_IS_FALSE(registered)) {
		ZEPHIR_INIT_VAR(_0);
		array_init(_0);
		zephir_array_fast_append(_0, this_ptr);
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "autoLoad", 1);
		zephir_array_fast_append(_0, _1);
		zephir_call_func_p1_noret("spl_autoload_register", _0);
		zephir_update_property_this(this_ptr, SL("_registered"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Unregister the autoload method
 *
 * @return Phalcon\Loader
 */
PHP_METHOD(Phalcon_Loader, unregister) {

	zval *registered, *_0, *_1;

	ZEPHIR_MM_GROW();

	registered = zephir_fetch_nproperty_this(this_ptr, SL("_registered"), PH_NOISY_CC);
	if (ZEPHIR_IS_FALSE(registered)) {
		ZEPHIR_INIT_VAR(_0);
		array_init(_0);
		zephir_array_fast_append(_0, this_ptr);
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "autoLoad", 1);
		zephir_array_fast_append(_0, _1);
		zephir_call_func_p1_noret("spl_autoload_unregister", _0);
		zephir_update_property_this(this_ptr, SL("_registered"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Makes the work of autoload registered classes
 *
 * @param string className
 * @return boolean
 */
PHP_METHOD(Phalcon_Loader, autoLoad) {

	zval *className_param = NULL;
	zval *className = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &className_param);

		zephir_get_strval(className, className_param);



}

/**
 * Get the path when a class was found
 *
 * @return string
 */
PHP_METHOD(Phalcon_Loader, getFoundPath) {


	RETURN_MEMBER(this_ptr, "_foundPath");

}

/**
 * Get the path the loader is checking for a path
 *
 * @return string
 */
PHP_METHOD(Phalcon_Loader, getCheckedPath) {


	RETURN_MEMBER(this_ptr, "_checkedPath");

}

