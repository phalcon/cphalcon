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

namespace Phalcon\Tests\Unit\Http\Message\Response;

use Phalcon\Http\Message\Response;
use UnitTester;

class HasHeaderCest
{
    /**
     * Tests Phalcon\Http\Message\Response :: hasHeader()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-03-09
     */
    public function httpMessageResponseHasHeader(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Response - hasHeader()');

        $data = [
            'Accept' => [
                'text/html',
                'text/json',
            ],
        ];

        $response = new Response('php://memory', 200, $data);

        $I->assertTrue(
            $response->hasHeader('accept')
        );

        $I->assertTrue(
            $response->hasHeader('aCCepT')
        );
    }

    /**
     * Tests Phalcon\Http\Message\Response :: hasHeader() - empty
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-03-09
     */
    public function httpMessageResponseHasHeaderEmpty(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Response - hasHeader() - empty');

        $response = new Response();

        $I->assertFalse(
            $response->hasHeader('empty')
        );
    }
}
