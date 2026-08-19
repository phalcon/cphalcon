
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
 */
class Item
{
    protected array context = [];
    protected <DateTimeImmutable> dateTime;
    protected int level;
    protected string levelName;
    protected string message;

    /**
     * Item constructor.
     *
     * @param string            $message
     * @param string            $levelName
     * @param int               $level
     * @param DateTimeImmutable $dateTime
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

    public function getContext() -> array
    {
        return this->context;
    }

    public function getDateTime() -> <DateTimeImmutable>
    {
        return this->dateTime;
    }

    public function getLevel() -> int
    {
        return this->level;
    }

    public function getLevelName() -> string
    {
        return this->levelName;
    }

    public function getMessage() -> string
    {
        return this->message;
    }
}
