<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Loader;

use function dataDir;
use Phalcon\Loader;
use Phalcon\Test\Fixtures\Traits\LoaderTrait;
use UnitTester;

class SetFileCheckingCallbackCest
{
    use LoaderTrait;

    /**
     * Tests Loader::setFileCheckingCallback
     *
     * @author Phalcon Team <team@phalconphp.com>
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
     * @author Phalcon Team <team@phalconphp.com>
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
