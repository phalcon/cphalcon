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
 * Class HasHeaderCest
 */
class HasHeaderCest
{
    /**
     * Tests Phalcon\Http\Message\ServerRequest :: hasHeader()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageServerRequestHasHeader(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - hasHeader()');
        $data    = [
            'Accept' => [
                'text/html',
                'text/json',
            ],
        ];
        $request = new ServerRequest('GET', null, [], 'php://input', $data);

        $actual = $request->hasHeader('accept');
        $I->assertTrue($actual);

        $actual   = $request->hasHeader('aCCepT');
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Http\Message\ServerRequest :: hasHeader() - empty
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageServerRequestHasHeaderEmpty(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - hasHeader() - empty');
        $request = new ServerRequest();

        $actual = $request->hasHeader('empty');
        $I->assertFalse($actual);
    }
}
