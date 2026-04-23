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

final class HasTest extends AbstractUnitTestCase
{
    use DiTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSessionBagHas(): void
    {
        $this->setNewFactoryDefault();
        $this->setDiService('sessionStream');
        $data = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];

        $collection = new Bag($this->container->get("session"), 'BagTest');
        $collection->init($data);

        $actual = $collection->has('three');
        $this->assertTrue($actual);

        $actual = $collection->has('THREE');
        $this->assertTrue($actual);

        $actual = $collection->has(uniqid());
        $this->assertFalse($actual);

        $actual = isset($collection['three']);
        $this->assertTrue($actual);

        $actual = isset($collection[uniqid()]);
        $this->assertFalse($actual);

        $actual = $collection->offsetExists('three');
        $this->assertTrue($actual);

        $actual = $collection->offsetExists(uniqid());
        $this->assertFalse($actual);
    }
}
