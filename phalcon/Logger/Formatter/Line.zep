
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Logger\Formatter;

use DateTime;
use Phalcon\Logger\Item;
use Phalcon\Support\Helper\Str\Interpolate;

/**
 * Phalcon\Logger\Formatter\Line
 *
 * Formats messages using an one-line string
 */
class Line extends AbstractFormatter
{
    /**
     * Format applied to each message
     *
     * @var string
     */
    protected format { get, set };

    /**
     * Phalcon\Logger\Formatter\Line construct
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
     */
    public function format(<Item> item) -> string
    {
        var context, format, interpolate, time;

        let context     = item->getContext(),
            format      = this->format,
            time        = item->getTime(),
            interpolate = new Interpolate();

        let context["date"]    = time->format(this->dateFormat),
            context["level"]   = item->getLevelName(),
            context["message"] = item->getMessage();

        return interpolate->__invoke(format, context);
    }
}
