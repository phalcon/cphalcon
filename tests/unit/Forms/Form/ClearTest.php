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

namespace Phalcon\Tests\Unit\Forms\Form;

use Phalcon\Filter\Validation\Validator\PresenceOf;
use Phalcon\Filter\Validation\Validator\StringLength;
use Phalcon\Filter\Validation\Validator\StringLength\Min;
use Phalcon\Forms\Element\Email;
use Phalcon\Forms\Element\Password;
use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Form;
use Phalcon\Html\Escaper;
use Phalcon\Html\TagFactory;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Tests\AbstractUnitTestCase;
use stdClass;

use function uniqid;

final class ClearTest extends AbstractUnitTestCase
{
    private array $postStore = [];

    public function setUp(): void
    {
        $this->postStore = $_POST ?? [];
    }

    public function tearDown(): void
    {
        $_POST = $this->postStore;
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-11-01
     */
    public function testFormsFormGet(): void
    {
        $addressValue = uniqid('add-');
        $address      = new Text('address');
        $address->setDefault($addressValue);

        $expected = $addressValue;
        $actual   = $address->getValue();
        $this->assertSame($expected, $actual);

        $addressValueNew = uniqid('addn-');

        $form = new Form();
        $form->add($address);

        $_POST = [
            'address' => $addressValueNew,
        ];

        $actual = $form->isValid($_POST);
        $this->assertTrue($actual);

        $expected = $addressValueNew;
        $actual   = $address->getValue();
        $this->assertSame($expected, $actual);

        $form->clear();

        $expected = $addressValue;
        $actual   = $address->getValue();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-06-28
     */
    public function testFormsFormClearAll(): void
    {
        $name     = new Text('name');
        $email    = new Email('email');
        $password = new Password('password');

        $form = new Form();
        $form
            ->add($name)
            ->add($email)
            ->add($password)
        ;

        $entity = new stdClass();
        $form->bind(
            [
                'name'     => 'Sid Roberts',
                'email'    => 'team@phalcon.io',
                'password' => 'hunter2',
            ],
            $entity
        );

        $form->clear();

        $this->assertNull(
            $form->get('name')->getValue()
        );

        $this->assertNull(
            $form->get('email')->getValue()
        );

        $this->assertNull(
            $form->get('password')->getValue()
        );
    }

    /**
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-06-28
     */
    public function testFormsFormClearFieldsArray(): void
    {
        $name     = new Text('name');
        $email    = new Email('email');
        $password = new Password('password');

        $form = new Form();
        $form
            ->add($name)
            ->add($email)
            ->add($password)
        ;

        $entity = new stdClass();
        $form->bind(
            [
                'name'     => 'Sid Roberts',
                'email'    => 'team@phalcon.io',
                'password' => 'hunter2',
            ],
            $entity
        );

        $form->clear(
            [
                'email',
                'password',
            ]
        );

        $this->assertEquals(
            'Sid Roberts',
            $form->get('name')->getValue()
        );

        $this->assertNull(
            $form->get('email')->getValue()
        );

        $this->assertNull(
            $form->get('password')->getValue()
        );
    }

    /**
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-06-28
     */
    public function testFormsFormClearFieldString(): void
    {
        $name     = new Text('name');
        $email    = new Email('email');
        $password = new Password('password');

        $form = new Form();
        $form
            ->add($name)
            ->add($email)
            ->add($password)
        ;

        $entity = new stdClass();
        $form->bind(
            [
                'name'     => 'Sid Roberts',
                'email'    => 'team@phalcon.io',
                'password' => 'hunter2',
            ],
            $entity
        );

        $form->clear('password');

        $this->assertEquals(
            'Sid Roberts',
            $form->get('name')->getValue()
        );

        $this->assertEquals(
            'team@phalcon.io',
            $form->get('email')->getValue()
        );

        $this->assertNull(
            $form->get('password')->getValue()
        );
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/12165
     * @issue  https://github.com/phalcon/cphalcon/issues/12099
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-10-01
     */
    public function testClearFormElements(): void
    {
        $factory = new TagFactory(new Escaper());

        $pass = new Password('passwd');
        $eml  = new Email('email');

        $text = new Text('name');
        $text->setDefault('Serghei Iakovlev');

        $form = new Form();
        $form->setTagFactory($factory);
        $form
            ->add($eml)
            ->add($text)
            ->add($pass)
        ;

        $this->assertNull(
            $form->get('passwd')->getValue()
        );

        $this->assertEquals(
            'Serghei Iakovlev',
            $form->get('name')->getValue()
        );

        $this->assertEquals(
            '<input type="password" id="passwd" name="passwd">',
            $form->render('passwd')
        );

        $this->assertEquals(
            '<input type="email" id="email" name="email">',
            $form->render('email')
        );

        $this->assertEquals(
            '<input type="text" id="name" name="name" value="Serghei Iakovlev">',
            $form->render('name')
        );

        $_POST = [
            'passwd' => 'secret',
            'name'   => 'Andres Gutierrez',
        ];

        $this->assertEquals(
            'secret',
            $form->get('passwd')->getValue()
        );

        $this->assertEquals(
            $pass->getValue(),
            $form->get('passwd')->getValue()
        );

        $this->assertEquals(
            'Andres Gutierrez',
            $form->get('name')->getValue()
        );

        $this->assertEquals(
            '<input type="password" id="passwd" name="passwd" value="secret">',
            $form->render('passwd')
        );

        $this->assertEquals(
            '<input type="text" id="name" name="name" value="Andres Gutierrez">',
            $form->render('name')
        );

        $pass->clear();

        $this->assertEquals(
            '<input type="password" id="passwd" name="passwd">',
            $form->render('passwd')
        );

        $this->assertNull(
            $pass->getValue()
        );

        $this->assertEquals(
            $pass->getValue(),
            $form->get('passwd')->getValue()
        );

        $form->clear();

        $this->assertEquals(
            'Serghei Iakovlev',
            $form->get('name')->getValue()
        );

        $this->assertNull(
            $form->get('email')->getValue()
        );

        $this->assertEquals(
            '<input type="text" id="name" name="name" value="Serghei Iakovlev">',
            $form->render('name')
        );

        $this->assertEquals(
            '<input type="email" id="email" name="email">',
            $form->render('email')
        );

        $this->assertEquals(
            [
                'passwd' => 'secret',
                'name'   => 'Andres Gutierrez',
            ],
            $_POST
        );
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/11978
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-10-01
     */
    public function testClearFormElementsAndUsingValidation(): void
    {
        $factory = new TagFactory(new Escaper());

        $password = new Password(
            'password',
            [
                'placeholder' => 'Insert your Password',
            ]
        );

        $password->addValidators(
            [
                new PresenceOf(
                    [
                        'message'      => 'The field is required',
                        'cancelOnFail' => true,
                    ]
                ),
                new StringLength(
                    [
                        'min'            => 7,
                        'messageMinimum' => 'The text is too short',
                    ]
                ),
            ]
        );

        $form = new Form();
        $form->setTagFactory($factory);
        $form->add($password);

        $this->assertNull(
            $form->get('password')->getValue()
        );

        $this->assertEquals(
            '<input type="password" id="password" name="password" placeholder="Insert your Password">',
            $form->render('password')
        );

        $_POST = ['password' => 'secret'];

        $this->assertEquals(
            'secret',
            $form->get('password')->getValue()
        );

        $this->assertEquals(
            '<input type="password" id="password" name="password" value="secret" placeholder="Insert your Password">',
            $form->render('password')
        );

        $this->assertFalse(
            $form->isValid($_POST)
        );

        $expected = new Messages(
            [
                new Message(
                    'The text is too short',
                    'password',
                    Min::class,
                    0
                ),
            ]
        );
        $this->assertEquals(
            $expected,
            $form->getMessages()
        );

        $form->clear(
            ['password']
        );

        $this->assertNull(
            $form->get('password')->getValue()
        );

        $this->assertEquals(
            '<input type="password" id="password" name="password" placeholder="Insert your Password">',
            $form->render('password')
        );

        $this->assertEquals(
            [
                'password' => 'secret',
            ],
            $_POST
        );
    }
}
