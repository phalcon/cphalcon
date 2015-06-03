
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

namespace Phalcon\Paginator;

/**
 * Phalcon\Paginator\Adapter
 */
abstract class Adapter
{

	/**
	 * Number of rows to show in the paginator. By default is null
	 */
	protected _limitRows = null;

	/**
	 * Current page in paginate
	 */
	protected _page = null;

	/**
	 * Set the current page number
	 */
	public function setCurrentPage(int page) -> <Adapter>
	{
		let this->_page = page;
		return this;
	}

	/**
	 * Set current rows limit
	 */
	public function setLimit(int limitRows) -> <Adapter>
	{
		let this->_limitRows = limitRows;
		return this;
	}

	/**
	 * Get current rows limit
	 */
	public function getLimit() -> int
	{
		return this->_limitRows;
	}
}
