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

namespace Phalcon\Tests\Unit\Support\Collection\Collection;

use Phalcon\Support\Collection;
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Support\Collection :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportCollectionConstruct(UnitTester $I)
    {
        $I->wantToTest('Support\Collection - __construct()');

        $collection = new Collection();

        $class = Collection::class;
        $I->assertInstanceOf($class, $collection);
    }
}
