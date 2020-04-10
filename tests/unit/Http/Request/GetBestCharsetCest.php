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

namespace Phalcon\Test\Unit\Http\Request;

use Phalcon\Test\Fixtures\Traits\DiTrait;
use UnitTester;

class GetBestCharsetCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Http\Request :: getBestCharset()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function httpRequestGetBestCharset(UnitTester $I)
    {
        $I->wantToTest('Http\Request - getBestCharset()');

        $store = $_SERVER ?? [];

        $this->setNewFactoryDefault();
        $request = $this->container->get('request');

        $_SERVER = [
            'HTTP_ACCEPT_CHARSET' => 'iso-8859-5,unicode-1-1;q=0.8',
        ];

        $accept = $request->getClientCharsets();
        $I->assertCount(2, $accept);


        $firstAccept = $accept[0];
        $I->assertEquals(
            'iso-8859-5',
            $firstAccept['charset']
        );

        $I->assertEquals(
            1,
            $firstAccept['quality']
        );

        $lastAccept = $accept[1];
        $I->assertEquals(
            'unicode-1-1',
            $lastAccept['charset']
        );

        $I->assertEquals(
            0.8,
            $lastAccept['quality']
        );

        $I->assertEquals(
            'iso-8859-5',
            $request->getBestCharset()
        );

        $_SERVER = $store;
    }
}
