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

final class GetSetDefaultHashTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testEncryptionSecurityGetSetDefaultHash(): void
    {
        $security = new Security();

        $this->assertSame(Security::CRYPT_DEFAULT, $security->getDefaultHash());

        $security->setDefaultHash(1);
        $this->assertSame(1, $security->getDefaultHash());
    }
}
