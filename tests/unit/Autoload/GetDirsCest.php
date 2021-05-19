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
use UnitTester;
use function dataDir;

class GetDirsCest
{
    /**
     * Tests Phalcon\Autoload\Loader:: getDirs()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-25
     */
    public function loaderGetDirs(UnitTester $I)
    {
        $I->wantToTest('Autoload\Loader- getDirs()');

        $Autoload\Loader = new Loader();

        $loader->registerDirs(
            [
                // missing trailing slash
                dataDir('fixtures/Loader/Example/Folders/Dialects'),
                dataDir('fixtures/Loader/Example/Folders/Types/'),
            ]
        );

        $I->assertEquals(
            [
                dataDir('fixtures/Loader/Example/Folders/Dialects'),
                dataDir('fixtures/Loader/Example/Folders/Types/'),
            ],
            $loader->getDirs()
        );
    }
}
