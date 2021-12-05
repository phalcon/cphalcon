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

namespace Phalcon\Tests\Unit\Autoload\Loader;

use Example\Namespaces\Adapter\Another;
use Example\Namespaces\Adapter\Mongo;
use Phalcon\Autoload\Loader;
use Phalcon\Tests\Fixtures\Traits\LoaderTrait;
use UnitTester;

use function dataDir;

class AutoloadCest
{
    use LoaderTrait;

    /**
     * Tests Phalcon\Autoloader\Loader :: autoload() = classes
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function autoloaderLoaderAutoloadClasses(UnitTester $I)
    {
        $I->wantToTest('Autoload\Loader - autoload() - classes');

        $loader = new Loader(true);

        $loader
            ->addClass(
                'One',
                dataDir('fixtures/Loader/Example/Classes/One.php')
            )
            ->addClass(
                'Two',
                dataDir('fixtures/Loader/Example/Classes/Two.php')
            )
        ;

        $loader->autoload('One');

        $expected = [
            'Loading: One',
            'Require: ' . dataDir('fixtures/Loader/Example/Classes/One.php'),
            'Class: load: ' . dataDir('fixtures/Loader/Example/Classes/One.php'),
        ];
        $actual   = $loader->getDebug();
        $I->assertEquals($expected, $actual);

        $loader->autoload('Two');

        $expected = [
            'Loading: Two',
            'Require: ' . dataDir('fixtures/Loader/Example/Classes/Two.php'),
            'Class: load: ' . dataDir('fixtures/Loader/Example/Classes/Two.php'),
        ];
        $actual   = $loader->getDebug();
        $I->assertEquals($expected, $actual);

        $loader->autoload('Three');

        $expected = [
            'Loading: Three',
            'Class: 404: Three',
            'Namespace: 404: Three',
            'Directories: 404: Three',
        ];
        $actual   = $loader->getDebug();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Autoloader\Loader :: autoload() = namespaces
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function autoloaderLoaderAutoloadNamespaces(UnitTester $I)
    {
        $I->wantToTest('Autoload\Loader - autoload() - namespaces');

        if (PHP_OS_FAMILY === 'Windows') {
            $I->markTestSkipped('Need to fix Windows new lines...');
        }

        $loader = new Loader(true);
        $loader
            ->addNamespace(
                'Example\Namespaces\Base',
                dataDir('fixtures/Loader/Example/Namespaces/Base/')
            )
            ->addNamespace(
                'Example\Namespaces\Adapter',
                dataDir('fixtures/Loader/Example/Namespaces/Adapter/')
            )
            ->addNamespace(
                'Example\Namespaces',
                dataDir('fixtures/Loader/Example/Namespaces/')
            )
        ;

        $loader->autoload(Mongo::class);

        $expected = [
            'Loading: Example\Namespaces\Adapter\Mongo',
            'Class: 404: Example\Namespaces\Adapter\Mongo',
            'Require: ' .
            dataDir('fixtures/Loader/Example/Namespaces/Adapter/') .
            'Mongo.php',
            'Namespace: Example\Namespaces\Adapter\ - ' .
            dataDir('fixtures/Loader/Example/Namespaces/Adapter/') .
            'Mongo.php',
        ];
        $actual   = $loader->getDebug();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Autoloader\Loader :: autoload() = namespaces multiple
     * folders
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function autoloaderLoaderAutoloadNamespacesMultipleFolders(UnitTester $I)
    {
        $I->wantToTest('Autoload\Loader - autoload() - namespaces multiple folders');

        if (PHP_OS_FAMILY === 'Windows') {
            $I->markTestSkipped('Need to fix Windows new lines...');
        }

        $loader = new Loader(true);
        $loader
            ->addNamespace(
                'Example\Namespaces\Base',
                dataDir('fixtures/Loader/Example/Namespaces/Base/')
            )
            ->addNamespace(
                'Example\Namespaces\Adapter',
                dataDir('fixtures/Loader/Example/Namespaces/Adapter/')
            )
            ->addNamespace(
                'Example\Namespaces',
                dataDir('fixtures/Loader/Example/Namespaces/')
            )
        ;
        $loader
            ->setNamespaces(
                [
                    'Example\Namespaces\Adapter' => [
                        dataDir('fixtures/Loader/Example/Namespaces/Adapter/'),
                        dataDir('fixtures/Loader/Example/Namespaces/Plugin/'),
                    ],
                ]
            )
        ;

        $loader->autoload(Another::class);

        $expected = [
            'Loading: Example\Namespaces\Adapter\Another',
            'Class: 404: Example\Namespaces\Adapter\Another',
            'Require: 404: ' .
            dataDir('fixtures/Loader/Example/Namespaces/Adapter/Another.php'),
            'Require: ' .
            dataDir('fixtures/Loader/Example/Namespaces/Plugin/Another.php'),
            'Namespace: Example\Namespaces\Adapter\ - ' .
            dataDir('fixtures/Loader/Example/Namespaces/Plugin/Another.php'),
        ];
        $actual   = $loader->getDebug();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Autoloader\Loader :: autoload() = namespaces no folders
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function autoloaderLoaderAutoloadNamespacesNoFolders(UnitTester $I)
    {
        $I->wantToTest('Autoload\Loader - autoload() - namespaces no folders');

        if (PHP_OS_FAMILY === 'Windows') {
            $I->markTestSkipped('Need to fix Windows new lines...');
        }

        $loader = new Loader(true);
        $loader->autoload(Mongo::class);

        $expected = [
            'Loading: Example\Namespaces\Adapter\Mongo',
            'Class: 404: Example\Namespaces\Adapter\Mongo',
            //            'Load: No folders registered: Example\Namespaces\Adapter\\',
            //            'Load: No folders registered: Example\Namespaces\\',
            //            'Load: No folders registered: Example\\',
            'Namespace: 404: Example\Namespaces\Adapter\Mongo',
            'Directories: 404: Example\Namespaces\Adapter\Mongo',
        ];
        $actual   = $loader->getDebug();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Autoloader\Loader :: autoload() = namespaces 404
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function autoloaderLoaderAutoloadNamespaces404(UnitTester $I)
    {
        $I->wantToTest('Autoload\Loader - autoload() - namespaces 404');

        if (PHP_OS_FAMILY === 'Windows') {
            $I->markTestSkipped('Need to fix Windows new lines...');
        }

        $loader = new Loader(true);
        $loader
            ->addNamespace(
                'Example\Namespaces\Adapter',
                dataDir('fixtures/Loader/Example/Namespaces/Adapter/')
            )
        ;

        $loader->autoload('Example\Namespaces\Adapter\Unknown');

        $expected = [
            'Loading: Example\Namespaces\Adapter\Unknown',
            'Class: 404: Example\Namespaces\Adapter\Unknown',
            'Require: 404: ' .
            dataDir('fixtures/Loader/Example/Namespaces/Adapter/Unknown.php'),
            'Namespace: 404: Example\Namespaces\Adapter\Unknown',
            'Directories: 404: Example\Namespaces\Adapter\Unknown',
        ];
        $actual   = $loader->getDebug();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Autoloader\Loader :: autoload() = extension
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function autoloaderLoaderAutoloadExtension(UnitTester $I)
    {
        $I->wantToTest('Autoload\Loader - autoload() - extension');

        if (PHP_OS_FAMILY === 'Windows') {
            $I->markTestSkipped('Need to fix Windows new lines...');
        }

        $loader = new Loader(true);
        $loader
            ->setExtensions(
                [
                    'inc',
                ]
            )
            ->setNamespaces(
                [
                    'Example\Namespaces\Base' => dataDir('fixtures/Loader/Example/Namespaces/Base/'),
                    'Example\Namespaces'      => dataDir('fixtures/Loader/Example/Namespaces/'),
                    'Example'                 => dataDir('fixtures/Loader/Example/Namespaces/'),
                ]
            )
        ;

        $loader->autoload('Example\Namespaces\Engines\Alcohol');

        $expected = [
            'Loading: Example\Namespaces\Engines\Alcohol',
            'Class: 404: Example\Namespaces\Engines\Alcohol',
            'Require: 404: ' .
            dataDir('fixtures/Loader/Example/Namespaces/Engines/Alcohol.php'),
            'Require: ' .
            dataDir('fixtures/Loader/Example/Namespaces/Engines/Alcohol.inc'),
            'Namespace: Example\Namespaces\ - ' .
            dataDir('fixtures/Loader/Example/Namespaces/Engines/Alcohol.inc'),
        ];
        $actual   = $loader->getDebug();
        $I->assertEquals($expected, $actual);
    }
}
