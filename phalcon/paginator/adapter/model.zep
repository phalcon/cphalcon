
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
 * Phalcon\Paginator\Adapter\Model
 *
 * This adapter allows to paginate data using a Phalcon\Mvc\Model resultset as base
 */
class Model implements Phalcon\Paginator\AdapterInterface
{

	/**
	 * Number of rows to show in the paginator. By default is null
	 */
	protected _limitRows = null;

	/**
	 * Configuration of paginator by model
	 */
	protected _config = null;

	/**
	 * Current page in paginate
	*/
	protected _page = null;

	/**
	 * Phalcon\Paginator\Adapter\Model constructor
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
	public function setCurrentPage(int page) -> void
	{
		let this->_page = page;
	}

	/**
	 * Returns a slice of the resultset to show in the pagination
	 *
	 * @return stdClass
	 */
	public function getPaginate() -> <stdclass>
	{
		var config, items, pageItems, page, valid;
		int pageNumber, show, n, start, lastPage, totalPages,
			lastShowPage, i, maximumPages, next, pagesTotal,
			before;

		let show       = (int) this->_limitRows,
			config     = this->_config,
			items      = config["data"],
			pageNumber = (int) this->_page;

		if pageNumber <= 0 {
			let pageNumber = 1;
		}

		if show <= 0 {
			throw new Phalcon\Paginator\Exception("The start page number is zero or less");
		}

		let n          = count(items),
			page       = new stdClass(),
			lastShowPage = pageNumber - 1,
			start      = show * lastShowPage,
			lastPage   = n - 1,
			totalPages = (int) ceil(lastPage / show);

		if typeof items != "object" {
			throw new Phalcon\Paginator\Exception("Invalid data for paginator");
		}

		if pageNumber <= 0 {
			let pageNumber = 1;
		}

		let pageItems = [];

		if n > 0 {

			/**
			 * Seek to the desired position</comment>
			 */
			if start <= n {
				items->seek(start);
			} else {
				items->seek(1);
				let pageNumber = 1;
			}

			/**
			 * The record must be iterable
			 */
			let i = 1;
			loop {

				let valid = items->valid();
				if valid == false {
					break;
				}

				let pageItems[] = items->current();
				if i >= show {
					break;
				}
				let i++;
			}
		}
		let page->items = pageItems,
			maximumPages = start + show;

		if maximumPages < n {
			let next = pageNumber + 1;
		} else {
			if maximumPages == n {
				let next = n;
			} else {
				let next = (int) (n / show + 1);
			}
		}

		//Fix next
		if next > totalPages {
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
			page->current = pageNumber;

		if n % show != 0 {
			let pagesTotal = (int) (n / show + 1);
		} else {
			let pagesTotal = (int) (n / show);
		}

		let page->last = pagesTotal,
			page->total_pages = pagesTotal,
			page->total_items = n;

		return page;
	}

}