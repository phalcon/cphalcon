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
use Phalcon\Assets\Filters\None;
use UnitTester;

/**
 * Class AddFilterCest
 *
 * @package Phalcon\Tests\Unit\Assets\Collection
 */
class AddFilterCest
{
    /**
     * Tests Phalcon\Assets\Collection :: addFilter()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsCollectionAddFilter(UnitTester $I)
    {
        $I->wantToTest('Assets\Collection - addFilter()');

        $collection = new Collection();
        $collection->addFilter(new None());
        $collection->addFilter(new None());

        $filters = $collection->getFilters();

        foreach ($filters as $filter) {
            $I->assertInstanceOf(None::class, $filter);
        }

        $I->assertCount(2, $filters);
    }
}
