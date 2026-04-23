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

use Phalcon\Encryption\Crypt\Padding\Noop;
use Phalcon\Tests\AbstractUnitTestCase;

final class NoopTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-12
     */
    public function testEncryptionCryptPaddingNoop(): void
    {
        $object = new Noop();

        $expected = "";
        $actual   = $object->pad(16);
        $this->assertSame($expected, $actual);

        $source   = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" . $actual;
        $expected = 0;
        $actual   = $object->unpad($source, 16);
        $this->assertSame($expected, $actual);
    }
}
