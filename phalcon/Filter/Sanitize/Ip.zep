
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Filter\Sanitize;

use Phalcon\Contracts\Filter\Sanitizer;

/**
 * Phalcon\Filter\Sanitize\IP
 *
 * Sanitizes a value to an ip address or CIDR range
 */
class Ip implements Sanitizer
{
    /**
     * @param string $input
     * @param int $filter
     * @return false|string
     */
    public function __invoke(string input, int filter = 0) -> string | false
    {
        var parts, ip, mask, maxMask, filtered, ipInput;

        let ipInput = trim(input);

        // CIDR notation (e.g., 192.168.1.0/24)
        if memstr(ipInput, "/") {
            let parts       = explode("/", input, 2),
                ip          = parts[0],
                mask        = parts[1];

            let filtered = filter_var(ip, FILTER_VALIDATE_IP, filter);
            if (filtered === false) {
                return false;
            }

            if (!ctype_digit(mask)) {
                return false;
            }

            let maxMask = strpos(filtered, ':') !== false ? 128 : 32;

            if ((int)mask <= maxMask) {
                return filtered . "/" . mask;
            }

            return false;
        }

        return filter_var(ipInput, FILTER_VALIDATE_IP, filter);
    }
}
