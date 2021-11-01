
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Logger;

use DateTimeImmutable;

/**
 * Phalcon\Logger\Item
 *
 * Represents each item in a logging transaction
 *
 * @property array             $context
 * @property string            $message
 * @property int               $level
 * @property string            $levelName
 * @property DateTimeImmutable $datetime
 */
class Item
{
    /**
     * @var array
     */
    protected context = [] { get };

    /**
     * @var string
     */
    protected message { get };

    /**
     * @var int
     */
    protected level { get };

    /**
     * @var string
     */
    protected levelName { get };

    /**
     * @var DateTimeImmutable
     */
    protected dateTime { get };

    /**
     * Item constructor.
     *
     * @param string            $message
     * @param string            $levelName
     * @param int               $level
     * @param DateTimeImmutable $datetime
     * @param array             $context
     */
    public function __construct(
        string message,
        string levelName,
        int level,
        <DateTimeImmutable> dateTime,
        array context = []
    ) {
        let this->message   = message,
            this->levelName = levelName,
            this->level     = level,
            this->dateTime  = dateTime,
            this->context   = context;
    }
}
