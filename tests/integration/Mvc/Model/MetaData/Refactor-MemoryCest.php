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
use Phalcon\Mvc\Model\Metadata\Memory;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Robots;
use Phalcon\Test\Models\Robotto;

class MemoryCest
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
                return new Memory();
            }
        );

        $this->data = require dataFolder('fixtures/metadata/robots.php');
    }

    public function redis(IntegrationTester $I)
    {
        $I->wantTo('fetch metadata from memory');

        /** @var \Phalcon\Mvc\Model\MetaDataInterface $md */
        $md = $this->container->getShared('modelsMetadata');

        $md->reset();
        $I->assertTrue($md->isEmpty());

        Robots::findFirst();

        $I->assertFalse($md->isEmpty());

        $md->reset();
        $I->assertTrue($md->isEmpty());
    }

    public function testMetadataManual(IntegrationTester $I)
    {
        /** @var \Phalcon\Mvc\Model\MetaDataInterface $metaData */
        $metaData = $this->container->getShared('modelsMetadata');

        $di = $I->getApplication()->getDI();

        $robotto = new Robotto();

        //Robots
        $pAttributes = [
            0 => 'id',
            1 => 'name',
            2 => 'type',
            3 => 'year',
        ];

        $attributes = $metaData->getAttributes($robotto);
        $I->assertEquals($attributes, $pAttributes);

        $ppkAttributes = [
            0 => 'id',
        ];

        $pkAttributes = $metaData->getPrimaryKeyAttributes($robotto);
        $I->assertEquals($ppkAttributes, $pkAttributes);

        $pnpkAttributes = [
            0 => 'name',
            1 => 'type',
            2 => 'year',
        ];

        $npkAttributes = $metaData->getNonPrimaryKeyAttributes($robotto);
        $I->assertEquals($pnpkAttributes, $npkAttributes);

        $I->assertEquals($metaData->getIdentityField($robotto), 'id');
    }
}
