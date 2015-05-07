
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

use Phalcon\Mvc\Model\Query\Builder;
use Phalcon\Paginator\Adapter;
use Phalcon\Paginator\AdapterInterface;
use Phalcon\Paginator\Exception;

/**
 * Phalcon\Paginator\Adapter\QueryBuilder
 *
 * Pagination using a PHQL query builder as source of data
 *
 *<code>
 *  $builder = $this->modelsManager->createBuilder()
 *                   ->columns('id, name')
 *                   ->from('Robots')
 *                   ->orderBy('name');
 *
 *  $paginator = new Phalcon\Paginator\Adapter\QueryBuilder(array(
 *      "builder" => $builder,
 *      "limit"=> 20,
 *      "page" => 1
 *  ));
 *</code>
 */
class QueryBuilder extends Adapter implements AdapterInterface
{
	/**
	 * Configuration of paginator by model
	 */
	protected _config;

	/**
	 * Paginator's data
	 */
	protected _builder;

	/**
	 * Phalcon\Paginator\Adapter\QueryBuilder
	 */
	public function __construct(array config)
	{
		var builder, limit, page;

		let this->_config = config;

		if !fetch builder, config["builder"] {
			throw new Exception("Parameter 'builder' is required");
		}

		if !fetch limit, config["limit"] {
			throw new Exception("Parameter 'limit' is required");
		}

		this->setQueryBuilder(builder);
		this->setLimit(limit);

		if fetch page, config["page"] {
			this->setCurrentPage(page);
		}
	}

	/**
	 * Get the current page number
	 */
	public function getCurrentPage() -> int
	{
		return this->_page;
	}

	/**
	 * Set query builder object
	 */
	public function setQueryBuilder(<Builder> builder) -> <QueryBuilder>
	{
		let this->_builder = builder;

		return this;
	}

	/**
	 * Get query builder object
	 */
	public function getQueryBuilder() -> <Builder>
	{
		return this->_builder;
	}

	/**
	 * Returns a slice of the resultset to show in the pagination
	 */
	public function getPaginate() -> <\stdClass>
	{
		var originalBuilder, builder, totalBuilder, totalPages,
			limit, numberPage, number, query, page, before, items, totalQuery,
			result, row, rowcount, next;

		let originalBuilder = this->_builder;

		/**
		 * We make a copy of the original builder to leave it as it is
		 */
		let builder = clone originalBuilder;

		/**
		 * We make a copy of the original builder to count the total of records
		 */
		let totalBuilder = clone builder;

		let limit = this->_limitRows;
		let numberPage = (int) this->_page;

		if !numberPage {
			let numberPage = 1;
		}

		let number = limit * (numberPage - 1);

		/**
		 * Set the limit clause avoiding negative offsets
		 */
		if number < limit {
			builder->limit(limit);
		} else {
			builder->limit(limit, number);
		}

		let query = builder->getQuery();

		if numberPage == 1 {
			let before = 1;
		} else {
			let before = numberPage - 1;
		}

		/**
		 * Execute the query an return the requested slice of data
		 */
		let items = query->execute();

		/**
		 * Change the queried columns by a COUNT(*)
		 */
		totalBuilder->columns("COUNT(*) [rowcount]");

		/**
		 * Remove the 'ORDER BY' clause, PostgreSQL requires this
		 */
		totalBuilder->orderBy(null);

		/**
		 * Obtain the PHQL for the total query
		 */
		let totalQuery = totalBuilder->getQuery();

		/**
		 * Obtain the result of the total query
		 */
		let result = totalQuery->execute(),
			row = result->getFirst(),
			rowcount = intval(row->rowcount),
			totalPages = intval(ceil(rowcount / limit));
			
		if numberPage < totalPages {
			let next = numberPage + 1;
		} else {
			let next = totalPages;
		}

		let page = new \stdClass(),
			page->items = items,
			page->first = 1,
			page->before = before,
			page->current = numberPage,
			page->last = totalPages,
			page->next = next,
			page->total_pages = totalPages,
			page->total_items = rowcount,
			page->limit = this->_limitRows;

		return page;
	}

}
