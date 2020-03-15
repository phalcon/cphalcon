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

namespace Phalcon\Test\Unit\Assets\Collection;

use Phalcon\Assets\Collection;
use Phalcon\Assets\Filters\None;
use UnitTester;

class AddFilterCest
{
    /**
     * Tests Phalcon\Assets\Collection :: addFilter()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-02-06
     */
    public function assetsCollectionAddFilter(UnitTester $I)
    {
        $I->wantToTest('Assets\Collection - addFilter()');

        $collection = new Collection();

        $collection->addFilter(
            new None()
        );

        $collection->addFilter(
            new None()
        );

        $filters = $collection->getFilters();

        foreach ($filters as $filter) {
            $I->assertInstanceOf(
                None::class,
                $filter
            );
        }

        $I->assertCount(2, $filters);
    }
}
