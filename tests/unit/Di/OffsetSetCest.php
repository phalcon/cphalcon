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

use Phalcon\Di;
use Phalcon\Html\Escaper;
use Phalcon\Support\Collection;
use UnitTester;

/**
 * Class OffsetSetCest
 *
 * @package Phalcon\Tests\Unit\Di
 */
class OffsetSetCest
{
    /**
     * Unit Tests Phalcon\Di :: offsetSet()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diOffsetSet(UnitTester $I)
    {
        $I->wantToTest('Di - offsetSet()');

        $container = new Di();

        $class = Escaper::class;
        $container->offsetSet('escaper', $class);

        $actual = $container->offsetGet('escaper');
        $I->assertInstanceOf($class, $actual);

        $container['collection'] = new Collection();

        $class  = Collection::class;
        $actual = $container->offsetGet('collection');
        $I->assertInstanceOf($class, $actual);
    }
}
