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

namespace Phalcon\Test\Integration\Mvc\Model\MetaData\Libmemcached;

use function dataDir;
use function env;
use IntegrationTester;
use Phalcon\Mvc\Model\MetaData\Libmemcached;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Robots;

/**
 * Class ConstructCest
 */
class ConstructCest
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

        $this->data = require dataDir('fixtures/metadata/robots.php');
    }

    /**
     * Tests Phalcon\Mvc\Model\MetaData\Libmemcached :: __construct()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelMetadataLibmemcachedConstruct(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\MetaData\Libmemcached - __construct()');

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
