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

namespace Phalcon\Tests\Unit\Loader;

use Example\Namespaces\Adapter\Another;
use Example\Namespaces\Adapter\Mongo;
use Example\Namespaces\Adapter\Redis;
use Example\Namespaces\Engines\Gasoline;
use Example\Namespaces\Example\Example;
use Phalcon\Loader;
use Phalcon\Tests\Fixtures\Traits\LoaderTrait;
use UnitTester;

use function dataDir;

class RegisterNamespacesCest
{
    use LoaderTrait;

    public function testNamespaces(UnitTester $I)
    {
        $loader = new Loader();

        $loader->registerNamespaces(
            [
                'Example\Namespaces\Base' => dataDir('fixtures/Loader/Example/Namespaces/Base/'),
            ]
        );

        $loader->registerNamespaces(
            [
                'Example\Namespaces\Adapter' => dataDir('fixtures/Loader/Example/Namespaces/Adapter/'),
                'Example\Namespaces'         => dataDir('fixtures/Loader/Example/Namespaces/'),
            ],
            true
        );

        $loader->register();

        $I->assertInstanceOf(
            Mongo::class,
            new Mongo()
        );

        $I->assertInstanceOf(
            Redis::class,
            new Redis()
        );

        $I->assertInstanceOf(
            Gasoline::class,
            new Gasoline()
        );

        $I->assertInstanceOf(
            Example::class,
            new Example()
        );

        $loader->unregister();
    }

    public function testNamespacesForMultipleDirectories(UnitTester $I)
    {
        $loader = new Loader();

        $loader->registerNamespaces(
            [
                'Example\\Namespaces\\Base' => dataDir('fixtures/Loader/Example/Namespaces/Base/'),
            ]
        );

        $expected = [
            'Example\\Namespaces\\Base' => [
                dataDir('fixtures/Loader/Example/Namespaces/Base/'),
            ],
        ];

        $I->assertEquals(
            $expected,
            $loader->getNamespaces()
        );

        $loader->registerNamespaces(
            [
                'Example\\Namespaces\\Adapter' => [
                    dataDir('fixtures/Loader/Example/Namespaces/Adapter/'),
                    dataDir('fixtures/Loader/Example/Namespaces/Plugin/'),
                ],
            ],
            true
        );

        $expected = [
            'Example\\Namespaces\\Base'    => [
                dataDir('fixtures/Loader/Example/Namespaces/Base/'),
            ],
            'Example\\Namespaces\\Adapter' => [
                dataDir('fixtures/Loader/Example/Namespaces/Adapter/'),
                dataDir('fixtures/Loader/Example/Namespaces/Plugin/'),
            ],
        ];

        $I->assertEquals(
            $expected,
            $loader->getNamespaces()
        );

        $loader->register();

        $I->assertInstanceOf(
            Mongo::class,
            new Mongo()
        );

        $I->assertInstanceOf(
            Another::class,
            new Another()
        );

        $I->assertInstanceOf(
            Redis::class,
            new Redis()
        );

        $loader->unregister();
    }
}
