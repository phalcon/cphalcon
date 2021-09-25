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

namespace Phalcon\Tests\Integration\Mvc\Model\MetaData\Redis;

use IntegrationTester;
use Phalcon\Cache\AdapterFactory;
use Phalcon\Mvc\Model\MetaData\Redis;
use Phalcon\Mvc\Model\MetaDataInterface;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Models\Robots;

use function dataDir;
use function env;

class ConstructCest
{
    use DiTrait;

    private $data;

    public function _before(IntegrationTester $I)
    {
        $I->checkExtensionIsLoaded('redis');
        $this->setNewFactoryDefault();
        $this->setDiMysql();
        $this->container->setShared(
            'modelsMetadata',
            function () {
                $serializer = new SerializerFactory();
                $factory    = new AdapterFactory($serializer);

                return new Redis(
                    $factory,
                    [
                        'host'  => env('DATA_REDIS_HOST', '127.0.0.1'),
                        'port'  => env('DATA_REDIS_PORT', 6379),
                        'index' => env('DATA_REDIS_NAME', 0),
                    ]
                );
            }
        );

        $this->data = require dataDir('fixtures/metadata/robots.php');
    }

    public function _after(IntegrationTester $I)
    {
        $this->container['db']->close();
    }

    /**
     * Tests Phalcon\Mvc\Model\MetaData\Redis :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelMetadataRedisConstruct(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\MetaData\Redis - __construct()');

        /** @var MetaDataInterface $md */
        $md = $this->container->getShared('modelsMetadata');

        $md->reset();
        $I->assertTrue($md->isEmpty());

        Robots::findFirst();

        $I->assertEquals(
            $this->data['meta-robots-robots'],
            $md->read('meta-phalcon\\test\\models\\robots-robots')
        );

        $I->assertEquals(
            $this->data['map-robots'],
            $md->read('map-phalcon\\test\\models\\robots')
        );

        $I->assertFalse($md->isEmpty());

        $md->reset();
        $I->assertTrue($md->isEmpty());
    }
}
