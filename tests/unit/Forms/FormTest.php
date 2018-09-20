<?php

namespace Phalcon\Test\Unit\Forms;

use Phalcon\Forms\Form;
use Phalcon\Forms\Element\Radio;
use Phalcon\Forms\Element\Select;
use Phalcon\Forms\Element\Text;
use Phalcon\Tag;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Validation\Message;
use Phalcon\Validation\Message\Group;
use Phalcon\Validation\Validator\PresenceOf;
use Phalcon\Validation\Validator\Regex;
use Phalcon\Validation\Validator\StringLength;
use Phalcon\Validation;

/**
 * \Phalcon\Test\Unit\Forms\FormTest
 * Tests the \Phalcon\Forms\Form component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit\Forms
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class FormTest extends UnitTest
{
    /**
     * executed after each test
     */
    protected function _after()
    {
        // Setting the doctype to XHTML5 for other tests to run smoothly
        Tag::setDocType(Tag::XHTML5);
    }

    public function testCount()
    {
        $this->specify(
            "Form::count does not return the correct number",
            function () {
                $form = new Form();

                expect($form)->count(0);
                expect($form->count())->equals(0);

                $form->add(
                    new Text("name")
                );

                $form->add(
                    new Text("telephone")
                );

                expect($form)->count(2);
                expect($form->count())->equals(2);
            }
        );
    }

    public function testIterator()
    {
        $this->specify(
            "Form incorrectly implements the Iterator interface",
            function () {
                $form = new Form();
                $data = [];

                foreach ($form as $key => $value) {
                    $data[$key] = $value->getName();
                }

                expect($data)->equals([]);

                $form->add(
                    new Text("name")
                );

                $form->add(
                    new Text("telephone")
                );

                foreach ($form as $key => $value) {
                    $data[$key] = $value->getName();
                }

                expect($data)->equals([
                    0 => "name",
                    1 => "telephone",
                ]);
            }
        );
    }

    public function testLabels()
    {
        $this->specify(
            "Form::getLabel and Form::label do not return the correct values",
            function () {
                $form = new Form();

                $form->add(
                    new Text("name")
                );

                $telephone = new Text("telephone");

                $telephone->setLabel("The Telephone");

                $form->add($telephone);

                expect($form->getLabel("name"))->equals("name");
                expect($form->getLabel("telephone"))->equals("The Telephone");

                expect($form->label("name"))->equals("<label for=\"name\">name</label>");
                expect($form->label("telephone"))->equals("<label for=\"telephone\">The Telephone</label>");

                // https://github.com/phalcon/cphalcon/issues/1029
                expect($form->label("name", ["class" => "form-control"]))->equals("<label for=\"name\" class=\"form-control\">name</label>");
                expect($form->label("telephone", ["class" => "form-control"]))->equals("<label for=\"telephone\" class=\"form-control\">The Telephone</label>");
            }
        );
    }

    /**
     * Tests Form::hasMessagesFor
     *
     * @author Sid Roberts <Sid@SidRoberts.co.uk>
     * @since  2016-04-03
     */
    public function testFormHasMessagesFor()
    {
        $this->specify('Form::hasMessagesFor does not check correctly if the Group is empty', function () {
            // First element
            $telephone = new Text('telephone');

            $telephone->addValidators([
                new Regex([
                    'pattern' => '/\+44 [0-9]+ [0-9]+/',
                    'message' => 'The telephone has an invalid format'
                ])
            ]);

            // Second element
            $address = new Text('address');
            $form = new Form();

            $form->add($telephone);
            $form->add($address);

            expect($form->isValid(['telephone' => '12345', 'address' => 'hello']))->false();

            expect($form->getMessagesFor('telephone'))->equals(
                Group::__set_state([
                    '_messages' => [
                        Message::__set_state([
                            '_type'    => 'Regex',
                            '_message' => 'The telephone has an invalid format',
                            '_field'   => 'telephone',
                            '_code'    => 0,
                        ])
                    ],
                ])
            );

            expect($form->getMessagesFor('address'))->equals(Group::__set_state(['_messages' => []]));
            expect($form->hasMessagesFor('telephone'))->true();
            expect($form->hasMessagesFor('address'))->false();
        });
    }

    /**
     * Tests Form::render
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/10398
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-07-17
     */
    public function testCreatingElementsWithNameSimilarToTheFormMethods()
    {
        $this->specify('Form::render does not return expected result', function ($name) {
            $form  = new Form;
            $element = new Text($name);

            expect($element->getName())->equals($name);

            $form->add($element);

            expect($form->render($name))->equals(sprintf('<input type="text" id="%s" name="%s" />', $name, $name));
            expect($form->getValue($name))->null();
            expect($element->getValue())->null();
        }, ['examples' => $this->nameLikeFormMethodsProvider()]);
    }

    protected function nameLikeFormMethodsProvider()
    {
        return [
            ['validation'],
            ['action'],
            ['useroption'],
            ['useroptions'],
            ['entity'],
            ['elements'],
            ['messages'],
            ['messagesfor'],
            ['label'],
            ['value'],
            ['di'],
            ['eventsmanager'],
        ];
    }

    public function testFormValidator()
    {
        $this->specify(
            "Form validators don't work",
            function () {
                //First element
                $telephone = new Text("telephone");

                $telephone->addValidator(
                    new PresenceOf(
                        array(
                            'message' => 'The telephone is required'
                        )
                    )
                );

                expect($telephone->getValidators())->count(1);

                $telephone->addValidators(array(
                    new StringLength(array(
                        'min' => 5,
                        'messageMinimum' => 'The telephone is too short'
                    )),
                    new Regex(array(
                        'pattern' => '/\+44 [0-9]+ [0-9]+/',
                        'message' => 'The telephone has an invalid format'
                    ))
                ));

                expect($telephone->getValidators())->count(3);

                //Second element
                $address = new Text('address');

                $address->addValidator(
                    new PresenceOf(
                        array(
                            'message' => 'The address is required'
                        )
                    )
                );

                expect($address->getValidators())->count(1);

                $form = new Form();

                $form->add($telephone);
                $form->add($address);

                expect($form->isValid([]))->false();

                $expectedMessages = Group::__set_state(
                    array(
                        '_messages' => array(
                            0 => Message::__set_state(
                                array(
                                    '_type' => 'PresenceOf',
                                    '_message' => 'The telephone is required',
                                    '_field' => 'telephone',
                                    '_code' => 0,
                                )
                            ),
                            1 => Message::__set_state(
                                array(
                                    '_type' => 'TooShort',
                                    '_message' => 'The telephone is too short',
                                    '_field' => 'telephone',
                                    '_code' => 0,
                                )
                            ),
                            2 => Message::__set_state(
                                array(
                                    '_type' => 'Regex',
                                    '_message' => 'The telephone has an invalid format',
                                    '_field' => 'telephone',
                                    '_code' => 0,
                                )
                            ),
                            3 => Message::__set_state(
                                array(
                                    '_type' => 'PresenceOf',
                                    '_message' => 'The address is required',
                                    '_field' => 'address',
                                    '_code' => 0,
                                )
                            ),
                        ),
                    )
                );

                expect($form->getMessages())->equals($expectedMessages);

                expect($form->isValid(array(
                    'telephone' => '12345',
                    'address' => 'hello'
                )))->false();

                $expectedMessages = Group::__set_state(array(
                    '_messages' => array(
                        0 =>  Message::__set_state(array(
                            '_type' => 'Regex',
                            '_message' => 'The telephone has an invalid format',
                            '_field' => 'telephone',
                            '_code' => 0,
                        )),
                    ),
                ));

                expect($form->getMessages())->equals($expectedMessages);

                expect($form->isValid(array(
                    'telephone' => '+44 124 82122',
                    'address' => 'hello'
                )))->true();
            }
        );
    }

    public function testFormIndirectElementRender()
    {
        $this->specify(
            "Indirect form element render doesn't work",
            function () {
                $form = new Form();

                $form->add(new Text("name"));

                expect($form->render("name"))->equals('<input type="text" id="name" name="name" />');
                expect($form->render("name", ["class" => "big-input"]))->equals('<input type="text" id="name" name="name" class="big-input" />');
            }
        );
    }

    /**
     * @issue https://github.com/phalcon/cphalcon/issues/1190
     */
    public function testIssue1190()
    {
        $this->specify(
            "Form::render doesn't escape value attributes on TextFields",
            function () {
                $object = new \stdClass();
                $object->title = 'Hello "world!"';

                $form = new Form($object);
                $form->add(new Text("title"));

                $actual   = $form->render("title");
                $expected = '<input type="text" id="title" name="title" value="Hello &quot;world!&quot;" />';

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * @issue https://github.com/phalcon/cphalcon/issues/706
     */
    public function testIssue706()
    {
        $this->specify(
            "Form field positions don't work",
            function () {
                $form = new Form();
                $form->add(new Text("name"));

                $form->add(new Text("before"), "name", true);
                $form->add(new Text("after"), "name");

                $data = ["before", "name", "after"];
                $result = [];

                foreach ($form as $element) {
                    $result[] = $element->getName();
                }

                expect($result)->equals($data);
            }
        );
    }

    /**
     * Tests Element::hasMessages() Element::getMessages()
     *
     * @author Mohamad Rostami <rostami@outlook.com>
     * @issue  https://github.com/phalcon/cphalcon/issues/11135
     * @issue  https://github.com/phalcon/cphalcon/issues/3167
     */
    public function testElementMessages()
    {
        $this->specify('Element messages are empty if form validation fails', function () {
            // First element
            $telephone = new Text('telephone');

            $telephone->addValidators([
                new Regex([
                    'pattern' => '/\+44 [0-9]+ [0-9]+/',
                    'message' => 'The telephone has an invalid format'
                ])
            ]);

            // Second element
            $address = new Text('address');
            $form = new Form();

            $form->add($telephone);
            $form->add($address);

            expect($form->isValid(['telephone' => '12345', 'address' => 'hello']))->false();
            expect($form->get('telephone')->hasMessages())->true();
            expect($form->get('address')->hasMessages())->false();

            expect($form->get('telephone')->getMessages())->equals(
                Group::__set_state([
                    '_messages' => [
                        Message::__set_state([
                            '_type'    => 'Regex',
                            '_message' => 'The telephone has an invalid format',
                            '_field'   => 'telephone',
                            '_code'    => 0,
                        ])
                    ],
                ])
            );
            expect($form->get('telephone')->getMessages())->equals($form->getMessages());
            expect($form->get('address')->getMessages())->equals(Group::__set_state(['_messages' => []]));
            expect($form->getMessagesFor('notelement'))->equals(Group::__set_state(['_messages' => []]));
        });
    }

    /**
     * Tests Form::setValidation()
     *
     * @author Mohamad Rostami <rostami@outlook.com>
     * @issue  https://github.com/phalcon/cphalcon/issues/12465
     */
    public function testCustomValidation()
    {
        $this->specify('Injecting custom validation to form doesn\'t validate correctly', function () {
            // First element
            $telephone = new Text('telephone');
            $customValidation = new Validation();
            $customValidation->add('telephone', new Regex([
                'pattern' => '/\+44 [0-9]+ [0-9]+/',
                'message' => 'The telephone has an invalid format'
            ]));
            $form = new Form();
            $address = new Text('address');
            $form->add($telephone);
            $form->add($address);
            $form->setValidation($customValidation);
            expect($form->isValid(['telephone' => '12345', 'address' => 'hello']))->false();
            expect($form->get('telephone')->hasMessages())->true();
            expect($form->get('address')->hasMessages())->false();
            expect($form->get('telephone')->getMessages())->equals(
                Group::__set_state([
                    '_messages' => [
                        Message::__set_state([
                            '_type' => 'Regex',
                            '_message' => 'The telephone has an invalid format',
                            '_field' => 'telephone',
                            '_code' => 0,
                        ])
                    ],
                ])
            );
            expect($form->get('telephone')->getMessages())->equals($form->getMessages());
            expect($form->get('address')->getMessages())->equals(Group::__set_state(['_messages' => []]));
        });
    }

    /**
     * Tests Form::isValid()
     *
     * @author Mohamad Rostami <rostami@outlook.com>
     * @issue  https://github.com/phalcon/cphalcon/issues/11500
     */
    public function testMergeValidators()
    {
        $this->specify('Injecting custom validation to form doesn\'t merge validators on isValid', function () {
            // First element
            $telephone = new Text('telephone');
            $telephone->addValidators([
                new PresenceOf([
                    'message' => 'The telephone is required'
                ])
            ]);
            $customValidation = new Validation();
            $customValidation->add('telephone', new Regex([
                'pattern' => '/\+44 [0-9]+ [0-9]+/',
                'message' => 'The telephone has an invalid format'
            ]));
            $form = new Form();
            $address = new Text('address');
            $form->add($telephone);
            $form->add($address);
            $form->setValidation($customValidation);
            expect($form->isValid(['address' => 'hello']))->false();
            expect($form->get('telephone')->hasMessages())->true();
            expect($form->get('address')->hasMessages())->false();
            expect($form->get('telephone')->getMessages())->equals(
                Group::__set_state([
                    '_messages' => [
                        Message::__set_state([
                            '_type' => 'Regex',
                            '_message' => 'The telephone has an invalid format',
                            '_field' => 'telephone',
                            '_code' => 0,
                        ]),
                        Message::__set_state([
                            '_type' => 'PresenceOf',
                            '_message' => 'The telephone is required',
                            '_field' => 'telephone',
                            '_code' => 0,
                        ])
                    ],
                ])
            );
            expect($form->get('telephone')->getMessages())->equals($form->getMessages());
            expect($form->get('address')->getMessages())->equals(Group::__set_state(['_messages' => []]));
        });
    }

    /**
     * Tests Form::getMessages(true)
     *
     * @author Mohamad Rostami <rostami@outlook.com>
     * @issue  https://github.com/phalcon/cphalcon/issues/13294
     *
     * This should be removed in next major version
     * We should not return multiple type of result in a single method! (form->getMessages(true) vs form->getMessages())
     */
    public function testGetElementMessagesFromForm()
    {
        $this->specify('When form is not valid, iterate over messages by elements is not possible', function () {
            // First element
            $telephone = new Text('telephone');
            $telephone->addValidators([
                new PresenceOf([
                    'message' => 'The telephone is required'
                ])
            ]);
            $customValidation = new Validation();
            $customValidation->add('telephone', new Regex([
                'pattern' => '/\+44 [0-9]+ [0-9]+/',
                'message' => 'The telephone has an invalid format'
            ]));
            $form = new Form();
            $address = new Text('address');
            $form->add($telephone);
            $form->add($address);
            $form->setValidation($customValidation);
            expect($form->isValid(['address' => 'hello']))->false();
            expect($form->getMessages(true))->equals([
                'telephone' => [
                    Group::__set_state([
                        '_messages' => [
                            Message::__set_state([
                                '_type' => 'Regex',
                                '_message' => 'The telephone has an invalid format',
                                '_field' => 'telephone',
                                '_code' => 0,
                            ])
                        ]
                    ]),
                    Group::__set_state([
                        '_messages' => [
                            Message::__set_state([
                                '_type' => 'PresenceOf',
                                '_message' => 'The telephone is required',
                                '_field' => 'telephone',
                                '_code' => 0,
                            ])
                        ]
                    ])
                ]
            ]);
        });
    }
}
