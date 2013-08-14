
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/output.h"

/**
 * Phalcon\Cache\Frontend\Output
 *
 * Allows to cache output fragments captured with ob_* functions
 *
 *<code>
 * 
 * //Create an Output frontend. Cache the files for 2 days
 * $frontCache = new Phalcon\Cache\Frontend\Output(array(
 *   "lifetime" => 172800
 * ));
 *
 * // Create the component that will cache from the "Output" to a "File" backend
 * // Set the cache file directory - it's important to keep the "/" at the end of
 * // the value for the folder
 * $cache = new Phalcon\Cache\Backend\File($frontCache, array(
 *     "cacheDir" => "../app/cache/"
 * ));
 *
 * // Get/Set the cache file to ../app/cache/my-cache.html
 * $content = $cache->start("my-cache.html");
 *
 * // If $content is null then the content will be generated for the cache
 * if ($content === null) {
 *
 *     //Print date and time
 *     echo date("r");
 *
 *     //Generate a link to the sign-up action
 *     echo Phalcon\Tag::linkTo(
 *         array(
 *             "user/signup",
 *             "Sign Up",
 *             "class" => "signup-button"
 *         )
 *     );
 *
 *     // Store the output into the cache file
 *     $cache->save();
 *
 * } else {
 *
 *     // Echo the cached output
 *     echo $content;
 * }
 *</code>
 */


/**
 * Phalcon\Cache\Frontend\Output initializer
 */
PHALCON_INIT_CLASS(Phalcon_Cache_Frontend_Output){

	PHALCON_REGISTER_CLASS(Phalcon\\Cache\\Frontend, Output, cache_frontend_output, phalcon_cache_frontend_output_method_entry, 0);

	zend_declare_property_bool(phalcon_cache_frontend_output_ce, SL("_buffering"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_cache_frontend_output_ce, SL("_frontendOptions"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_cache_frontend_output_ce TSRMLS_CC, 1, phalcon_cache_frontendinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Cache\Frontend\Output constructor
 *
 * @param array $frontendOptions
 */
PHP_METHOD(Phalcon_Cache_Frontend_Output, __construct){

	zval *frontend_options = NULL;

	phalcon_fetch_params(0, 0, 1, &frontend_options);
	
	if (frontend_options) {
		phalcon_update_property_this(this_ptr, SL("_frontendOptions"), frontend_options TSRMLS_CC);
	}
}

/**
 * Returns cache lifetime
 *
 * @return integer
 */
PHP_METHOD(Phalcon_Cache_Frontend_Output, getLifetime){

	zval **options, **lifetime;

	options = phalcon_fetch_nproperty_this(this_ptr, SL("_frontendOptions"), PH_NOISY_CC);
	if (phalcon_array_isset_string_fetch(&lifetime, *options, SS("lifetime"))) {
		if (return_value_ptr) {
			zval_ptr_dtor(return_value_ptr);
			*return_value_ptr = *lifetime;
			Z_ADDREF_PP(lifetime);
		}
		else {
			RETURN_ZVAL(*lifetime, 1, 0);
		}
	}
	else {
		RETURN_LONG(1);
	}
}

/**
 * Check whether if frontend is buffering output
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Frontend_Output, isBuffering){


	RETURN_MEMBER(this_ptr, "_buffering");
}

/**
 * Starts output frontend
 */
PHP_METHOD(Phalcon_Cache_Frontend_Output, start){

	phalcon_update_property_bool(this_ptr, SL("_buffering"), 1 TSRMLS_CC);
	phalcon_ob_start(TSRMLS_C);
}

/**
 * Returns output cached content
 *
 * @return string
 */
PHP_METHOD(Phalcon_Cache_Frontend_Output, getContent){

	zval **buffering;

	buffering = phalcon_fetch_nproperty_this(this_ptr, SL("_buffering"), PH_NOISY_CC);
	if (zend_is_true(*buffering)) {
		phalcon_ob_get_contents((return_value_ptr ? *return_value_ptr : return_value) TSRMLS_CC);
	}
}

/**
 * Stops output frontend
 */
PHP_METHOD(Phalcon_Cache_Frontend_Output, stop){

	zval **buffering;

	buffering = phalcon_fetch_nproperty_this(this_ptr, SL("_buffering"), PH_NOISY_CC);
	if (zend_is_true(*buffering)) {
		phalcon_ob_end_clean(TSRMLS_C);
	}
	
	phalcon_update_property_bool(this_ptr, SL("_buffering"), 0 TSRMLS_CC);
}

/**
 * Prepare data to be stored
 *
 * @param mixed $data
 * @return mixed
 */
PHP_METHOD(Phalcon_Cache_Frontend_Output, beforeStore){

	if (return_value_ptr) {
		zval_ptr_dtor(return_value_ptr);
		phalcon_fetch_params(0, 1, 0, return_value_ptr);
		Z_ADDREF_PP(return_value_ptr);
	}
	else {
		zval *data;
		phalcon_fetch_params(0, 1, 0, &data);
		RETURN_CCTORW(data);
	}
}

/**
 * Prepares data to be retrieved to user
 *
 * @param mixed $data
 * @return mixed
 */
PHP_METHOD(Phalcon_Cache_Frontend_Output, afterRetrieve){

	if (return_value_ptr) {
		zval_ptr_dtor(return_value_ptr);
		phalcon_fetch_params(0, 1, 0, return_value_ptr);
		Z_ADDREF_PP(return_value_ptr);
	}
	else {
		zval *data;
		phalcon_fetch_params(0, 1, 0, &data);
		RETURN_CCTORW(data);
	}
}
