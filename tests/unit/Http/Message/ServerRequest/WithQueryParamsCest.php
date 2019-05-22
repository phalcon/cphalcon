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

class WithQueryParamsCest
{
    /**
     * Tests Phalcon\Http\Message\ServerRequest :: withQueryParams()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageServerRequestWithQueryParams(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - withQueryParams()');

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
