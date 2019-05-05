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

namespace Phalcon\Test\Integration\Mvc\Model\MetaData\Redis;

use IntegrationTester;
use Phalcon\Mvc\Model\MetaData\Redis;
use Phalcon\Mvc\Model\MetaDataInterface;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Robots;
use function dataDir;
use function env;

/**
 * Class ConstructCest
 */
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
                return new Redis(
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

    /**
     * Tests Phalcon\Mvc\Model\MetaData\Redis :: __construct()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
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
