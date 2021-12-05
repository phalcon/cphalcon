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

use Codeception\Example;
use Phalcon\Autoload\Exception;
use Phalcon\Autoload\Loader;
use Phalcon\Tests\Fixtures\Traits\LoaderTrait;
use UnitTester;

use function class_exists;
use function function_exists;

class SetFileCheckingCallbackCest
{
    use LoaderTrait;

    /**
     * Tests Phalcon\Autoload\Loader :: setFileCheckingCallback()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     * @issue  https://github.com/phalcon/cphalcon/issues/13360
     * @issue  https://github.com/phalcon/cphalcon/issues/10472
     */
    public function autoloaderLoaderSetFileCheckingCallbackFalse(UnitTester $I)
    {
        $I->wantToTest('Autoload\Loader - setFileCheckingCallback() - callback false');

        $loader = new Loader();

        $loader->setFileCheckingCallback(
            function ($file) {
                return false;
            }
        );

        $loader->setFiles(
            [
                dataDir('fixtures/Loader/Example/Functions/FunctionsNoClassThree.php'),
            ]
        );

        $loader->setNamespaces(
            [
                'Example' => dataDir('fixtures/Loader/Example/'),
            ],
            true
        );

        $loader->register();

        $actual = function_exists('noClass3Foo');
        $I->assertFalse($actual);

        $actual = function_exists('noClass3Bar');
        $I->assertFalse($actual);
    }

    /**
     * Tests Phalcon\Autoload\Loader :: setFileCheckingCallback()
     *
     * @dataProvider getExamples
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     * @issue  https://github.com/phalcon/cphalcon/issues/13360
     * @issue  https://github.com/phalcon/cphalcon/issues/10472
     */
    public function autoloaderLoaderSetFileCheckingCallback(UnitTester $I, Example $example)
    {
        $I->wantToTest('Autoload\Loader - setFileCheckingCallback() - ' . $example[0]);
        $loader = new Loader();

        $loader->setFileCheckingCallback($example[1]);

        $loader->setFiles(
            [
                dataDir('fixtures/Loader/Example/Functions/FunctionsNoClassThree.php'),
            ]
        );

        $loader->setNamespaces(
            [
                'Example\Namespaces' => dataDir('fixtures/Loader/Example/Namespaces'),
            ],
            true
        );

        $loader->register();

        $actual = function_exists('noClass3Foo');
        $I->assertTrue($actual);

        $actual = function_exists('noClass3Bar');
        $I->assertTrue($actual);

        $actual = class_exists('\Example\Namespaces\Engines\Diesel');
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Autoload\Loader :: setFileCheckingCallback() - exception
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function autoloaderLoaderSetFileCheckingCallbackException(UnitTester $I)
    {
        $I->wantToTest('Autoload\Loader - setFileCheckingCallback() - exception');

        $I->expectThrowable(
            new Exception(
                "The 'method' parameter must be either a callable or NULL"
            ),
            function () {
                $loader = new Loader();
                $loader->setFileCheckingCallback(1234);
            }
        );
    }

    private function getExamples(): array
    {
        return [
            [
                'custom callback',
                'stream_resolve_include_path',
            ],
            [
                'null callback',
                null,
            ],
        ];
    }
}
