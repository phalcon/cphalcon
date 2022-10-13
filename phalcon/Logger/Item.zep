
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
    protected context = [];

    /**
     * @var DateTimeImmutable
     */
    protected dateTime;

    /**
     * @var string
     */
    protected message;

    /**
     * @var int
     */
    protected level;

    /**
     * @var string
     */
    protected levelName;

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

    /**
     * @return array
     */
    public function getContext() -> array
    {
        return this->context;
    }

    /**
     * @return DateTimeImmutable
     */
    public function getDateTime() -> <DateTimeImmutable>
    {
        return this->dateTime;
    }

    /**
     * @return string
     */
    public function getMessage() -> string
    {
        return this->message;
    }

    /**
     * @return int
     */
    public function getLevel() -> int
    {
        return this->level;
    }

    /**
     * @return string
     */
    public function getLevelName() -> string
    {
        return this->levelName;
    }
}
