
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Contracts\Logger\Adapter;

use Phalcon\Logger\Formatter\FormatterInterface;
use Phalcon\Logger\Item;

/**
 * Canonical contract for Phalcon\Logger adapters.
 */
interface Adapter
{
    /**
     * Adds a message in the queue
     *
     * @param Item $item
     *
     * @return Adapter
     */
    public function add(<Item> item) -> <Adapter>;

    /**
     * Starts a transaction
     *
     * @return Adapter
     */
    public function begin() -> <Adapter>;

    /**
     * Closes the logger
     *
     * @return bool
     */
    public function close() -> bool;

    /**
     * Commits the internal transaction
     *
     * @return Adapter
     */
    public function commit() -> <Adapter>;

    /**
     * Returns the internal formatter
     *
     * @return FormatterInterface
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
     *
     * @param Item $item
     */
    public function process(<Item> item) -> void;

    /**
     * Rollbacks the internal transaction
     *
     * @return Adapter
     */
    public function rollback() -> <Adapter>;

    /**
     * Sets the message formatter
     *
     * @param FormatterInterface $formatter
     *
     * @return Adapter
     */
    public function setFormatter(<FormatterInterface> formatter) -> <Adapter>;
}
