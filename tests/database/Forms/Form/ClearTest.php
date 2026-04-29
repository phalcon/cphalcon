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

namespace Phalcon\Tests\Database\Forms\Form;

use Phalcon\Filter\Validation\Validator\PresenceOf;
use Phalcon\Filter\Validation\Validator\StringLength;
use Phalcon\Filter\Validation\Validator\StringLength\Min;
use Phalcon\Forms\Element\Email;
use Phalcon\Forms\Element\Password;
use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Form;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Tag;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Database\Forms\Form\Fake\FakeSelect;
use Phalcon\Tests\Support\Traits\DiTrait;
use stdClass;

final class ClearTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    /**
     * @var array<string, mixed>
     */
    private array $postStore = [];

    public function setUp(): void
    {
        $this->markTestSkipped('Needs to be refactored because of Tag');
        $this->postStore = $_POST ?? [];

        $this->setNewFactoryDefault();
        $this->setDatabase();

        Tag::resetInput();
        Tag::setDocType(Tag::HTML5);
    }

    public function tearDown(): void
    {
        $_POST = $this->postStore;
        $this->tearDownDatabase();
    }

    /**
     * Tests Phalcon\Forms\Form :: clear() - all
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-06-28
     *
     * @group  mysql
     * @group sqlite
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
     * Tests Phalcon\Forms\Form :: clear() - fields array
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-06-28
     *
     * @group  mysql
     * @group sqlite
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
     * Tests Phalcon\Forms\Form :: clear() - field string
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-06-28
     *
     * @group  mysql
     * @group sqlite
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
     * Tests clearing the Form Elements
     *
     * @author Phalcon Team <team@phalcon.io>
     * @issue  https://github.com/phalcon/cphalcon/issues/12165
     * @issue  https://github.com/phalcon/cphalcon/issues/12099
     * @since  2016-10-01
     *
     * @group  mysql
     * @group sqlite
     *
     * @todo   Check implementation — uses Tag::setDefault() which needs review
     */
    public function testClearFormElements(): void
    {
        $this->markTestSkipped('Check implementation — uses Tag::setDefault()');

        $pass = new Password('passwd');
        $eml  = new Email('email');

        $text = new Text('name');
        $text->setDefault('Serghei Iakovlev');

        $form = new Form();
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

        Tag::setDefault('email', 'andres@phalcon.io');

        $this->assertEquals(
            '<input type="email" id="email" name="email" value="andres@phalcon.io">',
            $form->render('email')
        );

        $this->assertEquals(
            'andres@phalcon.io',
            $form->get('email')->getValue()
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
     * Tests clearing the Form Elements and using Form::isValid
     *
     * @author Phalcon Team <team@phalcon.io>
     * @issue  https://github.com/phalcon/cphalcon/issues/11978
     * @since  2016-10-01
     *
     * @group  mysql
     * @group sqlite
     */
    public function testClearFormElementsAndUsingValidation(): void
    {
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

    /**
     * Tests clearing the Form Elements by using Form::bind
     *
     * @author Phalcon Team <team@phalcon.io>
     * @issue  https://github.com/phalcon/cphalcon/issues/11978
     * @since  2016-10-01
     *
     * @group  mysql
     * @group sqlite
     *
     * @todo   Check implementation — uses Tag::getValue() / Tag::setDefault() which need review
     */
    public function testClearFormElementsByUsingFormBind(): void
    {
        $this->markTestSkipped('Check implementation — uses Tag::getValue() and Tag::setDefault()');

        $name = new Text('sel_name');
        $text = new Text('sel_text');

        $form = new Form();
        $form
            ->add($name)
            ->add($text)
        ;

        $entity = new FakeSelect();

        $this->assertNull(
            Tag::getValue('sel_name')
        );

        $this->assertNull(
            $form->getValue('sel_name')
        );

        $this->assertNull(
            $form->get('sel_name')->getValue()
        );

        $this->assertNull(
            $name->getValue()
        );

        Tag::setDefault('sel_name', 'Please specify name');

        $_POST = [
            'sel_name' => 'Some Name',
            'sel_text' => 'Some Text',
        ];

        $form->bind($_POST, $entity);

        $this->assertEquals(
            'Some Name',
            $entity->getName()
        );

        $this->assertEquals(
            'Some Text',
            $entity->getText()
        );

        $this->assertEquals(
            'Some Name',
            $form->getValue('sel_name')
        );

        $this->assertEquals(
            'Some Name',
            $form->get('sel_name')->getValue()
        );

        $this->assertEquals(
            'Some Name',
            $name->getValue()
        );

        $this->assertEquals(
            'Some Text',
            $form->getValue('sel_text')
        );

        $this->assertEquals(
            'Some Text',
            $form->get('sel_text')->getValue()
        );

        $this->assertEquals(
            'Some Text',
            $text->getValue()
        );

        $form->clear(['sel_name']);

        $this->assertNull(
            Tag::getValue('sel_name')
        );

        $this->assertNull(
            $form->getValue('sel_name')
        );

        $this->assertNull(
            $form->get('sel_name')->getValue()
        );

        $this->assertNull(
            $name->getValue()
        );

        $this->assertEquals(
            'Some Text',
            $form->getValue('sel_text')
        );

        $this->assertEquals(
            'Some Text',
            $form->get('sel_text')->getValue()
        );

        $this->assertEquals(
            'Some Text',
            $text->getValue()
        );

        $form->clear(
            [
                'non_existent',
                'another_filed',
            ]
        );

        $this->assertEquals(
            'Some Text',
            $form->getValue('sel_text')
        );

        $this->assertEquals(
            'Some Text',
            $form->get('sel_text')->getValue()
        );

        $this->assertEquals(
            'Some Text',
            $text->getValue()
        );

        $form->clear();

        $this->assertNull(
            Tag::getValue('sel_text')
        );

        $this->assertNull(
            $form->getValue('sel_text')
        );

        $this->assertNull(
            $form->get('sel_text')->getValue()
        );

        $this->assertNull(
            $text->getValue()
        );

        $this->assertEquals(
            'Some Name',
            $entity->getName()
        );

        $this->assertEquals(
            'Some Text',
            $entity->getText()
        );

        $this->assertEquals(
            [
                'sel_name' => 'Some Name',
                'sel_text' => 'Some Text',
            ],
            $_POST
        );
    }
}
