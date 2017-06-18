<?php

namespace Phalcon\Test\Unit\Mvc;

use Phalcon\Cache\Backend\File;
use Phalcon\Cache\Frontend\Data;
use Phalcon\Test\Models\Snapshot\Robots;
use UnitTester;

/**
 * \Phalcon\Test\Unit\Mvc\ModelCest
 * Tests the Phalcon\Mvc\Model component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @author    Wojciech Ślawski <jurigag@gmail.com>
 * @package   Phalcon\Test\Unit\Mvc
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class ModelCest
{
    public function testModelsCacheSnapshot(UnitTester $I)
    {
        $I->wantToTest("Saving snapshot using simple resultset while using modelsCache");

        $I->addServiceToContainer(
            'modelsCache',
            function () {
                return new File(
                    new Data(
                        [
                            'lifetime' => 20,
                        ]
                    ),
                    [
                        'cacheDir' => PATH_OUTPUT."tests/cache/",
                    ]
                );
            },
            true
        );

        for ($i = 0; $i <= 1; $i++) {
            $robot = Robots::findFirst(
                [
                    'cache' => [
                        'key' => 'robots-cache',
                    ],
                ]
            );
            $I->assertInstanceOf(Robots::class, $robot);
            $I->assertNotEmpty($robot->getSnapshotData());
            $I->assertEquals($robot->getSnapshotData(), $robot->toArray());
            $I->seeFileFound(PATH_OUTPUT."tests/cache/robots-cache");
        }
    }
}
