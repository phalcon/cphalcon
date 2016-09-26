<?php

namespace Phalcon\Test\Unit;

use Phalcon\Test\Models\Users;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Validation;
use Phalcon\Validation\Message;
use Phalcon\Validation\Message\Group;

/**
 * \Phalcon\Test\Unit\ValidationTest
 * Tests the \Phalcon\Validation component
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @author    Wojciech Ślawski <jurigag@gmail.com>
 * @package   Phalcon\Test\Unit
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
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
        $this->specify('Validation filters are not saving value to entity', function() {
            $users = new Users([
                'name' => 'SomeName      '
            ]);

            $this->validation->validate(null, $users);

            expect($users->name)->equals('SomeName');
        });
    }
}