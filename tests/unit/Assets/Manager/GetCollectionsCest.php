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

namespace Phalcon\Test\Unit\Assets\Manager;

use Countable;
use Iterator;
use Phalcon\Assets\Collection;
use Phalcon\Assets\Manager;
use UnitTester;

class GetCollectionsCest
{
    /**
     * Tests Phalcon\Assets\Manager :: getCollections()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-19
     */
    public function assetsManagerGetCollections(UnitTester $I)
    {
        $I->wantToTest('Assets\Manager - getCollections()');

        $assets = new Manager();

        $assets->set('hangout1', new Collection());
        $assets->set('hangout2', new Collection());

        $collections = $assets->getCollections();

        $I->assertCount(2, $collections);
        foreach ($collections as $collection) {
            $I->assertInstanceOf(Collection::class, $collection);
            $I->assertInstanceOf(Countable::class, $collection);
            $I->assertInstanceOf(Iterator::class, $collection);
        }
    }
}
