<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Forms\Form;

use IntegrationTester;
use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Form;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Tag;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Validation\Validator\Regex;

/**
 * Class HasMessagesForCest
 */
class HasMessagesForCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->newDi();
        $this->setDiEscaper();
        $this->setDiUrl();
    }

    /**
     * executed after each test
     */
    public function _after(IntegrationTester $I)
    {
        // Setting the doctype to XHTML5 for other tests to run smoothly
        Tag::setDocType(Tag::XHTML5);
    }

    /**
     * Tests Form::hasMessagesFor
     *
     * @author Sid Roberts <sid@sidroberts.co.uk>
     * @since  2016-04-03
     */
    public function testFormHasMessagesFor(IntegrationTester $I)
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

        $actual = $form->isValid(
            [
                'telephone' => '12345',
                'address'   => 'hello',
            ]
        );

        $I->assertFalse($actual);


        $expected = new Messages(
            [
                new Message(
                    'The telephone has an invalid format',
                    'telephone',
                    'Regex',
                    0
                ),
            ]
        );

        $actual = $form->getMessagesFor('telephone');

        $I->assertEquals($expected, $actual);


        $expected = new Messages();
        $actual   = $form->getMessagesFor('address');

        $I->assertEquals($expected, $actual);


        $actual = $form->hasMessagesFor('telephone');

        $I->assertTrue($actual);


        $actual = $form->hasMessagesFor('address');

        $I->assertFalse($actual);
    }
}
