
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Session;

use InvalidArgumentException;
use RuntimeException;
use SessionHandlerInterface;
use Phalcon\Di\AbstractInjectionAware;
use Phalcon\Di\DiInterface;
use Phalcon\Support\Helper\Arr\Get;

/**
 * Phalcon\Session\Manager
 *
 * Session manager class
 */
class Manager extends AbstractInjectionAware implements ManagerInterface
{
    /**
     * @var SessionHandlerInterface|null
     */
    private adapter = null;

    /**
     * @var string
     */
    private name = "";

    /**
     * @var array
     */
    private options = [];

    /**
     * @var string
     */
    private uniqueId = "";

    /**
     * Manager constructor.
     *
     * @param array options = [
     *     'uniqueId' => null
     * ]
     */
    public function __construct(array options = [])
    {
        this->setOptions(options);
    }

    /**
     * Alias: Gets a session variable from an application context
     */
    public function __get(string key) -> var
    {
        return this->get(key);
    }

    /**
     * Alias: Check whether a session variable is set in an application context
     */
    public function __isset(string key) -> bool
    {
        return this->has(key);
    }

    /**
     * Alias: Sets a session variable in an application context
     */
    public function __set(string key, value) -> void
    {
        this->set(key, value);
    }

    /**
     * Alias: Removes a session variable from an application context
     */
    public function __unset(string key) -> void
    {
        this->remove(key);
    }

    /**
     * Destroy/end a session
     */
    public function destroy() -> void
    {
        if true === this->exists() {
            session_destroy();

            let _SESSION = [];
        }
    }

    /**
     * Check whether the session has been started
     */
    public function exists() -> bool
    {
        return (session_status() === self::SESSION_ACTIVE);
    }

    /**
     * Gets a session variable from an application context
     */
    public function get(string key, var defaultValue = null, bool remove = false) -> var
    {
        var uniqueKey, value = null;

        if false === this->exists() {
            // To use $_SESSION variable we need to start session first
            return value;
        }

        let uniqueKey = this->getUniqueKey(key),
            value     = this->getArrVal(_SESSION, uniqueKey, defaultValue);

        if remove {
            unset(_SESSION[uniqueKey]);
        }

        return value;
    }

    /**
     * Returns the stored session adapter
     */
    public function getAdapter() -> <SessionHandlerInterface>
    {
        return this->adapter;
    }

    /**
     * Returns the session id
     */
    public function getId() -> string
    {
        return session_id();
    }

    /**
     * Returns the name of the session
     */
    public function getName() -> string
    {
        if "" === this->name {
            let this->name = session_name();
        }

        return this->name;
    }

    /**
     * Check whether a session variable is set in an application context
     */
    public function has(string key) -> bool
    {
        var uniqueKey;

        if false === this->exists() {
            // To use $_SESSION variable we need to start session first
            return false;
        }

        let uniqueKey = this->getUniqueKey(key);

        return isset _SESSION[uniqueKey];
    }

    /**
     * Get internal options
     */
    public function getOptions() -> array
    {
        return this->options;
    }

    /**
     * Regenerates the session id using the adapter.
     */
    public function regenerateId(deleteOldSession = true) -> <ManagerInterface>
    {
        var delete;

        let delete = (bool) deleteOldSession;

        if true === this->exists() {
            session_regenerate_id(delete);
        }

        return this;
    }

    /**
     * Removes a session variable from an application context
     */
    public function remove(string key) -> void
    {
        if false === this->exists() {
            // To use $_SESSION variable we need to start session first
            return;
        }

        var uniqueKey;

        let uniqueKey = this->getUniqueKey(key);

        unset(_SESSION[uniqueKey]);
    }

    /**
     * Sets a session variable in an application context
     */
    public function set(string key, value) -> void
    {
        var uniqueKey;

        if false === this->exists() {
            // To use $_SESSION variable we need to start session first
            return;
        }

         let uniqueKey          = this->getUniqueKey(key),
            _SESSION[uniqueKey] = value;
    }

    /**
     * Set the adapter for the session
     */
    public function setAdapter(<SessionHandlerInterface> adapter) -> <ManagerInterface>
    {
        let this->adapter = adapter;

        return this;
    }

    /**
     * Set session Id
     */
    public function setId(string id) -> <ManagerInterface>
    {
        if unlikely (true === this->exists()) {
            throw new RuntimeException(
                "The session has already been started. " .
                "To change the id, use regenerateId()"
            );
        }

        session_id(id);

        return this;
    }

    /**
     * Set the session name. Throw exception if the session has started
     * and do not allow poop names
     *
     * @param  string name
     *
     * @throws InvalidArgumentException
     *
     * @return Manager
     */
    public function setName(string name) -> <ManagerInterface>
    {
        if unlikely this->exists() {
            throw new InvalidArgumentException(
                "Cannot set session name after a session has started"
            );
        }

        if unlikely !preg_match("/^[\p{L}\p{N}_-]+$/u", name) {
            throw new InvalidArgumentException(
                "The name contains non alphanum characters"
            );
        }

        let this->name = name;

        session_name(name);

        return this;
    }

    /**
     * Sets session's options
     */
    public function setOptions(array options) -> void
    {
        let this->uniqueId = this->getArrVal(options, "uniqueId", ""),
            this->options  = options;
    }

    /**
     * Starts the session (if headers are already sent the session will not be
     * started)
     */
    public function start() -> bool
    {
        var name, value;

        let name = this->getName();

        /**
         * Check if the session exists
         */
        if true === this->exists() {
            return true;
        }

        /**
         * Cannot start this - headers already sent
         */
        if true === headers_sent() {
            return false;
        }

        if unlikely !(this->adapter instanceof SessionHandlerInterface) {
            throw new Exception("The session adapter is not valid");
        }

        /**
         * Verify that the session value is alphanumeric, otherwise we
         * unset the cookie to allow it to be created by session_start().
         */
        if fetch value, _COOKIE[name] {
            if !preg_match("/^[a-z0-9]+$/iD", value) {
                unset _COOKIE[name];
            }
        }

        /**
         * Register the adapter
         */
        session_set_save_handler(this->adapter);

        /**
         * Start the session
         */
        return session_start();
    }

    /**
     * Returns the status of the current session.
     */
    public function status() -> int
    {
        var status;

        let status = session_status();

        switch status {
            case PHP_SESSION_DISABLED:
                return self::SESSION_DISABLED;

            case PHP_SESSION_ACTIVE:
                return self::SESSION_ACTIVE;
        }

        return self::SESSION_NONE;
    }

    /**
     * Returns the key prefixed
     */
    private function getUniqueKey(string key) -> string
    {
        var uniqueId;

        let uniqueId = this->uniqueId;

        if !empty uniqueId {
            return this->uniqueId . "#" . key;
        } else {
            return key;
        }
    }

    /**
     * @todo Remove this when we get traits
     */
    private function getArrVal(
        array! collection,
        var index,
        var defaultValue = null
    ) -> var {
        var value;

        if unlikely !fetch value, collection[index] {
            return defaultValue;
        }

        return value;
    }
}
