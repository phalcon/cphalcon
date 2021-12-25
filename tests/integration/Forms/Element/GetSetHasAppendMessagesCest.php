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

namespace Phalcon\Tests\Integration\Forms\Element;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Forms\Element\Check;
use Phalcon\Forms\Element\Date;
use Phalcon\Forms\Element\Email;
use Phalcon\Forms\Element\File;
use Phalcon\Forms\Element\Hidden;
use Phalcon\Forms\Element\Numeric;
use Phalcon\Forms\Element\Password;
use Phalcon\Forms\Element\Radio;
use Phalcon\Forms\Element\Select;
use Phalcon\Forms\Element\Submit;
use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Element\TextArea;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;

use function uniqid;

class GetSetHasAppendMessagesCest
{
    /**
     * Tests Phalcon\Forms\Element\* :: getMessages()/setMessages()/hasMessages()/appendMessage()
     *
     * @dataProvider getExamples
     *
     * @param IntegrationTester $I
     * @param Example           $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2021-12-05
     */
    public function formsElementGetSetAppendMessages(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Forms\Element\* - getMessages()/setMessages()/appendMessage() - ' . $example[0]);

        $name   = uniqid();
        $one    = new Message('one', 'two');
        $two    = new Message('three', 'four');
        $three  = new Message('five', 'six');
        $messages = new Messages(
            [
                $one,
                $two,
            ]
        );

        $class  = $example[1];
        $object = new $class($name);

        $class  = Messages::class;
        $actual = $object->getMessages();
        $I->assertInstanceOf($class, $actual);

        $actual = $object->hasMessages();
        $I->assertFalse($actual);

        $object->setMessages($messages);

        $expected = $messages;
        $actual   = $object->getMessages();
        $I->assertSame($expected, $actual);

        $object->appendMessage($three);

        $messages[] = $three;
        $expected   = $messages;
        $actual     = $object->getMessages();
        $I->assertSame($expected, $actual);

        $actual = $object->hasMessages();
        $I->assertTrue($actual);
    }

    /**
     * @return string[][]
     */
    private function getExamples(): array
    {
        return [
            ["Check", Check::class],
            ["Date", Date::class],
            ["Email", Email::class],
            ["File", File::class],
            ["Hidden", Hidden::class],
            ["Numeric", Numeric::class],
            ["Password", Password::class],
            ["Radio", Radio::class],
            ["Select", Select::class],
            ["Submit", Submit::class],
            ["Text", Text::class],
            ["TextArea", TextArea::class],
        ];
    }
}
