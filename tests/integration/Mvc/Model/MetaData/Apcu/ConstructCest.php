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

namespace Phalcon\Test\Integration\Mvc\Model\MetaData\Apcu;

use IntegrationTester;
use Phalcon\Mvc\Model\MetaData\Apcu;
use Phalcon\Mvc\Model\MetaDataInterface;
use Phalcon\Storage\AdapterFactory;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Robots;
use function apcu_clear_cache;
use function apcu_fetch;
use function dataDir;
use function serialize;

/**
 * Class ConstructCest
 */
class ConstructCest
{
    use DiTrait;

    private $data;

    public function _before(IntegrationTester $I)
    {
        $I->checkExtensionIsLoaded('apcu');
        $this->setNewFactoryDefault();
        $this->setDiMysql();
        $this->container->setShared(
            'modelsMetadata',
            function () {
                $serializer = new SerializerFactory();
                $factory    = new AdapterFactory($serializer);
                return new Apcu(
                    $factory,
                    [
                        'prefix'   => 'app\\',
                        'lifetime' => 60,
                    ]
                );
            }
        );

        $this->data = require dataDir('fixtures/metadata/robots.php');
        apcu_clear_cache();
    }

    /**
     * Tests Phalcon\Mvc\Model\MetaData\Apcu :: __construct()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelMetadataApcuConstruct(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\MetaData\Apcu - __construct()');
        /** @var MetaDataInterface $md */
        $md = $this->container->getShared('modelsMetadata');


        $md->reset();
        $I->assertTrue($md->isEmpty());

        Robots::findFirst();

        $expected = serialize($this->data['meta-robots-robots']);
        $actual   = apcu_fetch('ph-mm-apcu-meta-phalcon\\test\models\\robots-robots');
        $I->assertEquals($expected, $actual);

        $expected = serialize($this->data['map-robots']);
        $actual   = apcu_fetch('ph-mm-apcu-map-phalcon\\test\\models\\robots');
        $I->assertEquals($expected, $actual);

        $I->assertFalse($md->isEmpty());

        $md->reset();
        $I->assertTrue($md->isEmpty());
    }
}
