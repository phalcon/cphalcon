<?php

namespace Phalcon\Test\Unit;

use Phalcon\Db\RawValue;
use Phalcon\Di\FactoryDefault;
use Phalcon\Test\Models\Users;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Validation;
use Phalcon\Validation\Message;
use Phalcon\Validation\Message\Group;

/**
 * \Phalcon\Test\Unit\ValidationTest
 * Tests the \Phalcon\Validation component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @author    Wojciech Ślawski <jurigag@gmail.com>
 * @package   Phalcon\Test\Unit
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class ValidationTest extends UnitTest
{
    /**
     * @var Validation
     */
    protected $validation;

    /**
     * executed before each test
     */
    protected function _before()
    {
        parent::_before();
        $this->validation = new Validation();
        $this->validation->add('name', new Validation\Validator\PresenceOf([
            'message' => 'Name cant be empty.'
        ]));
        $this->validation->setFilters('name', 'trim');
    }

    /**
     * Tests validate method with entity and filters
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-09-26
     */
    public function testWithEntityAndFilter()
    {
        $this->specify('Validation filters are not working with entity', function () {
            $users = new Users([
                'name' => ' '
            ]);
            $messages = $this->validation->validate(null, $users);

            expect($messages->count())->equals(1);
            expect($messages->offsetGet(0)->getMessage())->equals('Name cant be empty.');

            $expectedMessages = Group::__set_state([
                '_messages' => [
                    Message::__set_state([
                        '_type' => 'PresenceOf',
                        '_message' => 'Name cant be empty.',
                        '_field' => 'name',
                        '_code' => '0',
                    ])
                ],
            ]);

            expect($messages)->equals($expectedMessages);
        });
    }

    /**
     * Tests that filters in validation will correctly filter entity values
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-09-26
     */
    public function testFilteringEntity()
    {
        $this->specify('Validation filters are not saving value to entity', function () {
            $users = new Users([
                'name' => 'SomeName      '
            ]);

            $this->validation->validate(null, $users);

            expect($users->name)->equals('SomeName');
        });
    }

    public function testGetDefaultValidationMessageShouldReturnEmptyStringIfNoneIsSet()
    {
        $this->specify(
            "getDefaultMessage() should return empty string if none is set",
            function () {
                $validation = new Validation();

                expect($validation->getDefaultMessage('_notexistentvalidationmessage_'))->isEmpty();
            }
        );
    }

    public function testValidationFiltering()
    {
        $this->specify(
            "Validation filtering doesn't work as expected",
            function () {
                $validation = new Validation();

                $validation->setDI(new FactoryDefault());

                $validation
                    ->add('name', new Validation\Validator\PresenceOf(array(
                        'message' => 'The name is required'
                    )))
                    ->add('email', new Validation\Validator\PresenceOf(array(
                        'message' => 'The email is required'
                    )));

                $validation->setFilters('name', 'trim');
                $validation->setFilters('email', 'trim');

                $messages = $validation->validate(['name' => '  ', 'email' => '    ']);

                expect($messages)->count(2);

                $filtered = $messages->filter('email');

                $expectedMessages = array(
                    0 => Message::__set_state(array(
                        '_type' => 'PresenceOf',
                        '_message' => 'The email is required',
                        '_field' => 'email',
                        '_code' => '0',
                    ))
                );

                expect($filtered)->equals($expectedMessages);
            }
        );
    }

    public function testValidationSetLabels()
    {
        $this->specify(
            "setLabels() doesn't work as expected",
            function () {
                $validation = new Validation();

                $validation->add(
                    'email',
                    new Validation\Validator\PresenceOf(
                        array(
                            'message' => 'The :field is required'
                        )
                    )
                );
                $validation->add(
                    'email',
                    new Validation\Validator\Email(
                        array(
                            'message' => 'The :field must be email',
                            'label' => 'E-mail'
                        )
                    )
                );
                $validation->add(
                    'firstname',
                    new Validation\Validator\PresenceOf(
                        array(
                            'message' => 'The :field is required'
                        )
                    )
                );
                $validation->add(
                    'firstname',
                    new Validation\Validator\StringLength(
                        array(
                            'min' => 4,
                            'messageMinimum' => 'The :field is too short'
                        )
                    )
                );

                $validation->setLabels(array('firstname' => 'First name'));

                $messages = $validation->validate(['email' => '', 'firstname' => '']);

                $expectedMessages = Group::__set_state(array(
                    '_messages' => array(
                        0 => Message::__set_state(array(
                            '_type' => 'PresenceOf',
                            '_message' => 'The email is required',
                            '_field' => 'email',
                            '_code' => '0',
                        )),
                        1 => Message::__set_state(array(
                            '_type' => 'Email',
                            '_message' => 'The E-mail must be email',
                            '_field' => 'email',
                            '_code' => '0',
                        )),
                        2 => Message::__set_state(array(
                            '_type' => 'PresenceOf',
                            '_message' => 'The First name is required',
                            '_field' => 'firstname',
                            '_code' => '0',
                        )),
                        3 => Message::__set_state(array(
                            '_type' => 'TooShort',
                            '_message' => 'The First name is too short',
                            '_field' => 'firstname',
                            '_code' => '0',
                        ))
                    )
                ));

                expect($messages)->equals($expectedMessages);
            }
        );
    }

    /**
     * Tests that empty values behaviour.
     *
     * @author Gorka Guridi <gorka.guridi@gmail.com>
     * @since  2016-12-30
     */
    public function testEmptyValues()
    {
        $this->specify(
            "Validation of empty values doesn't work as expected",
            function () {
                $validation = new Validation();

                $validation->setDI(new FactoryDefault());

                $validation
                    ->add('name', new Validation\Validator\Alpha([
                        'message' => 'The name is not valid',
                    ]))
                    ->add('name', new Validation\Validator\PresenceOf([
                        'message' => 'The name is required',
                    ]))
                    ->add('url', new Validation\Validator\Url([
                        'message' => 'The url is not valid.',
                        'allowEmpty' => true,
                    ]))
                    ->add('email', new Validation\Validator\Email([
                        'message' => 'The email is not valid.',
                        'allowEmpty' => [null, false],
                    ]))
                    ->add('price', new Validation\Validator\Numericality([
                        'message' => 'The price is not valid.',
                        'allowEmpty' => [null, new RawValue('NULL')],
                    ]));

                $messages = $validation->validate([
                    'name' => '',
                    'url' => null,
                    'email' => '',
                    'price' => null,
                ]);
                expect($messages)->count(2);

                $messages = $validation->validate([
                    'name' => 'MyName',
                    'url' => '',
                    'email' => '',
                    'price' => null,
                ]);
                expect($messages)->count(1);

                $messages = $validation->validate([
                    'name' => 'MyName',
                    'url' => false,
                    'email' => null,
                    'price' => null,
                ]);
                expect($messages)->count(0);

                $messages = $validation->validate([
                    'name' => 'MyName',
                    'url' => 0,
                    'email' => 0,
                    'price' => null,
                ]);
                expect($messages)->count(1);

                $messages = $validation->validate([
                    'name' => 'MyName',
                    'url' => '',
                    'email' => null,
                    'price' => new RawValue('NULL'),
                ]);
                expect($messages)->count(0);
            }
        );
    }
}
