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

/**
 * Class GetRandomBytesCest
 */
class GetRandomBytesCest
{
    /**
     * Tests Phalcon\Security :: getRandomBytes()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function securityGetRandomBytes(UnitTester $I)
    {
        $I->wantToTest('Security - getRandomBytes()');
        $I->skipTest('Need implementation');
    }
}
