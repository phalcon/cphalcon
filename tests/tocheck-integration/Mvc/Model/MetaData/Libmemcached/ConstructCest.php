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

namespace Phalcon\Test\Integration\Mvc\Model\MetaData\Libmemcached;

use IntegrationTester;
use Phalcon\Cache\AdapterFactory;
use Phalcon\Mvc\Model\MetaData\Libmemcached;
use Phalcon\Mvc\Model\MetaDataInterface;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Robots;

use function dataDir;
use function getOptionsLibmemcached;

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
                $serializer = new SerializerFactory();
                $factory    = new AdapterFactory($serializer);

                return new Libmemcached(
                    $factory,
                    getOptionsLibmemcached()
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
     * Tests Phalcon\Mvc\Model\MetaData\Libmemcached :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelMetadataLibmemcachedConstruct(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\MetaData\Libmemcached - __construct()');

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
