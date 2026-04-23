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
use Phalcon\Tests\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\Test;

final class GetSetTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-19
     */
    public function testAssetsManagerGetSet(): void
    {
        $manager    = new Manager(new TagFactory(new Escaper()));
        $collection = new Collection();

        $manager->set('hangout', $collection);
        $actual = $manager->get('hangout');
        $this->assertInstanceOf(Collection::class, $actual);
        $this->assertInstanceOf(Countable::class, $actual);
        $this->assertInstanceOf(IteratorAggregate::class, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2017-06-04
     */
    public function testAssetsManagerGetUnknown(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'The collection does not exist in the manager'
        );

        $manager = new Manager(new TagFactory(new Escaper()));
        $manager->get('some-non-existent-collection');
    }
}
