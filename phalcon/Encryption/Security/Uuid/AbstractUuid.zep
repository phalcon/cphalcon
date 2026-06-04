
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
 * Shared base for all UUID version objects.
 */
abstract class AbstractUuid implements UuidInterface
{
    /**
     * @var string
     */
    const MAX = "ffffffff-ffff-ffff-ffff-ffffffffffff";

    /**
     * @var string
     */
    const NIL = "00000000-0000-0000-0000-000000000000";

    /**
     * 100-nanosecond intervals between UUID epoch (1582-10-15) and Unix epoch (1970-01-01).
     *
     * @var int
     */
    const TIME_OFFSET_INT = 0x01B21DD213814000;

    /**
     * Cached SysNodeProvider instance - shared within the request via static.
     *
     * @var NodeProviderInterface|null
     */
    protected static nodeProvider = null;

    /**
     * The generated UUID string.
     *
     * @var string
     */
    protected uid = "";

    /**
     * Returns the UUID string.
     */
    public function __toString() -> string
    {
        return this->uid;
    }

    /**
     * Returns the UUID string for JSON serialisation.
     */
    public function jsonSerialize() -> string
    {
        return this->uid;
    }

    /**
     * Returns the shared SysNodeProvider instance, creating it on first call.
     * The static property means one discovery per request regardless of how
     * many VersionN objects are constructed.
     */
    protected function getNodeProvider() -> <NodeProviderInterface>
    {
        if self::nodeProvider === null {
            let self::nodeProvider = new SysNodeProvider();
        }

        return self::nodeProvider;
    }

    /**
     * Converts a 60-bit UUID timestamp (100-ns intervals since UUID epoch) to
     * a DateTimeImmutable. Used by Version1 and Version6.
     */
    protected function uuidTimestampToDateTime(var timestamp) -> <\DateTimeImmutable>
    {
        var sec, usec;

        let sec  = intdiv(timestamp, 10000000) - 12219292800;
        let usec = intdiv(timestamp % 10000000, 10);

        return \DateTimeImmutable::createFromFormat(
            "U u",
            sec . " " . str_pad(usec, 6, "0", STR_PAD_LEFT)
        );
    }

    /**
     * Formats a 32-character hex string as a canonical UUID string.
     */
    protected function format(string hex) -> string
    {
        return substr(hex, 0, 8)
            . "-"
            . substr(hex, 8, 4)
            . "-"
            . substr(hex, 12, 4)
            . "-"
            . substr(hex, 16, 4)
            . "-"
            . substr(hex, 20, 12);
    }

    /**
     * Converts a canonical UUID string to its 16-byte binary representation.
     */
    protected function namespaceToBytes(string uuid) -> string
    {
        return hex2bin(
            str_replace("-", "", uuid)
        );
    }
}
