
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model\Query;

use Phalcon\Messages\MessageInterface;
use Phalcon\Mvc\ModelInterface;

/**
 * Phalcon\Mvc\Model\Query\StatusInterface
 *
 * Interface for Phalcon\Mvc\Model\Query\Status
 */
interface StatusInterface
{
    /**
     * Returns the messages produced by an operation failed
     */
    public function getMessages() -> <MessageInterface[]>;

    /**
     * Returns the model which executed the action
     */
    public function getModel() -> <ModelInterface>;

    /**
     * Allows to check if the executed operation was successful
     */
    public function success() -> bool;
}
