
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Paginator\Adapter;

use Phalcon\Db\Enum;
use Phalcon\Mvc\Model\Query\Builder;
use Phalcon\Paginator\RepositoryInterface;
use Phalcon\Paginator\Exception;

/**
 * Phalcon\Paginator\Adapter\QueryBuilder
 *
 * Pagination using a PHQL query builder as source of data
 *
 * ```php
 * use Phalcon\Paginator\Adapter\QueryBuilder;
 *
 * $builder = $this->modelsManager->createBuilder()
 *                 ->columns("id, name")
 *                 ->from(Robots::class)
 *                 ->orderBy("name");
 *
 * $paginator = new QueryBuilder(
 *     [
 *         "builder" => $builder,
 *         "limit"   => 20,
 *         "page"    => 1,
 *     ]
 * );
 *```
 */
class QueryBuilder extends AbstractAdapter
{
    /**
     * Paginator's data
     */
    protected builder;

    /**
     * Columns for count query if builder has having
     */
    protected columns;

    /**
     * Phalcon\Paginator\Adapter\QueryBuilder
     *
     * @param array config = [
     *     'limit' => 10,
     *     'builder' => null,
     *     'columns' => ''
     * ]
     */
    public function __construct(array config)
    {
        var builder, columns;

        if unlikely !isset config["limit"] {
            throw new Exception("Parameter 'limit' is required");
        }

        if unlikely !fetch builder, config["builder"] {
            throw new Exception("Parameter 'builder' is required");
        }
        if unlikely !(builder instanceof Builder) {
            throw new Exception(
                "Parameter 'builder' must be an instance " .
                "of Phalcon\\Mvc\\Model\\Query\\Builder"
            );
        }

        if fetch columns, config["columns"] {
            let this->columns = columns;
        }

        parent::__construct(config);

        this->setQueryBuilder(builder);
    }
    /**
     * Get the current page number
     */
    public function getCurrentPage() -> int
    {
        return this->page;
    }

    /**
     * Get query builder object
     */
    public function getQueryBuilder() -> <Builder>
    {
        return this->builder;
    }

    /**
     * Returns a slice of the resultset to show in the pagination
     */
    public function paginate() -> <RepositoryInterface>
    {
        var originalBuilder, builder, totalBuilder, totalPages, limit,
            number, query, previous, items, totalQuery, result, row, rowcount,
            next, sql, columns, db, model, modelClass, dbService, groups,
            groupColumn;
        bool hasHaving, hasGroup;
        int numberPage;

        let originalBuilder = this->builder;
        let columns = this->columns;

        /**
         * We make a copy of the original builder to leave it as it is
         */
        let builder = clone originalBuilder;

        /**
         * We make a copy of the original builder to count the total of records
         */
        let totalBuilder = clone builder;

        let limit = this->limitRows;
        let numberPage = (int) this->page;

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
            if unlikely empty columns {
                throw new Exception(
                    "When having is set there should be columns option provided for which calculate row count"
                );
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
                totalBuilder->groupBy(null)->columns(
                    [
                        "COUNT(DISTINCT " . groupColumn . ") AS [rowcount]"
                    ]
                );
            } else {
                totalBuilder->columns(
                    [
                        "DISTINCT " . groupColumn
                    ]
                );
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
                modelClass = builder->getModels();

            if unlikely modelClass === null {
                throw new Exception("Model not defined in builder");
            }

            if typeof modelClass == "array" {
                let modelClass = array_values(modelClass)[0];
            }

            let model     = create_instance(modelClass),
                dbService = model->getReadConnectionService(),
                db        = totalBuilder->getDI()->get(dbService);

            let row = db->fetchOne(
                "SELECT COUNT(*) as \"rowcount\" FROM (" .  sql["sql"] . ") as T1",
                Enum::FETCH_ASSOC,
                sql["bind"]
            );

            let rowcount = row ? intval(row["rowcount"]) : 0,
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

        return this->getRepository(
            [
                RepositoryInterface::PROPERTY_ITEMS         : items,
                RepositoryInterface::PROPERTY_TOTAL_ITEMS   : rowcount,
                RepositoryInterface::PROPERTY_LIMIT         : this->limitRows,
                RepositoryInterface::PROPERTY_FIRST_PAGE    : 1,
                RepositoryInterface::PROPERTY_PREVIOUS_PAGE : previous,
                RepositoryInterface::PROPERTY_CURRENT_PAGE  : numberPage,
                RepositoryInterface::PROPERTY_NEXT_PAGE     : next,
                RepositoryInterface::PROPERTY_LAST_PAGE     : totalPages
            ]
        );
    }

    /**
     * Set query builder object
     */
    public function setQueryBuilder(<Builder> builder) -> <QueryBuilder>
    {
        let this->builder = builder;

        return this;
    }
}
