<?php

namespace Phalcon\Test\Integration\Mvc\Model;

use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Cacheable\Parts;
use Phalcon\Test\Models\Cacheable\Robots;

use function cacheDir;

class ModelsResultsetCacheStaticCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();

        $I->cleanDir(
            cacheDir()
        );
    }

    public function _after(IntegrationTester $I)
    {
        $this->container['db']->close();
    }

    public function testOverrideStaticCache(IntegrationTester $I)
    {
        $this->setDiMysql();

        $this->getAndSetModelsCacheStream();

        $robot = Robots::findFirst(2);
        $I->assertInstanceOf(Robots::class, $robot);

        $robot = Robots::findFirst(2);
        $I->assertInstanceOf(Robots::class, $robot);

        $robot = Robots::findFirst(['id = 2']);
        $I->assertInstanceOf(Robots::class, $robot);

        $robot = Robots::findFirst(['id = 2']);
        $I->assertInstanceOf(Robots::class, $robot);

        $robot = Robots::findFirst(['order' => 'id DESC']);
        $I->assertInstanceOf(Robots::class, $robot);

        $robot = Robots::findFirst(['order' => 'id DESC']);
        $I->assertInstanceOf(Robots::class, $robot);

        $robot = Robots::findFirst(1);
        $I->assertInstanceOf(Robots::class, $robot);

        $robotParts = $robot->getRobotsParts();
        $I->assertInstanceOf(
            \Phalcon\Mvc\Model\Resultset\Simple::class,
            $robotParts
        );

        $robotParts = $robot->getRobotsParts();
        $I->assertInstanceOf(
            \Phalcon\Mvc\Model\Resultset\Simple::class,
            $robotParts
        );

        $part = $robotParts[0]->getParts();
        $I->assertInstanceOf(Parts::class, $part);

        $part = $robotParts[0]->getParts();
        $I->assertInstanceOf(Parts::class, $part);

        $robot = $robotParts[0]->getRobots();
        $I->assertInstanceOf(Robots::class, $robot);

        $robot = $robotParts[0]->getRobots();
        $I->assertInstanceOf(Robots::class, $robot);
    }
}
