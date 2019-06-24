
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Flash;

use Phalcon\Flash as FlashBase;
use Phalcon\DiInterface;
use Phalcon\Flash\Exception;
use Phalcon\Session\ManagerInterface as SessionInterface;

/**
 * Temporarily stores the messages in session, then messages can be printed in
 * the next request
 */
class Session extends FlashBase
{
    /**
     * Clear messages in the session messenger
     */
    public function clear() -> void
    {
        this->getSessionMessages(true);
        parent::clear();
    }

    /**
     * Returns the messages in the session flasher
     */
    public function getMessages(type = null, bool remove = true) -> array
    {
        return this->getSessionMessages(remove, type);
    }

    /**
     * Checks whether there are messages
     */
    public function has(type = null) -> bool
    {
        var messages;

        let messages = this->getSessionMessages(false);

        if typeof type != "string" {
            return true;
        }

        return isset messages[type];
    }

    /**
     * Adds a message to the session flasher
     */
    public function message(string type, string message) -> void
    {
        var messages;

        let messages = this->getSessionMessages(false);

        if !isset messages[type] {
            let messages[type] = [];
        }

        let messages[type][] = message;

        this->setSessionMessages(messages);
    }

    /**
     * Prints the messages in the session flasher
     */
    public function output(bool remove = true) -> void
    {
        var type, message, messages;

        let messages = this->getSessionMessages(remove);

        for type, message in messages {
            this->outputMessage(type, message);
        }

        parent::clear();
    }

    /**
     * Returns the messages stored in session
     */
    protected function getSessionMessages(bool remove, type = null) -> array
    {
        var container, session, messages, returnMessages;

        let container = <DiInterface> this->getDI();

        let session = <SessionInterface> container->getShared("session"),
            messages = session->get("_flashMessages");

        /**
         * Session might be empty
         */
        if typeof messages != "array" {
            let messages = [];
        }

        if typeof type == "string" {
            if fetch returnMessages, messages[type] {
                if remove {
                    unset(messages[type]);
                    session->set("_flashMessages", messages);
                }

                return returnMessages;
            }

            return [];
        }

        if remove {
            session->remove("_flashMessages");
        }

        return messages;
    }

    /**
     * Stores the messages in session
     */
    protected function setSessionMessages(array! messages) -> array
    {
        var container, session;

        let container = <DiInterface> this->getDI(),
            session = <SessionInterface> container->getShared("session");

        session->set("_flashMessages", messages);

        return messages;
    }
}
