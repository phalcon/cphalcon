
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
 |          Vladimir Metelitsa <green.cat@me.com>                         |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Paginator\Adapter;

use Phalcon\Paginator\Exception;
use Phalcon\Paginator\Adapter;
use Phalcon\Paginator\RepositoryInterface;

/**
 * Phalcon\Paginator\Adapter\Model
 *
 * This adapter allows to paginate data using a Phalcon\Mvc\Model resultset as a base
 *<code>
 *	$paginator = new \Phalcon\Paginator\Adapter\Model(
 *		array(
 *			"data"  => Robots::find(),
 *			"limit" => 25,
 *			"page"  => $currentPage
 *		)
 *	);
 *
 *  $paginate = $paginator->getPaginate();
 *</code>
 */
class Model extends Adapter
{

	/**
	 * Configuration of paginator by model
	 */
	protected _config = null;

	/**
	 * Phalcon\Paginator\Adapter\Model constructor
	 */
	public function __construct(array! config)
	{
		parent::__construct(config);
		let this->_config = config;
	}

	/**
	 * Returns a slice of the resultset to show in the pagination
	 */
	public function getPaginate() -> <RepositoryInterface>
	{
		var config, items, pageItems;
		int pageNumber, show, n, start, lastShowPage,
			i, next, totalPages, before;

		let show       = (int) this->_limitRows,
			config     = this->_config,
			items      = config["data"],
			pageNumber = (int) this->_page;

		if typeof items != "object" {
			throw new Exception("Invalid data for paginator");
		}

		//Prevents 0 or negative page numbers
		if pageNumber <= 0 {
			let pageNumber = 1;
		}

		//Prevents a limit creating a negative or zero first page
		if show <= 0 {
			throw new Exception("The start page number is zero or less");
		}

		let n 				= count(items),
			lastShowPage 	= pageNumber - 1,
			start 			= show * lastShowPage,
			pageItems 		= [];

		if n % show != 0 {
			let totalPages = (int) (n / show + 1);
		} else {
			let totalPages = (int) (n / show);
		}

		if n > 0 {

			//Seek to the desired position
			if start <= n {
				items->seek(start);
			} else {
				items->seek(0);
				let pageNumber = 1;
			}

			//The record must be iterable
			let i = 1;
			while items->valid() {
				let pageItems[] = items->current();
				if i >= show {
					break;
				}
				let i++;
				items->next();
			}
		}

		//Fix next
		let next = pageNumber + 1;
		if next > totalPages {
			let next = totalPages;
		}

		if pageNumber > 1 {
			let before = pageNumber - 1;
		} else {
			let before = 1;
		}

		return this->getRepository([
			RepositoryInterface::PROPERTY_ITEMS 		: pageItems,
			RepositoryInterface::PROPERTY_TOTAL_PAGES	: totalPages,
			RepositoryInterface::PROPERTY_TOTAL_ITEMS 	: n,
			RepositoryInterface::PROPERTY_LIMIT 		: this->_limitRows,
			RepositoryInterface::PROPERTY_FIRST_PAGE 	: 1,
			RepositoryInterface::PROPERTY_PREVIOUS_PAGE : before,
			RepositoryInterface::PROPERTY_CURRENT_PAGE 	: pageNumber,
			RepositoryInterface::PROPERTY_NEXT_PAGE 	: next,
			RepositoryInterface::PROPERTY_LAST_PAGE 	: totalPages
		]);
	}
}
