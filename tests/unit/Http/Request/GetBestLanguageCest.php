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

class GetBestLanguageCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Http\Request :: getBestLanguage()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-17
     */
    public function httpRequestGetBestLanguage(UnitTester $I)
    {
        $I->wantToTest('Http\Request - getBestLanguage()');

        $store = $_SERVER ?? [];

        $this->setNewFactoryDefault();
        $request = $this->container->get('request');

        $_SERVER = [
            'HTTP_ACCEPT_LANGUAGE' => 'es,es-ar;q=0.8,en;q=0.5,en-us;q=0.3,de-de; q=0.9',
        ];

        $accept = $request->getLanguages();
        $I->assertCount(5, $accept);


        $firstAccept = $accept[0];
        $I->assertEquals(
            'es',
            $firstAccept['language']
        );

        $I->assertEquals(
            1,
            $firstAccept['quality']
        );


        $fourthAccept = $accept[3];
        $I->assertEquals(
            'en-us',
            $fourthAccept['language']
        );

        $I->assertEquals(
            0.3,
            $fourthAccept['quality']
        );


        $lastAccept = $accept[4];
        $I->assertEquals(
            'de-de',
            $lastAccept['language']
        );

        $I->assertEquals(
            0.9,
            $lastAccept['quality']
        );

        $I->assertEquals('es', $request->getBestLanguage());

        $_SERVER = $store;
    }
}
