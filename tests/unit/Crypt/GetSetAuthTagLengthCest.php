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

class GetSetAuthTagLengthCest
{
    /**
     * Unit Tests Phalcon\Crypt :: getAuthTagLength()/setAuthTagLength()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-25
     */
    public function cryptGetSetAuthTagLength(UnitTester $I)
    {
        $I->wantToTest('Crypt - getAuthTagLength()/setAuthTagLength()');

        $crypt = new Crypt();

        $I->assertEquals(16, $crypt->getAuthTagLength());

        $crypt->setAuthTagLength(24);

        $I->assertEquals(
            24,
            $crypt->getAuthTagLength()
        );
    }
}
