<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Encryption\Crypt;

use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Encryption\Fake\Crypt\FakeCryptOpensslCipherIvLength;

final class IsValidDecryptLengthTest extends AbstractUnitTestCase
{
//    /**
//     * Tests Phalcon\Encryption\Crypt :: isValidDecryptLength()
//     *
//     * @return void
//     *
//     * @author Phalcon Team <team@phalcon.io>
//     * @since  2022-02-09
//     */
//    public function testEncryptionCryptGetSetKey(): void
//    {
//        $crypt = new Crypt();
//        $crypt->setKey('1234');
//
//        $input = uniqid();
//        $encrypted = $crypt->encrypt($input);
//
//        $actual = $crypt->isValidDecryptLength($encrypted);
//        $this->assertTrue($actual);
//
//        $actual = $crypt->isValidDecryptLength('text');
//        $this->assertFalse($actual);
//    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-02-09
     */
    public function testEncryptionCryptGetSetKeyFalseLength(): void
    {
        $crypt = new FakeCryptOpensslCipherIvLength();
        $crypt->setKey('1234');

        $actual = $crypt->isValidDecryptLength('text');
        $this->assertFalse($actual);
    }
}
