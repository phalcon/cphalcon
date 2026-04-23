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

namespace Phalcon\Tests\Unit\Dispatcher;

use Phalcon\Cache\Adapter\Memory;
use Phalcon\Di\Di;
use Phalcon\Mvc\Dispatcher;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Dispatcher\Fake\FakeModelBinder;

final class SetModelBinderTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testDispatcherSetModelBinderStringCache(): void
    {
        $serializerFactory = new SerializerFactory();
        $cacheAdapter      = new Memory($serializerFactory);

        $di = new Di();
        $di->set(
            'myCache',
            function () use ($cacheAdapter) {
                return $cacheAdapter;
            }
        );

        $dispatcher = new Dispatcher();
        $dispatcher->setDI($di);

        $binder = new FakeModelBinder();

        $result = $dispatcher->setModelBinder($binder, 'myCache');

        $this->assertSame($dispatcher, $result);
        $this->assertSame($cacheAdapter, $binder->getCache());
    }
}
