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
 * Class GetSetFiltersCest
 *
 * @package Phalcon\Tests\Unit\Assets\Collection
 */
class GetSetFiltersCest
{
    /**
     * Tests Phalcon\Assets\Collection :: getFilters()/setFilters()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsCollectionGetSetFilters(UnitTester $I)
    {
        $I->wantToTest('Assets\Collection - getFilters()/setFilters()');

        $collection = new Collection();
        $filters    = [new None(), new None(),];

        $collection->setFilters($filters);
        $I->assertEquals($filters, $collection->getFilters());
    }
}
