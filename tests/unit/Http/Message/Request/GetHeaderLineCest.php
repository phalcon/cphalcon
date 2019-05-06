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

class GetHeaderLineCest
{
    /**
     * Tests Phalcon\Http\Message\Request :: getHeaderLine()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageRequestGetHeaderLine(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Request - getHeaderLine()');

        $data = [
            'Accept' => [
                'text/html',
                'text/json',
            ],
        ];

        $request = new Request(
            'GET',
            null,
            'php://memory',
            $data
        );

        $expected = 'text/html,text/json';

        $I->assertEquals(
            $expected,
            $request->getHeaderLine('accept')
        );

        $I->assertEquals(
            $expected,
            $request->getHeaderLine('aCCepT')
        );
    }

    /**
     * Tests Phalcon\Http\Message\Request :: getHeaderLine() - empty
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageRequestGetHeaderLineEmpty(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Request - getHeaderLine() - empty');

        $request = new Request();

        $I->assertEquals(
            '',
            $request->getHeaderLine('accept')
        );
    }
}
