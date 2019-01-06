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
use Phalcon\Mvc\Model\Metadata\Files;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Robots;

class FilesCest
{
    use DiTrait;

    private $data;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDiMysql();
        $this->container->setShared(
            'modelsMetadata',
            function () {
                return new Files(
                    [
                        'metaDataDir' => cacheFolder(),
                    ]
                );
            }
        );

        $this->data = require dataFolder('fixtures/metadata/robots.php');
    }

    public function files(IntegrationTester $I)
    {
        $I->wantTo('fetch metadata from file cache');

        /** @var \Phalcon\Mvc\Model\MetaDataInterface $md */
        $md = $this->container->getShared('modelsMetadata');

        $md->reset();
        $I->assertTrue($md->isEmpty());

        Robots::findFirst();

        $I->amInPath(cacheFolder());

        $I->seeFileFound('meta-phalcon_test_models_robots-robots.php');

        $I->assertEquals(
            $this->data['meta-robots-robots'],
            require cacheFolder('meta-phalcon_test_models_robots-robots.php')
        );

        $I->seeFileFound('map-phalcon_test_models_robots.php');

        $I->assertEquals(
            $this->data['map-robots'],
            require cacheFolder('map-phalcon_test_models_robots.php')
        );

        $I->assertFalse($md->isEmpty());

        $md->reset();
        $I->assertTrue($md->isEmpty());

        $I->safeDeleteFile('meta-phalcon_test_models_robots-robots.php');
        $I->safeDeleteFile('map-phalcon_test_models_robots.php');
    }
}
