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

namespace Phalcon\Tests\Unit\Support\Debug;

use Phalcon\Support\Debug;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetJsSourcesTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportDebugGetJsSources(): void
    {
        $debug = new Debug();
        $uri = 'https://assets.phalcon.io/debug/5.0.x/';

        $expected = "
    <script src='{$uri}debug.js'></script>";

        $actual = $debug->getJsSources();
        $this->assertSame($expected, $actual);
    }
}
