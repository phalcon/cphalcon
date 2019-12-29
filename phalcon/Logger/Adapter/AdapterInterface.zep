
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Logger\Adapter;

use Phalcon\Logger\Formatter\FormatterInterface;
use Phalcon\Logger\Item;

/**
 * Phalcon\Logger\AdapterInterface
 *
 * Interface for Phalcon\Logger adapters
 */
interface AdapterInterface
{
    /**
     * Adds a message in the queue
     */
    public function add(<Item> item) -> <AdapterInterface>;

    /**
     * Starts a transaction
     */
    public function begin() -> <AdapterInterface>;

    /**
     * Closes the logger
     */
    public function close() -> bool;

    /**
     * Commits the internal transaction
     */
    public function commit() -> <AdapterInterface>;

    /**
     * Returns the internal formatter
     */
    public function getFormatter() -> <FormatterInterface>;

    /**
     * Returns the whether the logger is currently in an active transaction or
     * not
     *
     * @return bool
     */
    public function inTransaction() -> bool;

    /**
     * Processes the message in the adapter
     */
    public function process(<Item> item) -> void;

    /**
     * Rollbacks the internal transaction
     */
    public function rollback() -> <AdapterInterface>;

    /**
     * Sets the message formatter
     */
    public function setFormatter(<FormatterInterface> formatter) -> <AdapterInterface>;
}
