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

namespace Phalcon\Tests\Unit\Crypt;

use Phalcon\Crypt\Crypt;
use UnitTester;

use function uniqid;

/**
 * Class GetSetAuthDataCest
 *
 * @package Phalcon\Tests\Unit\Crypt
 */
class GetSetAuthDataCest
{
    /**
     * Unit Tests Phalcon\Crypt\Crypt :: getAuthData()/setAuthData()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function cryptGetSetAuthData(UnitTester $I)
    {
        $I->wantToTest('Crypt - getAuthData()/setAuthData()');

        $crypt = new Crypt();

        $data = uniqid('d-');
        $crypt->setAuthData($data);

        $expected = $data;
        $actual   = $crypt->getAuthData();
        $I->assertEquals($expected, $actual);
    }
}
