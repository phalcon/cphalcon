<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Model;

use IntegrationTester;
use Phalcon\Mvc\Model\Manager;
use Phalcon\Mvc\Model\Row;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\AlbumORama\Albums;
use Phalcon\Test\Models\AlbumORama\Artists;
use Phalcon\Test\Models\Customers;
use Phalcon\Test\Models\Relations\RobotsParts;
use Phalcon\Test\Models\Robots;

class ManagerCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDiMysql();
    }

    /**
     * Tests empty prefix for model
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/10328
     * @author Sid Roberts <sid@sidroberts.co.uk>
     * @since  2017-04-15
     */
    public function testShouldReturnSourceWithoutPrefix(IntegrationTester $I)
    {
        $robots = new Robots();

        $I->assertEquals('robots', $robots->getModelsManager()->getModelSource($robots));
        $I->assertEquals('robots', $robots->getSource());
    }

    /**
     * Tests non-empty prefix for model
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/10328
     * @author Sid Roberts <sid@sidroberts.co.uk>
     * @since  2017-04-15
     */
    public function testShouldReturnSourceWithPrefix(IntegrationTester $I)
    {
        $manager = new Manager();
        $manager->setModelPrefix('wp_');

        $robots = new Robots(null, null, $manager);

        $I->assertEquals('wp_robots', $robots->getModelsManager()->getModelSource($robots));
        $I->assertEquals('wp_robots', $robots->getSource());
    }

    public function testAliasedNamespacesRelations(IntegrationTester $I)
    {
        $I->skipTest('TODO - Check test');
        $manager = $this->getService('modelsManager');
        $manager->registerNamespaceAlias('AlbumORama', 'Phalcon\Test\Models\AlbumORama');

        $expected = ['AlbumORama' => 'Phalcon\Test\Models\AlbumORama'];
        $actual   = $manager->getNamespaceAliases();
        $I->assertEquals($expected, $actual);

        foreach (Albums::find() as $album) {
            $I->assertInstanceOf(Artists::class, $album->artist);
        }
    }

    /**
     * Tests Model::getRelated with the desired fields
     *
     * @test
     * @issue  https://github.com/phalcon/cphalcon/issues/12972
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-10-02
     */
    public function shouldReturnDesiredFieldsFromRelatedModel(IntegrationTester $I)
    {
        $I->skipTest('TODO - Check test');
        $parts = RobotsParts::findFirst();

        $robot = $parts->getRobots();

        $I->assertInstanceOf(Row::class, $robot);
        $I->assertEquals(['id' => 1, 'name' => 'Robotina'], $robot->toArray());

        $robot = $parts->getRobots(['columns' => 'id,type,name']);

        $I->assertInstanceOf(Row::class, $robot);
        $I->assertEquals(['id' => 1, 'type' => 'mechanical', 'name' => 'Robotina'], $robot->toArray());
    }

    /**
     * Tests Manager::isVisibleModelProperty
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-08-12
     */
    public function testModelPublicProperties(IntegrationTester $I)
    {
        $manager  = $this->getService('modelsManager');
        $examples = [
            ['id', true],
            ['document_id', true],
            ['customer_id', true],
            ['first_name', true],
            ['some_field', false],
            ['', false],
            ['protected_field', false],
            ['private_field', false],
        ];
        foreach ($examples as $item) {
            $property = $item[0];
            $expected = $item[1];
            $actual   = $manager->isVisibleModelProperty(new Customers, $property);
            $I->assertEquals($expected, $actual);
        }
    }
}
