
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Logger\Formatter;

use Exception;
use Phalcon\Logger\Item;

/**
 * Class Line
 */
class Line extends AbstractFormatter
{
    /**
     * Format applied to each message
     *
     * @var string
     */
    protected format;

    /**
     * Line constructor.
     *
     * @param string $format
     * @param string $dateFormat
     */
    public function __construct(
        string format = "[%date%][%level%] %message%",
        string dateFormat = "c"
    ) {
        let this->format     = format,
            this->dateFormat = dateFormat;
    }

    /**
     * Applies a format to a message before sent it to the internal log
     *
     * @param Item $item
     *
     * @return string
     * @throws Exception
     */
    public function format(<Item> item) -> string
    {
        var message;

        let message = strtr(
            this->format,
            [
                "%date%"    : this->getFormattedDate(item),
                "%level%"   : item->getLevelName(),
                "%message%" : item->getMessage()
            ]
        );

        return this->toInterpolate(message, item->getContext());
    }

    /**
     * Return the format applied to each message
     *
     * @return string
     */
    public function getFormat() -> string
    {
        return this->format;
    }

    /**
     * Set the format applied to each message
     *
     * @param string $format
     *
     * @return Line
     */
    public function setFormat(string format) -> <Line>
    {
        let this->format = format;

        return this;
    }
}
