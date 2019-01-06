<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Model\MetaData;

use IntegrationTester;
use Phalcon\Mvc\Model\Metadata\Libmemcached;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Robots;

class LibmemcachedCest
{
    use DiTrait;

    private $data;

    public function _before(IntegrationTester $I)
    {
        $I->checkExtensionIsLoaded('memcached');
        $this->setNewFactoryDefault();
        $this->setDiMysql();
        $this->container->setShared(
            'modelsMetadata',
            function () {
                return new Libmemcached(
                    [
                        'servers' => [
                            [
                                'host'   => env('DATA_MEMCACHED_HOST', '127.0.0.1'),
                                'port'   => env('DATA_MEMCACHED_PORT', 11211),
                                'weight' => 1,
                            ],
                        ],
                    ]
                );
            }
        );

        $this->data = require dataFolder('fixtures/metadata/robots.php');
    }

    public function memcached(IntegrationTester $I)
    {
        $I->wantTo('fetch metadata from memcached cache');

        /** @var \Phalcon\Mvc\Model\MetaDataInterface $md */
        $md = $this->container->getShared('modelsMetadata');

        $md->reset();
        $I->assertTrue($md->isEmpty());

        Robots::findFirst();

        $I->assertEquals(
            $this->data['meta-robots-robots'],
            $md->read("meta-phalcon\\test\\models\\robots-robots")
        );

        $I->assertEquals(
            $this->data['map-robots'],
            $md->read("map-phalcon\\test\\models\\robots")
        );

        $I->assertFalse($md->isEmpty());

        $md->reset();
        $I->assertTrue($md->isEmpty());
    }
}
