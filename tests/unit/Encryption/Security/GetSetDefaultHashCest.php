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
    public function securityGetSetDefaultHash(UnitTester $I)
    {
        $I->wantToTest('Security - getDefaultHash()');

        $security = new Security();

        $I->assertEquals(Security::CRYPT_DEFAULT, $security->getDefaultHash());

        $security->setDefaultHash(1);
        $I->assertEquals(1, $security->getDefaultHash());
    }
}
