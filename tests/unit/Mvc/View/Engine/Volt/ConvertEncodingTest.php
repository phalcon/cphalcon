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

namespace Phalcon\Tests\Unit\Mvc\View\Engine\Volt;

use Phalcon\Mvc\View;
use Phalcon\Mvc\View\Engine\Volt;
use Phalcon\Tests\AbstractUnitTestCase;

use function chr;

class ConvertEncodingTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-13
     */
    public function testMvcViewEngineVoltConvertEncoding(): void
    {
        $view   = new View();
        $engine = new Volt($view);

        $text     = 'Schl' . chr(252) . 'ssel';
        $from     = 'latin1';
        $to       = 'utf8';
        $expected = 'Schlüssel';
        $actual   = $engine->convertEncoding($text, $from, $to);
        $this->assertEquals($expected, $actual);

        $text     = 'Schlüssel';
        $from     = 'utf8';
        $to       = 'latin1';
        $expected = 'Schl' . chr(252) . 'ssel';
        $actual   = $engine->convertEncoding($text, $from, $to);
        $this->assertEquals($expected, $actual);

        $text     = 'Schlüssel';
        $from     = 'utf7';
        $to       = 'euc-jp';
        $expected = 'Schl??ssel';
        $actual   = $engine->convertEncoding($text, $from, $to);
        $this->assertEquals($expected, $actual);
    }
}
