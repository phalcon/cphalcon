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

namespace Phalcon\Test\Unit\Http\Message\Response;

use Phalcon\Http\Message\Response;
use UnitTester;

/**
 * Class HasHeaderCest
 */
class HasHeaderCest
{
    /**
     * Tests Phalcon\Http\Message\Response :: hasHeader()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-09
     */
    public function httpMessageResponseHasHeader(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Response - hasHeader()');
        $data    = [
            'Accept' => [
                'text/html',
                'text/json',
            ],
        ];
        $request = new Response('php://memory', 200, $data);

        $actual = $request->hasHeader('accept');
        $I->assertTrue($actual);

        $actual = $request->hasHeader('aCCepT');
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Http\Message\Response :: hasHeader() - empty
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-09
     */
    public function httpMessageResponseHasHeaderEmpty(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Response - hasHeader() - empty');
        $request = new Response();

        $actual = $request->hasHeader('empty');
        $I->assertFalse($actual);
    }
}
