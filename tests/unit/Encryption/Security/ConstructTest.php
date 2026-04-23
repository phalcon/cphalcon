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

namespace Phalcon\Tests\Unit\Encryption\Security;

use Phalcon\Encryption\Security;
use Phalcon\Tests\AbstractUnitTestCase;

final class ConstructTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testEncryptionSecurityConstruct(): void
    {
        $security = new Security();
        $this->assertInstanceOf(Security::class, $security);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSecurityConstants(): void
    {
        $this->assertSame(0, Security::CRYPT_DEFAULT);
        $this->assertSame(3, Security::CRYPT_MD5);
        $this->assertSame(4, Security::CRYPT_BLOWFISH);
        $this->assertSame(5, Security::CRYPT_BLOWFISH_A);
        $this->assertSame(6, Security::CRYPT_BLOWFISH_X);
        $this->assertSame(7, Security::CRYPT_BLOWFISH_Y);
        $this->assertSame(8, Security::CRYPT_SHA256);
        $this->assertSame(9, Security::CRYPT_SHA512);
    }
}
