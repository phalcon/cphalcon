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
use IteratorAggregate;
use Phalcon\Assets\Collection;
use Phalcon\Assets\Exception;
use Phalcon\Assets\Manager;
use Phalcon\Html\Escaper;
use Phalcon\Html\TagFactory;
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

        $manager    = new Manager(new TagFactory(new Escaper()));
        $collection = new Collection();

        $manager->set('hangout', $collection);
        $actual = $manager->get('hangout');
        $I->assertInstanceOf(Collection::class, $actual);
        $I->assertInstanceOf(Countable::class, $actual);
        $I->assertInstanceOf(IteratorAggregate::class, $actual);
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
                $manager = new Manager(new TagFactory(new Escaper()));
                $manager->get('some-non-existent-collection');
            }
        );
    }
}
