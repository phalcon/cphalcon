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

class GetSaltBytesCest
{
    /**
     * Tests Phalcon\Security :: getSaltBytes()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function securityGetSaltBytes(UnitTester $I)
    {
        $I->wantToTest('Security - getSaltBytes()');

        $security = new Security();

        $I->assertGreaterOrEquals(16, strlen($security->getSaltBytes()));
        $I->assertGreaterOrEquals(22, strlen($security->getSaltBytes(22)));
    }
}
