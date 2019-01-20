
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Filter;

use Phalcon\Service\Locator;

/**
 * Phalcon\Html\TagLocator
 *
 * Lazy loads, stores and exposes tag helper objects
 */
class FilterLocator extends Locator
{
	/**
	 * Sanitizes a value with a specified single or set of filters
	 */
	public function sanitize(var value, var filters, bool noRecursive = false) -> var
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
							let arrayValue[itemKey] = this->sanitizer(itemValue, filter);
						}
						let value = arrayValue;
					} else {
						let value = this->sanitizer(value, filter);
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
				let sanitizedValue[itemKey] = this->sanitizer(itemValue, filters);
			}
			return sanitizedValue;
		}

		return this->sanitizer(value, filters);
	}

	/**
	 * Internal sanitize wrapper to filter_var
	 */
	private function sanitizer(var value, string! filter) -> var
	{
		var filterObject;

		if (true === this->has(filter)) {
			let filterObject = this->get(filter);

			return {filterObject}(value);
		}

		return value;
	}
}
