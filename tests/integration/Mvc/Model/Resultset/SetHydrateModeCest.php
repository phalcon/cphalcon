<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Model\Resultset;

use IntegrationTester;
use Phalcon\Mvc\Model;
use Phalcon\Mvc\Model\Resultset;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\People;
use Phalcon\Test\Models\Personers;
use Phalcon\Test\Models\Robots;
use Phalcon\Test\Models\Robotters;

class SetHydrateModeCest
{
    use DiTrait;

    /**
     * @param IntegrationTester $I
     */
    public function _before(IntegrationTester $I)
    {
        $this->newFactoryDefault();
    }

    /**
     * Tests Phalcon\Mvc\Model\Resultset :: setHydrateMode() - mysql
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelResultsetSetHydrateModeMysql(IntegrationTester $I)
    {
        $message = 'Mvc\Model\Resultset - setHydrateMode() - Mysql';
        $this->setDiMysql();

        $this->executeTestsNormal($I, $message);
        $this->executeTestsNormalCastHydrate($I, $message);
        $this->executeTestsRenamed($I, $message);
        $this->executeTestsRenamedCastHydrate($I, $message);
        $this->executeTestsNormalComplex($I, $message);
        $this->executeTestsNormalComplexCastHydrate($I, $message);
    }

    /**
     * @param IntegrationTester $I
     * @param string            $message
     */
    private function executeTestsNormal(IntegrationTester $I, string $message)
    {
        $I->skipTest('TODO = Check the numbers');
        $I->wantToTest($message . ' - normal');
        $number = 0;
        $robots = Robots::find();

        foreach ($robots as $robot) {
            $I->assertInternalType('object', $robot);
            $I->assertInstanceOf('Phalcon\Test\Models\Robots', $robot);
            $number++;
        }

        $robots->setHydrateMode(Resultset::HYDRATE_RECORDS);
        foreach ($robots as $robot) {
            $I->assertInternalType('object', $robot);
            $I->assertInstanceOf('Phalcon\Test\Models\Robots', $robot);
            $number++;
        }

        $robots->setHydrateMode(Resultset::HYDRATE_ARRAYS);
        foreach ($robots as $robot) {
            $I->assertInternalType('array', $robot);
            $I->assertCount(7, $robot);
            $number++;
        }

        $robots->setHydrateMode(Resultset::HYDRATE_OBJECTS);
        foreach ($robots as $robot) {
            $I->assertInternalType('object', $robot);
            $I->assertInstanceOf('stdClass', $robot);
            $number++;
        }

        $I->assertEquals($number, 12);

        $number = 0;

        $people = People::find(['limit' => 33]);

        foreach ($people as $person) {
            $I->assertInternalType('object', $person);
            $I->assertInstanceOf('Phalcon\Test\Models\People', $person);
            $number++;
        }

        $people->setHydrateMode(Resultset::HYDRATE_RECORDS);
        foreach ($people as $person) {
            $I->assertInternalType('object', $person);
            $I->assertInstanceOf('Phalcon\Test\Models\People', $person);
            $number++;
        }

        $people->setHydrateMode(Resultset::HYDRATE_ARRAYS);
        foreach ($people as $person) {
            $I->assertInternalType('array', $person);
            $number++;
        }

        $people->setHydrateMode(Resultset::HYDRATE_OBJECTS);
        foreach ($people as $person) {
            $I->assertInternalType('object', $person);
            $I->assertInstanceOf('stdClass', $person);
            $number++;
        }

        $I->assertEquals($number, 33 * 4);
    }

    /**
     * @param IntegrationTester $I
     * @param string            $message
     */
    private function executeTestsNormalCastHydrate(IntegrationTester $I, string $message)
    {
        $I->wantToTest($message . ' - normal castOnHydrate');
        Model::setup(['castOnHydrate' => true]);

        $number = 0;

        $robots = Robots::find();

        foreach ($robots as $robot) {
            $I->assertInternalType('object', $robot);
            $I->assertInstanceOf('Phalcon\Test\Models\Robots', $robot);
            $number++;
        }

        $robots->setHydrateMode(Resultset::HYDRATE_RECORDS);
        foreach ($robots as $robot) {
            $I->assertInternalType('object', $robot);
            $I->assertInstanceOf('Phalcon\Test\Models\Robots', $robot);
            $number++;
        }

        $robots->setHydrateMode(Resultset::HYDRATE_ARRAYS);
        foreach ($robots as $robot) {
            $I->assertInternalType('array', $robot);
            $I->assertCount(7, $robot);
            $number++;
        }

        $robots->setHydrateMode(Resultset::HYDRATE_OBJECTS);
        foreach ($robots as $robot) {
            $I->assertInternalType('object', $robot);
            $I->assertInstanceOf('stdClass', $robot);
            $number++;
        }

        $I->assertEquals($number, 12);

        $number = 0;

        $people = People::find(['limit' => 33]);

        foreach ($people as $person) {
            $I->assertInternalType('object', $person);
            $I->assertInstanceOf('Phalcon\Test\Models\People', $person);
            $number++;
        }

        $people->setHydrateMode(Resultset::HYDRATE_RECORDS);
        foreach ($people as $person) {
            $I->assertInternalType('object', $person);
            $I->assertInstanceOf('Phalcon\Test\Models\People', $person);
            $number++;
        }

        $people->setHydrateMode(Resultset::HYDRATE_ARRAYS);
        foreach ($people as $person) {
            $I->assertInternalType('array', $person);
            $number++;
        }

        $people->setHydrateMode(Resultset::HYDRATE_OBJECTS);
        foreach ($people as $person) {
            $I->assertInternalType('object', $person);
            $I->assertInstanceOf('stdClass', $person);
            $number++;
        }

        $I->assertEquals($number, 33 * 4);

        Model::setup(['castOnHydrate' => false]);
    }

    /**
     * @param IntegrationTester $I
     * @param string            $message
     */
    private function executeTestsRenamed(IntegrationTester $I, string $message)
    {
        $I->wantToTest($message . ' - renamed');
        $number = 0;

        $robots = Robotters::find();

        foreach ($robots as $robot) {
            $I->assertInternalType('object', $robot);
            $I->assertInstanceOf('Phalcon\Test\Models\Robotters', $robot);
            $number++;
        }

        $robots->setHydrateMode(Resultset::HYDRATE_RECORDS);
        foreach ($robots as $robot) {
            $I->assertInternalType('object', $robot);
            $I->assertInstanceOf('Phalcon\Test\Models\Robotters', $robot);
            $number++;
        }

        $robots->setHydrateMode(Resultset::HYDRATE_ARRAYS);
        foreach ($robots as $robot) {
            $I->assertInternalType('array', $robot);
            $I->assertCount(7, $robot);
            $number++;
        }

        $robots->setHydrateMode(Resultset::HYDRATE_OBJECTS);
        foreach ($robots as $robot) {
            $I->assertInternalType('object', $robot);
            $I->assertInstanceOf('stdClass', $robot);
            $number++;
        }

        $I->assertEquals($number, 12);

        $number = 0;

        $people = Personers::find(['limit' => 33]);

        foreach ($people as $person) {
            $I->assertInternalType('object', $person);
            $I->assertInstanceOf('Phalcon\Test\Models\Personers', $person);
            $number++;
        }

        $people->setHydrateMode(Resultset::HYDRATE_RECORDS);
        foreach ($people as $person) {
            $I->assertInternalType('object', $person);
            $I->assertInstanceOf('Phalcon\Test\Models\Personers', $person);
            $number++;
        }

        $people->setHydrateMode(Resultset::HYDRATE_ARRAYS);

        foreach ($people as $person) {
            $I->assertInternalType('array', $person);
            $I->assertTrue(isset($person['navnes']));
            $number++;
        }

        $people->setHydrateMode(Resultset::HYDRATE_OBJECTS);
        foreach ($people as $person) {
            $I->assertInternalType('object', $person);
            $I->assertInstanceOf('stdClass', $person);
            $I->assertTrue(isset($person->navnes));
            $number++;
        }

        $I->assertEquals($number, 33 * 4);
    }

    /**
     * @param IntegrationTester $I
     * @param string            $message
     */
    private function executeTestsRenamedCastHydrate(IntegrationTester $I, string $message)
    {
        $I->wantToTest($message . ' - renamed castOnHydrate');

        Model::setup(['castOnHydrate' => true]);

        $number = 0;

        $robots = Robotters::find();

        foreach ($robots as $robot) {
            $I->assertInternalType('object', $robot);
            $I->assertInstanceOf('Phalcon\Test\Models\Robotters', $robot);
            $number++;
        }

        $robots->setHydrateMode(Resultset::HYDRATE_RECORDS);
        foreach ($robots as $robot) {
            $I->assertInternalType('object', $robot);
            $I->assertInstanceOf('Phalcon\Test\Models\Robotters', $robot);
            $number++;
        }

        $robots->setHydrateMode(Resultset::HYDRATE_ARRAYS);
        foreach ($robots as $robot) {
            $I->assertInternalType('array', $robot);
            $I->assertCount(7, $robot);
            $number++;
        }

        $robots->setHydrateMode(Resultset::HYDRATE_OBJECTS);
        foreach ($robots as $robot) {
            $I->assertInternalType('object', $robot);
            $I->assertInstanceOf('stdClass', $robot);
            $number++;
        }

        $I->assertEquals($number, 12);

        $number = 0;

        $people = Personers::find(['limit' => 33]);

        foreach ($people as $person) {
            $I->assertInternalType('object', $person);
            $I->assertInstanceOf('Phalcon\Test\Models\Personers', $person);
            $number++;
        }

        $people->setHydrateMode(Resultset::HYDRATE_RECORDS);
        foreach ($people as $person) {
            $I->assertInternalType('object', $person);
            $I->assertInstanceOf('Phalcon\Test\Models\Personers', $person);
            $number++;
        }

        $people->setHydrateMode(Resultset::HYDRATE_ARRAYS);

        foreach ($people as $person) {
            $I->assertInternalType('array', $person);
            $I->assertTrue(isset($person['navnes']));
            $number++;
        }

        $people->setHydrateMode(Resultset::HYDRATE_OBJECTS);
        foreach ($people as $person) {
            $I->assertInternalType('object', $person);
            $I->assertInstanceOf('stdClass', $person);
            $I->assertTrue(isset($person->navnes));
            $number++;
        }

        $I->assertEquals($number, 33 * 4);

        Model::setup(['castOnHydrate' => false]);
    }

    /**
     * @param IntegrationTester $I
     * @param string            $message
     */
    private function executeTestsNormalComplex(IntegrationTester $I, string $message)
    {
        $I->wantToTest($message . ' - normal complex');
        $I->skipTest('TODO - check relationships');
        $container = $this->getDi();
        $manager   = $container->get('modelsManager');
        $result    = $manager
            ->executeQuery('SELECT id FROM Phalcon\Test\Models\Robots');

        //Scalar complex query
        foreach ($result as $row) {
            $I->assertInstanceOf('Phalcon\Mvc\Model\Row', $row);
            $I->assertInternalType('numeric', $row->id);
        }

        $result->setHydrateMode(Resultset::HYDRATE_RECORDS);
        foreach ($result as $row) {
            $I->assertInstanceOf('Phalcon\Mvc\Model\Row', $row);
            $I->assertInternalType('numeric', $row->id);
        }

        $result->setHydrateMode(Resultset::HYDRATE_ARRAYS);
        foreach ($result as $row) {
            $I->assertInternalType('array', $row);
            $I->assertInternalType('numeric', $row['id']);
        }

        $result->setHydrateMode(Resultset::HYDRATE_OBJECTS);
        foreach ($result as $row) {
            $I->assertInstanceOf('stdClass', $row);
            $I->assertInternalType('numeric', $row->id);
        }

        //Complex resultset including scalars and complete objects
        $result = $manager
            ->executeQuery(
                'SELECT Phalcon\Test\Models\Robots.id, ' .
                'Phalcon\Test\Models\Robots.*, ' .
                'Phalcon\Test\Models\RobotsParts.* ' .
                'FROM Phalcon\Test\Models\Robots ' .
                'JOIN Phalcon\Test\Models\RobotsParts'
            );
        foreach ($result as $row) {
            $I->assertInstanceOf('Phalcon\Mvc\Model\Row', $row);
            $I->assertInternalType('numeric', $row->id);
            $I->assertInternalType('object', $row->robots);
            $I->assertInstanceOf('Phalcon\Test\Models\Robots', $row->robots);
            $I->assertInternalType('object', $row->robotsParts);
            $I->assertInstanceOf('Phalcon\Test\Models\RobotsParts', $row->robotsParts);
        }

        $result->setHydrateMode(Resultset::HYDRATE_RECORDS);
        foreach ($result as $row) {
            $I->assertInstanceOf('Phalcon\Mvc\Model\Row', $row);
            $I->assertInternalType('numeric', $row->id);
            $I->assertInternalType('object', $row->robots);
            $I->assertInstanceOf('Phalcon\Test\Models\Robots', $row->robots);
            $I->assertInternalType('object', $row->robotsParts);
            $I->assertInstanceOf('Phalcon\Test\Models\RobotsParts', $row->robotsParts);
        }

        $result->setHydrateMode(Resultset::HYDRATE_ARRAYS);
        foreach ($result as $row) {
            $I->assertInternalType('array', $row);
            $I->assertInternalType('numeric', $row['id']);
            $I->assertInternalType('array', $row['robots']);
            $I->assertCount(7, $row['robots']);
            $I->assertInternalType('array', $row['robotsParts']);
            $I->assertCount(3, $row['robotsParts']);
        }

        $result->setHydrateMode(Resultset::HYDRATE_OBJECTS);
        foreach ($result as $row) {
            $I->assertInstanceOf('stdClass', $row);
            $I->assertInternalType('numeric', $row->id);
            $I->assertInternalType('object', $row->robots);
            $I->assertInstanceOf('stdClass', $row->robots);
            $I->assertInternalType('object', $row->robotsParts);
            $I->assertInstanceOf('stdClass', $row->robotsParts);
        }
    }

    /**
     * @param IntegrationTester $I
     * @param string            $message
     */
    private function executeTestsNormalComplexCastHydrate(IntegrationTester $I, string $message)
    {
        $I->wantToTest($message . ' - castOnHydrate');
        Model::setup(['castOnHydrate' => true]);

        $container = $this->getDi();
        $manager   = $container->get('modelsManager');
        $result    = $manager
            ->executeQuery('SELECT id FROM Phalcon\Test\Models\Robots');

        //Scalar complex query
        foreach ($result as $row) {
            $I->assertInstanceOf('Phalcon\Mvc\Model\Row', $row);
            $I->assertInternalType('numeric', $row->id);
        }

        $result->setHydrateMode(Resultset::HYDRATE_RECORDS);
        foreach ($result as $row) {
            $I->assertInstanceOf('Phalcon\Mvc\Model\Row', $row);
            $I->assertInternalType('numeric', $row->id);
        }

        $result->setHydrateMode(Resultset::HYDRATE_ARRAYS);
        foreach ($result as $row) {
            $I->assertInternalType('array', $row);
            $I->assertInternalType('numeric', $row['id']);
        }

        $result->setHydrateMode(Resultset::HYDRATE_OBJECTS);
        foreach ($result as $row) {
            $I->assertInstanceOf('stdClass', $row);
            $I->assertInternalType('numeric', $row->id);
        }

        // Complex resultset including scalars and complete objects
        $result = $manager
            ->executeQuery(
                'SELECT Phalcon\Test\Models\Robots.id, ' .
                'Phalcon\Test\Models\Robots.*, ' .
                'Phalcon\Test\Models\RobotsParts.* ' .
                'FROM Phalcon\Test\Models\Robots ' .
                'JOIN Phalcon\Test\Models\RobotsParts'
            );
        foreach ($result as $row) {
            $I->assertInstanceOf('Phalcon\Mvc\Model\Row', $row);
            $I->assertInternalType('numeric', $row->id);
            $I->assertInternalType('object', $row->robots);
            $I->assertInstanceOf('Phalcon\Test\Models\Robots', $row->robots);
            $I->assertInternalType('object', $row->robotsParts);
            $I->assertInstanceOf('Phalcon\Test\Models\RobotsParts', $row->robotsParts);
        }

        $result->setHydrateMode(Resultset::HYDRATE_RECORDS);
        foreach ($result as $row) {
            $I->assertInstanceOf('Phalcon\Mvc\Model\Row', $row);
            $I->assertInternalType('numeric', $row->id);
            $I->assertInternalType('object', $row->robots);
            $I->assertInstanceOf('Phalcon\Test\Models\Robots', $row->robots);
            $I->assertInternalType('object', $row->robotsParts);
            $I->assertInstanceOf('Phalcon\Test\Models\RobotsParts', $row->robotsParts);
        }

        $result->setHydrateMode(Resultset::HYDRATE_ARRAYS);
        foreach ($result as $row) {
            $I->assertInternalType('array', $row);
            $I->assertInternalType('numeric', $row['id']);
            $I->assertInternalType('array', $row['robots']);
            $I->assertCount(7, $row['robots']);
            $I->assertInternalType('array', $row['robotsParts']);
            $I->assertCount(3, $row['robotsParts']);
        }

        $result->setHydrateMode(Resultset::HYDRATE_OBJECTS);
        foreach ($result as $row) {
            $I->assertInstanceOf('stdClass', $row);
            $I->assertInternalType('numeric', $row->id);
            $I->assertInternalType('object', $row->robots);
            $I->assertInstanceOf('stdClass', $row->robots);
            $I->assertInternalType('object', $row->robotsParts);
            $I->assertInstanceOf('stdClass', $row->robotsParts);
        }

        Model::setup(['castOnHydrate' => false]);
    }

    /**
     * Tests Phalcon\Mvc\Model\Resultset :: setHydrateMode() - mysql
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelResultsetSetHydrateModePostgresql(IntegrationTester $I)
    {
        $message = 'Mvc\Model\Resultset - setHydrateMode() - Postgresql';
        $this->setDiPostgresql();

        $this->executeTestsNormal($I, $message);
        $this->executeTestsNormalCastHydrate($I, $message);
        $this->executeTestsRenamed($I, $message);
        $this->executeTestsRenamedCastHydrate($I, $message);
        $this->executeTestsNormalComplex($I, $message);
        $this->executeTestsNormalComplexCastHydrate($I, $message);
    }

    /**
     * Tests Phalcon\Mvc\Model\Resultset :: setHydrateMode() - Sqlite
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelResultsetSetHydrateModeSqlite(IntegrationTester $I)
    {
        $message = 'Mvc\Model\Resultset - setHydrateMode() - Sqlite';
        $this->setDiSqlite();

        $this->executeTestsNormal($I, $message);
        $this->executeTestsNormalCastHydrate($I, $message);
        $this->executeTestsRenamed($I, $message);
        $this->executeTestsRenamedCastHydrate($I, $message);
        $this->executeTestsNormalComplex($I, $message);
        $this->executeTestsNormalComplexCastHydrate($I, $message);
    }
}
