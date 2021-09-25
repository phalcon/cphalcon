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
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Assets\Collection :: __construct()
     *
     * @author Naut de Jong <https://github.com/andejong>
     * @since  2020-02-14
     */
    public function assetsCollectionConstruct(UnitTester $I)
    {
        $I->wantToTest('Assets\Collection - __construct()');

        $collection = new Collection();

        $I->assertInstanceOf(
            Collection::class,
            $collection
        );
    }
}
