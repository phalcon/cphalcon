<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Encryption\Fake\Crypt;

use Phalcon\Encryption\Crypt;

/**
 * Counts the HMAC calculations so a test can tell whether the signed decrypt
 * path computes the HMAC even when the OpenSSL decrypt fails.
 */
class FakeCryptHashHmacCounter extends Crypt
{
    public static int $hashHmacCalls = 0;

    public static int $lastDataLength = 0;

    public static function resetHashHmacCalls(): void
    {
        self::$hashHmacCalls  = 0;
        self::$lastDataLength = 0;
    }

    /**
     * Generate a keyed hash value using the HMAC method
     *
     * @param string $algorithm
     * @param string $data
     * @param string $key
     * @param bool   $binary
     *
     * @return string
     *
     * @link https://php.net/manual/en/function.hash-hmac.php
     */
    protected static function phpHashHmac(
        string $algorithm,
        string $data,
        string $key,
        bool $binary = false
    ): string {
        self::$hashHmacCalls++;
        self::$lastDataLength = strlen($data);

        return parent::phpHashHmac($algorithm, $data, $key, $binary);
    }
}
