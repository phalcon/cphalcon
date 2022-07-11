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
use UnitTester;

class GetSetDefaultHashCest
{
    /**
     * Tests Phalcon\Security :: getDefaultHash() and setDefaultHash()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function encryptionSecurityGetSetDefaultHash(UnitTester $I)
    {
        $I->wantToTest('Encryption\Security - getDefaultHash()');

        $security = new Security();

        $I->assertSame(Security::CRYPT_DEFAULT, $security->getDefaultHash());

        $security->setDefaultHash(1);
        $I->assertSame(1, $security->getDefaultHash());
    }
}
