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

namespace Phalcon\Test\Integration\Forms\Element\Check;

use IntegrationTester;
use Phalcon\Forms\Element\Check;
use Phalcon\Test\Fixtures\Traits\DiTrait;

class GetSetNameCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->newDi();
        $this->setDiEscaper();
        $this->setDiUrl();
    }

    /**
     * Tests Phalcon\Forms\Element\Check :: getName() / setName()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-06-02
     */
    public function formsElementCheckGetSetName(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Element\Check - getName() / setName()');

        $element = new Check('simple');

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
