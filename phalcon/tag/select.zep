
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
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Tag;

use Phalcon\Tag\Exception;

/**
 * Phalcon\Tag\Select
 *
 * Generates a SELECT html tag using a static array of values or a Phalcon\Mvc\Model resultset
 */
abstract class Select
{

	/**
	 * Generates a SELECT tag
	 *
	 * @param array parameters
	 * @param array data
	 */
	public static function selectField(parameters, data=null)
	{
		var params, name, id, value, useEmpty, code, emptyValue, emptyText,
			key, avalue, options, closeOption, using;

		if typeof parameters != "array" {
			let params = [parameters, data];
		} else {
			let params = parameters;
		}

		if !fetch id, params[0] {
			let params[0] = params["id"];
		}

		if !fetch name, params["name"] {
			let params["name"] = id;
		} else {
			if !name {
				let params["name"] = id;
			}
		}

		/**
		 * Automatically assign the id if the name is not an array
		 */
		if !memstr(id, "[") {
			if !isset params["id"] {
				let params["id"] = id;
			}
		}

		if !fetch value, params["value"] {
			let value = \Phalcon\Tag::getValue(id, params);
		} else {
			unset params["value"];
		}

		let useEmpty = false;
		if fetch useEmpty, params["useEmpty"] {

			if !fetch emptyValue, params["emptyValue"] {
				let emptyValue = "";
			} else {
				unset params["emptyValue"];
			}

			if !fetch emptyText, params["emptyText"] {
				let emptyText = "Choose...";
			} else {
				unset params["emptyText"];
			}

			unset params["useEmpty"];
		}

		let code = "<select";
		if typeof params == "array" {
			for key, avalue in params {
				if typeof key != "integer" && typeof avalue != "array" {
					let code .= " " . key . "=\"" . avalue . "\"";
				}
			}
		}
		let code .= ">" . PHP_EOL;

		let closeOption = "</option>" . PHP_EOL;

		if useEmpty {
			/**
			 * Create an empty value
			 */
			let code .= "\t<option value=\"" . emptyValue . "\">" . emptyText . closeOption;
		}

		if !fetch options, params[1] {
			let options = data;
		}

		if typeof options == "object" {

			/**
			 * The options is a resultset
			 */
			if !fetch using, params["using"] {
				throw new Exception("The 'using' parameter is required");
			} else {
				if typeof using != "array" && typeof using != "object" {
					throw new Exception("The 'using' parameter should be an Array");
				}
			}

			/**
			 * Create the SELECT's option from a resultset
			 */
			let code .= self::_optionsFromResultset(options, using, value, closeOption);
		} else {
			if typeof options == "array" {

				/**
				 * Create the SELECT's option from an array
				 */
				let code .= self::_optionsFromArray(options, value, closeOption);
			} else {
				throw new Exception("Invalid data provided to SELECT helper");
			}
		}

		let code .= "</select>";

		return code;
	}

	/**
	 * Generate the OPTION tags based on a resulset
	 *
	 * @param Phalcon\Mvc\Model resultset
	 * @param array using
	 * @param mixed value
	 * @param string closeOption
	 */
	private static function _optionsFromResultset(resultset, using, value, closeOption)
	{
		var code, params, option, usingZero, usingOne, optionValue, optionText;

		let code = "";
		let params = null;

		resultset->rewind();

		while resultset->valid() !== false {

			/**
			 * Get the current option
			 */
			let option = resultset->current();

			if typeof using == "array" {

				let usingZero = using[0], usingOne = using[1];

				if typeof option == "object" {
					if method_exists(option, "readAttribute") {
						let optionValue = option->readAttribute(usingZero);
						let optionText = option->readAttribute(usingOne);
					} else {
						let optionValue = option->usingZero;
						let optionText = option->usingOne;
					}
				} else {
					if typeof option == "array" {
						let optionValue = option[usingZero];
						let optionText = option[usingOne];
					} else {
						throw new Exception("Resultset returned an invalid value");
					}
				}

				/**
				 * If the value is equal to the option"s value we mark it as selected
				 */
				if typeof value == "array" {
					if in_array(optionValue, value) {
						let code .= "\t<option selected=\"selected\" value=\"" . optionValue . "\">" . optionText . closeOption;
					} else {
						let code .= "\t<option value=\"" . optionValue . "\">" . optionText . closeOption;
					}
				} else {
					if optionValue == value {
						let code .= "\t<option selected=\"selected\" value=\"" . optionValue . "\">" . optionText . closeOption;
					} else {
						let code .= "\t<option value=\"" . optionValue . "\">" . optionText . closeOption;
					}
				}
			} else {

				/**
				 * Check if using is a closure
				 */
				if typeof using == "object" {
					if params === null {
						let params = [];
					}
					let params[0] = option;
					let code .= call_user_func_array(using, params);
				}
			}

		    resultset->next();
		}
		return code;
	}

	/**
	 * Generate the OPTION tags based on an array
	 *
	 * @param array data
	 * @param mixed value
	 * @param string closeOption
	 */
	private static function _optionsFromArray(data, value, closeOption)
	{
		var code, optionValue, optionText;

		let code = "";
		for optionValue, optionText in data {
			if typeof value == "array" {
				if in_array(optionValue, value) {
					let code .= "\t<option selected=\"selected\" value=\"" . optionValue . "\">" . optionText . closeOption;
				} else {
					let code .= "\t<option value=\"" . optionValue . "\">" . optionText . closeOption;
				}
			} else {
				if optionValue == value {
					let code .= "\t<option selected=\"selected\" value=\"" . optionValue . "\">" . optionText . closeOption;
				} else {
					let code .= "\t<option value=\"" . optionValue . "\">" . optionText . closeOption;
				}
			}
		}
		return code;
	}

}
