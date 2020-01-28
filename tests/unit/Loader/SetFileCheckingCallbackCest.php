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

namespace Phalcon\Test\Unit\Loader;

use Phalcon\Loader;
use Phalcon\Test\Fixtures\Traits\LoaderTrait;
use UnitTester;

use function dataDir;

class SetFileCheckingCallbackCest
{
    use LoaderTrait;

    /**
     * Tests Loader::setFileCheckingCallback
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-04-29
     * @issue  https://github.com/phalcon/cphalcon/issues/13360
     * @issue  https://github.com/phalcon/cphalcon/issues/10472
     */
    public function shouldNotFindFilesWithFalseCallback(UnitTester $I)
    {
        $loader = new Loader();

        $loader->setFileCheckingCallback(
            function ($file) {
                return false;
            }
        );

        $loader->registerFiles(
            [
                dataDir('fixtures/Loader/Example/Functions/FunctionsNoClassThree.php'),
            ]
        );

        $loader->registerNamespaces(
            [
                'Example' => dataDir('fixtures/Loader/Example/'),
            ],
            true
        );

        $loader->register();

        $I->assertFalse(
            function_exists('noClass3Foo')
        );

        $I->assertFalse(
            function_exists('noClass3Bar')
        );
    }

    /**
     * Tests Loader::setFileCheckingCallback
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-04-29
     * @issue  https://github.com/phalcon/cphalcon/issues/13360
     * @issue  https://github.com/phalcon/cphalcon/issues/10472
     */
    public function shouldWorkWithCustomFileCheckCallback(UnitTester $I)
    {
        $loader = new Loader();

        $loader->setFileCheckingCallback('stream_resolve_include_path');

        $loader->registerFiles(
            [
                dataDir('fixtures/Loader/Example/Functions/FunctionsNoClassThree.php'),
            ]
        );

        $loader->registerNamespaces(
            [
                'Example\Namespaces' => dataDir('fixtures/Loader/Example/Namespaces'),
            ],
            true
        );

        $loader->register();

        $I->assertTrue(
            function_exists('noClass3Foo')
        );

        $I->assertTrue(
            function_exists('noClass3Bar')
        );

        $I->assertTrue(
            class_exists('\Example\Namespaces\Engines\Diesel')
        );
    }
}
