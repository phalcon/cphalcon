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

namespace Phalcon\Tests\Unit\Encryption\Security\Random;

use Phalcon\Encryption\Security\Random;
use Phalcon\Tests\AbstractUnitTestCase;

final class Base58Test extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testEncryptionSecurityRandomBase58(): void
    {
        $random = new Random();
        $base58 = $random->base58();

        // Test forbidden characters
        $this->assertMatchesRegularExpression('/^[1-9A-Za-z][^OIl0]+$/', $base58);

        // Default length is 16 bytes
        $this->assertSame(16, strlen($base58));


        $differentString = $random->base58();
        // Buy lottery ticket if this fails (or fix the bug)
        $this->assertNotEquals($base58, $differentString);


        $expectedLength = 30;
        $base58         = $random->base58($expectedLength);
        $this->assertSame($expectedLength, strlen($base58));
    }
}
