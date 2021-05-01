
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
 * Phalcon\Mvc\Model\Query\Status
 *
 * This class represents the status returned by a PHQL
 * statement like INSERT, UPDATE or DELETE. It offers context
 * information and the related messages produced by the
 * model which finally executes the operations when it fails
 *
 *```php
 * $phql = "UPDATE Robots SET name = :name:, type = :type:, year = :year: WHERE id = :id:";
 *
 * $status = $app->modelsManager->executeQuery(
 *     $phql,
 *     [
 *         "id"   => 100,
 *         "name" => "Astroy Boy",
 *         "type" => "mechanical",
 *         "year" => 1959,
 *     ]
 * );
 *
 * // Check if the update was successful
 * if ($status->success()) {
 *     echo "OK";
 * }
 *```
 */
class Status implements StatusInterface
{
    /**
     * @var ModelInterface|null
     */
    protected model;

    /**
     * @var bool
     */
    protected success;

    /**
     * Phalcon\Mvc\Model\Query\Status
     */
    public function __construct(bool success, <ModelInterface> model = null)
    {
        let this->success = success,
            this->model = model;
    }

    /**
     * Returns the messages produced because of a failed operation
     */
    public function getMessages() -> <MessageInterface[]>
    {
        var model;

        let model = this->model;

        if typeof model != "object" {
            return [];
        }

        return model->getMessages();
    }

    /**
     * Returns the model that executed the action
     */
    public function getModel() -> <ModelInterface>
    {
        return this->model;
    }

    /**
     * Allows to check if the executed operation was successful
     */
    public function success() -> bool
    {
        return this->success;
    }
}
