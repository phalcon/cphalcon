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

namespace Phalcon\Tests\Unit\Encryption\Crypt;

use Phalcon\Encryption\Crypt;
use UnitTester;

class GetSetAuthTagLengthCest
{
    /**
     * Unit Tests Phalcon\Encryption\Crypt :: getAuthTagLength()/setAuthTagLength()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
     */
    public function cryptGetSetAuthTagLength(UnitTester $I)
    {
        $I->wantToTest('Crypt - getAuthTagLength()/setAuthTagLength()');

        $crypt = new Crypt();

        $data = 1234;
        $crypt->setAuthTagLength($data);

        $expected = $data;
        $actual   = $crypt->getAuthTagLength();
        $I->assertEquals($expected, $actual);
    }
}
