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
use Phalcon\Assets\Manager;
use Phalcon\Html\Escaper;
use Phalcon\Html\TagFactory;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetCollectionsTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-19
     */
    public function testAssetsManagerGetCollections(): void
    {
        $manager = new Manager(new TagFactory(new Escaper()));

        $manager->set('hangout1', new Collection());
        $manager->set('hangout2', new Collection());

        $collections = $manager->getCollections();

        $expected = 2;
        $actual   = count($collections);
        $this->assertSame($expected, $actual);

        foreach ($collections as $collection) {
            $class  = Collection::class;
            $actual = $collection;
            $this->assertInstanceOf($class, $actual);
            $class = Countable::class;
            $this->assertInstanceOf($class, $actual);
            $class = IteratorAggregate::class;
            $this->assertInstanceOf($class, $actual);
        }
    }
}
