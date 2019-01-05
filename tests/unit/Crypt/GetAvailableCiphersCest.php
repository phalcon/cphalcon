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

namespace Phalcon\Test\Unit\Crypt;

use Phalcon\Crypt;
use UnitTester;

/**
 * Class GetAvailableCiphersCest
 */
class GetAvailableCiphersCest
{
    /**
     * Tests Phalcon\Crypt :: getAvailableCiphers()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function cryptGetAvailableCiphers(UnitTester $I)
    {
        $I->wantToTest('Crypt - getAvailableCiphers()');
        $crypt = new Crypt();
        $I->assertInternalType("array", $crypt->getAvailableCiphers());
    }
}
