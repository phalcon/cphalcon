
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Paginator\Adapter;

use Phalcon\Paginator\Repository;
use Phalcon\Paginator\RepositoryInterface;

/**
 * Phalcon\Paginator\Adapter
 */
abstract class AbstractAdapter implements AdapterInterface
{
    /**
     * Configuration of paginator by model
     */
    protected config = null;

    /**
     * Number of rows to show in the paginator. By default is null
     */
    protected limitRows = null;

    /**
     * Current page in paginate
     */
    protected page = null;

    /**
     * Repository for pagination
     *
     * @var RepositoryInterface
     */
    protected repository;

    /**
     * Phalcon\Paginator\Adapter\Model constructor
     */
    public function __construct(array! config) -> void
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
    public function setCurrentPage(int page) -> <Adapter>
    {
        let this->page = page;

        return this;
    }

    /**
     * Set current rows limit
     */
    public function setLimit(int limitRows) -> <Adapter>
    {
        let this->limitRows = limitRows;

        return this;
    }

    /**
     * Sets current repository for pagination
     */
    public function setRepository(<RepositoryInterface> repository) -> <Adapter>
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
