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

namespace Phalcon\Tests\Database\Forms;

use Phalcon\Filter\Validation\Validator\PresenceOf;
use Phalcon\Filter\Validation\Validator\StringLength;
use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Form;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;

final class FormElementsTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * Tests cancelling validation on first fail
     *
     * @author Phalcon Team <team@phalcon.io>
     * @issue  https://github.com/phalcon/cphalcon/issues/13149
     * @since  2017-11-19
     *
     * @group  mysql
     * @group sqlite
     */
    public function testShouldCancelValidationOnFirstFail(): void
    {
        $form = new Form();

        $lastName = new Text('lastName');
        $lastName->setLabel('user.lastName');
        $lastName->setFilters(
            [
                'string',
                'striptags',
                'trim',
            ]
        );
        $lastName->addValidators(
            [
                new PresenceOf(
                    [
                        'message'      => 'user.lastName.presenceOf',
                        'cancelOnFail' => true,
                    ]
                ),
                new StringLength(
                    [
                        'min'            => 3,
                        'max'            => 255,
                        'messageMaximum' => 'user.lastName.max',
                        'messageMinimum' => 'user.lastName.min',
                    ]
                ),
            ]
        );

        $firstName = new Text('firstName');
        $firstName->setLabel('user.firstName');
        $firstName->setFilters(
            [
                'string',
                'striptags',
                'trim',
            ]
        );
        $firstName->addValidators(
            [
                new PresenceOf(
                    [
                        'message'      => 'user.firstName.presenceOf',
                        'cancelOnFail' => true,
                    ]
                ),
                new StringLength(
                    [
                        'min'            => 3,
                        'max'            => 255,
                        'messageMaximum' => 'user.firstName.max',
                        'messageMinimum' => 'user.firstName.min',
                    ]
                ),
            ]
        );

        $form->add($lastName);
        $form->add($firstName);

        $_POST = [];

        $this->assertFalse(
            $form->isValid($_POST)
        );

        $expected = new Messages(
            [
                new Message(
                    'user.lastName.presenceOf',
                    'lastName',
                    PresenceOf::class
                ),
                new Message(
                    'user.firstName.presenceOf',
                    'firstName',
                    PresenceOf::class
                ),
            ]
        );

        $actual = $form->getMessages();

        $this->assertEquals($expected, $actual);
    }
}
