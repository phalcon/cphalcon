
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
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

/**
 * Phalcon\FilterInterface
 *
 * Interface for Phalcon\Filter
 */
interface FilterInterface
{

	/**
	 * Adds a user-defined filter
	 */
	public function add(string! name, handler) -> <FilterInterface>;

	/**
	 * Sanizites a value with a specified single or set of filters
	 */
	public function sanitize(value, filters) -> var;

	/**
	 * Return the user-defined filters in the instance
	 */
	public function getFilters() -> array;
}
