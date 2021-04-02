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

namespace Phalcon\Test\Integration\Forms\Element\Date;

use IntegrationTester;
use Phalcon\Forms\Element\Date;
use Phalcon\Tag;
use Phalcon\Test\Fixtures\Traits\DiTrait;

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
     * Tests Phalcon\Forms\Element\Date :: __toString()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-23
     */
    public function formsElementDateToStringSimple(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Element\Date - __toString()');

        $element = new Date('simple');

        $I->assertEquals(
            '<input type="date" id="simple" name="simple" />',
            (string) $element
        );
    }

    /**
     * Tests Phalcon\Forms\Element\Date :: __toString() with parameters
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-23
     */
    public function formsElementDateToStringWithParameters(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Element\Date - __toString() with parameters');

        $element = new Date(
            'fantastic',
            [
                'class' => 'fancy',
            ]
        );

        $I->assertEquals(
            '<input type="date" id="fantastic" name="fantastic" class="fancy" />',
            (string) $element
        );
    }
}
