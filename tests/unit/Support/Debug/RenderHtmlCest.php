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

namespace Phalcon\Test\Unit\Support\Debug;

use Phalcon\Exception;
use Phalcon\Support\Debug;
use UnitTester;

class RenderHtmlCest
{
    /**
     * Tests Phalcon\Debug :: renderHtml()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-04-21
     */
    public function supportDebugRenderHtml(UnitTester $I)
    {
        $I->wantToTest('Debug - renderHtml()');

        $debug = new Debug();

        $var = 123;
        $debug->debugVar($var);

        $ex = new Exception(
            'Some Message',
            1024
        );

        $actual   = $debug->renderHtml($ex);

        $expected = '<title>Phalcon\Exception: Some Message</title>';
        $I->assertStringContainsString($expected, $actual);

        $expected = '<h1>Phalcon\Exception: Some Message</h1>';
        $I->assertStringContainsString($expected, $actual);
    }
}
