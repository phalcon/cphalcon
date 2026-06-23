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

namespace Phalcon\Tests\Database\Mvc\Model\Binder;

use Phalcon\Cache\Adapter\Memory;
use Phalcon\Mvc\Model\Binder;
use Phalcon\Mvc\Model\BinderInterface;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class SetCacheTest extends AbstractDatabaseTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcModelBinderSetCache(): void
    {
        $serializer = new SerializerFactory();
        $cache      = new Memory($serializer);

        $binder = new Binder();

        $returned = $binder->setCache($cache);

        $this->assertInstanceOf(BinderInterface::class, $returned);
        $this->assertSame($cache, $binder->getCache());
    }
}
