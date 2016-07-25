<?php

namespace Phalcon\Test\Unit\Validation\Validator;

use DateTime;
use Phalcon\Db\Adapter\Pdo;
use Phalcon\Di;
use Phalcon\Test\Models\Robots;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Validation;
use Phalcon\Validation\Validator\Uniqueness;

/**
 * \Phalcon\Test\Unit\Validation\Validator\UniquenessTest
 * Tests the \Phalcon\Validation\Validator\Uniqueness component
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @author    Wojciech Ślawski <jurigag@gmail.com>
 * @author    Bas Stottelaar <basstottelaar@gmail.com>
 * @package   Phalcon\Test\Unit\Validation\Validator
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class UniquenessTest extends UnitTest
{
    /**
     * @var Di
     */
    protected $di;

    /**
     * @var Robots
     */
    protected $robot;

    /**
     * @var Robots
     */
    protected $anotherRobot;

    /**
     * @var Robots
     */
    protected $deletedRobot;

    /**
     * Tests uniqueness validator with single fields
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testSingleField()
    {
        $this->specify('Test uniqueness with single field.', function () {
            $validation = new Validation();
            $validation->add('type', new Uniqueness());
            $messages = $validation->validate(null, $this->robot);
            expect($messages->count())->equals(1);
            $messages = $validation->validate(null, $this->anotherRobot);
            expect($messages->count())->equals(0);
        });
    }

    /**
     * Tests uniqueness validator with single fields and a converted value
     *
     * @author Bas Stottelaar <basstottelaar@gmail.com>
     * @since  2016-07-25
     */
    public function testSingleFieldConvert()
    {
        $this->specify('Test uniqueness with single field and a converted value.', function () {
            $validation = new Validation();
            $validation->add('type', new Uniqueness([
                'convert' => function (array $values) {
                    $values['type'] = 'hydraulic'; // mechanical -> hydraulic
                    return $values;
                }
            ]));
            $messages = $validation->validate(null, $this->robot);
            expect($messages->count())->equals(0);
        });
    }

    /**
     * Tests uniqueness validator with single field and a null value
     *
     * @author Bas Stottelaar <basstottelaar@gmail.com>
     * @since  2016-07-13
     */
    public function testSingleFieldWithNull()
    {
        $this->specify('Test uniqueness with single field and a null value.', function () {
            $validation = new Validation();
            $validation->add('deleted', new Uniqueness());
            $messages = $validation->validate(null, $this->robot);
            expect($messages->count())->equals(1);
            $messages = $validation->validate(null, $this->anotherRobot);
            expect($messages->count())->equals(1);
            $messages = $validation->validate(null, $this->deletedRobot);
            expect($messages->count())->equals(0);
        });
    }

    /**
     * Tests uniqueness validator with multiple fields
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testMultipleFields()
    {
        $this->specify('Test uniqueness with combination of fields.', function () {
            $validation = new Validation();
            $validation->add(['name', 'type'], new Uniqueness());
            $messages = $validation->validate(null, $this->robot);
            expect($messages->count())->equals(1);
            $messages = $validation->validate(null, $this->anotherRobot);
            expect($messages->count())->equals(0);
        });
    }

    /**
     * Tests uniqueness validator with multiple fields and a converted value
     *
     * @author Bas Stottelaar <basstottelaar@gmail.com>
     * @since  2016-07-25
     */
    public function testMultipleFieldsConvert()
    {
        $this->specify('Test uniqueness with combination of fields and a converted value.', function () {
            $validation = new Validation();
            $validation->add(['name', 'type'], new Uniqueness([
                'convert' => function (array $values) {
                    $values['type'] = 'hydraulic'; // mechanical -> hydraulic
                    return $values;
                }
            ]));
            $messages = $validation->validate(null, $this->robot);
            expect($messages->count())->equals(0);
        });
    }

    /**
     * Tests uniqueness validator with multiple fields and a null value
     *
     * @author Bas Stottelaar <basstottelaar@gmail.com>
     * @since  2016-07-13
     */
    public function testMultipleFieldsWithNull()
    {
        $this->specify('Test uniqueness with combination of fields and a null value.', function () {
            $validation = new Validation();
            $validation->add(['type','deleted'], new Uniqueness());
            $messages = $validation->validate(null, $this->robot);
            expect($messages->count())->equals(1);
            $messages = $validation->validate(null, $this->anotherRobot);
            expect($messages->count())->equals(0);
            $messages = $validation->validate(null, $this->deletedRobot);
            expect($messages->count())->equals(0);
        });
    }

    /**
     * Tests uniqueness validator with single field and except
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testExceptSingleFieldSingleExcept()
    {
        $this->specify('Test except option as single field and single value in uniqueness validator.', function () {
            $validation = new Validation();
            $validation->add('year', new Uniqueness([
                'except' => 1972,
            ]));
            $messages = $validation->validate(null, $this->robot);
            expect($messages->count())->equals(0);
            $messages = $validation->validate(null, $this->anotherRobot);
            expect($messages->count())->equals(1);
        });
    }

    /**
     * Tests uniqueness validator with single field and multiple except
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testExceptSingleFieldMultipleExcept()
    {
        $this->specify('Test except option as single field and array value in uniqueness validator.', function () {
            $validation = new Validation();
            $validation->add('year', new Uniqueness([
                'except' => [1972, 1952],
            ]));
            $messages = $validation->validate(null, $this->robot);
            expect($messages->count())->equals(0);
            $messages = $validation->validate(null, $this->anotherRobot);
            expect($messages->count())->equals(0);
        });
    }

    /**
     * Tests uniqueness validator with multiple field and single except
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testExceptMultipleFieldSingleExcept()
    {
        $this->specify('Test except option as combination of fields and single value in uniqueness validator.', function () {
            $validation = new Validation();
            $validation->add(['type', 'year'], new Uniqueness([
                'except' => [
                    'type' => 'mechanical',
                    'year' => 1972,
                ],
            ]));
            $messages = $validation->validate(null, $this->robot);
            expect($messages->count())->equals(0);
            $messages = $validation->validate(null, $this->anotherRobot);
            expect($messages->count())->equals(0);
        });
    }

    /**
     * Tests uniqueness validator with multiple field and except
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testExceptMultipleFieldMultipleExcept()
    {
        $this->specify('Test except option as combination of fields and single value in uniqueness validator.', function () {
            $validation = new Validation();
            $validation->add(['year', 'name'], new Uniqueness([
                'except' => [
                    'year' => [1942, 1972],
                    'type' => ['hydraulic', 'cyborg'],
                ],
            ]));
            $messages = $validation->validate(null, $this->robot);
            expect($messages->count())->equals(0);
            $messages = $validation->validate(null, $this->anotherRobot);
            expect($messages->count())->equals(0);
        });
    }

    /**
     * Tests value conversion for returning an array.
     *
     * @author Bas Stottelaar <basstottelaar@gmail.com>
     * @since  2016-07-25
     */
    public function testConvertArrayReturnsArray()
    {
        $this->specify('Test value conversion to return an array.', function () {
            $validation = new Validation();
            $validation->add('type', new Uniqueness([
                'convert' => function (array $values) {
                    ($values);
                    return null;
                }
            ]));
            try {
                $validation->validate(null, $this->robot);
                verify_that(false);
            } catch (\Exception $e) {
                verify_that(true);
            }
        });
    }

    /**
     * Initialize data for the tests
     */
    protected function _before()
    {
        parent::_before();
        $this->di = $this->tester->getApplication()->getDI();
        $this->robot = new Robots([
            'name' => 'Robotina',
            'type' => 'mechanical',
            'year' => 1972,
            'datetime' => (new DateTime())->format('Y-m-d H:i:s'),
            'deleted' => null,
            'text' => 'text',
        ]);
        $this->anotherRobot = new Robots([
            'name' => 'Robotina',
            'type' => 'hydraulic',
            'year' => 1952,
            'datetime' => (new DateTime())->format('Y-m-d H:i:s'),
            'deleted' => null,
            'text' => 'text',
        ]);
        $this->deletedRobot = new Robots([
            'name' => 'Robotina',
            'type' => 'mechanical',
            'year' => 1972,
            'datetime' => (new DateTime())->format('Y-m-d H:i:s'),
            'deleted' => (new DateTime())->format('Y-m-d H:i:s'),
            'text' => 'text',
        ]);
    }
}
