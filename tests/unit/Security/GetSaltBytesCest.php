<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Security;

use UnitTester;
use Phalcon\Security;

/**
 * Class GetSaltBytesCest
 */
class GetSaltBytesCest
{
    /**
     * Tests Phalcon\Security :: getSaltBytes()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function securityGetSaltBytes(UnitTester $I)
    {
        $I->wantToTest('Security - getSaltBytes()');
        $security = new Security();

        $I->assertGreaterOrEquals(16, strlen($security->getSaltBytes()));
        $I->assertGreaterOrEquals(22, strlen($security->getSaltBytes(22)));
    }
}
