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
use Integer;
use Phalcon\Loader;
use Phalcon\Test\Fixtures\Traits\LoaderTrait;
use Sqlite;
use UnitTester;

class RegisterDirsCest
{
    use LoaderTrait;

    public function testDirectories(UnitTester $I)
    {
        $loader = new Loader();

        $loader->registerDirs(
            [
                // missing trailing slash
                dataDir('fixtures/Loader/Example/Folders/Dialects'),
            ]
        );

        $loader->registerDirs(
            [
                dataDir('fixtures/Loader/Example/Folders/Types/'),
            ],
            true
        );

        $loader->register();

        $I->assertInstanceOf(
            Sqlite::class,
            new Sqlite()
        );

        $I->assertInstanceOf(
            Integer::class,
            new Integer()
        );

        $loader->unregister();
    }
}
