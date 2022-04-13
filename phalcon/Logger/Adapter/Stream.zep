
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Logger\Adapter;

use LogicException;
use Phalcon\Logger\Exception;
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
 * $logger->log(\Phalcon\Logger::ERROR, 'This is an error');
 * $logger->error('This is another error');
 *
 * $logger->close();
 *```
 *
 * @property resource|null $handler
 * @property string        $mode
 * @property string        $name
 * @property array         $options
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
    protected name { get };

    /**
     * Path options
     *
     * @var array
     */
    protected options;

    /**
     * Stream constructor.
     *
     * @param string $name
     * @param array  $options
     *
     * @throws Exception
     */
    public function __construct(string name, array options = [])
    {
        var mode;

        /**
         * Mode
         */
        let mode = true === isset(options["mode"]) ? options["mode"] : "ab";
        if (false !== mb_strpos(mode, "r")) {
            throw new Exception("Adapter cannot be opened in read mode");
        }

        let this->name = name,
            this->mode = mode;
    }

    /**
     * Closes the stream
     */
    public function close() -> bool
    {
        bool result = true;

        if is_resource(this->handler) {
            let result = fclose(this->handler);
        }

        let this->handler = null;

        return result;
    }

    /**
     * Processes the message i.e. writes it to the file
     *
     * @param Item $item
     */
    public function process(<Item> item) -> void
    {
        var message;

        if !is_resource(this->handler) {
            let this->handler = this->phpFopen(this->name, this->mode);

            if !is_resource(this->handler) {
                let this->handler = null;

                throw new LogicException(
                    "The file '" .
                    this->name .
                    "' cannot be opened with mode '" .
                    this->mode .
                    "'"
                );
            }
        }

        let message = this->getFormattedItem(item) . PHP_EOL;

        fwrite(this->handler, message);
    }

    /**
     * @todo to be removed when we get traits
     */
    protected function phpFopen(string filename, string mode)
    {
        return fopen(filename, mode);
    }
}
