
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

namespace Phalcon\Paginator\Adapter;

use Phalcon\Paginator\Exception;
use Phalcon\Paginator\Adapter;
use Phalcon\Paginator\AdapterInterface;

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
class NativeArray extends Adapter implements AdapterInterface
{

	/**
	 * Configuration of the paginator
	 */
	protected _config = null;

	/**
	 * Phalcon\Paginator\Adapter\NativeArray constructor
	 */
	public function __construct(array config)
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
	 * Returns a slice of the resultset to show in the pagination
	 */
	public function getPaginate() -> <\stdClass>
	{
		var config, items, page;
		int show, pageNumber, totalPages, number, before, next;
		double roundedTotal;

		/**
		 * TODO: Rewrite the whole method!
		 */
		let config = this->_config,
			items  = config["data"];

		if typeof items != "array" {
			throw new Exception("Invalid data for paginator");
		}

		let show    = (int) this->_limitRows,
			pageNumber = (int) this->_page;

		if pageNumber <= 0 {
			let pageNumber = 1;
		}

		let number = count(items),
			roundedTotal = number / floatval(show),
			totalPages = (int) roundedTotal;

		/**
		 * Increase total_pages if wasn't integer
		 */
		if totalPages != roundedTotal {
			let totalPages++;
		}

		let items = array_slice(items, show * (pageNumber - 1), show);

		//Fix next
		if pageNumber < totalPages {
			let next = pageNumber + 1;
		} else {
			let next = totalPages;
		}

		if pageNumber > 1 {
			let before = pageNumber - 1;
		} else {
			let before = 1;
		}

		let page = new \stdClass(),
			page->items = items,
			page->first = 1,
			page->before =  before,
			page->current = pageNumber,
			page->last = totalPages,
			page->next = next,
			page->total_pages = totalPages,
			page->total_items = number,
			page->limit = this->_limitRows;

		return page;
	}
}
