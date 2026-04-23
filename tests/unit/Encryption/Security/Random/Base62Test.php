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

final class Base62Test extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testEncryptionSecurityRandomBase62(): void
    {
        $random = new Random();
        $base62 = $random->base62();

        // Test forbidden characters
        $this->assertMatchesRegularExpression(
            '/^[0-9A-Za-z]+$/',
            $base62
        );

        // Default length is 16 bytes
        $this->assertSame(
            16,
            strlen($base62)
        );


        $differentString = $random->base62();

        // Buy lottery ticket if this fails (or fix the bug)
        $this->assertNotEquals($base62, $differentString);


        $expectedLength = 30;
        $base62         = $random->base62($expectedLength);

        $this->assertSame(
            $expectedLength,
            strlen($base62)
        );
    }
}
