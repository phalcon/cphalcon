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

namespace Phalcon\Test\Unit\Autoload;

use Example\Namespaces\Engines\Alcohol;
use Phalcon\Autoload\Loader;
use Phalcon\Test\Fixtures\Traits\LoaderTrait;
use UnitTester;

use function dataDir;

class SetExtensionsCest
{
    use LoaderTrait;

    public function testNamespacesExtensions(UnitTester $I)
    {
        $loader = new Loader();

        $loader->setExtensions(
            [
                'inc',
                'php',
            ]
        );

        $loader->registerNamespaces(
            [
                'Example\Namespaces\Base' => dataDir('fixtures/Loader/Example/Namespaces/Base/'),
                'Example\Namespaces'      => dataDir('fixtures/Loader/Example/Namespaces/'),
            ]
        );

        $loader->registerNamespaces(
            [
                'Example' => dataDir('fixtures/Loader/Example/Namespaces/'),
            ],
            true
        );

        $loader->register();

        $I->assertInstanceOf(
            Alcohol::class,
            new Alcohol()
        );

        $loader->unregister();
    }

    public function testDirectoriesExtensions(UnitTester $I)
    {
        /**
         * @TODO: Check Extensions for this test
         */
        $I->skipTest('TODO: Check Extensions for this test');

        $loader = new Loader();

        $loader->setExtensions(
            [
                'inc',
                'php',
            ]
        );
        $loader->registerDirs(
            [
                dataDir('fixtures/Loader/Example/Folders/Dialects'),
                dataDir('fixtures/Loader/Example/Folders/Types'),
                dataDir('fixtures/Loader/Example/Namespaces/Adapter'),
            ]
        );

        $loader->register();

        $I->assertInstanceOf(
            File::class,
            new File()
        );

        $loader->unregister();
    }
}
