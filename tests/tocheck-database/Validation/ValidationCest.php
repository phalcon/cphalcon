<?php

namespace Phalcon\Tests\Integration\Validation;

use IntegrationTester;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Models\Users;
use Phalcon\Validation;
use Phalcon\Validation\Validator\Alpha;
use Phalcon\Validation\Validator\Email;
use Phalcon\Validation\Validator\PresenceOf;
use Phalcon\Validation\Validator\StringLength;
use Phalcon\Validation\Validator\StringLength\Min;
use Phalcon\Validation\Validator\Url;
use stdClass;

/**
 * Phalcon\Tests\Integration\ValidationCest
 * Tests the \Phalcon\Filter\Validation component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link          http://www.phalcon.io
 * @author        Andres Gutierrez <andres@phalcon.io>
 * @author        Phalcon Team <team@phalcon.io>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalcon.io
 * so that we can send you a copy immediately.
 */
class ValidationCest
{
    use DiTrait;

    /**
     * @var Validation
     */
    protected $validation;

    /**
     * executed before each test
     */
    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDiMysql();

        $this->validation = new Validation();

        $this->validation->add(
            'name',
            new PresenceOf(
                [
                    'message' => 'Name cant be empty.',
                ]
            )
        );

        $this->validation->setFilters('name', 'trim');
    }

    public function _after(IntegrationTester $I)
    {
        $this->container['db']->close();
    }

    /**
     * Tests the get
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/10405
     *
     * @since  2016-06-27
     *
     * @author Phalcon Team <team@phalcon.io>
     */
    public function appendValidationMessageToTheNonObject(IntegrationTester $I)
    {
        $myValidator = new PresenceOf();
        $validation  = new Validation();

        $validation->bind(
            new stdClass(),
            [
                'day'   => date('d'),
                'month' => date('m'),
                'year'  => date('Y') + 1,
            ]
        );

        $myValidator->validate($validation, 'foo');

        $expectedMessages = new Messages(
            [
                new Message(
                    'Field foo is required',
                    'foo',
                    PresenceOf::class,
                    0
                ),
            ]
        );

        $I->assertEquals(
            $expectedMessages,
            $validation->getMessages()
        );
    }

    /**
     * Tests validate method with entity and filters
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-09-26
     */
    public function testWithEntityAndFilter(IntegrationTester $I)
    {
        $users = new Users(
            [
                'name' => ' ',
            ]
        );

        $messages = $this->validation->validate(null, $users);

        $I->assertEquals(
            1,
            $messages->count()
        );

        $I->assertEquals(
            'Name cant be empty.',
            $messages->offsetGet(0)->getMessage()
        );

        $expectedMessages = new Messages(
            [
                new Message(
                    'Name cant be empty.',
                    'name',
                    PresenceOf::class,
                    0
                ),
            ]
        );

        $I->assertEquals($messages, $expectedMessages);
    }

    /**
     * Tests that filters in validation will correctly filter entity values
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-09-26
     */
    public function testFilteringEntity(IntegrationTester $I)
    {
        $users = new Users();

        $users->assign(
            [
                'name' => 'SomeName      ',
            ]
        );

        $this->validation->validate(null, $users);

        $I->assertEquals(
            'SomeName',
            $users->name
        );
    }

    public function testValidationFiltering(IntegrationTester $I)
    {
        $validation = new Validation();

        $validation->setDI(
            $this->container
        );

        $validation
            ->add(
                'name',
                new PresenceOf(
                    [
                        'message' => 'The name is required',
                    ]
                )
            )
            ->add(
                'email',
                new PresenceOf(
                    [
                        'message' => 'The email is required',
                    ]
                )
            )
        ;

        $validation->setFilters('name', 'trim');
        $validation->setFilters('email', 'trim');

        $messages = $validation->validate(
            [
                'name'  => '  ',
                'email' => '    ',
            ]
        );

        $I->assertCount(2, $messages);

        $filtered = $messages->filter('email');

        $expectedMessages = [
            new Message(
                'The email is required',
                'email',
                PresenceOf::class,
                0
            ),
        ];

        $I->assertEquals($filtered, $expectedMessages);
    }

    public function testValidationSetLabels(IntegrationTester $I)
    {
        $validation = new Validation();

        $validation->add(
            'email',
            new PresenceOf(
                [
                    'message' => 'The :field is required',
                ]
            )
        );

        $validation->add(
            'email',
            new Email(
                [
                    'message' => 'The :field must be email',
                    'label'   => 'E-mail',
                ]
            )
        );

        $validation->add(
            'firstname',
            new PresenceOf(
                [
                    'message' => 'The :field is required',
                ]
            )
        );

        $validation->add(
            'firstname',
            new StringLength(
                [
                    'min'            => 4,
                    'messageMinimum' => 'The :field is too short',
                ]
            )
        );

        $validation->setLabels(
            [
                'firstname' => 'First name',
            ]
        );

        $messages = $validation->validate(
            [
                'email'     => '',
                'firstname' => '',
            ]
        );

        $expectedMessages = new Messages(
            [
                new Message(
                    'The email is required',
                    'email',
                    PresenceOf::class,
                    0
                ),
                new Message(
                    'The E-mail must be email',
                    'email',
                    Email::class,
                    0
                ),
                new Message(
                    'The First name is required',
                    'firstname',
                    PresenceOf::class,
                    0
                ),
                new Message(
                    'The First name is too short',
                    'firstname',
                    Min::class,
                    0
                ),
            ]
        );

        $I->assertEquals($messages, $expectedMessages);
    }

    /**
     * Tests that empty values behaviour.
     *
     * @author Gorka Guridi <gorka.guridi@gmail.com>
     * @since  2016-12-30
     */
    public function testEmptyValues(IntegrationTester $I)
    {
        $validation = new Validation();

        $validation->setDI(
            $this->container
        );

        $validation
            ->add(
                'name',
                new Alpha(
                    [
                        'message' => 'The name is not valid',
                    ]
                )
            )
            ->add(
                'name',
                new PresenceOf(
                    [
                        'message' => 'The name is required',
                    ]
                )
            )
            ->add(
                'url',
                new Url(
                    [
                        'message'    => 'The url is not valid.',
                        'allowEmpty' => true,
                    ]
                )
            )
            ->add(
                'email',
                new Email(
                    [
                        'message'    => 'The email is not valid.',
                        'allowEmpty' => [null, false],
                    ]
                )
            )
        ;


        $messages = $validation->validate(
            [
                'name'  => '',
                'url'   => null,
                'email' => '',
            ]
        );

        $I->assertCount(2, $messages);


        $messages = $validation->validate(
            [
                'name'  => 'MyName',
                'url'   => '',
                'email' => '',
            ]
        );

        $I->assertCount(1, $messages);


        $messages = $validation->validate(
            [
                'name'  => 'MyName',
                'url'   => false,
                'email' => null,
            ]
        );

        $I->assertCount(0, $messages);


        $messages = $validation->validate(
            [
                'name'  => 'MyName',
                'url'   => 0,
                'email' => 0,
            ]
        );

        $I->assertCount(1, $messages);
    }
}
