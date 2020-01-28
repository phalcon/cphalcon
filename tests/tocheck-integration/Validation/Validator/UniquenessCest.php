<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Validation\Validator;

use Exception;
use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Robots;
use Phalcon\Test\Models\Some\Robotters;
use Phalcon\Validation;
use Phalcon\Validation\Validator\Uniqueness;

use function date;

class UniquenessCest
{
    use DiTrait;

    /**
     * @var Robots
     */
    private $robot;

    /**
     * @var Robots
     */
    private $anotherRobot;

    /**
     * @var Robots
     */
    private $deletedRobot;

    /**
     * @throws Exception
     */
    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDiMysql();

        $this->robot = new Robots(
            [
                'name'     => 'Robotina',
                'type'     => 'mechanical',
                'year'     => 1972,
                'datetime' => date('Y-m-d H:i:s'),
                'deleted'  => null,
                'text'     => 'text',
            ]
        );

        $this->anotherRobot = new Robots(
            [
                'name'     => 'Robotina',
                'type'     => 'hydraulic',
                'year'     => 1952,
                'datetime' => date('Y-m-d H:i:s'),
                'deleted'  => null,
                'text'     => 'text',
            ]
        );

        $this->deletedRobot = new Robots(
            [
                'name'     => 'Robotina',
                'type'     => 'mechanical',
                'year'     => 1972,
                'datetime' => date('Y-m-d H:i:s'),
                'deleted'  => date('Y-m-d H:i:s'),
                'text'     => 'text',
            ]
        );
    }

    public function _after(IntegrationTester $I)
    {
        $this->container['db']->close();
    }

    /**
     * Tests uniqueness validator with single fields
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testSingleField(IntegrationTester $I)
    {
        $validation = new Validation();

        $validation->add(
            'type',
            new Uniqueness()
        );


        $messages = $validation->validate(null, $this->robot);

        $I->assertEquals(
            1,
            $messages->count()
        );


        $messages = $validation->validate(null, $this->anotherRobot);

        $I->assertEquals(
            0,
            $messages->count()
        );
    }

    /**
     * Tests uniqueness validator with single fields and a converted value
     *
     * @author Bas Stottelaar <basstottelaar@gmail.com>
     * @since  2016-07-25
     */
    public function testSingleFieldConvert(IntegrationTester $I)
    {
        $validation = new Validation();

        $validation->add(
            'type',
            new Uniqueness(
                [
                    'convert' => function (array $values) {
                        $values['type'] = 'hydraulic'; // mechanical -> hydraulic

                        return $values;
                    },
                ]
            )
        );


        $messages = $validation->validate(null, $this->robot);

        $I->assertEquals(
            0,
            $messages->count()
        );
    }

    /**
     * Tests uniqueness validator with single field and a null value
     *
     * @author Bas Stottelaar <basstottelaar@gmail.com>
     * @since  2016-07-13
     */
    public function testSingleFieldWithNull(IntegrationTester $I)
    {
        $validation = new Validation();

        $validation->add(
            'deleted',
            new Uniqueness()
        );


        $messages = $validation->validate(null, $this->robot);

        $I->assertEquals(
            1,
            $messages->count()
        );


        $messages = $validation->validate(null, $this->anotherRobot);

        $I->assertEquals(
            1,
            $messages->count()
        );


        $messages = $validation->validate(null, $this->deletedRobot);

        $I->assertEquals(
            0,
            $messages->count()
        );
    }

    /**
     * Tests uniqueness validator with multiple fields
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testMultipleFields(IntegrationTester $I)
    {
        $validation = new Validation();

        $validation->add(
            ['name', 'type'],
            new Uniqueness()
        );


        $messages = $validation->validate(null, $this->robot);

        $I->assertEquals(
            1,
            $messages->count()
        );


        $messages = $validation->validate(null, $this->anotherRobot);

        $I->assertEquals(
            0,
            $messages->count()
        );
    }

    /**
     * Tests uniqueness validator with multiple fields and a converted value
     *
     * @author Bas Stottelaar <basstottelaar@gmail.com>
     * @since  2016-07-25
     */
    public function testMultipleFieldsConvert(IntegrationTester $I)
    {
        $validation = new Validation();

        $validation->add(
            ['name', 'type'],
            new Uniqueness(
                [
                    'convert' => function (array $values) {
                        $values['type'] = 'hydraulic'; // mechanical -> hydraulic

                        return $values;
                    },
                ]
            )
        );


        $messages = $validation->validate(null, $this->robot);

        $I->assertEquals(
            0,
            $messages->count()
        );
    }

    /**
     * Tests uniqueness validator with multiple fields and a null value
     *
     * @author Bas Stottelaar <basstottelaar@gmail.com>
     * @since  2016-07-13
     */
    public function testMultipleFieldsWithNull(IntegrationTester $I)
    {
        $validation = new Validation();

        $validation->add(
            ['type', 'deleted'],
            new Uniqueness()
        );


        $messages = $validation->validate(null, $this->robot);

        $I->assertEquals(
            1,
            $messages->count()
        );

        $messages = $validation->validate(null, $this->anotherRobot);

        $I->assertEquals(
            0,
            $messages->count()
        );

        $messages = $validation->validate(null, $this->deletedRobot);

        $I->assertEquals(
            0,
            $messages->count()
        );
    }

    /**
     * Tests uniqueness validator with single field and except
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testExceptSingleFieldSingleExcept(IntegrationTester $I)
    {
        $validation = new Validation();

        $validation->add(
            'year',
            new Uniqueness(
                [
                    'except' => 1972,
                ]
            )
        );


        $messages = $validation->validate(null, $this->robot);

        $I->assertEquals(
            0,
            $messages->count()
        );


        $messages = $validation->validate(null, $this->anotherRobot);

        $I->assertEquals(
            1,
            $messages->count()
        );
    }

    /**
     * Tests uniqueness validator with single field and multiple except
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testExceptSingleFieldMultipleExcept(IntegrationTester $I)
    {
        $validation = new Validation();

        $validation->add(
            'year',
            new Uniqueness(
                [
                    'except' => [1972, 1952],
                ]
            )
        );


        $messages = $validation->validate(null, $this->robot);

        $I->assertEquals(
            0,
            $messages->count()
        );


        $messages = $validation->validate(null, $this->anotherRobot);

        $I->assertEquals(
            0,
            $messages->count()
        );
    }

    /**
     * Tests uniqueness validator with multiple field and single except
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testExceptMultipleFieldSingleExcept(IntegrationTester $I)
    {
        $validation = new Validation();

        $validation->add(
            ['type', 'year'],
            new Uniqueness(
                [
                    'except' => [
                        'type' => 'mechanical',
                        'year' => 1972,
                    ],
                ]
            )
        );


        $messages = $validation->validate(null, $this->robot);

        $I->assertEquals(
            0,
            $messages->count()
        );


        $messages = $validation->validate(null, $this->anotherRobot);

        $I->assertEquals(
            0,
            $messages->count()
        );
    }

    /**
     * Tests uniqueness validator with multiple field and except
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testExceptMultipleFieldMultipleExcept(IntegrationTester $I)
    {
        $validation = new Validation();

        $validation->add(
            ['year', 'type'],
            new Uniqueness(
                [
                    'except' => [
                        'year' => [1952, 1972],
                        'type' => ['hydraulic', 'mechanical'],
                    ],
                ]
            )
        );


        $messages = $validation->validate(null, $this->robot);

        $I->assertEquals(
            0,
            $messages->count()
        );


        $messages = $validation->validate(null, $this->anotherRobot);

        $I->assertEquals(
            0,
            $messages->count()
        );
    }

    /**
     * Tests value conversion for returning an array.
     *
     * @author Bas Stottelaar <basstottelaar@gmail.com>
     * @since  2016-07-25
     */
    public function testConvertArrayReturnsArray(IntegrationTester $I)
    {
        $I->skipTest('TODO: Check the verify');

        $validation = new Validation();

        $validation->add(
            'type',
            new Uniqueness(
                [
                    'convert' => function (array $values) {
                        ($values);

                        return null;
                    },
                ]
            )
        );

        $I->expectException(
            Exception::class,
            function () use ($validation) {
                $validation->validate(null, $this->robot);
            }
        );
    }

    /**
     * Tests except other than field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-01-16
     */
    public function testExceptOtherThanField(IntegrationTester $I)
    {
        $validation = new Validation();

        $validation->add(
            'text',
            new Uniqueness(
                [
                    'except' => [
                        'type' => ['mechanical', 'cyborg'],
                    ],
                ]
            )
        );


        $messages = $validation->validate(null, $this->robot);

        $I->assertEquals(
            0,
            $messages->count()
        );


        $messages = $validation->validate(null, $this->anotherRobot);

        $I->assertEquals(
            0,
            $messages->count()
        );

        $anotherRobot = clone $this->anotherRobot;

        $this->anotherRobot->create();


        $messages = $validation->validate(null, $anotherRobot);

        $I->assertEquals(
            1,
            $messages->count()
        );

        $this->anotherRobot->delete();
    }

    /**
     * Tests issue 13398
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2018-06-13
     */
    public function testIssue13398(IntegrationTester $I)
    {
        $validation = new Validation();

        $validation->add(
            'theName',
            new Uniqueness()
        );

        $robot = Robotters::findFirst(1);


        $robot->theName = 'Astro Boy';

        $messages = $validation->validate(null, $robot);

        $I->assertEquals(
            1,
            $messages->count()
        );


        $robot->theName = 'Astro Boyy';

        $messages = $validation->validate(null, $robot);

        $I->assertEquals(
            0,
            $messages->count()
        );
    }
}
