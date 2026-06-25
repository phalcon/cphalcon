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

namespace Phalcon\Tests\Unit\Encryption\Crypt\Padding;

use Phalcon\Encryption\Crypt\Padding\Pkcs7;
use Phalcon\Tests\AbstractUnitTestCase;

use function chr;
use function str_repeat;

final class Pkcs7Test extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-12
     */
    public function testEncryptionCryptPaddingPkcs7(): void
    {
        $object = new Pkcs7();

        $paddingSize = 32;
        $padding     = str_repeat(chr($paddingSize), $paddingSize);
        $expected    = $padding;
        $actual      = $object->pad($paddingSize);
        $this->assertSame($expected, $actual);

        $source   = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" . $padding;
        $expected = 32;
        $actual   = $object->unpad($source, 32);
        $this->assertSame($expected, $actual);

        /**
         * Invalid padding results in 0
         */
        $padding  = str_repeat(chr($paddingSize), $paddingSize - 1);
        $source   = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" . $padding;
        $expected = 0;
        $actual   = $object->unpad($source, 32);
        $this->assertSame($expected, $actual);
    }
}
