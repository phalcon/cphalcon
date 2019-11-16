
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Paginator\Adapter;

use Phalcon\Paginator\Exception;
use Phalcon\Paginator\RepositoryInterface;

/**
 * Phalcon\Paginator\Adapter\NativeArray
 *
 * Pagination using a PHP array as source of data
 *
 * ```php
 * use Phalcon\Paginator\Adapter\NativeArray;
 *
 * $paginator = new NativeArray(
 *     [
 *         "data"  => [
 *             ["id" => 1, "name" => "Artichoke"],
 *             ["id" => 2, "name" => "Carrots"],
 *             ["id" => 3, "name" => "Beet"],
 *             ["id" => 4, "name" => "Lettuce"],
 *             ["id" => 5, "name" => ""],
 *         ],
 *         "limit" => 2,
 *         "page"  => $currentPage,
 *     ]
 * );
 *```
 */
class NativeArray extends AbstractAdapter
{
    /**
     * Returns a slice of the resultset to show in the pagination
     */
    public function paginate() -> <RepositoryInterface>
    {
        var config, items;
        int show, pageNumber, totalPages, number, previous, next;
        double roundedTotal;

        /**
         * TODO: Rewrite the whole method!
         */
        let config = this->config,
            items  = config["data"];

        if unlikely typeof items != "array" {
            throw new Exception("Invalid data for paginator");
        }

        let show       = (int) this->limitRows,
            pageNumber = (int) this->page;

        if pageNumber <= 0 {
            let pageNumber = 1;
        }

        let number = count(items),
            roundedTotal = number / floatval(show),
            totalPages = (int) roundedTotal;

        /**
         * Increase totalpages if wasn't integer
         */
        if totalPages != roundedTotal {
            let totalPages++;
        }

        let items = array_slice(
            items,
            show * (pageNumber - 1),
            show
        );

        //Fix next
        if pageNumber < totalPages {
            let next = pageNumber + 1;
        } else {
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
                RepositoryInterface::PROPERTY_TOTAL_ITEMS   : number,
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
