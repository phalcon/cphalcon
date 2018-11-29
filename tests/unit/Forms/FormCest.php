<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Forms;

use Phalcon\Forms\Element\Radio;
use Phalcon\Forms\Element\Select;
use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Form;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Tag;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Validation;
use Phalcon\Validation\Validator\PresenceOf;
use Phalcon\Validation\Validator\Regex;
use Phalcon\Validation\Validator\StringLength;
use UnitTester;

class FormCest
{
    use DiTrait;

    public function _before(UnitTester $I)
    {
        $this->newDi();
        $this->setDiEscaper();
        $this->setDiUrl();
    }

    /**
     * executed after each test
     */
    public function _after(UnitTester $I)
    {
        // Setting the doctype to XHTML5 for other tests to run smoothly
        Tag::setDocType(Tag::XHTML5);
    }

    public function testCount(UnitTester $I)
    {
        $form = new Form();

        $expected = 0;
        $actual   = count($form);
        $I->assertEquals($expected, $actual);

        $form->add(
            new Text("name")
        );

        $form->add(
            new Text("telephone")
        );

        $expected = 2;
        $actual   = count($form);
        $I->assertEquals($expected, $actual);
    }

    public function testIterator(UnitTester $I)
    {
        $form = new Form();
        $data = [];

        foreach ($form as $key => $value) {
            $data[$key] = $value->getName();
        }

        $expected = [];
        $actual   = $data;
        $I->assertEquals($expected, $actual);

        $form->add(
            new Text("name")
        );

        $form->add(
            new Text("telephone")
        );

        foreach ($form as $key => $value) {
            $data[$key] = $value->getName();
        }

        $expected = [
            0 => "name",
            1 => "telephone",
        ];
        $actual   = $data;
        $I->assertEquals($expected, $actual);
    }

    public function testLabels(UnitTester $I)
    {
        $form = new Form();

        $form->add(
            new Text("name")
        );

        $telephone = new Text("telephone");
        $telephone->setLabel("The Telephone");
        $form->add($telephone);

        $expected = 'name';
        $actual   = $form->getLabel("name");
        $I->assertEquals($expected, $actual);

        $expected = 'The Telephone';
        $actual   = $form->getLabel("telephone");
        $I->assertEquals($expected, $actual);

        $expected = "<label for=\"name\">name</label>";
        $actual   = $form->label("name");
        $I->assertEquals($expected, $actual);

        $expected = "<label for=\"telephone\">The Telephone</label>";
        $actual   = $form->label("telephone");
        $I->assertEquals($expected, $actual);

        // https://github.com/phalcon/cphalcon/issues/1029
        $expected = "<label for=\"name\" class=\"form-control\">name</label>";
        $actual   = $form->label("name", ["class" => "form-control"]);
        $I->assertEquals($expected, $actual);

        $expected = "<label for=\"telephone\" class=\"form-control\">The Telephone</label>";
        $actual   = $form->label("telephone", ["class" => "form-control"]);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Form::hasMessagesFor
     *
     * @author Sid Roberts <Sid@SidRoberts.co.uk>
     * @since  2016-04-03
     */
    public function testFormHasMessagesFor(UnitTester $I)
    {
        // First element
        $telephone = new Text('telephone');
        $telephone->addValidators(
            [
                new Regex(
                    [
                        'pattern' => '/\+44 [0-9]+ [0-9]+/',
                        'message' => 'The telephone has an invalid format',
                    ]
                ),
            ]
        );

        // Second element
        $address = new Text('address');
        $form    = new Form();

        $form->add($telephone);
        $form->add($address);

        $actual = $form->isValid(['telephone' => '12345', 'address' => 'hello']);
        $I->assertFalse($actual);

        $expected = Messages::__set_state(
            [
                '_messages' => [
                    Message::__set_state(
                        [
                            '_type'    => 'Regex',
                            '_message' => 'The telephone has an invalid format',
                            '_field'   => 'telephone',
                            '_code'    => 0,
                        ]
                    ),
                ],
            ]
        );
        $actual   = $form->getMessagesFor('telephone');
        $I->assertEquals($expected, $actual);

        $expected = Messages::__set_state(['_messages' => []]);
        $actual   = $form->getMessagesFor('address');
        $I->assertEquals($expected, $actual);

        $actual = $form->hasMessagesFor('telephone');
        $I->assertTrue($actual);

        $actual = $form->hasMessagesFor('address');
        $I->assertFalse($actual);
    }

    /**
     * Tests Form::render
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/10398
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-07-17
     */
    public function testCreatingElementsWithNameSimilarToTheFormMethods(UnitTester $I)
    {
        $names = [
            'validation',
            'action',
            'useroption',
            'useroptions',
            'entity',
            'elements',
            'messages',
            'messagesfor',
            'label',
            'value',
            'di',
            'eventsmanager',
        ];

        foreach ($names as $name) {
            $form    = new Form;
            $element = new Text($name);

            $expected = $name;
            $actual   = $element->getName();
            $I->assertEquals($expected, $actual);

            $form->add($element);

            $expected = sprintf('<input type="text" id="%s" name="%s" />', $name, $name);
            $actual   = $form->render($name);
            $I->assertEquals($expected, $actual);

            $actual = $form->getValue($name);
            $I->assertNull($actual);
        }
    }

    public function testFormValidator(UnitTester $I)
    {
        //First element
        $telephone = new Text("telephone");
        $telephone->addValidator(
            new PresenceOf(
                [
                    'message' => 'The telephone is required',
                ]
            )
        );

        $expected = 1;
        $actual   = count($telephone->getValidators());
        $I->assertEquals($expected, $actual);

        $telephone->addValidators(
            [
                new StringLength(
                    [
                        'min'            => 5,
                        'messageMinimum' => 'The telephone is too short',
                    ]
                ),
                new Regex(
                    [
                        'pattern' => '/\+44 [0-9]+ [0-9]+/',
                        'message' => 'The telephone has an invalid format',
                    ]
                ),
            ]
        );

        $expected = 3;
        $actual   = count($telephone->getValidators());
        $I->assertEquals($expected, $actual);

        //Second element
        $address = new Text('address');
        $address->addValidator(
            new PresenceOf(
                [
                    'message' => 'The address is required',
                ]
            )
        );

        $expected = 3;
        $actual   = count($telephone->getValidators());
        $I->assertEquals($expected, $actual);

        $form = new Form();
        $form->add($telephone);
        $form->add($address);

        $actual = $form->isValid([]);
        $I->assertFalse($actual);

        $expected = Messages::__set_state(
            [
                '_messages' => [
                    0 => Message::__set_state(
                        [
                            '_type'    => 'PresenceOf',
                            '_message' => 'The telephone is required',
                            '_field'   => 'telephone',
                            '_code'    => 0,
                        ]
                    ),
                    1 => Message::__set_state(
                        [
                            '_type'    => 'TooShort',
                            '_message' => 'The telephone is too short',
                            '_field'   => 'telephone',
                            '_code'    => 0,
                        ]
                    ),
                    2 => Message::__set_state(
                        [
                            '_type'    => 'Regex',
                            '_message' => 'The telephone has an invalid format',
                            '_field'   => 'telephone',
                            '_code'    => 0,
                        ]
                    ),
                    3 => Message::__set_state(
                        [
                            '_type'    => 'PresenceOf',
                            '_message' => 'The address is required',
                            '_field'   => 'address',
                            '_code'    => 0,
                        ]
                    ),
                ],
            ]
        );
        $actual   = $form->getMessages();
        $I->assertEquals($expected, $actual);

        $actual = $form->isValid(
            [
                'telephone' => '12345',
                'address'   => 'hello',
            ]
        );
        $I->assertFalse($actual);

        $expected = Messages::__set_state(
            [
                '_messages' => [
                    0 => Message::__set_state(
                        [
                            '_type'    => 'Regex',
                            '_message' => 'The telephone has an invalid format',
                            '_field'   => 'telephone',
                            '_code'    => 0,
                        ]
                    ),
                ],
            ]
        );
        $actual   = $form->getMessages();
        $I->assertEquals($expected, $actual);

        $actual = $form->isValid(
            [
                'telephone' => '+44 124 82122',
                'address'   => 'hello',
            ]
        );
        $I->assertTrue($actual);
    }

    public function testFormIndirectElementRender(UnitTester $I)
    {
        $form = new Form();

        $form->add(new Text("name"));

        $expected = '<input type="text" id="name" name="name" />';
        $actual   = $form->render("name");
        $I->assertEquals($expected, $actual);

        $expected = '<input type="text" id="name" name="name" class="big-input" />';
        $actual   = $form->render("name", ["class" => "big-input"]);
        $I->assertEquals($expected, $actual);
    }

    /**
     * @issue https://github.com/phalcon/cphalcon/issues/1190
     */
    public function testIssue1190(UnitTester $I)
    {
        $object        = new \stdClass();
        $object->title = 'Hello "world!"';

        $form = new Form($object);
        $form->add(new Text("title"));

        $actual   = $form->render("title");
        $expected = '<input type="text" id="title" name="title" value="Hello &quot;world!&quot;" />';
        $I->assertEquals($expected, $actual);
    }

    /**
     * @issue https://github.com/phalcon/cphalcon/issues/706
     */
    public function testIssue706(UnitTester $I)
    {
        $form = new Form();
        $form->add(new Text("name"));

        $form->add(new Text("before"), "name", true);
        $form->add(new Text("after"), "name");

        $expected = ["before", "name", "after"];
        $actual   = [];

        foreach ($form as $element) {
            $actual[] = $element->getName();
        }
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Element::hasMessages() Element::getMessages()
     *
     * @author Mohamad Rostami <rostami@outlook.com>
     * @issue  https://github.com/phalcon/cphalcon/issues/11135
     * @issue  https://github.com/phalcon/cphalcon/issues/3167
     */
    public function testElementMessages(UnitTester $I)
    {
        // First element
        $telephone = new Text('telephone');

        $telephone->addValidators(
            [
                new Regex(
                    [
                        'pattern' => '/\+44 [0-9]+ [0-9]+/',
                        'message' => 'The telephone has an invalid format',
                    ]
                ),
            ]
        );

        // Second element
        $address = new Text('address');
        $form    = new Form();

        $form->add($telephone);
        $form->add($address);

        $actual = $form->isValid(['telephone' => '12345', 'address' => 'hello']);
        $I->assertFalse($actual);
        $actual = $form->get('telephone')->hasMessages();
        $I->assertTrue($actual);
        $actual = $form->get('address')->hasMessages();
        $I->assertFalse($actual);

        $expected = Messages::__set_state(
            [
                '_messages' => [
                    Message::__set_state(
                        [
                            '_type'    => 'Regex',
                            '_message' => 'The telephone has an invalid format',
                            '_field'   => 'telephone',
                            '_code'    => 0,
                        ]
                    ),
                ],
            ]
        );
        $actual   = $form->get('telephone')->getMessages();
        $I->assertEquals($expected, $actual);

        $expected = $form->getMessages();
        $actual   = $form->get('telephone')->getMessages();
        $I->assertEquals($expected, $actual);

        $expected = Messages::__set_state(['_messages' => []]);
        $actual   = $form->get('address')->getMessages();
        $I->assertEquals($expected, $actual);

        $expected = Messages::__set_state(['_messages' => []]);
        $actual   = $form->getMessagesFor('notelement');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Form::setValidation()
     *
     * @author Mohamad Rostami <rostami@outlook.com>
     * @issue  https://github.com/phalcon/cphalcon/issues/12465
     */
    public function testCustomValidation(UnitTester $I)
    {
        // First element
        $telephone        = new Text('telephone');
        $customValidation = new Validation();
        $customValidation->add(
            'telephone',
            new Regex(
                [
                    'pattern' => '/\+44 [0-9]+ [0-9]+/',
                    'message' => 'The telephone has an invalid format',
                ]
            )
        );
        $form    = new Form();
        $address = new Text('address');
        $form->add($telephone);
        $form->add($address);
        $form->setValidation($customValidation);

        $actual = $form->isValid(['telephone' => '12345', 'address' => 'hello']);
        $I->assertFalse($actual);

        $actual = $form->get('telephone')->hasMessages();
        $I->assertTrue($actual);

        $actual = $form->get('address')->hasMessages();
        $I->assertFalse($actual);

        $expected = Messages::__set_state(
            [
                '_messages' => [
                    Message::__set_state(
                        [
                            '_type'    => 'Regex',
                            '_message' => 'The telephone has an invalid format',
                            '_field'   => 'telephone',
                            '_code'    => 0,
                        ]
                    ),
                ],
            ]
        );
        $actual   = $form->get('telephone')->getMessages();
        $I->assertEquals($expected, $actual);

        $expected = $form->getMessages();
        $actual   = $form->get('telephone')->getMessages();
        $I->assertEquals($expected, $actual);

        $expected = Messages::__set_state(['_messages' => []]);
        $actual   = $form->get('address')->getMessages();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Form::isValid()
     *
     * @author Mohamad Rostami <rostami@outlook.com>
     * @issue  https://github.com/phalcon/cphalcon/issues/11500
     */
    public function testMergeValidators(UnitTester $I)
    {
        // First element
        $telephone = new Text('telephone');
        $telephone->addValidators(
            [
                new PresenceOf(
                    [
                        'message' => 'The telephone is required',
                    ]
                ),
            ]
        );
        $customValidation = new Validation();
        $customValidation->add(
            'telephone',
            new Regex(
                [
                    'pattern' => '/\+44 [0-9]+ [0-9]+/',
                    'message' => 'The telephone has an invalid format',
                ]
            )
        );
        $form    = new Form();
        $address = new Text('address');
        $form->add($telephone);
        $form->add($address);
        $form->setValidation($customValidation);

        $actual = $form->isValid(['address' => 'hello']);
        $I->assertFalse($actual);

        $actual = $form->get('telephone')->hasMessages();
        $I->assertTrue($actual);

        $actual = $form->get('address')->hasMessages();
        $I->assertFalse($actual);

        $expected = Messages::__set_state(
            [
                '_messages' => [
                    Message::__set_state(
                        [
                            '_type'    => 'Regex',
                            '_message' => 'The telephone has an invalid format',
                            '_field'   => 'telephone',
                            '_code'    => 0,
                        ]
                    ),
                    Message::__set_state(
                        [
                            '_type'    => 'PresenceOf',
                            '_message' => 'The telephone is required',
                            '_field'   => 'telephone',
                            '_code'    => 0,
                        ]
                    ),
                ],
            ]
        );
        $actual   = $form->get('telephone')->getMessages();
        $I->assertEquals($expected, $actual);

        $expected = $form->getMessages();
        $actual   = $form->get('telephone')->getMessages();
        $I->assertEquals($expected, $actual);

        $expected = Messages::__set_state(['_messages' => []]);
        $actual   = $form->get('address')->getMessages();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Form::getMessages(true)
     *
     * @author Mohamad Rostami <rostami@outlook.com>
     * @issue  https://github.com/phalcon/cphalcon/issues/13294
     *
     * This should be removed in next major version
     * We should not return multiple type of result in a single method!
     * (form->getMessages(true) vs form->getMessages())
     */
    public function testGetElementMessagesFromForm(UnitTester $I)
    {
        // First element
        $telephone = new Text('telephone');
        $telephone->addValidators(
            [
                new PresenceOf(
                    [
                        'message' => 'The telephone is required',
                    ]
                ),
            ]
        );
        $customValidation = new Validation();
        $customValidation->add(
            'telephone',
            new Regex(
                [
                    'pattern' => '/\+44 [0-9]+ [0-9]+/',
                    'message' => 'The telephone has an invalid format',
                ]
            )
        );
        $form    = new Form();
        $address = new Text('address');
        $form->add($telephone);
        $form->add($address);
        $form->setValidation($customValidation);

        $actual = $form->isValid(['address' => 'hello']);
        $I->assertFalse($actual);

        $expected = [
            'telephone' => [
                Messages::__set_state(
                    [
                        '_messages' => [
                            Message::__set_state(
                                [
                                    '_type'    => 'Regex',
                                    '_message' => 'The telephone has an invalid format',
                                    '_field'   => 'telephone',
                                    '_code'    => 0,
                                ]
                            ),
                        ],
                    ]
                ),
                Messages::__set_state(
                    [
                        '_messages' => [
                            Message::__set_state(
                                [
                                    '_type'    => 'PresenceOf',
                                    '_message' => 'The telephone is required',
                                    '_field'   => 'telephone',
                                    '_code'    => 0,
                                ]
                            ),
                        ],
                    ]
                ),
            ],
        ];
        $actual   = $form->getMessages(true);
        $I->assertEquals($expected, $actual);
    }
}
