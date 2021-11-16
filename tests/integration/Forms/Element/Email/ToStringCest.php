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

namespace Phalcon\Tests\Integration\Forms\Element\Email;

use IntegrationTester;
use Phalcon\Forms\Element\Email;
use Phalcon\Tag;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

class ToStringCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->newDi();
        $this->setDiService('escaper');
        $this->setDiService('url');
    }

    /**
     * executed after each test
     */
    public function _after(IntegrationTester $I)
    {
        // Setting the doctype to XHTML5 for other tests to run smoothly
        Tag::setDocType(
            Tag::XHTML5
        );
    }

    /**
     * Tests Phalcon\Forms\Element\Email :: __toString()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-23
     */
    public function formsElementEmailToStringSimple(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Element\Email - __toString()');

        $element = new Email('simple');

        $I->assertEquals(
            '<input type="email" id="simple" name="simple" />',
            (string) $element
        );
    }

    /**
     * Tests Phalcon\Forms\Element\Email :: __toString() with parameters
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-23
     */
    public function formsElementEmailToStringWithParameters(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Element\Email - __toString() with parameters');

        $element = new Email(
            'fantastic',
            [
                'class'       => 'fancy',
                'placeholder' => 'Initial value',
            ]
        );

        $I->assertEquals(
            '<input type="email" id="fantastic" name="fantastic" class="fancy" placeholder="Initial value" />',
            (string) $element
        );
    }
}
