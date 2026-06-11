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

namespace Phalcon\Tests\Unit\Session\Bag;

use Phalcon\Session\Bag;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;
use Phalcon\Tests\Unit\Session\Fake\PlainManager;

final class ConstructTest extends AbstractUnitTestCase
{
    use DiTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSessionBagConstruct(): void
    {
        $this->setNewFactoryDefault();
        $this->setDiService('sessionStream');
        $collection = new Bag($this->container->get("session"), 'BagTest');

        $class = Bag::class;
        $this->assertInstanceOf($class, $collection);
    }

    /**
     * @issue  17127
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-11
     */
    public function testSessionBagConstructWithManagerInterfaceOnlyImplementation(): void
    {
        $manager = new PlainManager();
        $manager->start();
        $manager->set('PlainBagTest', ['initial' => 'value']);

        $collection = new Bag($manager, 'PlainBagTest');

        $class = Bag::class;
        $this->assertInstanceOf($class, $collection);

        $expected = 'value';
        $actual   = $collection->get('initial');
        $this->assertSame($expected, $actual);

        $collection->set('other', 'data');

        $expected = ['initial' => 'value', 'other' => 'data'];
        $actual   = $manager->get('PlainBagTest');
        $this->assertSame($expected, $actual);
    }
}
