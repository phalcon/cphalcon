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

namespace Phalcon\Test\Unit\Http\Message\Request;

use Phalcon\Http\Message\Request;
use UnitTester;

/**
 * Class GetRequestTargetCest
 */
class GetRequestTargetCest
{
    /**
     * Tests Phalcon\Http\Message\Request :: getRequestTarget()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageRequestGetRequestTarget(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Request - getRequestTarget()');
        $request = new Request();

        $expected = '/';
        $actual   = $request->getRequestTarget();
        $I->assertEquals($expected, $actual);
    }
}
