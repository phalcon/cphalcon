
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
use Phalcon\Paginator\Repository;
use Phalcon\Paginator\RepositoryInterface;

/**
 * Phalcon\Paginator\Adapter\AbstractAdapter
 */
abstract class AbstractAdapter implements AdapterInterface
{
    /**
     * Configuration of paginator
     *
     * @var array
     */
    protected config;

    /**
     * Number of rows to show in the paginator. By default is null
     *
     * @var int|null
     */
    protected limitRows = null;

    /**
     * Current page in paginate
     *
     * @var int|null
     */
    protected page = null;

    /**
     * Repository for pagination
     *
     * @var RepositoryInterface
     */
    protected repository;

    /**
     * Phalcon\Paginator\Adapter\AbstractAdapter constructor
     *
     * @param array $config
     */
    public function __construct(array! config)
    {
        let this->config = config;

        if isset config["limit"] {
            this->setLimit(
                config["limit"]
            );
        }

        if isset config["page"] {
            this->setCurrentPage(
                config["page"]
            );
        }

        if isset config["repository"] {
            this->setRepository(
                config["repository"]
            );
        }
    }

    /**
     * Get current rows limit
     */
    public function getLimit() -> int
    {
        return this->limitRows;
    }

    /**
     * Set the current page number
     */
    public function setCurrentPage(int page) -> <AdapterInterface>
    {
        let this->page = page;

        return this;
    }

    /**
     * Set current rows limit
     */
    public function setLimit(int limitRows) -> <AdapterInterface>
    {
        if limitRows <= 0 {
            throw new Exception("Limit must be greater then zero");
        }
        let this->limitRows = limitRows;

        return this;
    }

    /**
     * Sets current repository for pagination
     */
    public function setRepository(<RepositoryInterface> repository) -> <AdapterInterface>
    {
        let this->repository = repository;

        return this;
    }

    /**
     * Gets current repository for pagination
     */
    protected function getRepository(array properties = null) -> <RepositoryInterface>
    {
        if typeof this->repository != "object" {
            let this->repository = new Repository();
        }

        if properties !== null {
            this->repository->setProperties(properties);
        }

        return this->repository;
    }
}
