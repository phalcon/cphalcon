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
use Phalcon\Mvc\Model\Metadata\Apcu;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Robots;
use function apcu_fetch;

class ApcuCest
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
                return new Apcu(
                    [
                        'prefix'   => 'app\\',
                        'lifetime' => 60,
                    ]
                );
            }
        );

        $this->data = require dataFolder('fixtures/metadata/robots.php');
        apcu_clear_cache();
    }

    public function apc(IntegrationTester $I)
    {
        $I->wantTo('fetch metadata from apc cache');
        $I->skipTest('TODO - Check test');
        /** @var \Phalcon\Mvc\Model\MetaDataInterface $md */
        $md = $this->container->getShared('modelsMetadata');

        $md->reset();
        $I->assertTrue($md->isEmpty());

        Robots::findFirst();

        $I->assertEquals(
            $this->data['meta-robots-robots'],
            apcu_fetch('$PMM$app\meta-phalcon\test\models\robots-robots')
        );

        $I->assertEquals(
            $this->data['map-robots'],
            apcu_fetch('$PMM$app\map-phalcon\test\models\robots')
        );

        $I->assertFalse($md->isEmpty());

        $md->reset();
        $I->assertTrue($md->isEmpty());
    }
}
