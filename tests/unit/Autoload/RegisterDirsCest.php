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

use Integer;
use Phalcon\Autoload\Loader;
use Phalcon\Test\Fixtures\Traits\LoaderTrait;
use Sqlite;
use UnitTester;

use function dataDir;

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
