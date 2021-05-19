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

use Phalcon\Autoload\Loader;
use Phalcon\Test\Fixtures\Traits\LoaderTrait;
use UnitTester;

use function dataDir;

class RegisterFilesCest
{
    use LoaderTrait;

    public function testFiles(UnitTester $I)
    {
        // TEST CASE : Register the file and check if functions in the file is accessible

        $I->assertFalse(
            function_exists('noClassFoo')
        );

        $I->assertFalse(
            function_exists('noClassBar')
        );

        $I->assertFalse(
            function_exists('noClass1Foo')
        );

        $I->assertFalse(
            function_exists('noClass1Bar')
        );

        $I->assertFalse(
            function_exists('noClass2Foo')
        );

        $I->assertFalse(
            function_exists('noClass2Bar')
        );

        $loader = new Loader();

        $loader->registerFiles(
            [
                dataDir('fixtures/Loader/Example/Functions/FunctionsNoClass.php'),
                dataDir('fixtures/Loader/Example/Functions/FunctionsNoClassOne.php'),
            ]
        );
        $loader->registerFiles(
            [
                dataDir('fixtures/Loader/Example/Functions/FunctionsNoClassTwo.php'),
            ],
            true
        );
        $loader->register();

        $I->assertTrue(
            function_exists('noClassFoo')
        );

        $I->assertTrue(
            function_exists('noClassBar')
        );

        $I->assertTrue(
            function_exists('noClass1Foo')
        );

        $I->assertTrue(
            function_exists('noClass1Bar')
        );

        $I->assertTrue(
            function_exists('noClass2Foo')
        );

        $I->assertTrue(
            function_exists('noClass2Bar')
        );

        // TEST CASE : We are going to un-register it, but the functions should still be accessible
        $loader->unregister();

        $I->assertTrue(
            function_exists('noClassFoo')
        );

        $I->assertTrue(
            function_exists('noClassBar')
        );

        $I->assertTrue(
            function_exists('noClass1Foo')
        );

        $I->assertTrue(
            function_exists('noClass1Bar')
        );

        $I->assertTrue(
            function_exists('noClass2Foo')
        );

        $I->assertTrue(
            function_exists('noClass2Bar')
        );
    }
}
