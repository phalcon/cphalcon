
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Filter\Sanitize;

/**
 * Phalcon\Filter\Sanitize\IP
 *
 * Sanitizes a value to an ip address or CIDR range
 */
class Ip
{
    /**
     * @param string $input
     * @param int $protocol
     * @param int $filter
     * @return false|string
     */
    public function __invoke(string input, int filter = 0) -> string | false
    {
        var parts, ip, mask, protocol, filtered;

        let protocol = this->getIpAddressProtocolVersion(input);
        if (protocol === false) {
            return false;
        }

        // CIDR notation (e.g., 192.168.1.0/24)
        if memstr(input, "/") {
            let parts       = explode("/", input, 2),
                ip          = parts[0],
                mask        = parts[1];

            // Try IPv4 validation
            if protocol === 4 {
                let filtered = filter_var(ip, FILTER_VALIDATE_IP, FILTER_FLAG_IPV4 | filter);
                if filtered !== false {
                    if is_numeric(mask) && mask >= 0 && mask <= 32 {
                        return filtered . "/" . mask;
                    }
                }
            }

            // Try IPv6 validation
            if protocol === 6 {
                let filtered = filter_var(ip, FILTER_VALIDATE_IP, FILTER_FLAG_IPV6 | filter);
                if (filtered) {
                    if is_numeric(mask) && mask >= 0 && mask <= 128 {
                        return filtered . "/" . mask;
                    }
                }
            }
        } else {
            // Single IP
            if protocol === 4 {
                return filter_var(input, FILTER_VALIDATE_IP, FILTER_FLAG_IPV4 | filter);
            }

            if (protocol === 6) {
                return filter_var(input, FILTER_VALIDATE_IP, FILTER_FLAG_IPV6 | filter);
            }
        }

        // return false if nothing filtered.
        return false;
    }

    /**
     * Return the IP address protocol version
     *
     * @param $ip
     * @return int
     */
    private function getIpAddressProtocolVersion(string input) -> int | false
    {
        var parts, ip;

        let ip = input;
        if (memstr(ip, "/")) {
            let parts   = explode("/", ip, 2),
                ip      = parts[0];
        }

        if (filter_var(ip, FILTER_VALIDATE_IP, FILTER_FLAG_IPV4) !== false) {
            return 4;
        }

        if (filter_var(ip, FILTER_VALIDATE_IP, FILTER_FLAG_IPV6) !== false) {
            return 6;
        }

        return false;
    }
}
