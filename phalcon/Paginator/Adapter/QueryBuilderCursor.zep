
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Paginator\Adapter;

use Phalcon\Mvc\Model\Query\Builder;
use Phalcon\Paginator\Exception;
use Phalcon\Paginator\Exceptions\InvalidBuilderInstance;
use Phalcon\Paginator\Exceptions\InvalidCursorColumn;
use Phalcon\Paginator\Exceptions\MissingRequiredParameter;
use Phalcon\Paginator\RepositoryInterface;

/**
 * Phalcon\Paginator\Adapter\QueryBuilderCursor
 *
 * Cursor-based (keyset) pagination using a PHQL query builder as source of
 * data.
 *
 * Unlike offset pagination, this adapter does not use an ever-growing OFFSET.
 * It appends a WHERE condition on a unique, indexed cursor column so that each
 * page is an O(1) index seek regardless of depth.
 *
 * Limitations:
 * - No total count: `getTotalItems()` always returns 0.
 * - No random access: `getLast()` always returns 0. Pages must be traversed
 *   in order by following the cursor value returned in `getNext()`.
 * - The cursor column must be unique and indexed (e.g. a primary key).
 * - Items are returned as an array of associative arrays (via
 *   `Resultset::toArray()`), not as model objects.
 * - `cursorColumn` must match the PHQL-accessible column name exactly
 *   (e.g. `"inv_id"`).
 *
 * ```php
 * use Phalcon\Paginator\Adapter\QueryBuilderCursor;
 *
 * $builder = $this->modelsManager->createBuilder()
 *                 ->columns("inv_id, inv_title")
 *                 ->from(Invoices::class)
 *                 ->orderBy("inv_id");
 *
 * $paginator = new QueryBuilderCursor(
 *     [
 *         "builder"      => $builder,
 *         "limit"        => 20,
 *         "cursorColumn" => "inv_id",
 *         "cursor"       => null,  // first page; pass $page->getNext() for subsequent pages
 *     ]
 * );
 *
 * $page = $paginator->paginate();
 * // $page->getItems()   - array of rows for this page
 * // $page->getNext()    - cursor value to pass for the next page (0 means no more pages)
 * // $page->getCurrent() - cursor value used for this page (0 on first page)
 * ```
 */
class QueryBuilderCursor extends AbstractAdapter
{
    /**
     * Paginator's data
     *
     * @var Builder
     */
    protected builder;

    /**
     * The cursor value for the current page (null = first page)
     *
     * @var mixed
     */
    protected cursor = null;

    /**
     * The column used as the cursor (must be unique and indexed)
     *
     * @var string
     */
    protected cursorColumn;

    /**
     * Phalcon\Paginator\Adapter\QueryBuilderCursor
     *
     * @param array config = [
     *     'limit'        => 10,
     *     'builder'      => null,
     *     'cursorColumn' => 'id',
     *     'cursor'       => null
     * ]
     */
    public function __construct(array config)
    {
        var builder, cursorColumn, cursor;

        if unlikely !isset config["limit"] {
            throw new MissingRequiredParameter("limit");
        }

        if unlikely !fetch builder, config["builder"] {
            throw new MissingRequiredParameter("builder");
        }

        if unlikely !(builder instanceof Builder) {
            throw new InvalidBuilderInstance();
        }

        if unlikely !fetch cursorColumn, config["cursorColumn"] {
            throw new MissingRequiredParameter("cursorColumn");
        }

        if unlikely typeof cursorColumn != "string" || empty cursorColumn {
            throw new InvalidCursorColumn();
        }

        let this->cursorColumn = cursorColumn;

        if fetch cursor, config["cursor"] {
            let this->cursor = cursor;
        }

        parent::__construct(config);

        this->setQueryBuilder(builder);
    }

    /**
     * Get the cursor value for the current page (null on first page)
     */
    public function getCursor() -> var
    {
        return this->cursor;
    }

    /**
     * Get the cursor column name
     */
    public function getCursorColumn() -> string
    {
        return this->cursorColumn;
    }

    /**
     * Get the current page number
     *
     * Returns the cursor value used for this page cast to int, or 0 for the
     * first page. Use getCursor() to retrieve the raw cursor value.
     */
    public function getCurrentPage() -> int
    {
        if this->cursor === null {
            return 0;
        }

        return (int) this->cursor;
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
     *
     * Fetches `limit + 1` rows from the builder. If the extra row is present
     * a next page exists; it is discarded and the cursor value of the last
     * included row is stored in the `next` repository property.
     */
    public function paginate() -> <RepositoryInterface>
    {
        var builder, query, result, items, lastItem, nextCursor, currentCursor,
            currentPage;
        int limit;

        let builder       = clone this->builder,
            limit         = (int) this->limitRows,
            currentCursor = this->cursor;

        if currentCursor === null {
            let currentPage = 0;
        } else {
            let currentPage = (int) currentCursor;
        }

        /**
         * Append the keyset WHERE condition (skipped on the first page)
         */
        if currentCursor !== null {
            builder->andWhere(
                "[" . this->cursorColumn . "] > :cursor:",
                ["cursor": currentCursor]
            );
        }

        /**
         * Fetch one extra row to detect whether a next page exists
         */
        builder->limit(limit + 1);

        let query  = builder->getQuery(),
            result = query->execute(),
            items  = result->toArray();

        /**
         * If we received more rows than the page size a next page exists.
         * Discard the lookahead row and record the cursor of the last
         * included row so the caller can advance to the next page.
         */
        if count(items) > limit {
            array_pop(items);

            let lastItem   = items[count(items) - 1],
                nextCursor = (int) lastItem[this->cursorColumn];
        } else {
            let nextCursor = 0;
        }

        return this->getRepository(
            [
                RepositoryInterface::PROPERTY_ITEMS         : items,
                RepositoryInterface::PROPERTY_TOTAL_ITEMS   : 0,
                RepositoryInterface::PROPERTY_LIMIT         : this->limitRows,
                RepositoryInterface::PROPERTY_FIRST_PAGE    : 1,
                RepositoryInterface::PROPERTY_PREVIOUS_PAGE : 0,
                RepositoryInterface::PROPERTY_CURRENT_PAGE  : currentPage,
                RepositoryInterface::PROPERTY_NEXT_PAGE     : nextCursor,
                RepositoryInterface::PROPERTY_LAST_PAGE     : 0
            ]
        );
    }

    /**
     * Set the cursor value for the next paginate() call
     *
     * Pass the value returned by Repository::getNext() to advance to the
     * next page, or null to restart from the first page.
     */
    public function setCursor(var cursor) -> <static>
    {
        let this->cursor = cursor;

        return this;
    }

    /**
     * Set query builder object
     */
    public function setQueryBuilder(<Builder> builder) -> <static>
    {
        let this->builder = builder;

        return this;
    }
}
