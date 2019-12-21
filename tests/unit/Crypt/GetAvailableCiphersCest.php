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

namespace Phalcon\Test\Unit\Crypt;

use Phalcon\Crypt;
use UnitTester;

class GetAvailableCiphersCest
{
    /**
     * Tests Phalcon\Crypt :: getAvailableCiphers()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function cryptGetAvailableCiphers(UnitTester $I)
    {
        $I->wantToTest('Crypt - getAvailableCiphers()');

        $crypt = new Crypt();

        $I->assertInternalType(
            'array',
            $crypt->getAvailableCiphers()
        );
    }
}
