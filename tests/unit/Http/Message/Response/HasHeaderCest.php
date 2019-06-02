<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Http\Message\Response;

use Phalcon\Http\Message\Response;
use UnitTester;

class HasHeaderCest
{
    /**
     * Tests Phalcon\Http\Message\Response :: hasHeader()
     *
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
