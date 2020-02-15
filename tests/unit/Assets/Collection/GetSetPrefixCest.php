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
use UnitTester;

class GetSetPrefixCest
{
    /**
     * Tests Phalcon\Assets\Collection :: getPrefix() / setPrefix()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-02-15
     */
    public function assetsCollectionGetSetPrefix(UnitTester $I)
    {
        $I->wantToTest('Assets\Collection - getPrefix() / setPrefix()');

        $collection = new Collection();

        $prefix = 'phly_';

        $collection->setPrefix($prefix);

        $I->assertEquals($prefix, $collection->getPrefix());
    }
}
