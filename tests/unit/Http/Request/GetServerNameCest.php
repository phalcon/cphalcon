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
 * Class GetServerNameCest
 */
class GetServerNameCest
{
    /**
     * Tests Phalcon\Http\Request :: getServerName()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function httpRequestGetServerName(UnitTester $I)
    {
        $I->wantToTest('Http\Request - getServerName()');
        $I->skipTest('Need implementation');
    }
}
