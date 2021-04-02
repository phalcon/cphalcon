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

namespace Phalcon\Test\Integration\Forms\Element\TextArea;

use IntegrationTester;
use Phalcon\Forms\Element\TextArea;
use Phalcon\Test\Fixtures\Traits\DiTrait;

class GetSetNameCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->newDi();
        $this->setDiService('escaper');
        $this->setDiService('url');
    }

    /**
     * Tests Phalcon\Forms\Element\TextArea :: getName() / setName()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-06-02
     */
    public function formsElementTextAreaGetSetName(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Element\TextArea - getName() / setName()');

        $element = new TextArea('simple');

        $I->assertEquals(
            'simple',
            $element->getName()
        );

        $element->setName('different');

        $I->assertEquals(
            'different',
            $element->getName()
        );
    }
}
