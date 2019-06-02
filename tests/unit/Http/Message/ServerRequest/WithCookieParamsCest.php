<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Http\Message\ServerRequest;

use Phalcon\Http\Message\ServerRequest;
use UnitTester;

class WithCookieParamsCest
{
    /**
     * Tests Phalcon\Http\Message\ServerRequest :: withCookieParams()
     *
     * @since  2019-03-03
     */
    public function httpMessageServerRequestWithCookieParams(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - withCookieParams()');

        $request = new ServerRequest();

        $newInstance = $request->withCookieParams(
            [
                'one' => 'two',
            ]
        );

        $I->assertNotEquals($request, $newInstance);

        $I->assertEquals(
            [
                'one' => 'two',
            ],
            $newInstance->getCookieParams()
        );
    }
}
