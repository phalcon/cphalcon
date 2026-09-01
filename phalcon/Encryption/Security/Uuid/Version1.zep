
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
 * Generates a version 1 (time-based) UUID.
 *
 * The timestamp is the number of 100-nanosecond intervals since
 * October 15, 1582 00:00:00.00 UTC (the UUID epoch). The node is resolved
 * via SysNodeProvider (hardware MAC, APCu-cached) with RandomNodeProvider
 * as fallback.
 *
 * @link https://www.ietf.org/rfc/rfc4122.txt
 */
class Version1 extends AbstractUuid implements TimeBasedUuidInterface
{
    public function __construct(<\DateTimeInterface> dateTime = null, var node = null)
    {
        var nowSec, nowUsec, dateTimestamp, dateUsec, timeLow, timeMid, timeHi,
            clockSeqBytes, clockSeqHiRes, clockSeqLow, nodeStr;
        int sec, usec, timestamp;

        if dateTime !== null {
            let dateTimestamp = dateTime->getTimestamp();
            let sec           = dateTimestamp;
            let dateUsec      = intval(dateTime->format("u")) * 10;
            let usec          = dateUsec;
        } else {
            let nowSec  = time();
            let sec     = nowSec;
            let nowUsec = intval(round((microtime(true) - doubleval(nowSec)) * 10000000.0));
            let usec    = nowUsec;
        }

        let timestamp = (sec + 12219292800) * 10000000 + usec;

        let timeLow = timestamp & 0xffffffff,
            timeMid = (timestamp >> 32) & 0xffff,
            timeHi  = ((timestamp >> 48) & 0x0fff) | 0x1000;

        let clockSeqBytes = random_bytes(2);
        let clockSeqHiRes = (ord(substr(clockSeqBytes, 0, 1)) & 0x3f) | 0x80;
        let clockSeqLow   = ord(substr(clockSeqBytes, 1, 1));

        if node !== null {
            let nodeStr = node;
        } else {
            let nodeStr = this->getNodeProvider()->getNode();
        }

        let this->uid = sprintf(
            "%08x-%04x-%04x-%02x%02x-%s",
            timeLow,
            timeMid,
            timeHi,
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
        var parts, hexTimeLow, hexTimeMid, hexTimeHi;
        int timeLow, timeMid, timeHi, timestamp;

        let parts      = explode("-", this->uid);
        let hexTimeLow = hexdec(parts[0]);
        let hexTimeMid = hexdec(parts[1]);
        let hexTimeHi  = hexdec(parts[2]) & 0x0fff;
        let timeLow    = hexTimeLow;
        let timeMid    = hexTimeMid;
        let timeHi     = hexTimeHi;
        let timestamp  = (timeHi << 48) | (timeMid << 32) | timeLow;

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
