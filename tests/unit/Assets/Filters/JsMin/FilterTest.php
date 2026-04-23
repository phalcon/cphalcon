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

namespace Phalcon\Tests\Unit\Assets\Filters\JsMin;

use Phalcon\Assets\Filters\JsMin;
use Phalcon\Tests\AbstractUnitTestCase;

final class FilterTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testAssetsFiltersJsMinFilter(): void
    {
        $jsMin = new JsMin();

        $source   = "// nothing special here\nvar a = 1;";
        $expected = $source;
        $actual   = $jsMin->filter($source);
        $this->assertSame($expected, $actual);
    }
}
