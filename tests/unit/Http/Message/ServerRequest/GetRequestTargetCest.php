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

namespace Phalcon\Test\Unit\Http\Message\ServerRequest;

use Phalcon\Http\Message\ServerRequest;
use UnitTester;

/**
 * Class GetRequestTargetCest
 */
class GetRequestTargetCest
{
    /**
     * Tests Phalcon\Http\Message\ServerRequest :: getRequestTarget()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageServerRequestGetRequestTarget(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - getRequestTarget()');
        $request = new ServerRequest();

        $expected = '/';
        $actual   = $request->getRequestTarget();
        $I->assertEquals($expected, $actual);
    }
}
