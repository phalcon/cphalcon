
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Session\Adapter;

use Phalcon\Session\Adapter\Exceptions\AdapterRuntimeError;
use Phalcon\Storage\AdapterFactory;

/**
 * Phalcon\Session\Adapter\Redis
 */
 class Redis extends AbstractAdapter
{
    /**
     * @var bool
     */
    protected lockAcquired = false;

    /**
     * Lock time-to-live in seconds. The lock is not refreshed during the
     * request: a request that runs longer than this expiry loses its lock
     * silently and a concurrent request may then acquire it (the token-guarded
     * release still avoids deleting the newer lock). Raise this above the
     * longest expected request to retain the lock for the whole request.
     *
     * @var int
     */
    protected lockExpiry = 30;

    /**
     * @var bool
     */
    protected lockingEnabled = false;

    /**
     * @var string
     */
    protected lockKey = "";

    /**
     * @var int
     */
    protected lockRetries = 100;

    /**
     * @var string
     */
    protected lockToken = "";

    /**
     * @var int
     */
    protected lockWaitTime = 50000;

    /**
     * @var string
     */
    protected prefix = "";

    /**
     * Constructor
     *
     * @param AdapterFactory $factory
     * @param array          $options = [
     *                                'prefix'         => 'sess-reds-',
     *                                'stripPrefix'    => false,
     *                                'host'           => '127.0.0.1',
     *                                'port'           => 6379,
     *                                'index'          => 0,
     *                                'persistent'     => false,
     *                                'auth'           => '',
     *                                'socket'         => '',
     *                                'lockingEnabled' => false,
     *                                'lockExpiry'     => 30,
     *                                'lockRetries'    => 100,
     *                                'lockWaitTime'   => 50000,
     * ]
     */
    public function __construct(<AdapterFactory> factory, array! options = [])
    {
        /**
         * Session ids are externally generated and never carry the storage
         * prefix; disable prefix stripping so an id that happens to start
         * with the prefix text cannot collide with another session
         */
        let options["prefix"]      = this->getArrVal(options, "prefix", "sess-reds-"),
            options["stripPrefix"] = this->getArrVal(options, "stripPrefix", false),
            this->lockExpiry       = (int) this->getArrVal(options, "lockExpiry", 30),
            this->lockingEnabled   = (bool) this->getArrVal(options, "lockingEnabled", false),
            this->lockRetries      = (int) this->getArrVal(options, "lockRetries", 100),
            this->lockWaitTime     = (int) this->getArrVal(options, "lockWaitTime", 50000),
            this->prefix           = (string) options["prefix"],
            this->adapter          = factory->newInstance("redis", options);
    }

    /**
     * Close - releases the session lock if one is held
     */
    public function close() -> bool
    {
        this->releaseLock();

        return true;
    }

    /**
     * Destroy
     */
    public function destroy(var id) -> bool
    {
        var result;

        let result = parent::destroy(id);

        this->releaseLock();

        return result;
    }

    /**
     * Read
     */
    public function read(var id) -> string
    {
        if (true === this->lockingEnabled && true !== this->acquireLock(id)) {
            throw new AdapterRuntimeError(
                "Could not acquire the session lock with key: " . this->lockKey
            );
        }

        return parent::read(id);
    }

    /**
     * Tries to acquire the session lock, pausing `lockWaitTime` microseconds
     * between attempts, up to `lockRetries` times
     */
    protected function acquireLock(var id) -> bool
    {
        var client, lockKey, result, token;
        int attempt;

        let lockKey = this->prefix . id . "-lock";

        /**
         * Re-entrant read (e.g. the session_reset() path) while this instance
         * already holds the lock for this id: return the held lock instead of
         * spinning against our own lock for the full retry budget
         */
        if (true === this->lockAcquired && lockKey === this->lockKey) {
            return true;
        }

        let this->lockKey = lockKey,
            client        = this->adapter->getAdapter(),
            token         = bin2hex(random_bytes(16)),
            attempt       = 0;

        while attempt < this->lockRetries {
            /**
             * rawCommand bypasses OPT_PREFIX and OPT_SERIALIZER so that the
             * lock value stays a plain string regardless of the configured
             * serializer; the key carries the session prefix manually
             */
            let result = client->rawCommand(
                "SET",
                this->lockKey,
                token,
                "NX",
                "EX",
                this->lockExpiry
            );

            if (false !== result) {
                let this->lockAcquired = true,
                    this->lockToken    = token;

                return true;
            }

            usleep(this->lockWaitTime);

            let attempt++;
        }

        return false;
    }

    /**
     * Releases the session lock - only when this instance still owns it
     */
    protected function releaseLock() -> void
    {
        var client;
        string script;

        if (true !== this->lockAcquired) {
            return;
        }

        let script = "if redis.call('get', KEYS[1]) == ARGV[1] then return redis.call('del', KEYS[1]) else return 0 end",
            client = this->adapter->getAdapter();

        client->rawCommand("EVAL", script, 1, this->lockKey, this->lockToken);

        let this->lockAcquired = false,
            this->lockToken    = "";
    }
}
