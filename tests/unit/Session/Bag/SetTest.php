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

/**
 * Class SetTest extends AbstractUnitTestCase
 *
 * @package Phalcon\Tests\Unit\Session\Bag
 */
final class SetTest extends AbstractUnitTestCase
{
    use DiTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSessionBagSet(): void
    {
        $this->setNewFactoryDefault();
        $this->setDiService('sessionStream');
        $collection = new Bag($this->container->get("session"), 'BagTest');

        $collection->set('three', 'two');
        $expected = 'two';
        $actual   = $collection->get('three');
        $this->assertEquals($expected, $actual);

        $collection->three = 'Phalcon';
        $expected          = 'Phalcon';
        $actual            = $collection->get('three');
        $this->assertEquals($expected, $actual);

        $collection->offsetSet('three', 123);
        $expected = 123;
        $actual   = $collection->get('three');
        $this->assertEquals($expected, $actual);

        $collection['three'] = true;
        $actual              = $collection->get('three');
        $this->assertTrue($actual);
    }
}
