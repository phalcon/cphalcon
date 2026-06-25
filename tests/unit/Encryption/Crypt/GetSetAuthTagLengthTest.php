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
use Phalcon\Encryption\Crypt\Exception\InvalidAuthTagLength;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetSetAuthTagLengthTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
     */
    public function testEncryptionCryptGetSetAuthTagLength(): void
    {
        $crypt = new Crypt();

        $data = 8;
        $crypt->setAuthTagLength($data);

        $expected = $data;
        $actual   = $crypt->getAuthTagLength();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-17
     */
    public function testEncryptionCryptSetAuthTagLengthAboveMaximumThrowsException(): void
    {
        $this->expectException(InvalidAuthTagLength::class);
        $this->expectExceptionMessage(
            'The auth tag length must be between 4 and 16 bytes.'
        );

        $crypt = new Crypt();
        $crypt->setAuthTagLength(17);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-17
     */
    public function testEncryptionCryptSetAuthTagLengthBelowMinimumThrowsException(): void
    {
        $this->expectException(InvalidAuthTagLength::class);
        $this->expectExceptionMessage(
            'The auth tag length must be between 4 and 16 bytes.'
        );

        $crypt = new Crypt();
        $crypt->setAuthTagLength(3);
    }
}
