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

class FakeCryptOpensslRandomPseudoBytes extends Crypt
{
    /**
     * Throws to simulate a failure in openssl_random_pseudo_bytes(). On PHP
     * 8.1+ the native function returns a string or throws on failure (it never
     * returns false), so a failure is signalled by an exception, which
     * Crypt::encrypt() catches and rethrows as RandomBytesGenerationFailed
     * ("Cannot calculate Random Pseudo Bytes").
     *
     * @param int $length
     *
     * @return string
     *
     * @link https://php.net/manual/en/function.openssl-random-pseudo-bytes
     */
    protected static function phpOpensslRandomPseudoBytes(int $length): string
    {
        throw new \Exception('Simulated openssl_random_pseudo_bytes() failure');
    }
}
