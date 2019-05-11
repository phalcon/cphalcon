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

class HasHeaderCest
{
    /**
     * Tests Phalcon\Http\Message\Request :: hasHeader()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageRequestHasHeader(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Request - hasHeader()');

        $data = [
            'Accept' => [
                'text/html',
                'text/json',
            ],
        ];

        $request = new Request('GET', null, 'php://input', $data);

        $I->assertTrue(
            $request->hasHeader('accept')
        );

        $I->assertTrue(
            $request->hasHeader('aCCepT')
        );
    }

    /**
     * Tests Phalcon\Http\Message\Request :: hasHeader() - empty
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageRequestHasHeaderEmpty(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Request - hasHeader() - empty');

        $request = new Request();

        $I->assertFalse(
            $request->hasHeader('empty')
        );
    }
}
