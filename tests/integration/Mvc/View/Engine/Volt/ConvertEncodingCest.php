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

namespace Phalcon\Test\Integration\Mvc\View\Engine\Volt;

use IntegrationTester;
use Phalcon\Mvc\View;
use Phalcon\Mvc\View\Engine\Volt;

/**
 * Class ConvertEncodingCest
 */
class ConvertEncodingCest
{
    /**
     * Tests Phalcon\Mvc\View\Engine\Volt :: convertEncoding()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-13
     */
    public function mvcViewEngineVoltConvertEncoding(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View\Engine\Volt - convertEncoding()');

        $view   = new View();
        $engine = new Volt($view);

        $text     = 'Schlüssel';
        $from     = 'latin1';
        $to       = 'utf8';
        $expected = 'SchlÃ¼ssel';
        $actual   = $engine->convertEncoding($text, $from, $to);
        $I->assertEquals($expected, $actual);

        $text     = 'SchlÃ¼ssel';
        $from     = 'utf8';
        $to       = 'latin1';
        $expected = 'Schlüssel';
        $actual   = $engine->convertEncoding($text, $from, $to);
        $I->assertEquals($expected, $actual);

        $text     = 'Schlüssel';
        $from     = 'utf7';
        $to       = 'euc-jp';
        $expected = 'Schl+eu8-ssel';
        $actual   = $engine->convertEncoding($text, $from, $to);
        $I->assertEquals($expected, $actual);
    }
}
