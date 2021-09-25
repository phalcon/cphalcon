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

namespace Phalcon\Tests\Unit\Assets\Manager;

use Countable;
use Iterator;
use Phalcon\Assets\Collection;
use Phalcon\Assets\Exception;
use Phalcon\Assets\Manager;
use UnitTester;

class GetSetCest
{
    /**
     * Tests Phalcon\Assets\Manager :: get()/set()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-19
     */
    public function assetsManagerGetSet(UnitTester $I)
    {
        $I->wantToTest('Assets\Manager - get()/set()');

        $assets = new Manager();

        $collection = new Collection();

        $assets->set('hangout', $collection);
        $actual = $assets->get('hangout');
        $I->assertInstanceOf(Collection::class, $actual);
        $I->assertInstanceOf(Countable::class, $actual);
        $I->assertInstanceOf(Iterator::class, $actual);
    }

    /**
     * Tests Phalcon\Assets\Manager :: get() - unknown
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2017-06-04
     */
    public function assetsManagerGetUnknown(UnitTester $I)
    {
        $I->wantToTest('Assets\Manager - get() - unknown');

        $I->expectThrowable(
            new Exception('The collection does not exist in the manager'),
            function () {
                $assets = new Manager();

                $assets->get('some-non-existent-collection');
            }
        );
    }
}
