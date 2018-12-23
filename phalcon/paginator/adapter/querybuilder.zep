
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Paginator\Adapter;

use Phalcon\Mvc\Model\Query\Builder;
use Phalcon\Paginator\Adapter;
use Phalcon\Paginator\RepositoryInterface;
use Phalcon\Paginator\Exception;
use Phalcon\Db;

/**
 * Phalcon\Paginator\Adapter\QueryBuilder
 *
 * Pagination using a PHQL query builder as source of data
 *
 * <code>
 * use Phalcon\Paginator\Adapter\QueryBuilder;
 *
 * $builder = $this->modelsManager->createBuilder()
 *                 ->columns("id, name")
 *                 ->from("Robots")
 *                 ->orderBy("name");
 *
 * $paginator = new QueryBuilder(
 *     [
 *         "builder" => $builder,
 *         "limit"   => 20,
 *         "page"    => 1,
 *     ]
 * );
 *</code>
 */
class QueryBuilder extends Adapter
{
	/**
	 * Paginator's data
	 */
	protected _builder;

	/**
	 * Columns for count query if builder has having
	 */
	protected _columns;

	/**
	 * Phalcon\Paginator\Adapter\QueryBuilder
	 */
	public function __construct(array config)
	{
		var builder, columns;
		
		if !isset config["limit"] {
			throw new Exception("Parameter 'limit' is required");
		}

		if !fetch builder, config["builder"] {
			throw new Exception("Parameter 'builder' is required");
		}

		if fetch columns, config["columns"] {
		    let this->_columns = columns;
		}

		parent::__construct(config);

		this->setQueryBuilder(builder);
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
	public function paginate() -> <RepositoryInterface>
	{
		var originalBuilder, builder, totalBuilder, totalPages,
			limit, numberPage, number, query, previous, items, totalQuery,
			result, row, rowcount, next, sql, columns, db, hasHaving, hasGroup,
			model, modelClass, dbService, groups, groupColumn;

		let originalBuilder = this->_builder;
		let columns = this->_columns;

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
			let previous = 1;
		} else {
			let previous = numberPage - 1;
		}

		/**
		 * Execute the query an return the requested slice of data
		 */
		let items = query->execute();

		let hasHaving = !empty totalBuilder->getHaving();

        let groups = totalBuilder->getGroupBy();

		let hasGroup = !empty groups;

		/**
		 * Change the queried columns by a COUNT(*)
		 */

		if hasHaving && !hasGroup {
            if empty columns {
                throw new Exception("When having is set there should be columns option provided for which calculate row count");
            }
		    totalBuilder->columns(columns);
		} else {
		    totalBuilder->columns("COUNT(*) [rowcount]");
		}

		/**
		 * Change 'COUNT()' parameters, when the query contains 'GROUP BY'
		 */
		if hasGroup {
			if typeof groups == "array" {
				let groupColumn = implode(", ", groups);
			} else {
				let groupColumn = groups;
			}

			if !hasHaving {
			    totalBuilder->groupBy(null)->columns(["COUNT(DISTINCT ".groupColumn.") AS [rowcount]"]);
			} else {
			    totalBuilder->columns(["DISTINCT ".groupColumn]);
			}
		}

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
		 * If we have having perform native count on temp table
		 */
		if hasHaving {
		    let sql = totalQuery->getSql(),
		      modelClass = builder->_models;

			if typeof modelClass == "array" {
    			let modelClass = array_values(modelClass)[0];
			}

			let model = new {modelClass}();
			let dbService = model->getReadConnectionService();
			let db = totalBuilder->getDI()->get(dbService);
			let row = db->fetchOne("SELECT COUNT(*) as \"rowcount\" FROM (" .  sql["sql"] . ") as T1", Db::FETCH_ASSOC, sql["bind"]),
		        rowcount = row ? intval(row["rowcount"]) : 0,
		        totalPages = intval(ceil(rowcount / limit));
		} else {
            let result = totalQuery->execute(),
                row = result->getFirst(),
                rowcount = row ? intval(row->rowcount) : 0,
                totalPages = intval(ceil(rowcount / limit));
		}

		if numberPage < totalPages {
			let next = numberPage + 1;
		} else {
			let next = totalPages;
		}

		return this->getRepository([
			RepositoryInterface::PROPERTY_ITEMS 		: items,
			RepositoryInterface::PROPERTY_TOTAL_ITEMS 	: rowcount,
			RepositoryInterface::PROPERTY_LIMIT 		: this->_limitRows,
			RepositoryInterface::PROPERTY_FIRST_PAGE 	: 1,
			RepositoryInterface::PROPERTY_PREVIOUS_PAGE : previous,
			RepositoryInterface::PROPERTY_CURRENT_PAGE 	: numberPage,
			RepositoryInterface::PROPERTY_NEXT_PAGE 	: next,
			RepositoryInterface::PROPERTY_LAST_PAGE 	: totalPages
		]);
	}
}
