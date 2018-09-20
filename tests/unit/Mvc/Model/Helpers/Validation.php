<?php

namespace Phalcon\Test\Unit\Mvc\Model\Helpers;

use Phalcon\Di;
use UnitTester;
use Phalcon\Db\RawValue;
use Phalcon\Mvc\Model\Message;
use Phalcon\Test\Models\Validation\Subscriptores;

class Validation
{
    protected function success(UnitTester $I)
    {
        /** @var \Phalcon\Di\FactoryDefault $di */
        $di = Di::getDefault();

        /** @var \Phalcon\Db\Adapter\Pdo\Mysql $connection */
        $connection = $di->getShared('db');

        $I->assertTrue($connection->delete('subscriptores'));

        $model = new Subscriptores();
        $I->assertTrue($model->save([
            'email'      => 'fuego@hotmail.com',
            'created_at' => new RawValue('now()'),
            'status'     => 'A'
        ]));
    }

    protected function presenceOf(UnitTester $I)
    {
        $model = new Subscriptores();
        $I->assertFalse($model->save([
            'email'      => 'diego@hotmail.com',
            'created_at' => null,
            'status'     => 'A'
        ]));

        $expected = [
            Message::__set_state([
                '_message' => 'Field created_at is required',
                '_field'   => 'created_at',
                '_type'    => 'PresenceOf',
                '_code'    => 0,
            ])
        ];

        $I->assertEquals($expected, $model->getMessages());
    }

    protected function email(UnitTester $I)
    {
        $model = new Subscriptores();
        $I->assertFalse($model->save([
            'email'      => 'fuego?=',
            'created_at' => new RawValue('now()'),
            'status'     => 'A'
        ]));

        $expected = [
            Message::__set_state([
                '_message' => 'Field email must be an email address',
                '_field'   => 'email',
                '_type'    => 'Email',
                '_code'    => 0,
            ])
        ];

        $I->assertEquals($expected, $model->getMessages());
    }

    /**
     * @issue https://github.com/phalcon/cphalcon/issues/1243
     * @param UnitTester $I
     */
    protected function emailWithDot(UnitTester $I)
    {
        $model = new Subscriptores();
        $I->assertFalse($model->save([
            'email'      => 'serghei.@yahoo.com',
            'created_at' => new RawValue('now()'),
            'status'     => 'A'
        ]));

        $expected = [
            Message::__set_state([
                '_message' => 'Field email must be an email address',
                '_field'   => 'email',
                '_type'    => 'Email',
                '_code'    => 0,
            ])
        ];

        $I->assertEquals($expected, $model->getMessages());
    }

    protected function exclusionIn(UnitTester $I)
    {
        $model = new Subscriptores();
        $I->assertFalse($model->save([
            'email'      => 'serghei@hotmail.com',
            'created_at' => new RawValue('now()'),
            'status'     => 'P'
        ]), 'The ExclusionIn Validation failed');

        $expected = [
            Message::__set_state([
                '_message' => 'Field status must not be a part of list: P, I, w',
                '_field'   => 'status',
                '_type'    => 'ExclusionIn',
                '_code'    => 0,
            ]),
            Message::__set_state([
                '_message' => 'Field status must be a part of list: A, y, Z',
                '_field'   => 'status',
                '_type'    => 'InclusionIn',
                '_code'    => 0,
            ]),
        ];

        $I->assertEquals($expected, $model->getMessages());
    }

    protected function inclusionIn(UnitTester $I)
    {
        $model = new Subscriptores();
        $I->assertFalse($model->save([
            'email'      => 'serghei@hotmail.com',
            'created_at' => new RawValue('now()'),
            'status'     => 'R'
        ]));

        $expected = [
            Message::__set_state([
                '_message' => 'Field status must be a part of list: A, y, Z',
                '_field'   => 'status',
                '_type'    => 'InclusionIn',
                '_code'    => 0,
            ]),
        ];

        $I->assertEquals($expected, $model->getMessages());
    }

    protected function uniqueness1(UnitTester $I)
    {
        $data = [
            'email'      => 'jurigag@hotmail.com',
            'created_at' => new RawValue('now()'),
            'status'     => 'A'
        ];

        $model = new Subscriptores();
        $I->assertTrue($model->save($data));

        $model = new Subscriptores();
        $I->assertFalse($model->save($data));

        $expected = [
            Message::__set_state([
                '_message' => 'Field email must be unique',
                '_field'   => 'email',
                '_type'    => 'Uniqueness',
                '_code'    => 0,
            ]),
        ];

        $I->assertEquals($expected, $model->getMessages());
    }

    /**
     * @issue https://github.com/phalcon/cphalcon/issues/1527
     * @param UnitTester $I
     */
    protected function uniqueness2(UnitTester $I)
    {
        $model = Subscriptores::findFirst();
        $model->save($model->toArray());

        $I->assertTrue($model->validation());
        $I->assertEmpty($model->getMessages());
    }

    protected function regex(UnitTester $I)
    {
        $model = new Subscriptores();
        $I->assertFalse($model->save([
            'email'      => 'andres@hotmail.com',
            'created_at' => new RawValue('now()'),
            'status'     => 'y'
        ]));

        $expected = [
            Message::__set_state([
                '_message' => 'Field status does not match the required format',
                '_field'   => 'status',
                '_type'    => 'Regex',
                '_code'    => 0,
            ]),
        ];

        $I->assertEquals($expected, $model->getMessages());
    }

    protected function tooLong(UnitTester $I)
    {
        $model = new Subscriptores();
        $I->assertFalse($model->save([
            'email'      => str_repeat('a', 50) . '@hotmail.com',
            'created_at' => new RawValue('now()'),
            'status'     => 'A'
        ]));

        $expected = [
            Message::__set_state([
                '_message' => 'Field email must not exceed 50 characters long',
                '_field'   => 'email',
                '_type'    => 'TooLong',
                '_code'    => 0,
            ]),
        ];

        $I->assertEquals($expected, $model->getMessages());
    }

    protected function tooShort(UnitTester $I)
    {
        $model = new Subscriptores();
        $I->assertFalse($model->save([
            'email'      => 'a@b.c',
            'created_at' => new RawValue('now()'),
            'status'     => 'A'
        ]));

        $expected = [
            Message::__set_state([
                '_message' => 'Field email must be at least 7 characters long',
                '_field'   => 'email',
                '_type'    => 'TooShort',
                '_code'    => 0,
            ]),
        ];

        $I->assertEquals($expected, $model->getMessages());
    }
}
