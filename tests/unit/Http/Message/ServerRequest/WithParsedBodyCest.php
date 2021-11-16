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

namespace Phalcon\Tests\Unit\Http\Message\ServerRequest;

use Phalcon\Http\Message\ServerRequest;
use UnitTester;

class WithParsedBodyCest
{
    /**
     * Tests Phalcon\Http\Message\ServerRequest :: withParsedBody()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-10
     */
    public function httpMessageServerRequestWithParsedBody(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - withParsedBody()');
        $request     = new ServerRequest();
        $newInstance = $request->withParsedBody('something');

        $I->assertNotEquals($request, $newInstance);

        $expected = null;
        $actual   = $request->getParsedBody();
        $I->assertEquals($expected, $actual);

        $expected = 'something';
        $actual   = $newInstance->getParsedBody();
        $I->assertEquals($expected, $actual);
    }
}
