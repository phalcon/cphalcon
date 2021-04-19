
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
 */
class Item
{
    /**
     * Log Context
     *
     * @var mixed
     */
    protected context { get };

    /**
     * Log message
     *
     * @var string
     */
    protected message { get };

    /**
     * Log type
     *
     * @var integer
     */
    protected level { get };

    /**
     * Log message
     *
     * @var string
     */
    protected levelName { get };

    /**
     * Log timestamp
     *
     * @var DateTimeImmutable
     */
    protected time { get };

    /**
     * Phalcon\Logger\Item constructor
     */
    public function __construct(
        string message,
        string levelName,
        int level,
        <DateTimeImmutable> time,
        array context = []
    ) {
        let this->message   = message,
            this->levelName = levelName,
            this->level     = level,
            this->time      = time,
            this->context   = context;
    }
}
