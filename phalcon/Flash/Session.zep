
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

namespace Phalcon\Flash;

use Phalcon\Di\DiInterface;
use Phalcon\Session\ManagerInterface;

/**
 * This is an implementation of the Phalcon\Flash\FlashInterface that
 * temporarily stores the messages in session, then messages can be printed in
 * the next request.
 */
class Session extends AbstractFlash
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
     *
     * @return null|string|void
     */
    public function message(string type, string message) -> string | null
    {
        var messages;

        let messages = this->getSessionMessages(false);

        if !isset messages[type] {
            let messages[type] = [];
        }

        let messages[type][] = message;

        this->setSessionMessages(messages);

        return null;
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
        var session, messages, returnMessages;

        let session  = this->getSessionService(),
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
        var session;

        let session  = this->getSessionService();

        session->set("_flashMessages", messages);

        return messages;
    }

    /**
     * Returns the Session Service
     */
    public function getSessionService() -> <ManagerInterface>
    {
        var container;

        if this->sessionService {
            return this->sessionService;
        }

        let container = <DiInterface> this->container;
        if unlikely typeof container != "object" {
            throw new Exception(
                Exception::containerServiceNotFound("the 'session' service")
            );
        }

        if likely container->has("session") {
            return <ManagerInterface> container->getShared("session");
        } else {
            throw new Exception(
                Exception::containerServiceNotFound("the 'session' service")
            );
        }
    }

}
