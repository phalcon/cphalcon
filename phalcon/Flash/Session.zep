
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Flash;

use Phalcon\Session\ManagerInterface;

/**
 * This is an implementation of the Phalcon\Flash\FlashInterface that
 * temporarily stores the messages in session, then messages can be printed in
 * the next request.
 *
 * Class Session
 *
 * @package Phalcon\Flash
 */
class Session extends AbstractFlash
{
    const SESSION_KEY = "_flashMessages";

    /**
     * Clear messages in the session messenger
     *
     * @throws Exception
     */
    public function clear() -> void
    {
        this->getSessionMessages(true);
        parent::clear();
    }

    /**
     * Returns the messages in the session flasher
     *
     * @param mixed|null $type
     * @param bool       $remove
     *
     * @return array
     * @throws Exception
     */
    public function getMessages(var type = null, bool remove = true) -> array
    {
        return this->getSessionMessages(remove, type);
    }

    /**
     * Checks whether there are messages
     *
     * @param string|null $type
     *
     * @return bool
     * @throws Exception
     */
    public function has(string type = null) -> bool
    {
        var messages;

        let messages = this->getSessionMessages(false);

        if !type {
            return (true !== empty(messages));
        }

        return isset(messages[type]);
    }

    /**
     * Adds a message to the session flasher
     *
     * @param string $type
     * @param mixed  $message
     *
     * @return string|null
     * @throws Exception
     */
    public function message(string type, var message) -> string | null
    {
        var messages;

        let messages = this->getSessionMessages(false);

        if (true !== isset(messages[type])) {
            let messages[type] = [];
        }

        let messages[type][] = message;

        this->setSessionMessages(messages);

        return null;
    }

    /**
     * Prints the messages in the session flasher
     *
     * @param bool $remove
     *
     * @throws Exception
     */
    public function output(bool remove = true) -> void
    {
        var message, messages, type;

        let messages = this->getSessionMessages(remove);

        for type, message in messages {
            this->outputMessage(type, message);
        }

        parent::clear();
    }

    /**
     * Returns the messages stored in session
     *
     * @param bool       $remove
     * @param mixed|null $type
     *
     * @return array
     * @throws Exception
     */
    protected function getSessionMessages(bool remove, string type = null) -> array
    {
        var session, messages, returnMessages;

        let session  = this->getSessionService(),
            messages = session->get(self::SESSION_KEY);

        /**
         * Session might be empty
         */
        if typeof messages !== "array" {
            let messages = [];
        }

        if true !== empty(type) {
            if fetch returnMessages, messages[type] {
                if remove {
                    unset(messages[type]);
                    session->set(self::SESSION_KEY, messages);
                }

                return returnMessages;
            }

            return [];
        }

        if remove {
            session->remove(self::SESSION_KEY);
        }

        return messages;
    }

    /**
     * Stores the messages in session
     *
     * @param array $messages
     *
     * @return array
     * @throws Exception
     */
    protected function setSessionMessages(array! messages) -> array
    {
        var session;

        let session  = this->getSessionService();

        session->set(self::SESSION_KEY, messages);

        return messages;
    }

    /**
     * Returns the Session Service
     *
     * @return ManagerInterface
     * @throws Exception
     */
    public function getSessionService() -> <ManagerInterface>
    {
        if null !== this->sessionService {
            return this->sessionService;
        }

        if (
            null !== this->container &&
            true === this->container->has("session")
        ) {
            let this->sessionService = this->container->getShared("session");

            return this->sessionService;
        }

        throw new Exception(
            Exception::containerServiceNotFound("the 'session' service")
        );
    }
}
