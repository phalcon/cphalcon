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

class GetBestLanguageIsoCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Http\Request :: getBestLanguageIso()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function httpRequestGetBestLanguageIso(UnitTester $I)
    {
        $I->wantToTest('Http\Request - getBestLanguageIso()');

        $store = $_SERVER ?? [];

        $this->setNewFactoryDefault();
        $request = $this->container->get('request');

        $_SERVER = [
            'HTTP_ACCEPT_LANGUAGE' => 'es,es-ar;q=0.8'
        ];
        $I->assertEquals('es', $request->getBestLanguageIso());

        $_SERVER = [
            'HTTP_ACCEPT_LANGUAGE' => 'es-ar;q=0.8'
        ];
        $I->assertEquals('es', $request->getBestLanguageIso());

        $_SERVER = [
            'HTTP_ACCEPT_LANGUAGE' => 'en-US'
        ];
        $I->assertEquals('en', $request->getBestLanguageIso());

        $_SERVER = [
            'HTTP_ACCEPT_LANGUAGE' => 'en'
        ];
        $I->assertEquals('en', $request->getBestLanguageIso());

        $_SERVER = [
            'HTTP_ACCEPT_LANGUAGE' => ''
        ];
        $I->assertEquals('', $request->getBestLanguageIso());

        $_SERVER = $store;
    }
}
