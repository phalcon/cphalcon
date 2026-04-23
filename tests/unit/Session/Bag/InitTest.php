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
use Phalcon\Session\Manager;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;

use function uniqid;

final class InitTest extends AbstractUnitTestCase
{
    use DiTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSessionBagInit(): void
    {
        $this->markTestSkipped('TODO: Check this test');

        $store = $_SESSION ?? [];

        $this->setNewFactoryDefault();
        $this->setDiService('sessionStream');

        $name            = uniqid();
        $_SESSION[$name] = [
            'one'   => 'two',
            'three' => 'four',
        ];

        $data = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];

        $session = $this->container->get("session");
        $this->assertInstanceOf(Manager::class, $session);

        $collection = new Bag($session, $name);

        $expected = 2;
        $actual   = $collection->count();
        $this->assertEquals($expected, $actual);

        $collection->init($data);
        $actual = $collection->toArray();
        $this->assertEquals($data, $actual);

        $_SESSION = $store;
    }
}
