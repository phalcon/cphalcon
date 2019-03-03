
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/fcall.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Cache\Frontend\Output
 *
 * Allows to cache output fragments captured with ob_* functions
 *
*<code>
* use Phalcon\Tag;
* use Phalcon\Cache\Backend\File;
* use Phalcon\Cache\Frontend\Output;
*
* // Create an Output frontend. Cache the files for 2 days
* $frontCache = new Output(
*     [
*         "lifetime" => 172800,
*     ]
* );
*
* // Create the component that will cache from the "Output" to a "File" backend
* // Set the cache file directory - it's important to keep the "/" at the end of
* // the value for the folder
* $cache = new File(
*     $frontCache,
*     [
*         "cacheDir" => "../app/cache/",
*     ]
* );
*
* // Get/Set the cache file to ../app/cache/my-cache.html
* $content = $cache->start("my-cache.html");
*
* // If $content is null then the content will be generated for the cache
* if (null === $content) {
*     // Print date and time
*     echo date("r");
*
*     // Generate a link to the sign-up action
*     echo Tag::linkTo(
*         [
*             "user/signup",
*             "Sign Up",
*             "class" => "signup-button",
*         ]
*     );
*
*     // Store the output into the cache file
*     $cache->save();
* } else {
*     // Echo the cached output
*     echo $content;
* }
*</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Cache_Frontend_Output) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Cache\\Frontend, Output, phalcon, cache_frontend_output, phalcon_cache_frontend_output_method_entry, 0);

	zend_declare_property_bool(phalcon_cache_frontend_output_ce, SL("_buffering"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_cache_frontend_output_ce, SL("_frontendOptions"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_cache_frontend_output_ce TSRMLS_CC, 1, phalcon_cache_frontendinterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Cache\Frontend\Output constructor
 */
PHP_METHOD(Phalcon_Cache_Frontend_Output, __construct) {

	zval *frontendOptions_param = NULL;
	zval frontendOptions;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&frontendOptions);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &frontendOptions_param);

	if (!frontendOptions_param) {
		ZEPHIR_INIT_VAR(&frontendOptions);
		array_init(&frontendOptions);
	} else {
		zephir_get_arrval(&frontendOptions, frontendOptions_param);
	}


	zephir_update_property_zval(this_ptr, SL("_frontendOptions"), &frontendOptions);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the cache lifetime
 */
PHP_METHOD(Phalcon_Cache_Frontend_Output, getLifetime) {

	zval options, lifetime;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&lifetime);


	zephir_read_property(&options, this_ptr, SL("_frontendOptions"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&options) == IS_ARRAY) {
		if (zephir_array_isset_string_fetch(&lifetime, &options, SL("lifetime"), 1)) {
			RETURN_CTORW(&lifetime);
		}
	}
	RETURN_LONG(1);

}

/**
 * Check whether if frontend is buffering output
 */
PHP_METHOD(Phalcon_Cache_Frontend_Output, isBuffering) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_buffering");

}

/**
 * Starts output frontend. Currently, does nothing
 */
PHP_METHOD(Phalcon_Cache_Frontend_Output, start) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval __$true, __$false;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	ZEPHIR_MM_GROW();

	if (1) {
		zephir_update_property_zval(this_ptr, SL("_buffering"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_buffering"), &__$false);
	}
	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 114);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns output cached content
 *
 * @return string
 */
PHP_METHOD(Phalcon_Cache_Frontend_Output, getContent) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_buffering"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_RETURN_CALL_FUNCTION("ob_get_contents", NULL, 115);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_NULL();

}

/**
 * Stops output frontend
 */
PHP_METHOD(Phalcon_Cache_Frontend_Output, stop) {

	zval __$true, __$false, _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_buffering"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_FUNCTION(NULL, "ob_end_clean", NULL, 116);
		zephir_check_call_status();
	}
	if (0) {
		zephir_update_property_zval(this_ptr, SL("_buffering"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_buffering"), &__$false);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Serializes data before storing them
 */
PHP_METHOD(Phalcon_Cache_Frontend_Output, beforeStore) {

	zval *data, data_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);

	zephir_fetch_params(0, 1, 0, &data);



	RETVAL_ZVAL(data, 1, 0);
	return;

}

/**
 * Unserializes data after retrieval
 */
PHP_METHOD(Phalcon_Cache_Frontend_Output, afterRetrieve) {

	zval *data, data_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);

	zephir_fetch_params(0, 1, 0, &data);



	RETVAL_ZVAL(data, 1, 0);
	return;

}

