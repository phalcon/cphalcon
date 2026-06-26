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
     * Returns false to simulate a failure in openssl_random_pseudo_bytes(),
     * triggering the "Cannot calculate Random Pseudo Bytes" exception.
     *
     * @param int $length
     *
     * @return mixed
     *
     * @link https://php.net/manual/en/function.openssl-random-pseudo-bytes
     */
    protected function phpOpensslRandomPseudoBytes(int $length): mixed
    {
        return false;
    }
}
