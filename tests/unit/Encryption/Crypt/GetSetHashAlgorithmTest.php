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

namespace Phalcon\Tests\Unit\Encryption\Crypt;

use Phalcon\Encryption\Crypt;
use Phalcon\Encryption\Crypt\Exception\Exception;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetSetHashAlgorithmTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
     */
    public function testEncryptionCryptGetSetHashAlgo(): void
    {
        $cipher = 'sha384';
        $crypt  = new Crypt();
        $crypt->setHashAlgorithm($cipher);

        $expected = $cipher;
        $actual   = $crypt->getHashAlgorithm();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
     */
    public function testEncryptionCryptGetSetHashAlgoUnknown(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            "The hash algorithm 'xxx-yyy-zzz' is not supported on this system."
        );

        $crypt = new Crypt();
        $crypt->setHashAlgorithm('xxx-yyy-zzz');
    }
}
