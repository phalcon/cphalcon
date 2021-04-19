
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
        var context, format, time;

        let context = item->getContext(),
            format  = this->format,
            time    = item->getTime();

        /**
         * Check if the format has the %date% placeholder
         */
        if memstr(format, "%date%") {
            let format = str_replace(
                "%date%",
                time->format(this->dateFormat),
                format
            );
        }

        /**
         * Check if the format has the %level% placeholder
         */
        if memstr(format, "%level%") {
            let format = str_replace("%level%", item->getLevelName(), format);
        }

        let format = str_replace("%message%", item->getMessage(), format);

        if !empty context {
            return this->interpolate(format, context);
        }

        return format;
    }
}
