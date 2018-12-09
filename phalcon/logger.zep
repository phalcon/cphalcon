
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon;

use Psr\Log\LoggerInterface;
use Psr\Log\InvalidArgumentException;
use Phalcon\Logger\Adapter\AdapterInterface;
use Phalcon\Logger\Item;
use Phalcon\Logger\Exception;

/**
 * Phalcon\Logger
 *
 * This component offers logging capabilities for your application. The component
 * accepts multiple adapters, working also as a multiple logger. Phalcon\Logger
 * implements PSR-3.
 *
 *<code>
 * use Phalcon\Logger;
 * use Phalcon\Logger\Adapter\Stream;
 *
 * $adapter1 = new Stream('/logs/first-log.log');
 * $adapter2 = new Stream('/remote/second-log.log');
 * $adapter3 = new Stream('/manager/third-log.log');
 *
 * $logger = new Logger(
 * 		'messages',
 * 		[
 * 			'local'   => $adapter1,
 * 			'remote'  => $adapter2,
 * 			'manager' => $adapter3,
 * 		]
 * 	);
 *
 * // Log to all adapters
 * $logger->error('Something went wrong');
 *
 * // Log to specific adapters
 * $logger
 * 		->excludeAdapters(['manager'])
 * 		->info('This does not go to the "manager" logger);
 *</code>
 */
class Logger implements LoggerInterface
{
	const ALERT     = 2;
	const CRITICAL  = 1;
	const CUSTOM    = 8;
	const DEBUG     = 7;
	const EMERGENCY = 0;
	const ERROR     = 3;
	const INFO      = 6;
	const NOTICE    = 5;
	const WARNING   = 4;

    /**
     * The adapter stack
     *
     * @var AdapterInterface[]
     */
    protected adapters = [];

    /**
     * @var string
     */
    protected name = "";

    /**
     * The excluded adapters for this log process
     *
     * @var AdapterInterface[]
     */
    protected excluded = [];

	/**
	 * Constructor.
	 *
	 * @param string name     The name of the logger
	 * @param array  adapters The collection of adapters to be used for logging (default [])
	 */
    public function __construct(string! name, array! adapters = []) -> void
    {
        let this->name = name;
        this->setAdapters(adapters);
    }

    /**
     * Add an adapter to the stack. For processing we use FIFO
     *
     * @param string             name    The name of the adapter
     * @param <AdapterInterface> adapter The adapter to add to the stack
     *
     * @return <Logger>
     */
    public function addAdapter(string name, <AdapterInterface> adapter) -> <Logger>
    {
        let this->adapters[name] = adapter;

        return this;
    }

    /**
     * Action must be taken immediately.
     *
     * Example: Entire website down, database unavailable, etc. This should
     * trigger the SMS alerts and wake you up.
     *
     * @param string message
     * @param array  context
     *
     * @return void
     */
    public function alert(message, array context = []) -> void
    {
        this->addMessage(self::ALERT, (string) message, context);
    }

    /**
     * Critical conditions.
     *
     * Example: Application component unavailable, unexpected exception.
     *
     * @param string message
     * @param array  context
     *
     * @return void
     */
    public function critical(message, array context = []) -> void
    {
        this->addMessage(self::CRITICAL, (string) message, context);
    }

    /**
     * Detailed debug information.
     *
     * @param string message
     * @param array  context
     *
     * @return void
     */
    public function debug(message, array context = []) -> void
    {
        this->addMessage(self::DEBUG, (string) message, context);
    }

    /**
     * Runtime errors that do not require immediate action but should typically
     * be logged and monitored.
     *
     * @param string message
     * @param array  context
     *
     * @return void
     */
    public function error(message, array context = []) -> void
    {
        this->addMessage(self::ERROR, (string) message, context);
    }

    /**
     * System is unusable.
     *
     * @param string message
     * @param array  context
     *
     * @return void
     */
    public function emergency(message, array context = []) -> void
    {
        this->addMessage(self::EMERGENCY, (string) message, context);
    }

    /**
     * System is unusable.
     *
     * @param string message
     * @param array  context
     *
     * @return void
     */
    public function excludeAdapters(array adapters = []) -> <Logger>
    {
    	var name, registered;

    	let registered = this->getAdapters();

    	/**
    	 * Loop through what has been passed. Check these names with
    	 * the registered adapters. If they match, add them to the
    	 * this->excluded array
		 */
    	for name, _ in adapters {
			if isset(registered[name]) {
				let this->excluded[] = name;
			}
    	}

        return this;
    }

    /**
     * Returns an adapter from the stack
     *
     * @param string name The name of the adapter
     *
     * @return <AdapterInterface>
     * @throws <Exception>
     */
    public function getAdapter(string name) -> <AdapterInterface>
    {
    	var adapter, adapters;

    	let adapters = this->getAdapters();

    	if !fetch adapter, adapters[name] {
    		throw new Exception("Adapter does not exist for this logger");
    	}

        return adapter;
    }

    /**
     * Returns the adapter stack array
     *
     * @return AdapterInterface[]
     */
    public function getAdapters() -> array
    {
        return this->adapters;
    }

    /**
     * Returns the name of the logger
     *
     * @return string
     */
    public function getName() -> string
    {
        return this->name;
    }

    /**
     * Interesting events.
     *
     * Example: User logs in, SQL logs.
     *
     * @param string message
     * @param array  context
     *
     * @return void
     */
    public function info(message, array context = []) -> void
    {
        this->addMessage(self::INFO, (string) message, context);
    }

    /**
     * Logs with an arbitrary level.
     *
     * @param mixed  $level
     * @param string message
     * @param array  context
     *
     * @return void
     */
    public function log(level, message, array context = []) -> void
    {
    	var intLevel;

    	let intLevel = this->getLevelNumber(level);

        this->addMessage(level, (string) message, context);
    }

    /**
     * Normal but significant events.
     *
     * @param string message
     * @param array  context
     *
     * @return void
     */
    public function notice(message, array context = []) -> void
    {
        this->addMessage(self::NOTICE, (string) message, context);
    }

    /**
     * Removes an adapter from the stack
     *
     * @param string name The name of the adapter
     *
     * @return <Logger>
     * @throws <Logger\Exception>
     */
    public function removeAdapter(string name) -> <Logger>
    {
    	var adapters;

		let adapters = this->adapters;

    	if true !== isset(adapters[name]) {
    		throw new Exception("Adapter does not exist for this logger");
    	}

    	unset adapters[name];

		let this->adapters = adapters;

        return this;
    }

    /**
     * Sets the adapters stack overriding what is already there
     *
     * @param array adapters An array of adapters
     *
     * @return <Logger>
     */
    public function setAdapters(array! adapters) -> <Logger>
    {
        let this->adapters = adapters;

        return this;
    }

    /**
     * Exceptional occurrences that are not errors.
     *
     * Example: Use of deprecated APIs, poor use of an API, undesirable things
     * that are not necessarily wrong.
     *
     * @param string message
     * @param array  context
     *
     * @return void
     */
    public function warning(message, array context = []) -> void
    {
        this->addMessage(self::WARNING, (string) message, context);
    }

    /**
     * Adds a message to each handler for processing
     *
     * @param int    level
     * @param string message
     * @param array  context
     *
     * @return bool
     * @throws <Logger\Exception>
     */
    protected function addMessage(int level, string message, array context = []) -> bool
    {
    	var adapter, key, keys, excluded, levelName, levels, item, registered;

		let registered = this->adapters,
			excluded   = this->excluded;

    	if count(registered) === 0 {
    		throw new Exception("No adapters specified");
    	}

		let levels = this->getLevels();
		if !fetch levelName, levels[level] {
			let levelName = levels[self::CUSTOM];
		}

		let item = new Item(message, levelName, level, time(), context);

		/**
		 * Compare the actual adapters array with the excluded one. Whatever
		 * the difference is, that is the array of adapters that we will log
		 * this message to. By default `excluded` is empty so the message will
		 * be loggged to all registered adapters
		 */
		 let keys = array_diff(array_keys(registered), excluded);

		for key in keys {
			let adapter = registered[key];
    		adapter->process(item);
    	}

		/**
		 * Clear the excluded array since we made the call now
		 */
		let this->excluded = [];

    	return true;
	}

    /**
     * Returns an array of log levels with integer to string conversion
     *
     * @return array
     */
    protected function getLevels() -> array
    {
		return [
			self::ALERT     : "alert",
			self::CRITICAL  : "critical",
			self::DEBUG     : "debug",
			self::EMERGENCY : "emergency",
			self::ERROR     : "error",
			self::INFO      : "info",
			self::NOTICE    : "notice",
			self::WARNING   : "warning",
			self::CUSTOM    : "custom"
		];
    }

    /**
     * Converts the level from string/word to an integer
     *
     * @param string|int level
     *
     * @return int
     */
	private function getLevelNumber(level) -> int
    {
    	var levelName, numberLevel, levels;

    	if typeof level === "string" {
    		let levelName = strtolower(level),
    			levels    = array_flip(this->getLevels());

    		if fetch numberLevel, levels[levelName] {
    			return numberLevel;
    		}
    	} elseif is_numeric(level) {
    		let levels = this->getLevels();

    		if fetch numberLevel, levels[level] {
    			return numberLevel;
    		}
    	}

    	 return self::CUSTOM;
    }
}
