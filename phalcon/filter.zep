
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

namespace Phalcon;

use Phalcon\FilterInterface;
use Phalcon\Filter\Exception;

/**
 * Phalcon\Filter
 *
 * The Phalcon\Filter component provides a set of commonly needed data filters. It provides
 * object oriented wrappers to the php filter extension. Also allows the developer to
 * define his/her own filters
 *
 *<code>
 *	$filter = new \Phalcon\Filter();
 *	$filter->sanitize("some(one)@exa\\mple.com", "email"); // returns "someone@example.com"
 *	$filter->sanitize("hello<<", "string"); // returns "hello"
 *	$filter->sanitize("!100a019", "int"); // returns "100019"
 *	$filter->sanitize("!100a019.01a", "float"); // returns "100019.01"
 *</code>
 */
class Filter implements FilterInterface
{

	protected _filters;

	/**
	 * Adds a user-defined filter
	 *
	 * @param string name
	 * @param callable handler
	 * @return Phalcon\Filter
	 */
	public function add(string! name, handler) -> <Filter>
	{

		if typeof handler != "object" {
			throw new Exception("Filter must be an object");
		}

		let this->_filters[name] = handler;
		return this;
	}

	/**
	 * Sanitizes a value with a specified single or set of filters
	 *
	 * @param  value
	 * @param  filters
	 * @param  noRecursive
	 * @return mixed
	 */
	public function sanitize(var value, var filters, boolean noRecursive = false)
	{
		var filter, arrayValue, itemKey, itemValue, sanitizedValue;

		/**
		 * Apply an array of filters
		 */
		if typeof filters == "array" {
			if value !== null {
				for filter in filters {
					/**
					 * If the value to filter is an array we apply the filters recursively
					 */
					if typeof value == "array" && !noRecursive {
						let arrayValue = [];
						for itemKey, itemValue in value {
							let arrayValue[itemKey] = this->_sanitize(itemValue, filter);
						}
						let value = arrayValue;
					} else {
						let value = this->_sanitize(value, filter);
					}
				}
			}
			return value;
		}

		/**
		 * Apply a single filter value
		 */
		if typeof value == "array" && !noRecursive {
			let sanitizedValue = [];
			for itemKey, itemValue in value {
				let sanitizedValue[itemKey] = this->_sanitize(itemValue, filters);
			}
			return sanitizedValue;
		}

		return this->_sanitize(value, filters);
	}

	/**
	 * Internal sanitize wrapper to filter_var
	 *
	 * @param  mixed $value
	 * @param  string $filter
	 * @return mixed
	 */
	protected function _sanitize(var value, string! filter)
	{
		var filterObject;

		if fetch filterObject, this->_filters[filter] {

			/**
			 * If the filter is a closure we call it in the PHP userland
			 */
			if filterObject instanceof \Closure {
				return call_user_func_array(filterObject, [value]);
			}

			return filterObject->filter(value);
		}

		switch filter {

			case "email":
				/**
				 * The 'email' filter uses the filter extension
				 */
				return filter_var(str_replace("'", "", value), constant("FILTER_SANITIZE_EMAIL"));

			case "int":
				/**
				 * 'int' filter sanitizes a numeric input
				 */
				return filter_var(value, FILTER_SANITIZE_NUMBER_INT);

			case "int!":
				return intval(value);

			case "string":
				return filter_var(value, FILTER_SANITIZE_STRING);

			case "float":
				/**
				 * The 'float' filter uses the filter extension
				 */
				return filter_var(value, FILTER_SANITIZE_NUMBER_FLOAT, ["flags": FILTER_FLAG_ALLOW_FRACTION]);

			case "float!":
				return doubleval(value);

			case "alphanum":
				return preg_replace("/[^A-Za-z0-9]/", "", value);

			case "trim":
				return trim(value);

			case "striptags":
				return strip_tags(value);

			case "lower":
				if function_exists("mb_strtolower") {
					/**
					 * 'lower' checks for the mbstring extension to make a correct lowercase transformation
					 */
					return mb_strtolower(value);
				}
				return strtolower(value);

			case "upper":
				if function_exists("mb_strtoupper") {
					/**
					 * 'upper' checks for the mbstring extension to make a correct lowercase transformation
					 */
					return mb_strtoupper(value);
				}
				return strtoupper(value);

			default:
				throw new Exception("Sanitize filter '" . filter . "' is not supported");
		}
	}

	/**
	 * Return the user-defined filters in the instance
	 *
	 * @return object[]
	 */
	public function getFilters()
	{
		return this->_filters;
	}
}
