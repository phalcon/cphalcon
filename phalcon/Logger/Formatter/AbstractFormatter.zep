
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Logger\Formatter;

use DateTimeImmutable;
use DateTimeZone;
use Phalcon\Logger;
use Phalcon\Logger\Item;

abstract class AbstractFormatter implements FormatterInterface
{
    /**
     * Default date format
     *
     * @var string
     */
    protected dateFormat { get, set };

    /**
     * Interpolates context values into the message placeholders
     *
     * @see http://www.php-fig.org/psr/psr-3/ Section 1.2 Message
     * @param string $message
     * @param array $context
     */
    public function interpolate(string message, var context = null)
    {
        var key, value;
        array replace;

        if typeof context == "array" && count(context) > 0 {
            let replace = [];

            for key, value in context {
                let replace["{" . key . "}"] = value;
            }

            return strtr(message, replace);
        }

        return message;
    }

    /**
     * Returns the date formatted for the logger.
     * @todo Not using the set time from the Item since we have interface
     * misalignment which will break semver This will change in the future
     */
    protected function getFormattedDate() -> string
    {
        var date, timezone;

        let timezone = date_default_timezone_get();
            date     = new DateTimeImmutable("now", new DateTimeZone(timezone));

        return date->format(this->dateFormat);
    }
}
