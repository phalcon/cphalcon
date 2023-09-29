
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
use Phalcon\Logger\Item;
use Phalcon\Support\Helper\Str\AbstractStr;

/**
 * Class AbstractFormatter
 */
abstract class AbstractFormatter extends AbstractStr implements FormatterInterface
{
    /**
     * Default date format
     *
     * @var string
     */
    protected dateFormat = "c";

    /**
     * @var string
     */
    protected interpolatorLeft = "%";

    /**
     * @var string
     */
    protected interpolatorRight = "%";

    /**
     * @return string
     */
    public function getDateFormat() -> string
    {
        return $this->dateFormat;
    }

    /**
     * @param string $format
     */
    public function setDateFormat(string $format) -> void
    {
        let this->dateFormat = $format;
    }

    /**
     * Returns the date formatted for the logger.
     *
     * @param Item $item
     *
     * @return string
     */
    protected function getFormattedDate(<Item> item) -> string
    {
        return item->getDateTime()->format(this->dateFormat);
    }

    /**
     * @param Item   $item
     * @param string $message
     *
     * @return string
     */
    protected function getInterpolatedMessage(
        <Item> item,
        string message
    ) -> string {
        return $this->toInterpolate(
            message,
            item->getContext(),
            this->interpolatorLeft,
            this->interpolatorRight
        );
    }
}
