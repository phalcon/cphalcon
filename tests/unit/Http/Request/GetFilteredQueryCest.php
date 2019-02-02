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
 * Class GetFilteredQueryCest
 */
class GetFilteredQueryCest
{
    /**
     * Tests Phalcon\Http\Request :: getFilteredQuery()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function httpRequestGetFilteredQuery(UnitTester $I)
    {
        $I->wantToTest('Http\Request - getFilteredQuery()');
        $I->skipTest('Need implementation');
    }
}
