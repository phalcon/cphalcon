
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model;

use Phalcon\Messages\Message;
use Phalcon\Mvc\ModelInterface;

/**
 * Phalcon\Mvc\Model\ValidationFailed
 *
 * This exception is generated when a model fails to save a record
 * Phalcon\Mvc\Model must be set up to have this behavior
 */
class ValidationFailed extends Exception
{
    /**
     * @var array
     */
    protected messages = [];

    /**
     * @var ModelInterface
     */
    protected model;

    /**
     * Phalcon\Mvc\Model\ValidationFailed constructor
     *
     * @param ModelInterface model
     * @param Message[] validationMessages
     */
    public function __construct(<ModelInterface> model, array! validationMessages)
    {
        var messageStr, message;

        if count(validationMessages) > 0 {
            /**
             * Get the first message in the array
             */
            let message = validationMessages[0];

            /**
             * Get the message to use it in the exception
             */
            let messageStr = message->getMessage();
        } else {
            let messageStr = "Validation failed";
        }

        let this->model = model;
        let this->messages = validationMessages;

        parent::__construct(messageStr);
    }

    /**
     * Returns the complete group of messages produced in the validation
     */
    public function getMessages() -> <Message[]>
    {
        return this->messages;
    }

    /**
     * Returns the model that generated the messages
     */
    public function getModel() -> <ModelInterface>
    {
        return this->model;
    }
}
