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

use Phalcon\Assets\FilterInterface;
use Phalcon\Assets\Filters\JsMin;
use Phalcon\Tests\AbstractUnitTestCase;

final class ConstructTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testAssetsFiltersJsMinConstruct(): void
    {
        $jsMin = new JsMin();

        $class  = JsMin::class;
        $actual = $jsMin;
        $this->assertInstanceOf($class, $actual);

        $class = FilterInterface::class;
        $this->assertInstanceOf($class, $actual);
    }
}
