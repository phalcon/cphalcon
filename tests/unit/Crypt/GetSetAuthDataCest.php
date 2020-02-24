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

class GetSetAuthDataCest
{
    /**
     * Unit Tests Phalcon\Crypt :: getAuthData()/setAuthData()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-16
     */
    public function cryptGetSetAuthData(UnitTester $I)
    {
        $I->wantToTest('Crypt - getAuthData()/setAuthData()');

        $crypt = new Crypt();

        $crypt->setAuthData('test-data');

        $I->assertEquals(
            'test-data',
            $crypt->getAuthData()
        );
    }
}
