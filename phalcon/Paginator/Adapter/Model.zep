
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Paginator\Adapter;

use Phalcon\Helper\Arr;
use Phalcon\Mvc\ModelInterface;
use Phalcon\Mvc\Model\ResultsetInterface;
use Phalcon\Paginator\Exception;
use Phalcon\Paginator\RepositoryInterface;

/**
 * Phalcon\Paginator\Adapter\Model
 *
 * This adapter allows to paginate data using a Phalcon\Mvc\Model resultset as a
 * base.
 *
 * ```php
 * use Phalcon\Paginator\Adapter\Model;
 *
 * $paginator = new Model(
 *     [
 *         "model" => Robots::class,
 *         "limit" => 25,
 *         "page"  => $currentPage,
 *     ]
 * );
 *
 *
 * $paginator = new Model(
 *     [
 *         "model" => Robots::class,
 *         "parameters" => [
 *              "columns" => "id, name"
 *         ],
 *         "limit" => 12,
 *         "page"  => $currentPage,
 *     ]
 * );
 *
 *
 * $paginator = new Model(
 *     [
 *         "model" => Robots::class,
 *         "parameters" => [
 *              "type = :type:",
 *              "bind" => [
 *                  "type" => "mechanical"
 *              ],
 *              "order" => "name"
 *         ],
 *         "limit" => 16,
 *         "page"  => $currentPage,
 *     ]
 * );
 *
 * $paginator = new Model(
 *     [
 *         "model" => Robots::class,
 *         "parameters" => "(id % 2) = 0",
 *         "limit" => 8,
 *         "page"  => $currentPage,
 *     ]
 * );
 *
 *
 * $paginator = new Model(
 *     [
 *         "model" => Robots::class,
 *         "parameters" => [ "(id % 2) = 0" ],
 *         "limit" => 8,
 *         "page"  => $currentPage,
 *     ]
 * );
 *
 * $paginate = $paginator->paginate();
 *```
 */
class Model extends AbstractAdapter
{
    /**
     * Returns a slice of the resultset to show in the pagination
     */
    public function paginate() -> <RepositoryInterface>
    {
        var config, items, pageItems, modelClass, parameters;
        int pageNumber, limit, rowcount, next, totalPages,
            previous;

        let limit      = (int) this->limitRows,
            config     = this->config,
            pageNumber = (int) this->page,
            modelClass = <ModelInterface> config["model"],
            parameters = Arr::get(config, "parameters", [], "array");

        //Prevents 0 or negative page numbers
        if pageNumber <= 0 {
            let pageNumber = 1;
        }

        let rowcount  = (int) call_user_func([modelClass, "count"], parameters),
            pageItems = [];

        if rowcount % limit != 0 {
            let totalPages = (int) (rowcount / limit + 1);
        } else {
            let totalPages = (int) (rowcount / limit);
        }

        if rowcount > 0 {
            let parameters["limit"]  = limit,
                parameters["offset"] = limit * (pageNumber - 1);

            let items = <ResultsetInterface> call_user_func(
                [modelClass, "find"],
                parameters
            );
        }

        //Fix next
        let next = pageNumber + 1;

        if next > totalPages {
            let next = totalPages;
        }

        if pageNumber > 1 {
            let previous = pageNumber - 1;
        } else {
            let previous = 1;
        }

        return this->getRepository(
            [
                RepositoryInterface::PROPERTY_ITEMS         : items,
                RepositoryInterface::PROPERTY_TOTAL_ITEMS   : rowcount,
                RepositoryInterface::PROPERTY_LIMIT         : this->limitRows,
                RepositoryInterface::PROPERTY_FIRST_PAGE    : 1,
                RepositoryInterface::PROPERTY_PREVIOUS_PAGE : previous,
                RepositoryInterface::PROPERTY_CURRENT_PAGE  : pageNumber,
                RepositoryInterface::PROPERTY_NEXT_PAGE     : next,
                RepositoryInterface::PROPERTY_LAST_PAGE     : totalPages
            ]
        );
    }
}
