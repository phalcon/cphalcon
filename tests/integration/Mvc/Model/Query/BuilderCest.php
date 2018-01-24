<?php

/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-present Phalcon Team (https://phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Test\Unit\Mvc\Model\Query;

use Phalcon\Cache\Backend\File;
use Phalcon\Cache\Frontend\Data;
use Phalcon\Mvc\Model\Query\Builder;
use Phalcon\Test\Models\Snapshot\Robots;
use Phalcon\Test\Models\Snapshot\RobotsParts;
use IntegrationTester;

/**
 * Phalcon\Test\Integration\Mvc\Model\Query\BuilderCest
 *
 * Tests the Phalcon\Mvc\Model\Query\Builder component
 *
 * @package Phalcon\Test\Integration\Mvc\Model\Query
 */
class BuilderCest
{
    /**
     * Tests Models cache
     *
     * @test
     * @issue  -
     * @author Andres Gutierrez <andres@phalconphp.com>
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-12-09
     */
    public function shouldSaveToUseComplexSnapshotCache(IntegrationTester $I)
    {
        $I->wantToTest("Saving snapshot using complex resultset while using modelsCache");

        $I->addServiceToContainer(
            'modelsCache',
            function () {
                return new File(
                    new Data(
                        ['lifetime' => 20,]
                    ),
                    ['cacheDir' => PATH_OUTPUT.'tests/cache/',]
                );
            },
            true
        );

        for ($i = 0; $i <= 1; $i++) {
            $builder = new Builder();
            $result = $builder->columns(['rp.*,r.*'])
                ->from(['rp' => RobotsParts::class])
                ->leftJoin(Robots::class, 'r.id = rp.robots_id', 'r')
                ->where('rp.id = 1')
                ->getQuery()
                ->cache(
                    [
                        'key' => 'robots-cache-complex',
                    ]
                )
                ->getSingleResult();
            /** @var Robots $robot */
            $robot = $result['r'];
            /** @var RobotsParts $robotParts */
            $robotParts = $result['rp'];
            $I->assertInstanceOf(Robots::class, $robot);
            $I->assertNotEmpty($robot->getSnapshotData());
            $I->assertEquals($robot->getSnapshotData(), $robot->toArray());
            $I->assertInstanceOf(RobotsParts::class, $robotParts);
            $I->assertNotEmpty($robotParts->getSnapshotData());
            $I->assertEquals($robotParts->getSnapshotData(), $robotParts->toArray());
            $I->seeFileFound(PATH_OUTPUT."tests/cache/robots-cache-complex");
        }
    }
}
