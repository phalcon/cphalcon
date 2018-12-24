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

namespace Phalcon\Test\Unit\Http\Request;

use UnitTester;

/**
 * Class HasPutCest
 */
class HasPutCest
{
    /**
     * Tests Phalcon\Http\Request :: hasPut()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function httpRequestHasPut(UnitTester $I)
    {
        $I->wantToTest('Http\Request - hasPut()');
        $I->skipTest('Need implementation');
    }
}
