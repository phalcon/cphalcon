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

namespace Phalcon\Test\Unit\Security;

use Phalcon\Security;
use UnitTester;

class GetSaltBytesCest
{
    /**
     * Tests Phalcon\Security :: getSaltBytes()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function securityGetSaltBytes(UnitTester $I)
    {
        $I->wantToTest('Security - getSaltBytes()');

        $security = new Security();

        $I->assertGreaterOrEquals(
            16,
            strlen(
                $security->getSaltBytes()
            )
        );

        $I->assertGreaterOrEquals(
            22,
            strlen(
                $security->getSaltBytes(22)
            )
        );
    }
}
