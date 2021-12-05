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

use Phalcon\Autoload\Loader;
use Phalcon\Tests\Fixtures\Traits\LoaderTrait;
use UnitTester;

use function dataDir;
use function function_exists;

class LoadFilesCest
{
    use LoaderTrait;

    /**
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function autoloaderLoaderLoadFiles(UnitTester $I)
    {
        $I->wantToTest('Autoload\Loader - loadFiles()');

        $loader = new Loader();

        $actual = function_exists('noClass2Foo');
        $I->assertFalse($actual);

        $actual = function_exists('noClass2Bar');
        $I->assertFalse($actual);

        $loader
            ->addFile(
                dataDir('fixtures/Loader/Example/Functions/FunctionsNoClassTwo.php')
            )
            ->addFile(
                '/path/to/unknown/file'
            )
        ;

        $loader->loadFiles();

        $actual = function_exists('noClass2Foo');
        $I->assertTrue($actual);

        $actual = function_exists('noClass2Bar');
        $I->assertTrue($actual);
    }
}
