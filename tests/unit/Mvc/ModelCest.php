<?php

namespace Phalcon\Test\Unit\Mvc;

use IntegrationTester;
use Phalcon\Cache\Backend\File;
use Phalcon\Cache\Frontend\Data;
use Phalcon\Test\Models\AlbumORama\Albums;
use Phalcon\Test\Models\AlbumORama\Artists;
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

    public function mvcModelSaveAfterFetchingRelatedIssue14270(UnitTester $I)
    {
        $I->wantToTest('Mvc\Model::save() after fetching related');

        $artist = new Artists(
            [
                'name' => 'Mr Robot',
            ]
        );

        $album1 = new Albums(
            [
                'name' => 'Feedback',
            ]
        );
        $album2 = new Albums(
            [
                'name' => 'Syntax Error',
            ]
        );

        // Assign relationship in both directions on unsaved models
        $artist->albums = [$album1, $album2];

        $I->assertTrue(
            $artist->save()
        );

        $artist = Artists::findFirstByName("Mr Robot");

        // Query the parts, for some reason,
        // for example to check if the parts are in the db already...
        $firstAlbums = $artist->albums;

        $I->assertEquals(
            2,
            count($firstAlbums)
        );

        $album3 = new Albums(
            [
                'name' => 'Feedback 2',
            ]
        );
        $album4 = new Albums(
            [
                'name' => 'Syntax Error 2',
            ]
        );
        $artist->albums = [$album3, $album4];
        $artist->save();

        $artist = Artists::findFirstByName("Mr Robot");

        $allAlbums = $artist->getRelated('albums');

        $I->assertEquals(
            4,
            count($allAlbums)
        );
    }
}
