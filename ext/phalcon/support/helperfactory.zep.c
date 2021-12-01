
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
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * ServiceLocator implementation for helpers
 *
 * @method array  blacklist(array $collection, array $blackList)
 * @method array  chunk(array $collection, int $size, bool $preserveKeys = false)
 * @method mixed  first(array $collection, callable $method = null)
 * @method mixed  firstKey(array $collection, callable $method = null)
 * @method array  flatten(array $collection, bool $deep = false)
 * @method mixed  get(array $collection, $index, $defaultValue = null, string $cast = null)
 * @method array  group(array $collection, $method)
 * @method bool   has(array $collection, $index)
 * @method bool   isUnique(array $collection)
 * @method mixed  last(array $collection, callable $method = null)
 * @method mixed  lastKey(array $collection, callable $method = null)
 * @method array  order(array $collection, $attribute, string $order = 'asc')
 * @method array  pluck(array $collection, string $element)
 * @method array  set(array $collection, $value, $index = null)
 * @method array  sliceLeft(array $collection, int $elements = 1)
 * @method array  sliceRight(array $collection, int $elements = 1)
 * @method array  split(array $collection)
 * @method object toObject(array $collection)
 * @method bool   validateAll(array $collection, callable $method)
 * @method bool   validateAny(array $collection, callable $method)
 * @method array  whitelist(array $collection, array $whiteList)
 * @method string basename(string $uri, string $suffix = null)
 * @method string decode(string $data, bool $associative = false, int $depth = 512, int $options = 0)
 * @method string encode($data, int $options = 0, int $depth = 512)
 * @method bool   between(int $value, int $start, int $end)
 * @method string concat(string $delimiter, string $first, string $second, string ...$arguments)
 * @method int    countVowels(string $text)
 * @method string decapitalize(string $text, bool $upperRest = false, string $encoding = 'UTF-8')
 * @method string decrement(string $text, string $separator = '_')
 * @method string dirFromFile(string $file)
 * @method string dirSeparator(string $directory)
 * @method bool   endsWith(string $haystack, string $needle, bool $ignoreCase = true)
 * @method string firstBetween(string $text, string $start, string $end)
 * @method string friendly(string $text, string $separator = '-', bool $lowercase = true, $replace = null)
 * @method string humanize(string $text)
 * @method bool   includes(string $haystack, string $needle)
 * @method string increment(string $text, string $separator = '_')
 * @method bool   isAnagram(string $first, string $second)
 * @method bool   isLower(string $text, string $encoding = 'UTF-8')
 * @method bool   isPalindrome(string $text)
 * @method bool   isUpper(string $text, string $encoding = 'UTF-8')
 * @method int    len(string $text, string $encoding = 'UTF-8')
 * @method string lower(string $text, string $encoding = 'UTF-8')
 * @method string prefix($text, string $prefix)
 * @method string random(int $type = 0, int $length = 8)
 * @method string reduceSlashes(string $text)
 * @method bool   startsWith(string $haystack, string $needle, bool $ignoreCase = true)
 * @method string suffix($text, string $suffix)
 * @method string ucwords(string $text, string $encoding = 'UTF-8')
 * @method string underscore(string $text)
 * @method string upper(string $text, string $encoding = 'UTF-8')
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_HelperFactory)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Support, HelperFactory, phalcon, support_helperfactory, phalcon_factory_abstractfactory_ce, phalcon_support_helperfactory_method_entry, 0);

	return SUCCESS;
}

/**
 * FactoryTrait constructor.
 *
 * @param array $services
 */
PHP_METHOD(Phalcon_Support_HelperFactory, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *services_param = NULL;
	zval services;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&services);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(services)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &services_param);
	if (!services_param) {
		ZEPHIR_INIT_VAR(&services);
		array_init(&services);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&services, services_param);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "init", NULL, 0, &services);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * @param string $name
 * @param array  $arguments
 *
 * @return mixed
 * @throws Exception
 */
PHP_METHOD(Phalcon_Support_HelperFactory, __call)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arguments, _0;
	zval *name_param = NULL, *arguments_param = NULL, helper, _1;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&helper);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_ARRAY(arguments)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &arguments_param);
	zephir_get_strval(&name, name_param);
	zephir_get_arrval(&arguments, arguments_param);


	ZEPHIR_CALL_METHOD(&helper, this_ptr, "newinstance", NULL, 0, &name);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	zephir_array_fast_append(&_0, &helper);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "__invoke");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_0, &arguments);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string $name
 *
 * @return mixed
 * @throws Exception
 */
PHP_METHOD(Phalcon_Support_HelperFactory, newInstance)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);
	zephir_get_strval(&name, name_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getservice", NULL, 0, &name);
	zephir_check_call_status();
	ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(return_value, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Support_HelperFactory, getExceptionClass)
{
	zval *this_ptr = getThis();



	RETURN_STRING("Phalcon\\Support\\Exception");
}

/**
 * Returns the available adapters
 *
 * @return string[]
 */
PHP_METHOD(Phalcon_Support_HelperFactory, getServices)
{
	zval *this_ptr = getThis();



	zephir_create_array(return_value, 59, 0);
	add_assoc_stringl_ex(return_value, SL("blacklist"), SL("Phalcon\\Support\\Helper\\Arr\\Blacklist"));
	add_assoc_stringl_ex(return_value, SL("chunk"), SL("Phalcon\\Support\\Helper\\Arr\\Chunk"));
	add_assoc_stringl_ex(return_value, SL("filter"), SL("Phalcon\\Support\\Helper\\Arr\\Filter"));
	add_assoc_stringl_ex(return_value, SL("first"), SL("Phalcon\\Support\\Helper\\Arr\\First"));
	add_assoc_stringl_ex(return_value, SL("firstKey"), SL("Phalcon\\Support\\Helper\\Arr\\FirstKey"));
	add_assoc_stringl_ex(return_value, SL("flatten"), SL("Phalcon\\Support\\Helper\\Arr\\Flatten"));
	add_assoc_stringl_ex(return_value, SL("get"), SL("Phalcon\\Support\\Helper\\Arr\\Get"));
	add_assoc_stringl_ex(return_value, SL("group"), SL("Phalcon\\Support\\Helper\\Arr\\Group"));
	add_assoc_stringl_ex(return_value, SL("has"), SL("Phalcon\\Support\\Helper\\Arr\\Has"));
	add_assoc_stringl_ex(return_value, SL("isUnique"), SL("Phalcon\\Support\\Helper\\Arr\\IsUnique"));
	add_assoc_stringl_ex(return_value, SL("last"), SL("Phalcon\\Support\\Helper\\Arr\\Last"));
	add_assoc_stringl_ex(return_value, SL("lastKey"), SL("Phalcon\\Support\\Helper\\Arr\\LastKey"));
	add_assoc_stringl_ex(return_value, SL("order"), SL("Phalcon\\Support\\Helper\\Arr\\Order"));
	add_assoc_stringl_ex(return_value, SL("pluck"), SL("Phalcon\\Support\\Helper\\Arr\\Pluck"));
	add_assoc_stringl_ex(return_value, SL("set"), SL("Phalcon\\Support\\Helper\\Arr\\Set"));
	add_assoc_stringl_ex(return_value, SL("sliceLeft"), SL("Phalcon\\Support\\Helper\\Arr\\SliceLeft"));
	add_assoc_stringl_ex(return_value, SL("sliceRight"), SL("Phalcon\\Support\\Helper\\Arr\\SliceRight"));
	add_assoc_stringl_ex(return_value, SL("split"), SL("Phalcon\\Support\\Helper\\Arr\\Split"));
	add_assoc_stringl_ex(return_value, SL("toObject"), SL("Phalcon\\Support\\Helper\\Arr\\ToObject"));
	add_assoc_stringl_ex(return_value, SL("validateAll"), SL("Phalcon\\Support\\Helper\\Arr\\ValidateAll"));
	add_assoc_stringl_ex(return_value, SL("validateAny"), SL("Phalcon\\Support\\Helper\\Arr\\ValidateAny"));
	add_assoc_stringl_ex(return_value, SL("whitelist"), SL("Phalcon\\Support\\Helper\\Arr\\Whitelist"));
	add_assoc_stringl_ex(return_value, SL("basename"), SL("Phalcon\\Support\\Helper\\File\\Basename"));
	add_assoc_stringl_ex(return_value, SL("decode"), SL("Phalcon\\Support\\Helper\\Json\\Decode"));
	add_assoc_stringl_ex(return_value, SL("encode"), SL("Phalcon\\Support\\Helper\\Json\\Encode"));
	add_assoc_stringl_ex(return_value, SL("isBetween"), SL("Phalcon\\Support\\Helper\\Number\\IsBetween"));
	add_assoc_stringl_ex(return_value, SL("camelize"), SL("Phalcon\\Support\\Helper\\Str\\Camelize"));
	add_assoc_stringl_ex(return_value, SL("concat"), SL("Phalcon\\Support\\Helper\\Str\\Concat"));
	add_assoc_stringl_ex(return_value, SL("countVowels"), SL("Phalcon\\Support\\Helper\\Str\\CountVowels"));
	add_assoc_stringl_ex(return_value, SL("decapitalize"), SL("Phalcon\\Support\\Helper\\Str\\Decapitalize"));
	add_assoc_stringl_ex(return_value, SL("decrement"), SL("Phalcon\\Support\\Helper\\Str\\Decrement"));
	add_assoc_stringl_ex(return_value, SL("dirFromFile"), SL("Phalcon\\Support\\Helper\\Str\\DirFromFile"));
	add_assoc_stringl_ex(return_value, SL("dirSeparator"), SL("Phalcon\\Support\\Helper\\Str\\DirSeparator"));
	add_assoc_stringl_ex(return_value, SL("dynamic"), SL("Phalcon\\Support\\Helper\\Str\\Dynamic"));
	add_assoc_stringl_ex(return_value, SL("endsWith"), SL("Phalcon\\Support\\Helper\\Str\\EndsWith"));
	add_assoc_stringl_ex(return_value, SL("firstBetween"), SL("Phalcon\\Support\\Helper\\Str\\FirstBetween"));
	add_assoc_stringl_ex(return_value, SL("friendly"), SL("Phalcon\\Support\\Helper\\Str\\Friendly"));
	add_assoc_stringl_ex(return_value, SL("humanize"), SL("Phalcon\\Support\\Helper\\Str\\Humanize"));
	add_assoc_stringl_ex(return_value, SL("includes"), SL("Phalcon\\Support\\Helper\\Str\\Includes"));
	add_assoc_stringl_ex(return_value, SL("increment"), SL("Phalcon\\Support\\Helper\\Str\\Increment"));
	add_assoc_stringl_ex(return_value, SL("interpolate"), SL("Phalcon\\Support\\Helper\\Str\\Interpolate"));
	add_assoc_stringl_ex(return_value, SL("isAnagram"), SL("Phalcon\\Support\\Helper\\Str\\IsAnagram"));
	add_assoc_stringl_ex(return_value, SL("isLower"), SL("Phalcon\\Support\\Helper\\Str\\IsLower"));
	add_assoc_stringl_ex(return_value, SL("isPalindrome"), SL("Phalcon\\Support\\Helper\\Str\\IsPalindrome"));
	add_assoc_stringl_ex(return_value, SL("isUpper"), SL("Phalcon\\Support\\Helper\\Str\\IsUpper"));
	add_assoc_stringl_ex(return_value, SL("len"), SL("Phalcon\\Support\\Helper\\Str\\Len"));
	add_assoc_stringl_ex(return_value, SL("lower"), SL("Phalcon\\Support\\Helper\\Str\\Lower"));
	add_assoc_stringl_ex(return_value, SL("prefix"), SL("Phalcon\\Support\\Helper\\Str\\Prefix"));
	add_assoc_stringl_ex(return_value, SL("random"), SL("Phalcon\\Support\\Helper\\Str\\Random"));
	add_assoc_stringl_ex(return_value, SL("reduceSlashes"), SL("Phalcon\\Support\\Helper\\Str\\ReduceSlashes"));
	add_assoc_stringl_ex(return_value, SL("startsWith"), SL("Phalcon\\Support\\Helper\\Str\\StartsWith"));
	add_assoc_stringl_ex(return_value, SL("suffix"), SL("Phalcon\\Support\\Helper\\Str\\Suffix"));
	add_assoc_stringl_ex(return_value, SL("ucwords"), SL("Phalcon\\Support\\Helper\\Str\\Ucwords"));
	add_assoc_stringl_ex(return_value, SL("uncamelize"), SL("Phalcon\\Support\\Helper\\Str\\Uncamelize"));
	add_assoc_stringl_ex(return_value, SL("underscore"), SL("Phalcon\\Support\\Helper\\Str\\Underscore"));
	add_assoc_stringl_ex(return_value, SL("upper"), SL("Phalcon\\Support\\Helper\\Str\\Upper"));
	return;
}

