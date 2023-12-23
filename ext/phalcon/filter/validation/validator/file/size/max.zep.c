
#ifdef HAVE_CONFIG_H
#include "../../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../../php_ext.h"
#include "../../../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Checks if a value has a correct file
 *
 * ```php
 * use Phalcon\Filter\Validation;
 * use Phalcon\Filter\Validation\Validator\File\Size;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "file",
 *     new Max(
 *         [
 *             "size"     => "2M",
 *             "included" => true,
 *             "message"  => ":field exceeds the max file size (:size)",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "file",
 *         "anotherFile",
 *     ],
 *     new Max(
 *         [
 *             "size" => [
 *                 "file"        => "2M",
 *                 "anotherFile" => "4M",
 *             ],
 *             "included" => [
 *                 "file"        => false,
 *                 "anotherFile" => true,
 *             ],
 *             "message" => [
 *                 "file"        => "file exceeds the max file size 2M",
 *                 "anotherFile" => "anotherFile exceeds the max file size 4M",
 *             ],
 *         ]
 *     )
 * );
 * ```
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_Validation_Validator_File_Size_Max)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Filter\\Validation\\Validator\\File\\Size, Max, phalcon, filter_validation_validator_file_size_max, phalcon_filter_validation_validator_file_size_equal_ce, phalcon_filter_validation_validator_file_size_max_method_entry, 0);

	/**
	 * @var string|null
	 */
	zend_declare_property_string(phalcon_filter_validation_validator_file_size_max_ce, SL("template"), "File :field exceeds the size of :size", ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Executes the conditional
 *
 * @param float $source
 * @param float $target
 * @param bool  $included
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_File_Size_Max, getConditional)
{
	zend_bool included;
	zval *source_param = NULL, *target_param = NULL, *included_param = NULL;
	double source, target;

	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ZVAL(source)
		Z_PARAM_ZVAL(target)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(included)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 1, &source_param, &target_param, &included_param);
	source = zephir_get_doubleval(source_param);
	target = zephir_get_doubleval(target_param);
	if (!included_param) {
		included = 0;
	} else {
		}
	if (included == 1) {
		RETURN_BOOL(target >= source);
	}
	RETURN_BOOL(target > source);
}

