
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Logger\Adapter;

use Phalcon\Logger\Adapter\Exceptions\FileOpenFailed;
use Phalcon\Logger\Adapter\Exceptions\InvalidStreamMode;
use Phalcon\Logger\Item;

/**
 * Phalcon\Logger\Adapter\Stream
 *
 * Adapter to store logs in plain text files
 *
 *```php
 * $logger = new \Phalcon\Logger\Adapter\Stream('app/logs/test.log');
 *
 * $logger->log('This is a message');
 * $logger->log(\Phalcon\Logger\Enum::ERROR, 'This is an error');
 * $logger->error('This is another error');
 *
 * $logger->close();
 *```
 *
 * @property resource|null $handler
 * @property string        $mode
 * @property string        $name
 */
class Stream extends AbstractAdapter
{
    /**
     * Stream handler resource
     *
     * @var resource|null
     */
    protected handler = null;

    /**
     * The file open mode. Defaults to 'ab'
     *
     * @var string
     */
    protected mode = "ab";

    /**
     * Stream name
     *
     * @var string
     */
    protected name;

    /**
     * Stream constructor.
     *
     * @param string $name
     * @param array  $options
     *
     * @throws InvalidStreamMode
     */
    public function __construct(string name, array options = [])
    {
        var mode;

        /**
         * Mode
         */
        let mode = true === isset(options["mode"]) ? options["mode"] : "ab";
        if (false !== mb_strpos(mode, "r")) {
            throw new InvalidStreamMode();
        }

        let this->name = name,
            this->mode = mode;
    }

    /**
     * Closes the stream
     */
    public function close() -> bool
    {
        var handler;

        if (this->handler !== null) {
            let handler = this->handler,
                this->handler = null;
            return this->phpFclose(handler);
        }

        return true;
    }

    /**
     * Stream name
     *
     * @return string
     */
    public function getName() -> string
    {
        return this->name;
    }

    /**
     * Processes the message i.e. writes it to the file
     *
     * @param Item $item
     */
    public function process(<Item> item) -> void
    {
        var fileHandler, message;

        if (!is_resource(this->handler)) {
            let fileHandler = this->phpFopen(this->name, this->mode);

            if (!is_resource(fileHandler)) {
                let this->handler = null;

                throw new FileOpenFailed(this->name, this->mode);
            }

            let this->handler = fileHandler;
        }

        let message = this->getFormattedItem(item) . PHP_EOL;
        this->phpFwrite(this->handler, message);
    }

    /**
     * @todo to be removed when we get traits
     */
    protected function phpFclose(var handle) -> bool
    {
        return fclose(handle);
    }

    /**
     * @todo to be removed when we get traits
     */
    protected function phpFopen(string filename, string mode)
    {
        return fopen(filename, mode);
    }

    /**
     * @todo to be removed when we get traits
     */
    protected function phpFwrite(var handle, string message)
    {
        return fwrite(handle, message);
    }
}
