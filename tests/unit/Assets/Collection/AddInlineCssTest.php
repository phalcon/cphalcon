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

namespace Phalcon\Tests\Unit\Assets\Collection;

use Phalcon\Assets\Collection;
use Phalcon\Tests\AbstractUnitTestCase;

final class AddInlineCssTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testAssetsCollectionAddInlineCss(): void
    {
        $collection = new Collection();
        $collection->addInlineCss(".awesome{color: #8fc6bc}");

        $expected = 1;
        $actual   = count($collection->getCodes());
        $this->assertSame($expected, $actual);
    }
}
