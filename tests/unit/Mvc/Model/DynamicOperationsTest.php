<?php

namespace Phalcon\Test\Unit\Mvc\Model;

use Phalcon\Di;
use Helper\ModelTrait;
use Phalcon\Db\RawValue;
use Phalcon\DiInterface;
use Phalcon\Events\Event;
use Phalcon\Db\AdapterInterface;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Events\ManagerInterface;
use Helper\Db\Connection\MysqlFactory;
use Phalcon\Test\Models\Dynamic\Robots;
use Phalcon\Test\Models\Dynamic\Personas;
use Phalcon\Test\Models\Dynamic\Personers;
use Phalcon\Events\Manager as EventsManager;

/**
 * Phalcon\Test\Unit\Mvc\Model\DynamicOperationsTest
 * Tests the Phalcon\Mvc\Model component.
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @author    Wojciech Ślawski <jurigag@gmail.com>
 * @package   Phalcon\Test\Unit\Mvc\Model
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class DynamicOperationsTest extends UnitTest
{
    use ModelTrait;

    protected $oldDI;
    protected $tracer = [];

    /**
     * executed before each test
     */
    protected function _before()
    {
        parent::_before();

        $this->oldDI = Di::getDefault();
    }

    /**
     * executed after each test
     */
    protected function _after()
    {
        parent::_after();

        if ($this->oldDI instanceof DiInterface) {
            Di::reset();
            Di::setDefault($this->oldDI);
        }
    }

    /**
     * Tests dynamic update create then update
     *
     * @test
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @issue  https://github.com/phalcon/cphalcon/issues/12766
     * @since  2017-04-04
     */
    public function shouldSaveSnapshotWhenHavingPublicPropertyWithNullValue()
    {
        $this->specify(
            'Dynamic update does not work when model have a public property with null value',
            function () {
                $this->setUpConnectionAwareModelsManager(MysqlFactory::class);

                $robots = new Robots();
                $robots->name = 'Test';
                $robots->type = 'mechanical';
                $robots->datetime = (new \DateTime())->format('Y-m-d');
                $robots->text = 'text';

                expect($robots->create())->true();
                expect($robots->year)->null();

                $robots->year = date('Y');

                expect($robots->update())->true();
                expect($robots->year)->equals(date('Y'));

                expect($robots->delete())->true();
            }
        );
    }

    /**
     * Tests dynamic update with default use case.
     *
     * @test
     * @author Andres Gutierrez <andres@phalconphp.com>
     * @since  2013-03-01
     */
    public function shouldWorkUsingDynamicUpdate()
    {
        $this->specify(
            'Dynamic update does not work as expected',
            function () {
                $this->setUpConnectionAwareModelsManager(MysqlFactory::class);
                $this->setUpEventsManager();

                $persona = Personas::findFirst();
                expect($persona->save())->true();

                // For Personas::useDynamicUpdate(false)
                // ------------------------------------
                // 1. Check table
                // 2. Describe table
                // 3. Personas::findFirst
                // 4. Personas::save
                //
                // For Personas::useDynamicUpdate(true)
                // ------------------------------------
                // 1. Check table
                // 2. Describe table
                // 3. Personas::findFirst
                expect($this->tracer)->count(3);

                $persona->nombres = 'Other Name ' . mt_rand(0, 150000);

                expect($persona->getChangedFields())->equals(['nombres']);
                expect($persona->save())->true();
                expect('UPDATE `personas` SET `nombres` = ? WHERE `cedula` = ?')->equals($this->tracer[3]);

                $persona->nombres = 'Other Name ' . mt_rand(0, 150000);
                $persona->direccion = 'Address ' . mt_rand(0, 150000);

                expect($persona->getChangedFields())->equals(['nombres', 'direccion']);
                expect($persona->save())->true();
                expect('UPDATE `personas` SET `nombres` = ?, `direccion` = ? WHERE `cedula` = ?')->equals($this->tracer[4]);

                // Cleanup for future tests in this class
                $this->tracer = [];
            }
        );
    }

    /**
     * Tests dynamic update with renamed model fields.
     *
     * @test
     * @author Andres Gutierrez <andres@phalconphp.com>
     * @since  2013-03-01
     */
    public function shouldWorkUsingDynamicUpdateForRenamedModelFields()
    {
        $this->specify(
            'Dynamic update for renamed model fields does not work as expected',
            function () {
                $this->setUpConnectionAwareModelsManager(MysqlFactory::class);
                $this->setUpEventsManager();

                $persona = Personers::findFirst();
                expect($persona->save())->true();

                // For Personers::useDynamicUpdate(false)
                // ------------------------------------
                // 1. Check table
                // 2. Describe table
                // 3. Personas::findFirst
                // 4. Personas::save
                //
                // For Personers::useDynamicUpdate(true)
                // ------------------------------------
                // 1. Check table
                // 2. Describe table
                // 3. Personas::findFirst
                expect($this->tracer)->count(3);

                $persona->navnes = 'Other Name ' . mt_rand(0, 150000);

                expect($persona->getChangedFields())->equals(['navnes']);
                expect($persona->save())->true();
                expect('UPDATE `personas` SET `nombres` = ? WHERE `cedula` = ?')->equals($this->tracer[3]);

                $persona->navnes = 'Other Name ' . mt_rand(0, 150000);
                $persona->adresse = 'Address ' . mt_rand(0, 150000);

                expect($persona->getChangedFields())->equals(['navnes', 'adresse']);
                expect($persona->save())->true();
                expect('UPDATE `personas` SET `nombres` = ?, `direccion` = ? WHERE `cedula` = ?')->equals($this->tracer[4]);

                // Cleanup for future tests in this class
                $this->tracer = [];
            }
        );
    }

    /**
     * Tests dynamic update soft delete with renamed model.
     *
     * @test
     * @author limx <715557344@qq.com>
     * @since  2018-02-24
     */
    public function shouldWorkUsingDynamicUpdateSoftDeleteForRenamedModel()
    {
        $this->specify(
            'Dynamic update soft delete for renamed model does not work as expected',
            function () {
                $this->setUpConnectionAwareModelsManager(MysqlFactory::class);
                $this->setUpEventsManager();

                $persona = Personers::findFirst();
                expect($persona->delete())->true();
                expect($persona->status)->equals('X');
            }
        );
    }

    /**
     * Tests dynamic update and rawvalue
     *
     * @test
     * @author limingxinleo <715557344@qq.com>
     * @issue  https://github.com/phalcon/cphalcon/issues/13170
     * @since  2017-11-20
     */
    public function shouldWorkUsingDynamicUpdateForRawValue()
    {
        $this->specify(
            'Dynamic update does not work as expected for fields which raw values were assigned to',
            function () {
                $robot = new Robots();
                $robot->name = 'Test';
                $robot->type = 'mechanical';
                $robot->datetime = (new \DateTime())->format('Y-m-d');
                $robot->text = 'text';
                $robot->year = 1;
                $robot->save();

                $robot = Robots::findFirst([
                    'conditions' => 'year = ?0',
                    'bind'       => [1]
                ]);

                $robot->year = new RawValue('year + 1');
                expect($robot->save())->true();

                $robot = Robots::findFirst($robot->id);
                expect($robot->year)->equals(2);
            }
        );
    }

    /**
     * Setting up the Events Manager.
     *
     * @return void
     */
    protected function setUpEventsManager()
    {
        if (!Di::getDefault()->has('eventsManager')) {
            $eventsManager = new EventsManager();
        } else {
            $eventsManager = Di::getDefault()->get('eventsManager');
            expect($eventsManager)->isInstanceOf(ManagerInterface::class);
        }

        $that = $this;

        $eventsManager->attach(
            'db',
            function (Event $event, AdapterInterface $connection) use ($that) {
                if ($event->getType() == 'beforeQuery') {
                    $that->tracer[] = $connection->getSqlStatement();
                }
            }
        );

        $connection = Di::getDefault()->get('db');
        expect($connection)->isInstanceOf(AdapterInterface::class);

        $connection->setEventsManager($eventsManager);
    }

    /**
     * Setting up the Models Manager.
     *
     * @param string $connection
     * @return void
     */
    protected function setUpConnectionAwareModelsManager($connection)
    {
        $factory = new $connection();
        $this->setUpModelsManager($factory->createConnection());
    }
}
