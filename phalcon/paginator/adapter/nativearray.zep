
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

namespace Phalcon\Paginator\Adapter;

/**
 * Phalcon\Paginator\Adapter\NativeArray
 *
 * Pagination using a PHP array as source of data
 *
 *<code>
 *	$paginator = new \Phalcon\Paginator\Adapter\Model(
 *		array(
 *			"data"  => array(
 *				array('id' => 1, 'name' => 'Artichoke'),
 *				array('id' => 2, 'name' => 'Carrots'),
 *				array('id' => 3, 'name' => 'Beet'),
 *				array('id' => 4, 'name' => 'Lettuce'),
 *				array('id' => 5, 'name' => '')
 *			),
 *			"limit" => 2,
 *			"page"  => $currentPage
 *		)
 *	);
 *</code>
 *
 */
class NativeArray implements Phalcon\Paginator\AdapterInterface
{

	/**
	 * Number of rows to show in the paginator. By default is null
	 */
	protected _limitRows = null;

	/**
	 * Configuration of the paginator
	 */
	protected _config = null;

	/**
	 * Current page in paginate
	 */
	protected _page = null;

	/**
	 * Phalcon\Paginator\Adapter\NativeArray constructor
	 *
	 * @param array config
	 */
	public function __construct(config)
	{
		var page, limit;

		let this->_config = config;
		if fetch limit, config["limit"] {
			let this->_limitRows = limit;
		}
		if fetch page, config["page"] {
			let this->_page = page;
		}
	}

	/**
	 * Set the current page number
	 *
	 * @param int page
	 */
	public function setCurrentPage(int page)
	{
		let this->_page = page;
	}

	/**
	 * Returns a slice of the resultset to show in the pagination
	 *
	 * @return stdClass
	 */
	public function getPaginate() -> <stdClass>
	{
		var config, items, page;
		int show, pageNumber, totalPages, number, before, next;
		double roundedTotal;

		/**
		 * TODO: Rewrite the whole method!</comment>
		 */
		let config = this->_config,
			items  = config["data"];

		if typeof items != "array" {
			throw new Phalcon\Paginator\Exception("Invalid data for paginator");
		}

		let show    = (int) this->_limitRows,
			pageNumber = (int) this->_page;

		if pageNumber <= 0 {
			let pageNumber = 1;
		}

		let page = new stdClass(),
			number = count(items),
			roundedTotal = number / show,
			totalPages = (int) roundedTotal;

		/**
		 * Increase total_pages if wasn't integer
		 */
		if totalPages != roundedTotal {
			let totalPages++;
		}

		let page->items = array_slice(items, show * (pageNumber - 1), show);

		//Fix next
		if pageNumber < totalPages {
			let next = pageNumber + 1;
		} else {
			let next = totalPages;
		}
		let page->next = next;

		if pageNumber > 1 {
			let before = pageNumber - 1;
		} else {
			let before = 1;
		}

		let page->first = 1,
			page->before =  before,
			page->current = pageNumber,
			page->last = totalPages,
			page->total_pages = totalPages,
			page->total_items = number;

		return page;
	}

}