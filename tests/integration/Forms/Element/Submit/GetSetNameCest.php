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

namespace Phalcon\Tests\Integration\Forms\Element\Submit;

use IntegrationTester;
use Phalcon\Forms\Element\Submit;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

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
     * Tests Phalcon\Forms\Element\Submit :: getName() / setName()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-06-02
     */
    public function formsElementSubmitGetSetName(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Element\Submit - getName() / setName()');

        $element = new Submit('simple');

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
