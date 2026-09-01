
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by sinbadxiii/cphalcon-uuid
 * @link    https://github.com/sinbadxiii/cphalcon-uuid
 */

namespace Phalcon\Encryption\Security\Uuid;

/**
 * Generates a version 6 (reordered time-based) UUID.
 *
 * Uses the same 60-bit UUID timestamp as version 1 but rearranges the
 * fields so the most-significant time bits come first, producing UUIDs
 * that sort lexicographically in chronological order.
 *
 * @link https://www.rfc-editor.org/rfc/rfc9562
 */
class Version6 extends AbstractUuid implements TimeBasedUuidInterface
{
    public function __construct()
    {
        var nowSec, nowUsec, timeHigh32, timeMid16, timeLow12, clockSeqBytes, clockSeqHiRes, clockSeqLow, nodeStr;
        int sec, usec, timestamp;

        let nowSec  = time();
        let sec     = nowSec;
        let nowUsec = intval(round((microtime(true) - doubleval(nowSec)) * 10000000.0));
        let usec    = nowUsec;

        let timestamp = (sec + 12219292800) * 10000000 + usec;

        let timeHigh32 = (timestamp >> 28) & 0xffffffff,
            timeMid16  = (timestamp >> 12) & 0xffff,
            timeLow12  = 0x6000 | (timestamp & 0x0fff);

        let clockSeqBytes = random_bytes(2);
        let clockSeqHiRes = (ord(substr(clockSeqBytes, 0, 1)) & 0x3f) | 0x80;
        let clockSeqLow   = ord(substr(clockSeqBytes, 1, 1));

        let nodeStr = this->getNodeProvider()->getNode();

        let this->uid = sprintf(
            "%08x-%04x-%04x-%02x%02x-%s",
            timeHigh32,
            timeMid16,
            timeLow12,
            clockSeqHiRes,
            clockSeqLow,
            nodeStr
        );
    }

    /**
     * Returns a DateTimeImmutable built from the UUID's embedded timestamp.
     */
    public function getDateTime() -> <\DateTimeImmutable>
    {
        var parts, hexHigh32, hexMid16, hexLow12;
        int timeHigh32, timeMid16, timeLow12, timestamp;

        let parts      = explode("-", this->uid);
        let hexHigh32  = hexdec(parts[0]);
        let hexMid16   = hexdec(parts[1]);
        let hexLow12   = hexdec(parts[2]) & 0x0fff;
        let timeHigh32 = hexHigh32;
        let timeMid16  = hexMid16;
        let timeLow12  = hexLow12;
        let timestamp  = (timeHigh32 << 28) | (timeMid16 << 12) | timeLow12;

        return this->uuidTimestampToDateTime(timestamp);
    }

    /**
     * Returns the 12-character hex node embedded in the UUID.
     */
    public function getNode() -> string
    {
        return substr(this->uid, 24);
    }
}
