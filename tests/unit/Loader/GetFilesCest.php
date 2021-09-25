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

use Phalcon\Loader;
use UnitTester;

use function dataDir;

class GetFilesCest
{
    /**
     * Tests Phalcon\Loader :: getFiles()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-25
     */
    public function loaderGetFiles(UnitTester $I)
    {
        $I->wantToTest('Loader - getFiles()');

        $loader = new Loader();

        $loader->registerFiles(
            [
                dataDir('fixtures/Loader/Example/Functions/FunctionsNoClass.php'),
                dataDir('fixtures/Loader/Example/Functions/FunctionsNoClassOne.php'),
                dataDir('fixtures/Loader/Example/Functions/FunctionsNoClassTwo.php'),
            ]
        );

        $I->assertEquals(
            [
                dataDir('fixtures/Loader/Example/Functions/FunctionsNoClass.php'),
                dataDir('fixtures/Loader/Example/Functions/FunctionsNoClassOne.php'),
                dataDir('fixtures/Loader/Example/Functions/FunctionsNoClassTwo.php'),
            ],
            $loader->getFiles()
        );
    }
}
