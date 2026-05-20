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
        $this->setNewFactoryDefault();
        $this->setDiService('sessionStream');

        $session = $this->container->get('session');
        $this->assertInstanceOf(Manager::class, $session);
        $session->start();

        $name = uniqid('bag-');
        $session->set($name, [
            'one'   => 'two',
            'three' => 'four',
        ]);

        // Constructor pulls existing data out of the session under $name.
        $collection = new Bag($session, $name);
        $this->assertSame(2, $collection->count());

        // init() replaces the bag contents and writes back through the
        // session.
        $data = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];
        $collection->init($data);

        $this->assertSame($data, $collection->toArray());
        $this->assertSame($data, $session->get($name));

        $session->destroy();
    }
}
