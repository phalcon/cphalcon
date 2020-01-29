<?php

namespace Phalcon\Test\Integration\Mvc\Model;

use IntegrationTester;
use Phalcon\Mvc\Model\MetaData\Memory;
use Phalcon\Mvc\Model\MetaData\Strategy\Annotations;
use Phalcon\Mvc\Model\MetaData\Strategy\Introspection;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Boutique\Robots as BoutiqueRobots;
use Phalcon\Test\Models\Robots;

class ModelsMetadataStrategyCest
{
    use DiTrait;

    protected $meta = [
        0  => [
            0 => 'id',
            1 => 'name',
            2 => 'type',
            3 => 'year',
            4 => 'datetime',
            5 => 'deleted',
            6 => 'text',
        ],
        1  => [
            0 => 'id',
        ],
        2  => [
            0 => 'name',
            1 => 'type',
            2 => 'year',
            3 => 'datetime',
            4 => 'deleted',
            5 => 'text',
        ],
        3  => [
            0 => 'id',
            1 => 'name',
            2 => 'type',
            3 => 'year',
            4 => 'datetime',
            5 => 'text',
        ],
        4  => [
            'id'       => 0,
            'name'     => 2,
            'type'     => 2,
            'year'     => 0,
            'datetime' => 4,
            'deleted'  => 4,
            'text'     => 6,
        ],
        5  => [
            'id'   => true,
            'year' => true,
        ],
        8  => 'id',
        9  => [
            'id'       => 1,
            'name'     => 2,
            'type'     => 2,
            'year'     => 1,
            'datetime' => 2,
            'deleted'  => 2,
            'text'     => 2,
        ],
        10 => [],
        11 => [],
        12 => [
            'type'    => 'mechanical',
            'year'    => 1900,
            'deleted' => null,
        ],
        13 => [],
    ];

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
    }

    public function _after(IntegrationTester $I)
    {
        $this->container['db']->close();
    }

    public function testMetadataDatabaseIntrospection(IntegrationTester $I)
    {
        $this->setDiMysql();
        $this->container['modelsMetadata'] = function () {
            $metaData = new Memory();
            $metaData->setStrategy(new Introspection());

            return $metaData;
        };

        $metaData = $this->container['modelsMetadata'];

        $robots = new Robots();
        $meta   = $metaData->readMetaData($robots);
        $I->assertEquals($meta, $this->meta);

        $meta = $metaData->readMetaData($robots);
        $I->assertEquals($meta, $this->meta);
    }

    public function testMetadataAnnotations(IntegrationTester $I)
    {
        $this->setDiMysql();
        $this->container['modelsMetadata'] = function () {
            $metaData = new Memory();
            $metaData->setStrategy(new Annotations());

            return $metaData;
        };

        $metaData = $this->container['modelsMetadata'];

        $robots = new BoutiqueRobots();

        $meta = $metaData->readMetaData($robots);
        $I->assertEquals($meta, $this->meta);

        $meta = $metaData->readMetaData($robots);
        $I->assertEquals($meta, $this->meta);
    }
}
