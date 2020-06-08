<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Database\Validation\Validator;

use DatabaseTester;
use Phalcon\Paginator\Exception;
use Phalcon\Test\Fixtures\Migrations\ObjectsMigration;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Objects;
use Phalcon\Test\Models\ObjectsWithColumnMap;
use Phalcon\Validation;
use Phalcon\Validation\Validator\Uniqueness;

class UniquenessCest
{
    use DiTrait;

    public function _before(DatabaseTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDatabase($I);

        /** @var PDO $connection */
        $connection = $I->getConnection();
        $migration  = new ObjectsMigration($connection);
        $migration->clear();
    }

    /**
     * Tests Phalcon\Validation\Validator\Uniqueness with single fields
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @author Ruud Boon <https://github.com/ruudboon>
     * @since  2016-06-05
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */

    public function testSingleField(DatabaseTester $I)
    {
        $I->wantToTest('Tests Phalcon\Validation\Validator\Uniqueness with single fields');

        /** @var PDO $connection */
        $connection = $I->getConnection();
        $migration  = new ObjectsMigration($connection);
        $migration->insert(1, 'Phalcon', 1);

        $validation = new Validation();

        $validation->add(
            'obj_name',
            new Uniqueness()
        );

        $existing = new Objects();
        $existing->obj_name = "Phalcon";


        $messages = $validation->validate(null, $existing);

        $I->assertEquals(
            1,
            $messages->count()
        );

        $nonExisting = new Objects();
        $nonExisting->obj_name = "Not Phalcon";

        $messages = $validation->validate(null, $nonExisting);

        $I->assertEquals(
            0,
            $messages->count()
        );
    }

    /**
     * Tests Phalcon\Validation\Validator\Uniqueness with single fields and a converted value
     *
     * @author Bas Stottelaar <basstottelaar@gmail.com>
     * @author Ruud Boon <https://github.com/ruudboon>
     * @since  2016-07-25
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function testSingleFieldConvert(DatabaseTester $I)
    {
        $I->wantToTest('Tests Phalcon\Validation\Validator\Uniqueness with single fields and a converted value');

        /** @var PDO $connection */
        $connection = $I->getConnection();
        $migration  = new ObjectsMigration($connection);
        $migration->insert(1, 'Phalcon', 1);

        $validation = new Validation();

        $validation->add(
            'obj_name',
            new Uniqueness(
                [
                    'convert' => function (array $values) {
                        $values['obj_name'] = 'Not Phalcon'; // Phalcon -> Not Phalcon

                        return $values;
                    },
                ]
            )
        );

        $existing = new Objects();
        $existing->obj_name = "Phalcon";

        $messages = $validation->validate(null, $existing);

        $I->assertEquals(
            0,
            $messages->count()
        );
    }

    /**
     * Tests Phalcon\Validation\Validator\Uniqueness with multiple fields
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @author Ruud Boon <https://github.com/ruudboon>
     * @since  2016-06-05
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function testMultipleFields(DatabaseTester $I)
    {
        $I->wantToTest('Tests Phalcon\Validation\Validator\Uniqueness with multiple fields');

        /** @var PDO $connection */
        $connection = $I->getConnection();
        $migration  = new ObjectsMigration($connection);
        $migration->insert(1, 'Phalcon', 1);

        $validation = new Validation();

        $validation->add(
            ['obj_name', 'obj_type'],
            new Uniqueness()
        );

        // All values exist
        $existing = new Objects();
        $existing->obj_name = "Phalcon";
        $existing->obj_type = 1;

        $messages = $validation->validate(null, $existing);

        $I->assertEquals(
            1,
            $messages->count()
        );

        // All values don't exist
        $nonExisting = new Objects();
        $nonExisting->obj_name = "Not Phalcon";
        $nonExisting->obj_type = 2;

        $messages = $validation->validate(null, $nonExisting);

        $I->assertEquals(
            0,
            $messages->count()
        );

        // One int value exist
        $nonExisting = new Objects();
        $nonExisting->obj_name = "Not Phalcon";
        $nonExisting->obj_type = 1;

        $messages = $validation->validate(null, $nonExisting);

        $I->assertEquals(
            0,
            $messages->count()
        );

        // One string value exist
        $nonExisting = new Objects();
        $nonExisting->obj_name = "Phalcon";
        $nonExisting->obj_type = 2;

        $messages = $validation->validate(null, $nonExisting);

        $I->assertEquals(
            0,
            $messages->count()
        );
    }

    /**
     * Tests Phalcon\Validation\Validator\Uniqueness with multiple fields and a converted value
     *
     * @author Bas Stottelaar <basstottelaar@gmail.com>
     * @author Ruud Boon <https://github.com/ruudboon>
     * @since  2016-07-25
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function testMultipleFieldsConvert(DatabaseTester $I)
    {
        $I->wantToTest('Tests Phalcon\Validation\Validator\Uniqueness with multiple fields and a converted value');

        /** @var PDO $connection */
        $connection = $I->getConnection();
        $migration  = new ObjectsMigration($connection);
        $migration->insert(1, 'Phalcon', 1);

        $validation = new Validation();

        // All values exist
        $existing = new Objects();
        $existing->obj_name = "Phalcon";
        $existing->obj_type = 1;

        $validation->add(
            ['obj_name', 'obj_type'],
            new Uniqueness(
                [
                    'convert' => function (array $values) {
                        $values['obj_name'] = 'Not Phalcon'; // Phalcon -> Not Phalcon

                        return $values;
                    },
                ]
            )
        );


        $messages = $validation->validate(null, $existing);

        $I->assertEquals(
            0,
            $messages->count()
        );
    }

    /**
     * Tests Phalcon\Validation\Validator\Uniqueness with single field and except
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @author Ruud Boon <https://github.com/ruudboon>
     * @since  2016-06-05
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function testExceptSingleFieldSingleExcept(DatabaseTester $I)
    {
        $I->wantToTest('Tests Phalcon\Validation\Validator\Uniqueness with single field and except');

        /** @var PDO $connection */
        $connection = $I->getConnection();
        $migration  = new ObjectsMigration($connection);
        $migration->insert(1, 'Phalcon 1', 1);
        $migration->insert(2, 'Phalcon 2', 2);
        $migration->insert(3, 'Phalcon 3', 3);

        $validation = new Validation();

        $validation->add(
            'obj_type',
            new Uniqueness(
                [
                    'except' => 1,
                ]
            )
        );


        // All values exist but allow duplicate due to except
        $existing = new Objects();
        $existing->obj_name = "Phalcon 1";
        $existing->obj_type = 1;

        $messages = $validation->validate(null, $existing);

        $I->assertEquals(
            0,
            $messages->count()
        );


        // All values exist
        $existing = new Objects();
        $existing->obj_name = "Phalcon 2";
        $existing->obj_type = 2;

        $messages = $validation->validate(null, $existing);

        $I->assertEquals(
            1,
            $messages->count()
        );
    }

    /**
     * Tests Phalcon\Validation\Validator\Uniqueness with single field and multiple except'
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @author Ruud Boon <https://github.com/ruudboon>
     * @since  2016-06-05
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function testExceptSingleFieldMultipleExcept(DatabaseTester $I)
    {
        $I->wantToTest('Tests Phalcon\Validation\Validator\Uniqueness with single field and multiple except');

        /** @var PDO $connection */
        $connection = $I->getConnection();
        $migration  = new ObjectsMigration($connection);
        $migration->insert(1, 'Phalcon 1', 1);
        $migration->insert(2, 'Phalcon 2', 2);
        $migration->insert(3, 'Phalcon 3', 3);

        $validation = new Validation();

        $validation->add(
            'obj_type',
            new Uniqueness(
                [
                    'except' => [1, 2],
                ]
            )
        );

        // All values exist but allow duplicate due to except
        $existing = new Objects();
        $existing->obj_name = "Phalcon 1";
        $existing->obj_type = 1;

        $messages = $validation->validate(null, $existing);

        $I->assertEquals(
            0,
            $messages->count()
        );

        // All values exist but allow duplicate due to except
        $existing = new Objects();
        $existing->obj_name = "Phalcon 2";
        $existing->obj_type = 2;

        $messages = $validation->validate(null, $existing);

        $I->assertEquals(
            0,
            $messages->count()
        );

        // All values exist
        $existing = new Objects();
        $existing->obj_name = "Phalcon 3";
        $existing->obj_type = 3;

        $messages = $validation->validate(null, $existing);

        $I->assertEquals(
            1,
            $messages->count()
        );
    }

    /**
     * Tests Phalcon\Validation\Validator\Uniqueness with multiple field and single except
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @author Ruud Boon <https://github.com/ruudboon>
     * @since  2016-06-05
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function testExceptMultipleFieldSingleExcept(DatabaseTester $I)
    {
        $I->wantToTest('Tests Phalcon\Validation\Validator\Uniqueness with multiple field and single except');

        /** @var PDO $connection */
        $connection = $I->getConnection();
        $migration  = new ObjectsMigration($connection);
        $migration->insert(1, 'Phalcon 1', 1);
        $migration->insert(2, 'Phalcon 2', 2);
        $migration->insert(3, 'Phalcon 3', 3);

        $validation = new Validation();

        $validation->add(
            ['obj_name', 'obj_type'],
            new Uniqueness(
                [
                    'except' => [
                        'obj_name' => 'Phalcon 2',
                        'obj_type' => 3,
                    ],
                ]
            )
        );


        // All values exist but allow duplicate due to except
        $existing = new Objects();
        $existing->obj_name = "Phalcon 2";
        $existing->obj_type = 3;

        $messages = $validation->validate(null, $existing);

        $I->assertEquals(
            0,
            $messages->count()
        );

        // All values exist but only name is on execpt
        $existing = new Objects();
        $existing->obj_name = "Phalcon 2";
        $existing->obj_type = 2;

        $messages = $validation->validate(null, $existing);

        $I->assertEquals(
            1,
            $messages->count()
        );

        // All values exist
        $existing = new Objects();
        $existing->obj_name = "Phalcon 1";
        $existing->obj_type = 1;

        $messages = $validation->validate(null, $existing);

        $I->assertEquals(
            1,
            $messages->count()
        );
    }

    /**
     * Tests Phalcon\Validation\Validator\Uniqueness with multiple field and except
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @author Ruud Boon <https://github.com/ruudboon>
     * @since  2016-06-05
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function testExceptMultipleFieldMultipleExcept(DatabaseTester $I)
    {
        $I->wantToTest('Tests Phalcon\Validation\Validator\Uniqueness with multiple field and except');

        /** @var PDO $connection */
        $connection = $I->getConnection();
        $migration  = new ObjectsMigration($connection);
        $migration->insert(1, 'Phalcon 1', 1);
        $migration->insert(2, 'Phalcon 2', 2);
        $migration->insert(3, 'Phalcon 3', 3);

        $validation = new Validation();

        $validation->add(
            ['obj_name', 'obj_type'],
            new Uniqueness(
                [
                    'except' => [
                        'obj_name' => ['Phalcon 1', 'Phalcon 2'],
                        'obj_type' => [1, 2],
                    ],
                ]
            )
        );

        // All values exist but allow duplicate due to except
        $existing = new Objects();
        $existing->obj_name = "Phalcon 1";
        $existing->obj_type = 1;

        $messages = $validation->validate(null, $existing);

        $I->assertEquals(
            0,
            $messages->count()
        );

        // All values exist
        $existing = new Objects();
        $existing->obj_name = "Phalcon 3";
        $existing->obj_type = 3;

        $messages = $validation->validate(null, $existing);

        $I->assertEquals(
            1,
            $messages->count()
        );
    }

    /**
     * Tests value conversion for returning an array.
     *
     * @author Bas Stottelaar <basstottelaar@gmail.com>
     * @since  2016-07-25
     */
    public function testConvertArrayReturnsArray(DatabaseTester $I)
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

        $I->expectThrowable(
            Exception::class,
            function () use ($validation) {
                $validation->validate(null, $this->robot);
            }
        );
    }


    /**
     * Tests issue 13398
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @author Ruud Boon <https://github.com/ruudboon>
     * @since  2018-06-13
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function testIssue13398(DatabaseTester $I)
    {

        /** @var PDO $connection */
        $connection = $I->getConnection();
        $migration  = new ObjectsMigration($connection);
        $migration->insert(1, 'Phalcon 1', 1);
        $migration->insert(2, 'Phalcon 2', 2);
        $migration->insert(3, 'Phalcon 3', 3);

        $validation = new Validation();

        $validation->add(
            'theName',
            new Uniqueness()
        );

        $object = ObjectsWithColumnMap::findFirst(1);


        $object->theName = 'Phalcon 2';

        $messages = $validation->validate(null, $object);

        $I->assertEquals(
            1,
            $messages->count()
        );


        $object->theName = 'Not Phalcon 1';

        $messages = $validation->validate(null, $object);

        $I->assertEquals(
            0,
            $messages->count()
        );
    }
}
