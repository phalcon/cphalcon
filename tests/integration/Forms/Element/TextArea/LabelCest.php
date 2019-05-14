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

namespace Phalcon\Test\Integration\Forms\Element\TextArea;

use IntegrationTester;

/**
 * Class LabelCest
 */
class LabelCest
{
    /**
     * Tests Phalcon\Forms\Element\TextArea :: label()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function formsElementTextareaLabel(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Element\TextArea - label()');
        $I->skipTest('Need implementation');
    }
}
