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

use Phalcon\Autoload\Exception;
use Phalcon\Autoload\Loader;
use Phalcon\Tests\Fixtures\Traits\LoaderTrait;
use UnitTester;

use function dataDir;

class GetCheckedPathCest
{
    use LoaderTrait;

    /**
     * Tests Phalcon\Autoload\Loader :: getCheckedPath()
     *
     * @param UnitTester $I
     *
     * @throws Exception
     * @since  2020-09-09
     * @author Phalcon Team <team@phalcon.io>
     */
    public function autoloaderLoaderGetCheckedPath(UnitTester $I)
    {
        $I->wantToTest('Autoload\Loader - getCheckedPath()');

        if (PHP_OS_FAMILY === 'Windows') {
            $I->markTestSkipped('Need to fix Windows new lines...');
        }

        $loader    = new Loader(true);
        $directory = dataDir('fixtures/Loader/Example/Folders/Types/');
        $loader->addDirectory($directory);

        $loader->autoload('Integer');

        $expected = [
            'Loading: Integer',
            'Class: 404: Integer',
            'Namespace: 404: Integer',
            'Require: ' . $directory . 'Integer.php',
            'Directories: ' . $directory . 'Integer.php',
        ];
        $actual   = $loader->getDebug();
        $I->assertEquals($expected, $actual);

        $expected = $directory . 'Integer.php';
        $actual   = $loader->getCheckedPath();
        $I->assertEquals($expected, $actual);
    }
}
