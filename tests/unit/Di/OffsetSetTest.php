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

namespace Phalcon\Tests\Unit\Di;

use Phalcon\Di\Di;
use Phalcon\Html\Escaper;
use Phalcon\Support\Collection;
use Phalcon\Tests\AbstractUnitTestCase;

final class OffsetSetTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function testDiOffsetSet(): void
    {
        $container = new Di();

        $class = Escaper::class;
        $container->offsetSet('escaper', $class);

        $actual = $container->offsetGet('escaper');
        $this->assertInstanceOf($class, $actual);

        $container['collection'] = new Collection();

        $class  = Collection::class;
        $actual = $container->offsetGet('collection');
        $this->assertInstanceOf($class, $actual);
    }
}
